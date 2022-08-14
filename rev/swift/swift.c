#include <stdio.h>

// shellctf{T4yl0r5_s3r1e5_oF_4_fUnC7i0n}
double func(int x)
{
    double sum = 1, oldsum = 0, term = 1;

    int i = 1;
    while(sum != oldsum)
    {
        oldsum = sum;
        term *= (double)x / i;
        sum += term;
        
        i++;
    }
    return sum;
}

void encrypt(char key[13]) // EULERSNUMBER
{
    double vals[12];
    
    //int offset[12] = {-2, -1, 1, 2, -3, 0, 5, -1, -1, 1, 3, 5}
    char offset[12] = "GVKCUSIVNABM";
    for(int i = 0; i < 12; i++)
    {
        vals[i] = func(key[i] - offset[i]);
        printf("%f ", vals[i]);
    }
    printf("\n");
}

int main()
{
    char flag[39] = "wbppcugz{F4zp0i5_w3l1p5_sW_4_xHhO7j0r}";
    printf("%s\n%s\n%s\n", "alright here you go: ", flag, "wait, do you not want to know the key?");
    encrypt("EULERSNUMBER");
}
