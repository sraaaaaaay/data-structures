#include "arraylist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ArrayList {
    void* buffer;        ///< A pointer to the allocated memory section.
    size_t element_size; ///< The size of the element type to be stored. Must be specified at creation time.
    unsigned int bufsize; ///< The maximum size of the buffer. Increased as necessary.
    unsigned int len; ///< The size of the buffer.
};

ArrayList* ArrayListCreate(int initial_capacity, size_t element_size) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));

    /* Malloc failed: return null */
    if (!list)
        return NULL;

    list->len          = 0;
    list->element_size = element_size;
    list->bufsize      = initial_capacity > 0 ? initial_capacity : 10;
    list->buffer       = (int*)malloc(list->bufsize * element_size);

    /* If malloc failed, let the caller handle it */
    if (!list->buffer)
        return NULL;

    return list;
}

int ArrayListAdd(ArrayList* list, void* value) {
    /* If the list is full, double its size (arbitrary growth factor - 1.5 is also common) */
    if (list->len >= list->bufsize) {

        list->bufsize *= 2;
        void* newList = realloc(list->buffer, list->bufsize * list->element_size);
        
        /* If the realloc failed, return failure */
        if (!list)
            return 0;

        list->buffer = newList;
    }

    /* Type-agnostic means no indexed access - calculate chunk via pointer arithmetic */
    void* target = (char*)list->buffer + (list->len * list->element_size);
    memcpy(target, value, list->element_size);
    list->len++;

    return 1;
}

int ArrayListRemove(ArrayList* list, int index) {
    if (index < 0 || index > list->len) {
        return 0;
    }

    // Pointer arithmetic - find where we're copying to (what's the newly-empty memory chunk?)
    char* destination = (char*)list->buffer + (index * list->element_size);

    // Pointer arithmetic - where are we copying from? (start at the next element after the removed one)
    char* src = destination + list->element_size;

    // How far to the end of the allocated memory?
    int bytes_to_move = (list->len - (index - 1)) * list->element_size;

    // Move everything as needed
    if (bytes_to_move > 0) {
        memcpy(destination, src, bytes_to_move);
    }
    list->len--;
    return 1;
}

void* ArrayListGet(ArrayList* list, int index) {
    /* List doesn't exist, return null */
    if (!list) {
        return NULL;
    }
    /* Index out of bounds: return null */
    if (index > list->len - 1) {
        return NULL;
    }

    /* Pointer arithmetic to get the element */
    return (char*)list->buffer + (index * list->element_size);
}

void ArrayListFree(ArrayList* list) {
    free(list->buffer);
    free(list);
}