#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *getString()
{
int size = 25;
char *str = (char *)malloc(sizeof(char)*size); 
*(str+0) = 'S';
*(str+1) = 'H';
*(str+2) = 'E';
*(str+3) = 'L';
*(str+4) = 'L';
*(str+5) = 'C';
*(str+6) = 'T';
*(str+7) = 'F';
*(str+8) = '{';
*(str+9) = 'k';
*(str+10) = '3';
*(str+11) = 'y';
*(str+12) = 'g';
*(str+13) = 'e';
*(str+14) = 'n';
*(str+15) = '_';
*(str+16) = '1';
*(str+17) = 's';
*(str+18) = '_';
*(str+19) = 'c';
*(str+20) = '0';
*(str+21) = 'o';
*(str+22) = 'L';
*(str+23) = '}';
*(str+24) = '\0';
    
return str;
}   

//SHELLCTF{k3ygen_1s_c0oL}

int main(int argc,char *argv[]){
	if(argc==2){
		printf("Checking license: %s\n",argv[1]);
		int sum=0;
		for(int i=0;i<=strlen(argv[1]);i++){
			sum += argv[1][i];}
		if (sum==786){	
			printf("Access Granted!:%s",getString());}
			else {
				printf("Wrong!!!");}
			}


	else{
			printf("Usage: ./keygen <key>\n");
		}		

		return 0;	}