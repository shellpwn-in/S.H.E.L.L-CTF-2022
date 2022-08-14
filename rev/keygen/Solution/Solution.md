# Keygen

*challenge description:Enter the license key and get the flag,simple right*

Here we had a executable file named keygen which we have to executed with a license key ,if the key is correct it will give us the flag.

```
$ ./keygen givemetheflag 
Checking license: givemetheflag
Wrong!!!
```
so if we a strings command to print the printable characters

```
/lib64/ld-linux-x86-64.so.2
libc.so.6
puts
printf
strlen
malloc
__cxa_finalize
__libc_start_main
GLIBC_2.2.5
_ITM_deregisterTMCloneTable
__gmon_start__
_ITM_registerTMCloneTable
u+UH
[]A\A]A^A_
Checking license: %s
Access Granted!:%s
Wrong!!!
Usage: ./keygen <key>
:*3$"
```
It gives us some function names but it doesn't help much.we tried to decompile it with ghidra and check the main function. 
```
undefined8 main(int param_1,long param_2)

{
  size_t sVar1;
  undefined8 uVar2;
  int local_20;
  int local_1c;
  
  if (param_1 == 2) {
    printf("Checking license: %s\n",*(undefined8 *)(param_2 + 8));
    local_20 = 0;
    local_1c = 0;
    while( true ) {
      sVar1 = strlen(*(char **)(param_2 + 8));
      if (sVar1 < (ulong)(long)local_1c) break;
      local_20 = local_20 + *(char *)((long)local_1c + *(long *)(param_2 + 8));
      local_1c = local_1c + 1;
    }
    if (local_20 == 0x312) {
      uVar2 = getString();
      printf("Access Granted!:%s",uVar2);
    }
    else {
      printf("Wrong!!!");
    }
  }
  else {
    puts("Usage: ./keygen <key>");
  }
  return 0;
}
```
So if i explain it directly,the binary will check if the sum of characters of the license is equal to `0x312==786 in hex`.If it's same then it will print the flag.so i wrote a ![Python]() Script to list all the license key whose character sum is 786.
```
$ python3 solution.py 
Found valid key: mPugVhmN
Found valid key: v0Rls6WjD
Found valid key: Yt1ifMSo6
Found valid key: fVDHmFB0l9
Found valid key: NMryXsLu
Found valid key: _7j3WjTee
Found valid key: hoiCIS-H6H
Found valid key: 16cDQD0alE-
Found valid key: LH0n8W-gOn
Found valid key: uEhqi6Cf7
Found valid key: 26tWCaNVNI
Found valid key: ezHOwoOg
Found valid key: 59mkcNr41D
Found valid key: rw3LVSrW8
Found valid key: tLAdKYHRo
Found valid key: APrjdW1Qh
Found valid key: zLMxV6YUM
Found valid key: 4qcuK0kHg
Found valid key: 8uVw3nW934
Found valid key: HUbq96wsI
Found valid key: 9b9dqAarU
Found valid key: 3w1TOvuWR
Found valid key: azYO5p-Cz
Found valid key: 5gzdrHS8S
Found valid key: 9GUvT6GTSO
Found valid key: qfLQjbkg
```
So now if i use any of this key i should be getting the flag.
```
$ ./keygen  v0Rls6WjD
Checking license: v0Rls6WjD
Access Granted!:SHELLCTF{k3ygen_1s_c0oL}

$ ./keygen  26tWCaNVNI
Checking license: 26tWCaNVNI
Access Granted!:SHELLCTF{k3ygen_1s_c0oL}

$ ./keygen  By-GMQoTJ8
Checking license: By-GMQoTJ8
Access Granted!:SHELLCTF{k3ygen_1s_c0oL}
```

So our flag is : `SHELLCTF{k3ygen_1s_c0oL}`


This was the intended solution for keygen,there are also another way to solve the challenge by opening the getstring function where the flag was stored.

