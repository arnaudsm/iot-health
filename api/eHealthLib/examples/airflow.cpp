//Include eHealth library
#include "eHealth.h"

extern SerialPi Serial;

void setup() { 
	 
}

void loop() { 
	int air = eHealth.getAirFlow();   
	eHealth.airFlowWave(air);  
	delay(50);
}

int main (){
	setup();
	while(1){
		loop();
	}
	return (0);
}
