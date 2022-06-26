#include <stdio.h>
#include <string.h>
#include<stdbool.h>  

int change(char * c, int position, int i){
    // upcase characters
    if((c[i] <= (position+25)) && (c[i] >= position)){
        c[i] += 32;
    }
    // lowercase characters
    if((c[i] <= (position+63)) && (c[i] >= (position+32))){
        c[i] -= 32;
    }
    // if(position > 122){
    //     if((c[i] <= (position+63)) && (c[i] >= (position+32))){
    //         c -= 32;
    //     } 
    //     return 0;       
    // }
    return 0;
}

void sarcasm(char * str){
    bool sw = false;
    for(int i = 0; i <= strlen(str); i++){
            // skipping space
            if((str[i] == ' ') || (str[i] < 65) || ((str[i] > 122) && (str[i] < 192)) || ((str[i] > 90) && (str[i] < 97))) {
                continue;
            }
            // change bool var each time it circulates in loop e.g. 1 -> 0, 0 -> 1, 1 -> 0
            // this changes the character
            if(sw == true){
                // for english
                // start from decimal position of 65 in ascii table
                change(str, 65, i);
                // for russian
                // start from decimal position of 97 in ascii table
                change(str, 97, i);
                sw = false;
                continue;
            }
            // this if does nothing
            if(sw == false){
                sw = true;
                continue;
            }    
        }
}

void input(char * str){
    printf("Your text here: \n");
        // scanning input until first Enter
        scanf("%[^\n]s", str);
}

void print(char * str){
    // printing out text
        for(int i = 0; i <= strlen(str); i++){
            printf("%c", str[i]);
        }
        printf("\n");
}

int main(){
    char str[500];
    char r = 0;
        //printf("%c\n", r+43);
        input(str);
        //printf("%c\n", (str[1]+32));
        sarcasm(str);
        print(str);

        return 0;
}