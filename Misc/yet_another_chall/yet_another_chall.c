// shellctf{5h1ft_n_r3v_4ll_aT_0nCe}

#include <stdio.h>
#include <string.h>

int a(int n, int k)
{
    return n << (k % 3);
}

int b(int n, int k)
{
    return n + k;
}

int c(int n, int k)
{
    return n - k;
}

int d(int n, int k)
{
    return n * k;
}

int e(int n, int k)
{
    return n ^ k;
}

int f(int n, int k)
{
    return n >> (k % 3);
}

int check(int out[])
{
    
    int correct[33] = {230, 106, 98, 432, 105, 99, 232, 110, 114, 530, 99, 49, 204, 130, 80, 1760, 78, 114, 102, 138, 74, 1144, 123, 108, 190, 123, 57, 2660, 45, 110, 134, 133, 92};

    for (int i = 0; i < 33; i++)
        if (out[i] != correct[i])
            return 0;
    return 1;
}

int main()
{
    char s[34];
    printf("good job. now hand over the flag\n");
    scanf("%s", s);

    int out[33] = {0};

    int (*funcs[])(int, int) = {a, b, c, d, e, f};
    
    for (int i = 0; i < 33; i++)
    {
        out[i] = (*funcs[i % 6])(s[i], i+1);
    }

    
    int res = check(out);

    if (res == 1)
        printf("great, you got it\n");
    else
        printf("keep trying\n");
}
