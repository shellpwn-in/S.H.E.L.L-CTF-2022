# Solution
    
Using IDA, the decompiler output is:
```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v4; // [rsp+8h] [rbp-A8h]
  int i; // [rsp+Ch] [rbp-A4h]
  int v6[28]; // [rsp+10h] [rbp-A0h]
  char s[40]; // [rsp+80h] [rbp-30h] BYREF
  unsigned __int64 v8; // [rsp+A8h] [rbp-8h]

  v8 = __readfsqword(0x28u);
  printf("enter the flag: ");
  __isoc99_scanf("%s", s);
  if ( strlen(s) == 27 )
  {
    v6[0] = 460;
    v6[1] = 416;
    v6[2] = 404;
    v6[3] = 432;
    v6[4] = 432;
    v6[5] = 396;
    v6[6] = 464;
    v6[7] = 408;
    v6[8] = 492;
    v6[9] = 392;
    v6[10] = 196;
    v6[11] = 464;
    v6[12] = 348;
    v6[13] = 420;
    v6[14] = 212;
    v6[15] = 404;
    v6[16] = 380;
    v6[17] = 192;
    v6[18] = 448;
    v6[19] = 204;
    v6[20] = 456;
    v6[21] = 260;
    v6[22] = 464;
    v6[23] = 192;
    v6[24] = 456;
    v6[25] = 332;
    v6[26] = 500;
    v4 = 1;
    for ( i = 0; i <= 26; ++i )
      v4 = (v6[i] >> 2 == s[i]) & (unsigned __int8)v4;
    if ( v4 == 1 )
      puts("yes, that's it");
    else
      puts("nah that's not it");
  }
  else
  {
    puts("wrong length");
  }
  return 0;
}
```
    
Here we can see that there's an array with some values. An input is taken from the user, the length is checked and some operations are performed. The bulk of the logic is in these lines: 
```c
v4 = 1;
for ( i = 0; i <= 26; ++i )
    v4 = (v6[i] >> 2 == s[i]) & (unsigned __int8)v4;
if ( v4 == 1 )
    puts("yes, that's it");
else
    puts("nah that's not it");
```
Here we have an integer v4 that's initialized to 1, and then the program iterates through the user input, right shifts the corresponding array element and compares it to the input, and the output of this comparison is ANDed with v4. If v4 remains 1, we have the right flag, else we don't. In other words, this loop checks if each value of the predefined array when right shifted by 2, is the same as that in the user input. It's simple to reverse it from here, we can right shift each of the values in the array and obtain the values of the flag in ascii. Convering them to char we will obtain the flag. A simple python script will do the job for us:

```python
s = [460, 416, 404, 432, 432, 396, 464, 408, 492, 392, 196, 464, 348, 420, 212, 404, 380, 192, 448, 204, 456, 260, 464, 192, 456, 332, 500]
for i in s:
    print(chr(i >> 2), end = '')
```
Output:
```bash
shellctf{b1tWi5e_0p3rAt0rS}
```
