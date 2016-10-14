#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  TVector<int> v(5), cop(1);
  v[1] = 1;
  v[2] = 3;
  v[4] = 228;

  cop = v;

  EXPECT_EQ(v, cop);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v(5), cop(1);
  v[1] = 1;
  v[2] = 3;
  v[4] = 228;

  cop = v;

  v[4] = 1337;

  EXPECT_EQ(228, cop[4]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
  TVector<int> v(5);

  ASSERT_ANY_THROW(v[-1] = 1);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<int> v(5);

  ASSERT_ANY_THROW(v[100500] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> v(2);
  v[0] = 1;
  v[1] = 15;

  v = v;
  
  EXPECT_EQ(1, v[0]);
  EXPECT_EQ(15, v[1]);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<int> v(3), w(3);
  v[0] = 1;
  v[1] = 15;
  v[2] = 666;

  w = v;

  EXPECT_EQ(1,w[0]);
  EXPECT_EQ(15, w[1]);
  EXPECT_EQ(666, w[2]);
  
}

TEST(TVector, assign_operator_change_vector_size)
{
  TVector<int> v(3), w(50);

  v = w;

  EXPECT_EQ(50, v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  TVector<int> v(11), w(3);
  v[0] = 1;
  v[1] = 15;
  v[10] = 666;

  w = v;

  EXPECT_EQ(1,w[0]);
  EXPECT_EQ(15, w[1]);
  EXPECT_EQ(666, w[10]);
}

TEST(TVector, compare_equal_vectors_return_true)
{
  TVector<int> v(3), w(3);
  
  v[0] = 1;
  v[1] = 15;
  v[2] = 666;

  w[0] = 1;
  w[1] = 15;
  w[2] = 666;

  EXPECT_EQ(true ,w==v);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  TVector<int> v(11);
  
  v[0] = 1;
  v[1] = 15;
  v[10] = 666;

  EXPECT_EQ(true ,v==v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  TVector<int> v(11), w(3);
  
  v[0] = 1;
  v[1] = 15;
  v[10] = 666;

  w[0] = 1;
  w[1] = 15;

  EXPECT_EQ(false ,w==v);
}

TEST(TVector, can_add_scalar_to_vector)
{
  TVector<int> v(2), w(2);

  v[0] = 17;
  v[1] = 27;

  w[0] = 20;
  w[1] = 30;

  EXPECT_EQ(w ,v+3);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  TVector<int> v(2), w(2);

  v[0] = 17;
  v[1] = 27;

  w[0] = 20;
  w[1] = 30;

  EXPECT_EQ(v ,w-3);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
  TVector<int> v(2), w(2);

  v[0] = 3;
  v[1] = 6;

  w[0] = 1;
  w[1] = 2;

  EXPECT_EQ(v ,w*3);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
  TVector<int> v(2), w(2), res(2);

  v[0] = 3;
  v[1] = 6;

  w[0] = 1;
  w[1] = 2;

  res[0] = 4;
  res[1] = 8;

  EXPECT_EQ(res ,v+w);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
  TVector<int> v(2), w(3);

  ASSERT_ANY_THROW(v+w);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  TVector<int> v(2), w(2), res(2);

  v[0] = 3;
  v[1] = 6;

  w[0] = 1;
  w[1] = 2;

  res[0] = 2;
  res[1] = 4;

  EXPECT_EQ(res ,v-w);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  TVector<int> v(2), w(3);

  v[0] = 3;
  v[1] = 6;

  w[0] = 1;
  w[2] = 2;

  ASSERT_ANY_THROW(v-w);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  TVector<int> v(2), w(2);

  v[0] = 2;
  v[1] = 6;

  w[0] = 2;
  w[1] = 4;

  EXPECT_EQ(28 ,v*w);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  TVector<int> v(2), w(3);

  v[0] = 2;
  v[1] = 6;

  w[0] = 2;
  w[1] = 4;
  w[2] = 1;

  ASSERT_ANY_THROW(v*w);
}

