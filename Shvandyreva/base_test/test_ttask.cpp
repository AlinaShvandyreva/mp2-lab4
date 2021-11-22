#include "TTask.h"
#include <gtest.h>

TEST(TTask, can_create_task)
{
	ASSERT_NO_THROW(TTask task);
}
TEST(TTask, can_create_task_with_values)
{
	ASSERT_NO_THROW(TTask task(10,10));
}
TEST(TTask, cant_create_task_with_incorrect_size_one)
{
	ASSERT_ANY_THROW(TTask task(MIN_PROCESSORS_SIZE - 1, MIN_TACTS_SIZE - 1));
}
TEST(TTask, cant_create_task_with_incorrect_size_two)
{
	ASSERT_ANY_THROW(TTask task(MAX_PROCESSORS_SIZE + 1, MAX_TACTS_SIZE + 1));
}
TEST(TTask, cant_create_task_with_incorrect_size_three)
{
	ASSERT_ANY_THROW(TTask task(50, MIN_TACTS_SIZE - 1));
}
TEST(TTask, cant_create_task_with_incorrect_size_four)
{
	ASSERT_ANY_THROW(TTask task(MIN_PROCESSORS_SIZE - 1, 600));
}