#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	//open arduino device file (linux)
        std::ofstream arduino;
	arduino.open( "/dev/ttyUSB0");

	//write to it
        arduino << "A";
	arduino.close();

	return 0;
}