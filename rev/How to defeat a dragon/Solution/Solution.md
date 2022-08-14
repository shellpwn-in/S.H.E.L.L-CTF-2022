# How to defeat the dragon .

*challenge description:Dragonairre,the dragon with the hexadecimal head has attacked the village to take revenge on his last defeat,we need to get the ultimate weapon*

It was a beginner level Reversing challenge in which when you execute the binary file ,it will ask for a code .if the code is correct it will give you the flag,else it will give you a error.

```
$ ./vault 
Help us defeat the dragon!! Enter the code:4265
wron..aaaaaahhhhhhhh
```
So to solve this,u can use a any reverse engineering tool,like for example ghidra to decompile the binary file.if you check the main function in ghidra you will see something like this .
```
undefined8 main(void)

{
  long in_FS_OFFSET;
  int local_7c;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_78 = 0x4654434c4c454853;
  local_70 = 0x343534383433357b;
  local_68 = 0x3434353334633463;
  local_60 = 0x3535333133623736;
  local_58 = 0x3336373333323566;
  local_50 = 0x3631333533323733;
  local_48 = 0x3333336635373665;
  local_40 = 0x3766333937333734;
  local_38 = 0x7d64;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  printf("Help us defeat the dragon!! Enter the code:");
  __isoc99_scanf(&DAT_00102034,&local_7c);
  if (local_7c == 0x10f2c) { //0x10f2c == 69420
    printf("Yeahh!!,we did it,We defeated the dragon.Thanks for your help here\'s your reward : %s",
           &local_78);
  }
  else if (local_7c == 0x45) {
    printf("Nice,but this is not the code :(.");
  }
  else if (local_7c == 0x1a4) {
    printf("Bruh!! Seriously?");
  }
  else {
    printf("wron..aaaaaahhhhhhhh");
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}
```

once you get the code,you can use it to get the flag.
```
$ ./vault 
Help us defeat the dragon!! Enter the code:69420
Yeahh!!,we did it,We defeated the dragon.Thanks for your help here's your reward : SHELLCTF{5348454c4c4354467b31355f523376337235316e675f333473793f7d}
```
Here we entered the code and got the flag but there's a catch,this flag is fake.if you read the description of the challenge there's mention of a term called hexadecimal,so we need to dehex the thing which is under the curly brackets.
we can either use some online tools or python to dehex this,i will be using ![python](https://github.com/S-H-E-L-L/S.H.E.L.L-CTF-2022/blob/main/rev/How%20to%20defeat%20a%20dragon/Solution/dehex.py).

so the final flag that we got is : `SHELLCTF{15_R3v3r51ng_34sy?}`
