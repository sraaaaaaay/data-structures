#include "linkedlist.h"

struct Node {
    void* value;
    Node* next;
};

struct LinkedList {
    Node* head;
    size_t size;
    size_t element_size;
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
        printf("Couldn't make node");
        return NULL;
    }
    /* Make some space for the new value*/
    node->value = malloc(list->element_size);
    if (!node->value) {
        printf("Couldn't make node value");
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
        printf("Error getting list size: list does not exist");
        return NULL;
    }
    if (list->size)
        return list->size;
}
