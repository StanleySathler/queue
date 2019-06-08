#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**
 * @brief Find next start index circularly.
 */
static int
find_next_start(queue_t* queue)
{
  return ((queue->pos_start + 1) < queue->max)
    ? (queue->pos_start + 1)
    : 0;
}

/**
 * @brief Find next end index circularly.
 */
static int
find_next_end(queue_t* queue)
{
  return ((queue->pos_end + 1) < queue->max)
    ? (queue->pos_end + 1)
    : 0;
}

/**
 * @brief Create a queue.
 */
queue_t
queue_create(int max)
{
  queue_t q;
  q.max = max;
  q.total = 0;
  q.pos_start = 0;
  q.pos_end = 0;
  q.items = malloc(sizeof(int) * max);

  return q;
}

/**
 * @brief Destroy a queue.
 */
void
queue_destroy(queue_t* queue)
{
  free(queue->items);
  queue = NULL;
}

/**
 * @brief Check if the queue is empty.
 */
int
queue_empty(queue_t* queue)
{
  return (queue->total == 0);
}

/**
 * @brief Check if the queue is full.
 */
int
queue_full(queue_t* queue)
{
  return (queue->total == queue->max);
}

/**
 * @brief Add an item into the queue.
 */
void
queue_add(queue_t* queue, int item)
{
  if (queue_full(queue))
  {
    fprintf(stderr, "Tried to add an item into a full queue");
    exit(1);
  }

  queue->items[queue->pos_end] = item;
  queue->total++;
  queue->pos_end = find_next_end(queue);
}

/**
 * @brief Consume an item from the queue.
 */
int
queue_consume(queue_t* queue)
{
  if (queue_empty(queue))
  {
    fprintf(stderr, "Tried to consume an item from an empty queue");
    exit(1);
  }

  int item = queue->items[queue->pos_start];
  queue->total--;
  queue->pos_start = find_next_start(queue);

  return item;
}