#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define PASSWORD "1234567"
int verify(char *password)
{
    int auth;
    char buffer[8];
    auth = strcmp(password, PASSWORD);
    strcpy(buffer, password);
    return auth;
}

int main(void){
    int flag = 0;
    char pass[1024];
    while(1){
        printf("enter the password:\t");
        scanf("%s", pass);
        flag = verify(pass);
        if(flag)
            printf("password incorrect!\n");
        else{
            printf("congratulation!\n");
            break;
        }
    }
    system("pause"); 
}

