#include <stdio.h>
#include <string.h>

// shellctf{s0Me_b4S3_c0nVer51on5_4_U}
int main()
{
    char flag[38];
    scanf("%s", flag);

    char binary[300];
    int binlen = 0;
    
    for (int i = 0; i < strlen(flag); i++)
    {
        int n = flag[i];
        while (n > 0)    
        {    
            binary[binlen] = '0' + n % 2;    
            n = n / 2;
            binlen++;
        }

        while (binlen % 8 != 0)
        {
            binary[binlen] = '0';
            binlen++;
        }

    }
    binary[binlen] = '\0';

    int k = 2;

    char hex[300] = "";
    int hexlen = 0;
    for (int i = 0; i < binlen;)
    {
        char num[10] = "";
        int size = 0;
        for (int j = 0; j < k && (i + j) < binlen; j++)
        {
            num[j] = binary[i + j];
            size++;
        }

        if (size == 1)
        {
            if (strcmp(num, "0") == 0)
                hex[hexlen] = 'a';
            else if (strcmp(num, "1") == 0)
                hex[hexlen] = 'b';
            
        }
        else if (size == 2)
        {
            if (strcmp(num, "00") == 0)
                hex[hexlen] = 'c';
            else if (strcmp(num, "01") == 0)
                hex[hexlen] = 'd';
            else if (strcmp(num, "10") == 0)
                hex[hexlen] = 'e';
            else if (strcmp(num, "11") == 0)
                hex[hexlen] = 'f';
            
        }
        else if (size == 3)
        {
            if (strcmp(num, "000") == 0)
                hex[hexlen] = '1';
            else if (strcmp(num, "001") == 0)
                hex[hexlen] = '2';
            else if (strcmp(num, "010") == 0)
                hex[hexlen] = '3';
            else if (strcmp(num, "011") == 0)
                hex[hexlen] = '4';
            else if (strcmp(num, "100") == 0)
                hex[hexlen] = '5';
            else if (strcmp(num, "101") == 0)
                hex[hexlen] = '6';
            else if (strcmp(num, "110") == 0)
                hex[hexlen] = '7';
            else if (strcmp(num, "111") == 0)
                hex[hexlen] = '8';
            
        }
        else
        {
            hex[hexlen] = '9';
        }

        i += size;
        hexlen++;
        k = (k + 1) % 4;
    }

    int output[100];
    int outlen = 0;
    for (int i = 0; i < hexlen; i += 2)
    {
        int num = 0;

        if (hex[i + 1] >= '0' && hex[i + 1] <= '9')
            num += hex[i + 1] - '0';
        else
            num += hex[i + 1] - 'a';

        if (hex[i] >= '0' && hex[i] <= '9')
            num += (hex[i] - '0') * 16;
        else
            num += (hex[i] - 'a') * 16;
        output[outlen] = num;
        outlen++;
    }

    
        int check[] = {82, 145, 65, 145, 54, 144, 68, 144, 39, 145, 66, 145, 54, 145, 36, 144, 38, 145, 68, 144, 54, 145, 56, 144, 82, 145, 65, 144, 82, 144, 82, 144, 69, 145, 72, 145, 69, 145, 36, 144, 38, 145, 39, 144, 70, 145, 39, 144, 88, 144, 71, 144, 53, 144, 39, 144, 55, 145, 68, 144, 70, 144, 68, 144, 50, 145, 70, 144, 82, 144, 39, 144, 87, 145, 68, 145, 54, 144, 71, 144, 88, 144, 66, 144, 82, 145, 86, 144, 70, 144, 70, 145, 84};

        int checkNum = 0;
    for (int i = 0; i < 93; i++)
        if (check[i] == output[i])
            checkNum++;

    if (checkNum == 93)
        printf("you're good at this!\n");
    else
        printf("nope, that's not it.\n");
    
}
