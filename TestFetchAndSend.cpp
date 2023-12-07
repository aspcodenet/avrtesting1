#include <gtest/gtest.h>

extern "C" {
    #include "sensorFetchAndSend.c"
}

unsigned int supersensor_get(){ 
    return 12;
}
int antal;
void addData(char* name, int data){
    antal++;
}
void pushData(void){

}



class FetchAndSendTest : public testing::Test {
protected:
	void SetUp() override {
		//game_initialize();	/* Without this the Tests could break*/
	}
};

TEST_F(FetchAndSendTest,addDataShouldBeCalledTwice){
    // ARRANGE
    antal = 0;
    // ACT
    fetchAndSend(); 

    // ASSERT
    ASSERT_EQ(antal,2);

}
