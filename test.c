#include <stdio.h>
#include <cs50.h>
#include <string.h>

void checker(string,int);

int main(void){
    printf("hi\n");
    printf("woz ur name\n");
    string s = get_string();
    if (s != NULL){
        printf("ur intital is %c\n", s[0]);
        printf("all ur inits are\n");
        for(int i=0;i<strlen(s);i++){
            checker(s,i);
        }
    }
}

void checker(string s, int i){
    if ((int) s[i] >100){
                printf("%c is a lower\n",s[i]);
            }else{
                printf("%c is caps\n",s[i]);
            }
}
