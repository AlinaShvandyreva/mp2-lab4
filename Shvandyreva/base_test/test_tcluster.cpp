#include "TCluster.cpp"
#include "TCluster.h"
#include <gtest.h>

TEST(TCluster, can_create_cluster)
{
	ASSERT_NO_THROW(TCluster cluster());
}
TEST(TCluster, can_create_cluster_with_values)
{
	ASSERT_NO_THROW(TCluster cluster(10, 10, 0.8));
}
TEST(TCluster, can_work_cluster_with_values)
{
	TCluster cluster(10, 10, 0.8);
	ASSERT_NO_THROW(cluster.PreparationForWork(10));
}
TEST(TCluster, can_create_cluster_less_than_min_size_processors)
{
	ASSERT_ANY_THROW(TCluster cluster(MIN_PROCESSORS_SIZE-1, 10, 0.8));
}
TEST(TCluster, can_create_cluster_more_than_max_size_processors)
{
	ASSERT_ANY_THROW(TCluster cluster(MAX_PROCESSORS_SIZE+1, 10, 0.8));
}
TEST(TCluster, can_create_cluster_less_than_min_size_tacts)
{
	ASSERT_ANY_THROW(TCluster cluster(10, MIN_TACTS_SIZE-1, 0.8));
}
TEST(TCluster, can_create_cluster_more_than_max_size_tacts)
{
	ASSERT_ANY_THROW(TCluster cluster(10, MAX_TACTS_SIZE+1, 0.8));
}
TEST(TCluster, can_create_cluster_less_than_min_size_intensity)
{
	ASSERT_ANY_THROW(TCluster cluster(10, 10, MIN_INTENSITY_SIZE-1));
}
TEST(TCluster, can_create_cluster_more_than_max_size_intensity)
{
	ASSERT_ANY_THROW(TCluster cluster(10, 10, MAX_INTENSITY_SIZE+1));
}
TEST(TCluster, can_work_cluster_less_than_min_size)
{
	TCluster cluster(10, 10, 0.8);
	ASSERT_ANY_THROW(cluster.PreparationForWork(MIN_QUEUE_SIZE-1));
}
TEST(TCluster, can_work_cluster_more_than_max_size)
{
	TCluster cluster(10, 10, 0.8);
	ASSERT_ANY_THROW(cluster.PreparationForWork(MAX_QUEUE_SIZE+1));
}