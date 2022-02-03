#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char* string)
{
    int res = 0;
    char buffer[16];

    strcpy(buffer, string);

    return res;
}

int main() {

    char input[31];
    printf("Enter the magic string: ");
    scanf("%s", input);
    
    if(check(input))
    {
        FILE* fp = fopen("flag.txt", "r");
        char flag[31];
        fgets(flag, 31, fp);
        printf("%s\n", flag);
    }
    else
        printf("Access Denied.\n");
}
