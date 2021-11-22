#include "TQueue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> v;);
}
TEST(TQueue, can_create_queue_with_values)
{
	ASSERT_NO_THROW(TQueue<int> v(10););
}
TEST(TQueue, cant_create_queue_more_than_max_size)
{
	ASSERT_ANY_THROW(TQueue<int> queue(MAX_QUEUE_SIZE + 1));
}
TEST(TQueue, cant_create_queue_more_than_min_size)
{
	ASSERT_ANY_THROW(TQueue<int> queue(MIN_QUEUE_SIZE - 1));
}
TEST(TQueue, can_get_empty_queue)
{
	TQueue<int> queue;
	EXPECT_EQ(1, queue.Empty());
}
TEST(TQueue, can_get_full_queue)
{
	TQueue<int> queue(5);
	queue.AddElQueue(1);
	queue.AddElQueue(2);
	queue.AddElQueue(3);
	queue.AddElQueue(4);
	queue.AddElQueue(5);
	EXPECT_EQ(1, queue.Full());
}
TEST(TQueue, can_get_first_in_queue_one)
{ 
	TQueue<int> queue(10);
	queue.AddElQueue(1);
	queue.AddElQueue(2);
	EXPECT_EQ(1, queue.GetTop());
}
TEST(TQueue, can_get_first_in_queue_two)
{
	TQueue<int> queue(10);
	queue.AddElQueue(1);
	queue.AddElQueue(2);
	EXPECT_EQ(1, queue.TakeElQueue());
}
TEST(TQueue, can_get_first_in_queue_and_delete)
{
	TQueue<int> queue(10);
	queue.AddElQueue(1);
	queue.AddElQueue(2);
	queue.TakeElQueue();
	EXPECT_EQ(2, queue.GetTop());
}
TEST(TQueue, can_get_number_of_tasks_in_queue)
{
	TQueue<int> queue(10);
	queue.AddElQueue(1);
	queue.AddElQueue(2);
	EXPECT_EQ(2, queue.BusyElSize());
}
