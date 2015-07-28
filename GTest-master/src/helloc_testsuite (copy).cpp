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


/*printf("%s in %s:%d\n%s\n",
             test_part_result.failed() ? "*** Failure" : "Success",
             test_part_result.file_name(),
             test_part_result.line_number(),
             test_part_result.summary());*/

//class MinimalistPrinter : public ::testing::EmptyTestEventListener {
    // Called before a test starts.
  //  virtual void OnTestStart(const ::testing::TestInfo& test_info) {
      //printf("*** Test %s.%s starting.\n",
        //   test_info.test_case_name(), test_info.name());
    //}

    // Called after a failed assertion or a SUCCEED() invocation.
    //virtual void OnTestPartResult(
      //  const ::testing::TestPartResult& test_part_result) {
      //printf("%s in %s:%d\n%s\n",
        //     test_part_result.failed() ? "*** Failure" : "Success",
          //   test_part_result.file_name(),
            // test_part_result.line_number(),
             //test_part_result.summary());
    //}

    // Called after a test ends.
    //virtual void OnTestEnd(const ::testing::TestInfo& test_info) {
      //printf("*** Test %s.%s ending.\n",
        //     test_info.test_case_name(), test_info.name());
    //}
  //};



int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  
    testing::InitGoogleTest(&argc, argv);

// Gets hold of the event listener list.
  //::testing::TestEventListeners& listeners =
    //  ::testing::UnitTest::GetInstance()->listeners();
  // Adds a listener to the end.  Google Test takes the ownership.
  //listeners.Append(new MinimalistPrinter);


  int ret_val = RUN_ALL_TESTS();
  //UnitTest& unit_test = *UnitTest::GetInstance();

	//for (int i = 0; i < unit_test.total_test_case_count(); ++i) 
	//{
	  //  const TestCase& test_case = *unit_test.GetTestCase(i);
	    //for (int j = 0; j < test_case.total_test_count(); ++j) 
		//{
		  //   const TestInfo& test_info = *test_case.GetTestInfo(j);
		    // const TestResult& test_result = *test_info.result();
		     //printf("Test Name:  %s Test Case Name: %s.\n", test_info.name(), test_info.test_case_name());
		     //printf("Test Result:  %s Elapsed Time: %s.\n",test_result.Failed() ? "Failure" : "Success",test_result.elapsed_time());
			//if(test_result.Failed())
			//{
			//	const TestPartResult& testP_result = test_result.GetTestPartResult(0);
			//	printf("%s in %s:%d\n%s\n",
			//		     testP_result.failed() ? "*** Failure" : "Success",
			//		     testP_result.file_name(),
			//		     testP_result.line_number(),
			//		     testP_result.summary());
			//}
		//}
	
	//}
return ret_val;
}


// Hide main
#define TESTING
// Hide the io function since this will segfault in testing
int fake_register;
int myapp_do_dangerous_io()
{
	return fake_register;
}
#include "myapp.c"



class MyAppTestSuite : public testing::Test
{
	void SetUp(){
		memset(&my_filter, 0, sizeof(my_filter));
		readIdx = 0;
		writeIdx = 0;
	}

	void TearDown(){}
};

TEST(Hi, SampleTest) {
	
    EXPECT_EQ(0, 10);
}

TEST_F(MyAppTestSuite, myapp_task_should_return_correct_delay_for_one_element) {
	fake_register = 10;
    EXPECT_EQ(0, myapp_task());
}

TEST_F(MyAppTestSuite, myapp_task_should_return_correct_delay_for_two_elements) {
	fake_register = 10;
	myapp_task();
	fake_register = 20;
    EXPECT_EQ(15, myapp_task());
}

TEST_F(MyAppTestSuite, get_average_should_return_zero_on_empty_filter) {
	ASSERT_EQ(10, myapp_get_average());
}

TEST_F(MyAppTestSuite, addFirstFilterValAddsVal) {
	filter_add(42);
	ASSERT_EQ(42, my_filter[readIdx]);
}

TEST_F(MyAppTestSuite, addFirstReturnsCorrectAverage) {
	filter_add(42);
	ASSERT_EQ(42, myapp_get_average());
}


TEST_F(MyAppTestSuite, addTwoValuesReturnsCorrectAverage) {
	filter_add(42);
	filter_add(40);
	ASSERT_EQ(41, myapp_get_average());
}

TEST_F(MyAppTestSuite, get_average_should_return_average_of_full_filter) {
	for(int i = 0; i < MAX_ITEMS; i++){
		filter_add(i);
	}
	ASSERT_EQ((0+1+2+3+4+5+6)/MAX_ITEMS, myapp_get_average());
}

TEST_F(MyAppTestSuite, get_average_should_return_average_of_wrapped_filter) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add(i);
	}
	ASSERT_EQ((1+2+3+4+5+6+7)/MAX_ITEMS, myapp_get_average());
}

/// ....test buffer operations...


TEST_F(MyAppTestSuite, addFirstFilterValIncsWriteIdx) {
	filter_add(42);
	ASSERT_EQ(writeIdx, 1);
	ASSERT_EQ(1,filter_len());
}

TEST_F(MyAppTestSuite, addFilterValWrapsWriteIdx) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add(i);
	}
	ASSERT_EQ(0, writeIdx);
}

TEST_F(MyAppTestSuite, addFilterValUpdatesReadIndex) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add(i);
	}
	ASSERT_EQ(readIdx, 1);
	ASSERT_EQ(MAX_ITEMS, filter_len());
}

TEST_F(MyAppTestSuite, addFilterValWrapsReadIndex) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add(i);
	}
	for(int i = 0; i < BUFFER_SIZE-1; i++){
		filter_add(i);
	}
	ASSERT_EQ(readIdx, 0);
	ASSERT_EQ(MAX_ITEMS, filter_len());
}

TEST_F(MyAppTestSuite, addFilterValGivesCorrectLen) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		filter_add(i);
	}
	ASSERT_EQ(readIdx, 1);
	ASSERT_EQ(MAX_ITEMS, filter_len());
}
