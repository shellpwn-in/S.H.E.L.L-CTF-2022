#include <stdio.h>
#include <string.h>

int main()
{
    char flag[] = "shellctf{s0Me_b4S3_c0nVer51on5_4_U}";

    char binary[400];
    int index = 0;
    
    for (int i = 0; i < strlen(flag); i++)
    {
        int n = flag[i];
        while (n > 0)    
        {    
            binary[index] = '0' + n % 2;    
            n = n / 2;
            index++;
        }    
    }
    binary[index] = '\0';
    printf("%d\n", index);
    for (int i = 0; i < index; i++)
    {
        printf("%d ", binary[i]);
    }
    printf("\n%d\n", strlen(binary));

    int k = 2;

    char hex[400] = "";
    int hexlen = 0;
    for (int i = 0; i < index;)
    {
        char num[10] = "";
        int size = 0;
        for (int j = 0; j < k && (i + j) < index; j++)
        {
            num[j] = binary[i + j];
            //num[j + 1] = '\0';
            //printf("%c", num[j]);
            size++;
        }

        //num[size] = '\0';
        //printf("%s\n", num);
        //if (strcmp(num, "0") == 0)
        //    printf("SOMETHING WORKS\n");
        //for (int z = 0; z < size; z++)
        //    printf("%c", num[z]);
        //printf("\n");
        
        if (size == 1)
        {
            //printf("here0\n");
            if (strcmp(num, "0") == 0)
                hex[hexlen] = 'a';
            else if (strcmp(num, "1") == 0)
                hex[hexlen] = 'b';
            i += 1;
        }
        else if (size == 2)
        {
            //printf("here1\n");
            if (strcmp(num, "00") == 0)
                hex[hexlen] = 'c';
            else if (strcmp(num, "01") == 0)
                hex[hexlen] = 'd';
            else if (strcmp(num, "10") == 0)
                hex[hexlen] = 'e';
            else if (strcmp(num, "11") == 0)
                hex[hexlen] = 'f';
            i += 2;
        }
        else if (size == 3)
        {
            //printf("here2\n");
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
            i += 3;
        }
        else
        {
            //printf("here3\n");
            hex[hexlen] = '9';
        }

        //printf("%s\n", hex);
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
        printf("%d ", num);
    }
    printf("\n");
    
}
