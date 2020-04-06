#ifndef __QUEUE_H__
#define __QUEUE_H__

  /**
   * @brief Queue's structure.
   */
  typedef struct {
    int max;
    int total;
    int pos_start;
    int pos_end;
    int* items;
  } queue_t;

  /**
   * @brief Find next start index circularly.
   */
  static int
  find_next_start(queue_t* queue);

  /**
   * @brief Find next end index circularly.
   */
  static int
  find_next_end(queue_t* queue);

  /**
   * @brief Create a queue.
   */
  queue_t
  queue_create(int max);

  /**
   * @brief Destroy a queue.
   */
  void
  queue_destroy(queue_t* queue);

  /**
   * @brief Check if the queue is empty.
   */
  int
  queue_empty(queue_t* queue);

  /**
   * @brief Check if the queue is full.
   */
  int
  queue_full(queue_t* queue);

  /**
   * @brief Add an item into the queue.
   */
  void
  queue_add(queue_t* queue, int item);

  /**
   * @brief Consume an item from the queue.
   */
  int
  queue_consume(queue_t* queue);

#endif /* __QUEUE_H__ */