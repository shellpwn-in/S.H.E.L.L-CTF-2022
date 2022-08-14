#include <stdio.h>
#include <string.h>

// shellctf{T0_1nfiNi7y_4nD_B3y0nd}
char pwd[50] = "";

void boilWater()
{
    printf("Enter the flag: ");
    scanf("%s", pwd);
}
    
void addSugar()
{
    char odd[17] = "", even[17] = "";

    for(int i = 0; i < strlen(pwd); i++)
    {
        if (i % 2 == 0)
            strncat(even, &pwd[i], 1);
        else
            strncat(odd, &pwd[i], 1);
    }

    char* join = odd;
    strncat(join, even, 17);
    
    strcpy(pwd,join);
}

void addTea()
{
    char string[33] = "";
    for(int i = 0; i < strlen(pwd) / 2; i++)
    {
        char new = pwd[i] - 3 * (i / 2);
        strncat(string, &new, 1);
    }
    for(int i = strlen(pwd) / 2; i < strlen(pwd); i++)
    {
        char new = pwd[i] + (i / 6);
        strncat(string, &new, 1);
    }
    strcpy(pwd, string);
}

void addMilk()
{
    int i = 0;

    char a[33] = "", b[33] = "", c[33] = "";
    while (pwd[i] != '5' && i < strlen(pwd))
    {
        strncat(a, &pwd[i], 1);
        i += 1;
    }
    while (pwd[i] != 'R' && i < strlen(pwd))
    {
        strncat(b, &pwd[i], 1);
        i += 1;
    }
    while (i < strlen(pwd))
    {
        strncat(c, &pwd[i], 1);
        i += 1;
    }
    char* join = c;
    strncat(join, a, strlen(a));
    strncat(join, b, strlen(b));
    
    strcpy(pwd,join);

    
}

void strainAndServe()
{
    if (strcmp("R;crc75ihl`cNYe`]m%50gYhugow~34i", pwd) == 0)
        printf("yep, that's right\n");
    else
        printf("nope, that's not it\n");
}

int main()
{
    boilWater();
    if (strlen(pwd) == 32)
    {
        addSugar();
        addTea();
        addMilk();
        strainAndServe();
    }
   else
       printf("wrong length\n");
}
