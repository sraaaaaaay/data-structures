#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Implements a type-agnostic node in a Linked List
 *
 */
typedef struct Node Node;

/**
 * @brief Implements a type-agnostic Linked List
 *
 */
typedef struct LinkedList LinkedList;


/**
 * @brief Create a new linked list
 *
 * @param element_size The size of the element to be stored (monotype, agnostic)
 * @return LinkedList* The newly-created list
 */
LinkedList* LinkedListCreate(size_t element_size);

/**
 * @brief Add a value to an existing LinkedList
 *
 * @param list The list to add to
 * @param value The value to add
 * @return int Success/failure value
 */
int LinkedListAdd(LinkedList* list, void* value);

/**
 * @brief Get the size of an existing LinkedList
 *
 * @param list List to get the size of
 * @return int the size
 */
int LinkedListGetSize(LinkedList* list);



#endif