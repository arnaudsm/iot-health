#include "eHealth.h"

void setup(){
	eHealth.initPositionSensor();
}

void loop(){
	printf("Current position : \n");
	uint8_t position = eHealth.getBodyPosition(); 
	eHealth.printPosition(position);  

	printf("\n");
	delay(3000);
}

int main (){
	setup();
	while(1){
		loop();
	}
	return (0);
}
