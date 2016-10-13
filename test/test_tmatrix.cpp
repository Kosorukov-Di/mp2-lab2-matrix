#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  TMatrix<int> v(5), cop(1);
  v[0][0] = 1;
  v[2][0] = 3;
  v[4][1] = 228;

  cop = v;

  EXPECT_EQ(v, cop);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix<int> v(5), cop(1);
  v[1][0] = 1;
  v[2][0] = 3;
  v[4][1] = 228;

  cop = v;

  v[4][1] = 1337;

  EXPECT_EQ(228, cop[4][1]);
}

TEST(TMatrix, can_get_size)
{
  TMatrix<int> v(5);

  EXPECT_EQ(5, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> v(5);

  v[1][1] = 101;

  EXPECT_EQ(101, v[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  TMatrix<int> v(5);

  ASSERT_ANY_THROW(v[-1][0] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int> v(5);

  ASSERT_ANY_THROW(v[100500][1337] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
  TMatrix<int> v(5);

  ASSERT_NO_THROW(v=v);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  TMatrix<int> v(3), w(3);
  v[0][0] = 1;
  v[1][0] = 15;
  v[2][1] = 666;

  w = v;

  EXPECT_EQ(1,w[0][0]);
  EXPECT_EQ(15, w[1][0]);
  EXPECT_EQ(666, w[2][1]);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  TMatrix<int> v(3), w(50);

  v = w;

  EXPECT_EQ(50, v.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  TMatrix<int> v(11), w(3);
  v[0][0] = 1;
  v[1][0] = 15;
  v[10][10] = 666;

  w = v;

  EXPECT_EQ(1,w[0][0]);
  EXPECT_EQ(15, w[1][0]);
  EXPECT_EQ(666, w[10][10]);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix<int> v(3), w(3);
  
  v[0][0] = 1;
  v[1][1] = 15;
  v[2][2] = 666;

  w[0][0] = 1;
  w[1][1] = 15;
  w[2][2] = 666;

  EXPECT_EQ(true ,w==v);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix<int> v(11);
  
  v[0][0] = 1;
  v[1][1] = 15;
  v[10][10] = 666;

  EXPECT_EQ(true ,v==v);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> v(11), w(3);

  EXPECT_EQ(false ,w==v);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  TMatrix<int> v(2), w(2), res(2);

  v[0][0] = 3;
  v[1][1] = 6;

  w[0][0] = 1;
  w[1][1] = 2;

  res[0][0] = 4;
  res[1][1] = 8;

  EXPECT_EQ(res ,v+w);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> v(2), w(3);

  ASSERT_ANY_THROW(v+w);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  TMatrix<int> v(2), w(2), res(2);

  v[0][0] = 3;
  v[1][1] = 6;

  w[0][0] = 1;
  w[1][1] = 2;

  res[0][0] = 2;
  res[1][1] = 4;

  EXPECT_EQ(res ,v-w);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> v(2), w(3);

  ASSERT_ANY_THROW(v-w);
}

