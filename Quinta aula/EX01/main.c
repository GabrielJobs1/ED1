#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
void main(){
    Stack *principal = CriarStack();
    char comando;
    int id;
    
    while(scanf(" %c %d", &comando,&id)&&(comando != '0' ||id != 0)){
        if(comando == 'i'){
            if(!Push(principal, id)){
                printf("overflow\n");
            }
        }else if(comando == 'r'){
            RemoverCarro(principal, id);
        }
        
    }
    free(principal);

}
