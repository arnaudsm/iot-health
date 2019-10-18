//Include eHealth library
#include "eHealth.h"

void setup() { 

  eHealth.readGlucometer();
  delay(100);    
}

void loop() { 

  uint8_t numberOfData = eHealth.getGlucometerLength();   
  printf("Number of measures : %d",numberOfData);       
  delay(100);


  for (int i = 0; i< numberOfData; i++) { 
    // The protocol sends data in this order 
    printf("\n==========================================\n");

    printf("Measure number %d\n",i+1);

    printf("Date -> %d",eHealth.glucoseDataVector[i].day); 
    printf(" of "); 
    printf("%s",eHealth.numberToMonth(eHealth.glucoseDataVector[i].month));
    printf(" of ");
    printf("%d",2000 + eHealth.glucoseDataVector[i].year);    
    printf(" at ");

    if (eHealth.glucoseDataVector[i].hour < 10) {
      printf("0"); // Only for best representation.
    }

    printf("%d",eHealth.glucoseDataVector[i].hour);
    printf(":");

    if (eHealth.glucoseDataVector[i].minutes < 10) {
      printf("0");// Only for best representation.
    }
    printf("%d",eHealth.glucoseDataVector[i].minutes);

    if (eHealth.glucoseDataVector[i].meridian == 0xBB)
      printf(" pm");
    else if (eHealth.glucoseDataVector[i].meridian == 0xAA)
      printf(" am"); 

    printf("\nGlucose value : %d mg/dL",eHealth.glucoseDataVector[i].glucose); 
  }
  delay(20000);
}

int main (){
	setup();
	while(1){
		loop();
	}
	return (0);
}
