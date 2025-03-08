#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Implements a type-agnostic ArrayList.
 *
 * Includes create, add, remove, get and free operations.
 */
typedef struct ArrayList ArrayList;

/**
 * @brief
 *
 *
 * @brief Creates a new ArrayList.
 *
 * @param initial_capacity The initial size of the buffer.
 * @param element_size The size of the element type being stored
 * @return ArrayList* A pointer to the ArrayList.
 */
ArrayList* ArrayListCreate(int initial_capacity, size_t element_size);

/**
 * @brief Adds a value to the ArrayList.
 *
 * @param list A pointer to the ArrayList being worked with.
 * @param value The value to be added.
 * @return int 1 if the addition is successful, 0 if it fails.
 */
int ArrayListAdd(ArrayList* list, void* value);

/**
 * @brief Removes the element from a specified ArrayList at the specified index.
 *
 * Pointer arithmetic is used to left-shift the array elements as needed.
 *
 * @param list A pointer to the ArrayList to remove from.
 * @param index The index to remove at.
 * @return int 1 if successful, 0 if failure.
 */
int ArrayListRemove(ArrayList* list, int index);

/**
 * @brief Gets the value at a specified index of a specified ArrayList.
 *
 * @param list The ArrayList to get from.
 * @param index The index to get the value from.
 * @return void* A void pointer to the returned element (casting responsibility is on the user).
 */
void* ArrayListGet(ArrayList* list, int index);

/**
 * @brief Frees the memory allocated for an ArrayList
 * 
 * @param list The ArrayList to free up.
 */
int ArrayListFree(ArrayList* list);

#endif