#include <shogun/lib/SGMatrix.h>
#include <shogun/mathematics/Math.h>
#include <gtest/gtest.h>

using namespace shogun;

TEST(SGMatrixTest,ctor_zero_const)
{
	SGMatrix<float64_t> a(10, 5);
	EXPECT_EQ(a.num_rows, 10);
	EXPECT_EQ(a.num_cols, 5);

	a.zero();
	for (int i=0; i < 10; ++i)
	{
		for (int j=0; j < 5; ++j)
		EXPECT_EQ(0, a(i,j));
	}

	a.set_const(3.3);
	for (int i=0; i < 10; ++i)
	{
		for (int j=0; j < 5; ++j)
		EXPECT_EQ(3.3, a(i,j));
	}
}

TEST(SGMatrixTest,setget)
{
	SGMatrix<index_t> v(3,2);
	v(0,0)=1;
	v(0,1)=2;
	v(1,0)=3;
	v(1,1)=4;
	v(2,0)=5;
	v(2,1)=6;

	EXPECT_EQ(v(0,0), 1);
	EXPECT_EQ(v(0,1), 2);
	EXPECT_EQ(v(1,0), 3);
	EXPECT_EQ(v(1,1), 4);
	EXPECT_EQ(v(2,0), 5);
	EXPECT_EQ(v(2,1), 6);
}

TEST(SGMatrixTest,equals_equal)
{
	SGMatrix<float64_t> a(3,2);
	SGMatrix<float64_t> b(3,2);
	a(0,0)=1;
	a(0,1)=2;
	a(1,0)=3;
	a(1,1)=4;
	a(2,0)=5;
	a(2,1)=6;
	
	b(0,0)=1;
	b(0,1)=2;
	b(1,0)=3;
	b(1,1)=4;
	b(2,0)=5;
	b(2,1)=6;
	
	EXPECT_TRUE(a.equals(b));
}

TEST(SGMatrixTest,equals_different)
{
	SGMatrix<float64_t> a(3,2);
	SGMatrix<float64_t> b(3,2);
	a(0,0)=1;
	a(0,1)=2;
	a(1,0)=3;
	a(1,1)=4;
	a(2,0)=5;
	a(2,1)=6;
	
	b(0,0)=1;
	b(0,1)=2;
	b(1,0)=3;
	b(1,1)=4;
	b(2,0)=5;
	b(2,1)=7;
	
	EXPECT_FALSE(a.equals(b));
}

TEST(SGMatrixTest,equals_different_size)
{
	SGMatrix<float64_t> a(3,2);
	SGMatrix<float64_t> b(2,2);
	a.zero();
	b.zero();
	
	EXPECT_FALSE(a.equals(b));
}
