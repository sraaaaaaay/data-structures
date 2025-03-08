#include "linkedlist.h"
#include "compare.h"
#include <string.h>

struct Node {
    void* value; ///< A pointer to the value (type-agnostic)
    Node* next;  ///< The next node in the list
};

struct LinkedList {
    Node* head;          ///< The first value in the linked list
    size_t size;         ///< The size of the list
    size_t element_size; ///< The size of a value stored in the list
};

LinkedList* LinkedListCreate(size_t element_size) {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

    /* Make sure we have enough memory */
    if (!list) {
        return NULL;
    }

    list->size         = 0;
    list->element_size = element_size;
    list->head         = NULL;

    return list;
}

int LinkedListAdd(LinkedList* list, void* value) {
    /* Make space for the new node*/
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        return NULL;
    }
    /* Make some space for the new value*/
    node->value = malloc(list->element_size);
    if (!node->value) {
        free(node);
        return NULL;
    }

    /* Copy arg into node */
    memcpy(node->value, value, list->element_size);
    node->next = NULL;

    /* Find the tail and add the new node */
    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* cur = list->head;
        while (cur->next != NULL) {
            cur = cur->next;
        }

        cur->next = node;
    }
    ++list->size;
}


int LinkedListGetSize(LinkedList* list) {
    if (!list) {
        return NULL;
    }
    if (list->size)
        return list->size;
}

void* LinkedListGetIndex(LinkedList* list, int index) {
    if (!list)
        return NULL;
    if (list->size == 0)
        return NULL;
    if (index >= list->size)
        return NULL;

    int i     = 0;
    Node* cur = list->head;
    while (i < index) {
        cur = cur->next;
        i++;
    }
    return cur->value;
}

int LinkedListContains(LinkedList* list, void* value, compare_func f) {
    if (!list)
        return -1;
    if (list->size == 0)
        return -1;

    Node* cur = list->head;

    while (cur != NULL) {
        if (f(cur->value, value) == 0) {
            return 1;
        }
    }
    return 0;
}
