#include<stdio.h>
int main()
{   int code;
    char flag[][100] = {"SHELLCTF{5348454c4c4354467b31355f523376337235316e675f333473793f7d}"};
    printf("Help us defeat the dragon!! Enter the code:");
    scanf("%d",&code);

    if (code == 69420)
    {
        printf("Yeahh!!,we did it,We defeated the dragon.Thanks for your help here's your reward : %s",flag[0]);}
    else if (code == 69)    
    {
        printf("Nice,but this is not the code :(.");
    }
    else if (code == 420)
    {
        printf("Bruh!! Seriously?");
    }
    else {
        printf("wron..aaaaaahhhhhhhh");
    }
    
    return 0;
}
