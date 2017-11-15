#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool isValidCall(int argc);
bool isValidKey(string argument);
void enCipherText(string plain, string key);
char performShift(char plain, char shift, bool lower);

int main(int argc, string argv[]){
    if (!isValidCall(argc)) return 1;           //if program call supplied a key
    if (!isValidKey(argv[1])) return 1;         //if key supplied was letters only
    printf("plaintext: ");                      //prompt for plaintext
    string plain=get_string();                  //collect plaintext
    enCipherText(plain, argv[1]);               //display cipher text
}

bool isValidCall(int argc){
    if (argc!=2){
        printf("invalid program call\n");
        return false;
    }else{
        return true;
    }
}

bool isValidKey(string argument){
    bool invalid=false;
    for(int j=0, l=strlen(argument);j<l;j++){
        if (isalpha(argument[j])==0){
             invalid=true;
        }
    }
    if (invalid){
        printf("argument contains NONalpha  - BAD!\n");
        return false;
    }else{
        //printf("alpha argument provided - GOOD\n");
        return true;
    }
}


void enCipherText(string plain, string key){
    printf("ciphertext: ");

    char shift;
    int kind=0;
    int klen=strlen(key);

    for(int i=0, len=strlen(plain);i<len;i++) {

        if (isalpha(plain[i])==0){
            printf("%c", plain[i]);
        }else{
            shift=key[kind];
            kind++;
            if (kind==klen) kind=0;

            char cipher = performShift(plain[i],shift,islower(plain[i]));
            printf("%c", cipher);
        }
    }
    printf("\n");
}

char performShift(char plain, char shift, bool lower){
    int x,y,z;
    if (islower(shift)) {
        y=shift-97;
    }else{
        y=shift-65;
    }
    if (lower){
        x=plain-97;
        z=(x+y)%26;
        return z+97;
    }else{
        x=plain-65;
        z=(x+y)%26;
        return z+65;
    }
}
