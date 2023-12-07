#include <gtest/gtest.h>
#include "fff.h"
DEFINE_FFF_GLOBALS;

extern "C" {
    #include "sensorFetchAndSend.c"
}

FAKE_VOID_FUNC(addData,char *, int);
FAKE_VOID_FUNC(pushData);
FAKE_VALUE_FUNC(unsigned int, supersensor_get);


// GAMLA FAKES
// unsigned int supersensor_get(){ 
//     return 12;
// }
// int antal;
// void addData(char* name, int data){
//     antal++;
// }
// void pushData(void){

// }



class FetchAndSendTest : public testing::Test {
protected:
	void SetUp() override {
		//game_initialize();	/* Without this the Tests could break*/
	}
};


void setup()
{
    // Register resets
    RESET_FAKE(addData);
    RESET_FAKE(pushData);
    RESET_FAKE(supersensor_get);
}

TEST_F(FetchAndSendTest,addDataShouldBeCalledTwice){
    // ARRANGE
    setup();
    // ACT
    fetchAndSend(); 

    // ASSERT
    ASSERT_EQ(addData_fake.call_count,2);

}

TEST_F(FetchAndSendTest,pushDataShouldBeCalledOnce){
    // ARRANGE
    setup();

    // ACT
    fetchAndSend(); 

    // ASSERT
    ASSERT_EQ(pushData_fake.call_count,1);

}

TEST_F(FetchAndSendTest,addDataShouldSendCorrectData){
    // ARRANGE - control the world
    setup();
    supersensor_get_fake.return_val = 99;

    // ACT
    fetchAndSend(); 

    // ASSERT -  argumenten till addData var "field1", 
    ASSERT_EQ(addData_fake.arg0_val, "field2");
    ASSERT_EQ(addData_fake.arg1_val, 99);

}




// TEST_F(FetchAndSendTest,addDataShouldBeCalledTwice){
//     // ARRANGE
//     antal = 0;
//     // ACT
//     fetchAndSend(); 

//     // ASSERT
//     ASSERT_EQ(antal,2);

// }
