#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Type-agnostic circular queue
 * 
 */
typedef struct Queue Queue;

/**
 * @brief Creates a queue
 * 
 * @param initial_capacity Size of the queue buffer 
 * @param element_size Size of the queue elements
 * @return Queue* Pointer to the queue
 */
Queue* QueueCreate(int initial_capacity, size_t element_size);

/**
 * @brief Add to the tail of the queue
 * 
 * @param queue Queue to add to.
 * @param element Element to add.
 * @return int -1 if error, 1 if success.
 */
int QueueAdd(Queue* queue, void* element);

/**
 * @brief Get and remove head of queue.
 * 
 * @param queue Queue to remove from.
 * @return void* The value at the head.
 */
void* QueueGet(Queue* queue);

/**
 * @brief Get, but do not remove, the head of the queue.
 * 
 * @param queue Queue to remove from.
 * @return void* The value at the head.
 */
void* QueuePeek(Queue* queue);

int QueueDelete(Queue* queue);

#endif
