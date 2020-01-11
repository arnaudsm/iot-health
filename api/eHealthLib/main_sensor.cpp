#include <iostream>
#include <unistd.h>

#include "eHealth.h"

using namespace std;

int main(int argc, char* argv[]) {
    eHealthClass eHealth();
    eHealth->initPulsioximeter();

    while(true) {
        int oxy = eHealth->getOxygenSaturation();
        int bpm = eHealth->getBPM();
        cout << "Oxy: " << oxy << endl;
        cout << "BPM: " << bpm << endl;
        sleep(2000);
    }
}
