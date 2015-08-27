#include <gtest/gtest.h>
#include <stdio.h>

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::Test;
using ::testing::TestCase;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::UnitTest;
using ::testing::TestResult;
using ::testing::TestPartResult;






/*int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();



}*/
#define TESTING
// Hide the io function since this will segfault in testing
int fake_register1;
int myapp_do_dangerous_io1()
{
	return fake_register1;
}
#include "myapp1.c"



class LPC_CRC : public testing::Test
{
	void SetUp(){
		memset(&my_filter1, 0, sizeof(my_filter1));
		readIdx = 0;
		writeIdx = 0;
	}

	void TearDown(){}
};


TEST_F(LPC_CRC, CRC_1_16Bit_CCITTPoly333) {
	fake_register1 = 10;
    EXPECT_EQ(0, myapp_task1());
}

TEST_F(LPC_CRC, CRC_5_8Bit_CCITTPoly) {
	fake_register1 = 10;
	myapp_task1();
	fake_register1 = 20;
    EXPECT_EQ(15, myapp_task1());
}

TEST_F(LPC_CRC, CRC_8_32Bit_CCITTPoly) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add1(i);
	}
	ASSERT_EQ((1+2+3+4+5+6+7)/MAX_ITEMS, myapp_get_average1());
}

<<<<<<< HEAD
TEST_F(LPC_CRC, CRC_8_32Bit_CCITTPoly1111) {
=======

TEST_F(LPC_CRC, CRC_8_32Bit_CCITTPoly123gggg) {
>>>>>>> 0fb1c094e24c77401a7249d8e781150a3ccab246
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add1(i);
	}
	ASSERT_EQ((1+2+3+4+5+6+7)/MAX_ITEMS, myapp_get_average1());
}

<<<<<<< HEAD

=======
>>>>>>> 0fb1c094e24c77401a7249d8e781150a3ccab246
/// ....test buffer operations...


TEST_F(LPC_CRC, CRC_32_16Bit_CCITTPoly) {
	filter_add1(42);
	ASSERT_EQ(writeIdx, 1);
	ASSERT_EQ(1,filter_len1());
}

TEST_F(LPC_CRC, CRC_1_8Bit_CRC16Poly) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add1(i);
	}
	ASSERT_EQ(0, writeIdx);
}

TEST_F(LPC_CRC, CRC_5_16Bit_CRC16Poly) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add1(i);
	}
	ASSERT_EQ(readIdx, 1);
	ASSERT_EQ(MAX_ITEMS, filter_len1());
}

TEST_F(LPC_CRC, CRC_8_32Bit_CRC16Poly) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add1(i);
	}
	for(int i = 0; i < BUFFER_SIZE-1; i++){
		filter_add1(i);
	}
	ASSERT_EQ(readIdx, 0);
	ASSERT_EQ(MAX_ITEMS, filter_len1());
}

