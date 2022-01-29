#include <stdio.h>
#include <string.h>

// shellctf{b1t_m4N1puL47i0n5_3verYwh3r3}

int main()
{
    char flag[39];

    printf("enter the flag: ");
    scanf("%s", flag);

    if(strlen(flag) != 38)
        printf("wrong length\n");
    else
    {
    
        int check[] = {460, 416, 404, 432, 432, 396, 464, 408, 492, 392, 196, 464, 380, 436, 208, 312, 196, 448, 468, 304, 208, 220, 420, 192, 440, 212, 380, 204, 472, 404, 456, 356, 476, 416, 204, 456, 204, 500};

        int res = 1;
        for(int i = 0; i < 38; i++)
            res &= !((check[i] >> 2) ^ flag[i]);

        if(res != 1)
            printf("nah that's not it\n");
        else
            printf("yes, that's it\n");
    }
}

