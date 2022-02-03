#include <stdio.h>

// shellctf{T4yl0r5_s3r1e5_oF_4_fUnC7i0n}
double func(int x) 
{
    double sum = 0, term = ((double)x - 1) / (x + 1), step = term * term, oldSum = 1;

    int i = 0;
    while(oldSum != sum)
    {
        oldSum = sum;
        sum += term / (2 * i + 1);
        term *= step;
        i++;
    }
    
    return 2 * sum;
}

void encrypt(char key[17]) // NATURALLOGARITHM
{
    double vals[16];
    
    for(int i = 0; i < 16; i++)
    {
        vals[i] = func(key[i]);
        printf("%f ", vals[i]);
    }
    printf("\n");
}

int main()
{
    char flag[39] = "fhxfcceq{H4el0i5_a3k1l5_aS_4_fNhT7i0y}";
    printf("%s\n%s\n%s\n", "alright here you go: ", flag, "wait, do you not want to know the key?");
}
