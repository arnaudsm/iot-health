//Include eHealth library
#include "eHealth.h"

void loop() { 
	float temperature = eHealth.getTemperature();   
	printf("Temperature : %f \n", temperature);
	delay(2000);
}

int main (){
	//setup();
	while(1){
		loop();
	}
	return (0);
}
