#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main (void){
    string s = get_string();
    printf("%c",toupper(s[0]));
    for(int i=0, n=strlen(s);i<n;i++){
        if ((int)s[i]==32){     // space is 32 in ASCII
        printf("%c",toupper(s[i+1]));
        }
    }
    printf("\n");
}
