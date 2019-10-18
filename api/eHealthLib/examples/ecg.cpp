//Include ArduPi library
#include "eHealth.h"

// The loop routine runs over and over again forever:
void loop() {

  float ECG = eHealth.getECG();

  printf("ECG value :  %f V\n",ECG);
  delay(1000);
}

int main (){
	//setup();
	while(1){
		loop();
	}
	return (0);
}
