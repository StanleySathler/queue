#include "../libs/include/assert.h"
#include "../src/queue.h"

int
main()
{
  queue_t q;

  q = queue_create(1);
  assert_int(1, queue_empty(&q), "(queue_empty): Should return true if queue is empty");
  queue_destroy(&q);

  q = queue_create(1);
  queue_add(&q, 5);
  assert_int(0, queue_empty(&q), "(queue_empty): Should return false if queue is NOT empty");
  queue_destroy(&q);

  q = queue_create(1);
  queue_add(&q, 5);
  assert_int(1, queue_full(&q), "(queue_full): Should return true if queue is full");
  queue_destroy(&q);

  q = queue_create(1);
  assert_int(0, queue_full(&q), "(queue_full): Should return false if queue is NOT full");
  queue_destroy(&q);

  q = queue_create(2);
  queue_add(&q, 1);
  queue_add(&q, 2);
  assert_int(2, q.total, "(queue_add): Should set total correctly after adding an item");
  assert_int(1, queue_consume(&q), "(queue_add): Should have added 1");
  assert_int(2, queue_consume(&q), "(queue_add): Should have added 2");
  queue_destroy(&q);

  q = queue_create(2);
  queue_add(&q, 2);
  queue_add(&q, 3);
  queue_consume(&q);
  queue_add(&q, 5);
  assert_int(5, q.items[0], "(queue_add): Should queue the item in a circular way");
  queue_destroy(&q);

  q = queue_create(2);
  queue_add(&q, 5);
  queue_add(&q, 6);
  assert_int(5, queue_consume(&q), "(queue_consume): Should consume the first added item");
  assert_int(6, queue_consume(&q), "(queue_consume): Should consume the second added item");
  queue_destroy(&q);

  q = queue_create(2);
  queue_add(&q, 2);
  queue_add(&q, 3);
  queue_consume(&q);
  queue_add(&q, 5);
  queue_consume(&q);
  assert_int(5, queue_consume(&q), "(queue_consume): Should consume the item in a circular way");
  queue_destroy(&q);
}
