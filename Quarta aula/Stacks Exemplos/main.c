#include<stdio.h>
#include"pilha.h"

int main(){
    Pilha *p = criarPilha();
    int op;
    int valor;
    do{
        printf("1 - Push\n2 - Pop\n3 - Acesso ao topo\n4 - Ver tamanho\n5 - Ver capacidade\n6 - Sair\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                Push(p, valor);
                break;
            case 2:
                Pop(p);
                break;
            case 3:
                AcessoTopo(p);
                break;
            case 4:
                VerTamanho(p);
                break;
            case 5:
                VerCapacidade(p);
                break;
            case 6:
                DestruirPilha(p);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(op != 6);
    return 0;
}