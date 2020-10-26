#include <stdio.h>
#include <string.h>
#include <termios.h>

char serialPortFilename[] = "/dev/ttyUSB0";

int main()
{
		//termios mode;
		//memset(&mode,0,sizeof( mode));
		//tcgetattr(m_fd,& mode);

    char readBuffer[1024];
    int numBytesRead;

    FILE *serPort = fopen(serialPortFilename, "r");

	if (serPort == NULL)
	{
		printf("USB ERROR");	
		return 0;
	}

	// printf(serialPortFilename);
	printf(":\n");
	while(1)
	{
		memset(readBuffer, 0, 1024);
		fread(readBuffer, sizeof(char),1024,serPort);
		if(sizeof(readBuffer) != 0)
		{
			printf(readBuffer);
		}
	}
	return 0;
}
