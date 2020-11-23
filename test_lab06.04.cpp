#include "gtest/gtest.h"
#include "func.h"

using namespace std;

TEST(gTest, ReturnValue) {
    int parr [4] = {3,5,6,-6};
    ASSERT_EQ(3, number_of_min_element (parr,4));
    ASSERT_TRUE( 3 ==number_of_min_element (parr,4));
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}