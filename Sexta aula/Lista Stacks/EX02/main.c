#include<stdio.h>
#include "Stack.h"

void main(){
    Stack* s = stack_create();
    char str[10];
    printf("Digite uma palavra:\n");
    scanf("%s",str);
    for(int i = 0; str[i] != '\0'; i++){
        if(stack_push(s, str[i])){
            printf("\n");
        };
    }
    if(verificar_palindromo(s)){
        printf("A palavra e um palindromo!");
    } else {
        printf("A palavra nao e um palindromo!");
    }
}