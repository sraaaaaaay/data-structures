#include "queue.h"

struct Queue {
    void* buffer;        ///< Memory allocated for the buffer
    size_t element_size; ///< Size of an element in the Queue
    int bufsize;         ///< Maximum size of the queue (fixed at creation)
    int len;             ///< Length of the queue
    int tail;            ///< Index of the end of the queue
};

Queue* QueueCreate(int initial_capacity, size_t element_size) {
    if (initial_capacity <= 0)
        return NULL;
    if (element_size <= 0)
        return NULL;

    Queue* queue = (Queue*)malloc(sizeof(Queue));

    if (!queue)
        return NULL;

    queue->len          = 0;
    queue->tail         = 0;
    queue->bufsize      = initial_capacity;
    queue->element_size = element_size;
    queue->buffer       = (int*)malloc(queue->bufsize * element_size);

    if (!queue->buffer) {
        free(queue);
        return NULL;
    }
    return queue;
}

int QueueAdd(Queue* queue, void* element) {
    /* Queue must exist & have space */
    if (!queue)
        return -1;
    if (queue->len + 1 > queue->bufsize) {
        return -1;
    }

    void* target = (char*)queue->buffer + (queue->tail * queue->element_size);
    memcpy(target, element, queue->element_size);

    queue->tail = (queue->tail + 1) % queue->bufsize;
    queue->len++;

    return 1;
}

void* QueueGet(Queue* queue) {
    if (!queue || queue->len == 0)
        return NULL;

    size_t head_i = (queue->tail + queue->bufsize - queue->len) % queue->bufsize;
    void* head = (char*)queue->buffer + (head_i * queue->element_size);

    queue->len--;

    return head;
}

int QueueGetSize(Queue* queue){
    if(!queue) return -1;
    return queue->len;
}

void* QueuePeek(Queue* queue) {
    if (!queue || queue->len == 0)
        return NULL;

    size_t head_i = (queue->tail + queue->bufsize - queue->len) % queue->bufsize;
    void* head = (char*)queue->buffer + (head_i * queue->element_size);

    return head;
}

int QueueDelete(Queue* queue){
    if(!queue) return -1;
    free(queue->buffer);
    free(queue);
    return 0;
}