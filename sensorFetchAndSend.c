#include "thesupersensor.h"
#include "ESP8266.h"

void fetchAndSend(){
    int data = supersensor_get();				// Get dummy data
    if(1 == 0)
        addData("field1",data);
    data = supersensor_get();				// Get dummy data
    addData("field2",data);
    pushData();							// Push data to Firebase
}