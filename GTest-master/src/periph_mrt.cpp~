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

extern int x;

int x = 5;


/*int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/



#define TESTING
// Hide the io function since this will segfault in testing
int fake_register;
int myapp_do_dangerous_io()
{
	return fake_register;
}
#include "myapp.c"



class LPC_MRT : public testing::Test
{
	void SetUp(){
		memset(&my_filter, 0, sizeof(my_filter));
		readIdx = 0;
		writeIdx = 0;
	}

	void TearDown(){}
};

TEST_F(LPC_MRT, MRT_Tim0_OnseShotMode_TimeInt_LD1) {
	fake_register = 10;
    EXPECT_EQ(0, myapp_task());
}

TEST_F(LPC_MRT, MRT_StopTim0_OnseShotMode_LD1) {
	fake_register = 10;
	myapp_task();
	fake_register = 20;
    EXPECT_EQ(15, myapp_task());
}


TEST_F(LPC_MRT, MRT_StopTim0_OnseShotMode_LD1123) {
	fake_register = 10;
	myapp_task();
	fake_register = 20;
    EXPECT_EQ(15, myapp_task());
}


/*TEST_F(LPC_MRT, get_average_should_return_zero_on_empty_filter) {
	ASSERT_EQ(10, myapp_get_average());
}

TEST_F(LPC_MRT, addFirstFilterValAddsVal) {
	filter_add(42);
	ASSERT_EQ(42, my_filter[readIdx]);
}

TEST_F(LPC_MRT, addFirstReturnsCorrectAverage) {
	filter_add(42);
	ASSERT_EQ(42, myapp_get_average());
}


TEST_F(LPC_MRT, addTwoValuesReturnsCorrectAverage) {
	filter_add(42);
	filter_add(40);
	ASSERT_EQ(41, myapp_get_average());
}

TEST_F(LPC_MRT, get_average_should_return_average_of_full_filter) {
	for(int i = 0; i < MAX_ITEMS; i++){
		filter_add(i);
	}
	ASSERT_EQ((0+1+2+3+4+5+6)/MAX_ITEMS, myapp_get_average());
}*/

TEST_F(LPC_MRT, MRT_StopTim0_RepeatMode_LD1) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add(i);
	}
	ASSERT_EQ((1+2+3+4+5+6+7)/MAX_ITEMS, myapp_get_average());
}

/// ....test buffer operations...


TEST_F(LPC_MRT, MRT_StopTim0_RepeatMode_LD0) {
	filter_add(42);
	ASSERT_EQ(writeIdx, 1);
	ASSERT_EQ(1,filter_len());
}

TEST_F(LPC_MRT, MRT_Tim0_RepeatMode_TimeInt_LD1) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add(i);
	}
	ASSERT_EQ(0, writeIdx);
}

TEST_F(LPC_MRT, MRT_Tim0_RepeatMode_TimeInt_LD0) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add(i);
	}
	ASSERT_EQ(readIdx, 1);
	ASSERT_EQ(MAX_ITEMS, filter_len());
}

TEST_F(LPC_MRT, MRT_Tim0_OneShotMode) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add(i);
	}
	for(int i = 0; i < BUFFER_SIZE-1; i++){
		filter_add(i);
	}
	ASSERT_EQ(readIdx, 0);
	ASSERT_EQ(MAX_ITEMS, filter_len());
}

TEST_F(LPC_MRT, MRT_Tim0_RepeatMode) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add(i);
	}
	ASSERT_EQ(readIdx, 1);
	ASSERT_EQ(MAX_ITEMS, filter_len());
}
