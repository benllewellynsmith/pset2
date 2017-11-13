#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){
    int k=0;
    if (argc==2){
        k=atoi(argv[1]);
        printf("kshift: %i\n",k);
        //return 0;
    }else{
        printf("error - no kshift provided\n");
        return 1;
    }

    printf("plaintext: ");
    string s = get_string();
    printf("ciphertext: ");
    for(int i=0,len=strlen(s);i<len;i++){
        if (s[i]>='a' && s[i]<='z'){
            char ct = ((s[i]-96+k)%26)+96;
            printf("%c",ct);
        }else if (s[i]>='A' && s[i]<='Z'){
            char ct = ((s[i]-65+k)%26)+65;
            printf("%c",ct);
        }else{
        printf("%c",s[i]);
        }
    }
    printf("\n");
}
