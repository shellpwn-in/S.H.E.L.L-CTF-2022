# Solution
Upon executing the binary we get the following output:

```bash 
alright here you go: 
wbppcugz{F4zp0i5_w3l1p5_sW_4_xHhO7j0r}
wait, do you not want to know the key?
```

So we get the flag and it's encrypted with a key. We decompile the main function in IDA and obtain this:
```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
  char v4[40]; // [rsp+0h] [rbp-30h] BYREF
  unsigned __int64 v5; // [rsp+28h] [rbp-8h]

  v5 = __readfsqword(0x28u);
  strcpy(v4, "wbppcugz{F4zp0i5_w3l1p5_sW_4_xHhO7j0r}");
  printf("%s\n%s\n%s\n", "alright here you go: ", v4, "wait, do you not want to know the key?");
  return 0;
}
```
The key is not in main, but in another function. In the list of functions on the left we see a function called encrypt. On decompiling that we obtain this:
```c
unsigned __int64 __fastcall encrypt(__int64 a1)
{
  int i; // [rsp+1Ch] [rbp-84h]
  double v3[13]; // [rsp+20h] [rbp-80h]
  _BYTE v4[12]; // [rsp+8Ch] [rbp-14h] BYREF
  unsigned __int64 v5; // [rsp+98h] [rbp-8h]

  v5 = __readfsqword(0x28u);
  qmemcpy(v4, "GVKCUSIVNABM", sizeof(v4));
  for ( i = 0; i <= 11; ++i )
  {
    v3[i] = func((unsigned int)(*(char *)(i + a1) - (char)v4[i]));
    printf("%f ", v3[i]);
  }
  putchar(10);
  return __readfsqword(0x28u) ^ v5;
}
```
This function takes the key as parameter, then iterates across the key, subtracts the corresponding value in the string v4, passes it to func() and prints the output. Decompiling func, we obtain:
```c
double __fastcall func(int a1)
{
  int v2; // [rsp+8h] [rbp-1Ch]
  double v3; // [rsp+Ch] [rbp-18h]
  double v4; // [rsp+14h] [rbp-10h]
  double v5; // [rsp+1Ch] [rbp-8h]

  v3 = 1.0;
  v4 = 0.0;
  v5 = 1.0;
  v2 = 1;
  while ( v3 != v4 )
  {
    v4 = v3;
    v5 = (double)a1 / (double)v2 * v5;
    v3 = v3 + v5;
    ++v2;
  }
  return v3;
}
```
Mathematically put, this is 
1 + x + x^2/2! + x^3/3! + ...
which is the Taylor series function for
e^x
The name of the chall, swift, is a hint towards the use of Taylor series in the chall.
Now it's simple to decompile: calculate ln(x) for each value in output.txt, add it to v4. A short script will do it for us:
```python
out = [0.135335, 0.367879, 2.718282, 7.389056, 0.049787, 1.000000, 148.413159, 0.367879, 0.367879, 2.718282, 20.085537, 148.413159]
s = "GVKCUSIVNABM"
for i in range(len(out)):
    print(chr(round(math.log(out[i]) + ord(s[i]))))
```
Output of the script:
```bash
EULERSNUMBER
```
Now we have the enciphered flag and the key, which is a string. A string ciphered using a key which is also a string, is the Vigenere cipher. So we decipher it and obtain the flag.
```bash
shellctf{T4yl0r5_s3r1e5_oF_4_fUnC7i0n}
```
