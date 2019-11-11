#include <string.h>

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

char*
launchShell()
{

	return "";
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