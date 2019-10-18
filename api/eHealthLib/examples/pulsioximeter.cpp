//Include ArduPi library
#include "eHealth.h"

int cont = 0;

void readPulsioximeter();

void setup() { 

	eHealth.initPulsioximeter();
	//Attach the inttruptions for using the pulsioximeter.
	attachInterrupt(6, readPulsioximeter, RISING);
    
}

void loop() { 

  printf("PRbpm : %d",eHealth.getBPM()); 

  printf("    %%SPo2 : %d\n", eHealth.getOxygenSaturation());

  printf("=============================");
  
  digitalWrite(2,HIGH);
  
  delay(500);
  
}

void readPulsioximeter(){  

  cont ++;
  if (cont == 500) { //Get only of one 50 measures to reduce the latency
    eHealth.readPulsioximeter();  
    cont = 0;
  }
}

int main (){
	setup();
	while(1){
		loop();
	}
	return (0);
}
