#include "Stack.h"
#include <string.h>
#include <stdio.h>

int main(void){
    Stack* s = create();
    char str[MAX];
    printf("Digite uma palavra:\n");
    if(fgets(str, MAX, stdin) == NULL){
        return 1;
    }

    str[strcspn(str, "\n")] = '\0';

    for(int i = 0; str[i] != '\0'; i++){
        push(s, str[i]);
    }

    if(verificar_palindromo(s)){
        printf("A palavra e um palindromo!");
    } else {
        printf("A palavra nao e um palindromo!");
    }

    return 0;
}