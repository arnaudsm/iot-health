#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
	cout << "{\"sensor_id\":" + std::to_string(1) + ", \"value\":" + std::to_string(3) + "}";
}
