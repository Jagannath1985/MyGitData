#include <stdio.h>
#include <unistd.h>

#define IOMEM_BASE 0x2FF
#define VALUE_REG  (IOMEM_BASE + 3)

// This must be a power of 2!
#define BUFFER_SIZE 8
#define MAX_ITEMS (BUFFER_SIZE-1)
static int my_filter1[BUFFER_SIZE];
static int readIdx = 0;
static int writeIdx = 0;


int filter_len1(){ return (BUFFER_SIZE + writeIdx - readIdx) % BUFFER_SIZE; }

void filter_add1(int val) {
	my_filter1[writeIdx] = val;
	writeIdx = (writeIdx+1) & (BUFFER_SIZE-1);
	if(writeIdx == readIdx) readIdx = (readIdx+1) & (BUFFER_SIZE-1);
}

#ifndef TESTING
int myapp_do_dangerous_io1()
{
	// lets dereference an io mapped register
	// - on the target it is at address IOMEM_BASE + 3
	return *((int *)VALUE_REG);
}
#endif

int myapp_get_average1(){
	int len = filter_len1();
	if(0 == len) return 0;
	int sum = 0;
	for(int i = 0; i < len; i++){
		sum += my_filter1[(i+readIdx)%BUFFER_SIZE];
	}
	return sum/len;
}

int myapp_task1()
{
	// get value from register
	int nextval = myapp_do_dangerous_io1();

	// add to filter line
	filter_add1(nextval);

	// return the average value as the next delay
	return myapp_get_average1();
}

int myapp_mainloop1()
{
	for(;;){
		int nextloopdelay = myapp_task1();
		sleep(nextloopdelay);
	}
return 0;
}

#ifndef TESTING
int main() {
	printf("!!!Hello World!!!\n");
	return myapp_mainloop1();
}
#endif
