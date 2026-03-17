#include <stdio.h>
#include "Ex02.h"

int main() {
    int op, opc, elem;
    Conjunto *c1 = CriarConjunto();
    Conjunto *c2 = CriarConjunto();
    Conjunto *temp = NULL;

    do {
        printf("\n==== MENU CONJUNTOS ====\n");
        printf("1 - Inserir Elemento\n");
        printf("2 - Remover Elemento\n");
        printf("3 - Intersecao (c1 e c2)\n");
        printf("4 - Diferenca (c1 - c2)\n");
        printf("5 - Uniao (c1 e c2)\n");
        printf("6 - Maior Valor\n");
        printf("7 - Menor Valor\n");
        printf("8 - Testar Igualdade\n");
        printf("9 - Verificar Tamanho\n");
        printf("10 - Verificar se Vazio\n");
        printf("11 - Mostrar Conjunto\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Valor a inserir: "); scanf("%d", &elem);
                printf("Qual conjunto? (1 ou 2): "); scanf("%d", &opc);
                if(opc == 1) InserirElemento(c1, elem); else InserirElemento(c2, elem);
                break;

            case 2:
                printf("Remover de qual conjunto? (1 ou 2): "); scanf("%d", &opc);
                if(opc == 1) removerElemento(c1); else removerElemento(c2);
                break;

            case 3:
                temp = IntersecaoConjuntos(c1, c2);
                printf("Resultado da Intersecao: ");
                MostrarConjunto(temp);
                destruir_conjunto(temp); 
                break;

            case 4:
                temp = DiferencaConjuntos(c1, c2);
                printf("Resultado da Diferenca (c1 - c2): ");
                MostrarConjunto(temp);
                destruir_conjunto(temp);
                break;

            case 5:
                temp = UnirConjuntos(c1, c2);
                printf("Resultado da Uniao: ");
                MostrarConjunto(temp);
                destruir_conjunto(temp);
                break;

            case 6:
                printf("Verificar maior de qual? (1 ou 2): "); scanf("%d", &opc);
                if(opc == 1) printf("Maior valor em c1: %d\n", MaiorValor(c1));
                else printf("Maior valor em c2: %d\n", MaiorValor(c2));
                break;

            case 7:
                printf("Verificar menor de qual? (1 ou 2): "); scanf("%d", &opc);
                if(opc == 1) printf("Menor valor em c1: %d\n", MenorValor(c1));
                else printf("Menor valor em c2: %d\n", MenorValor(c2));
                break;

            case 8:
                TestarIgualdade(c1, c2);
                break;

            case 9:
                printf("Verificar tamanho de qual? (1 ou 2): "); scanf("%d", &opc);
                if(opc == 1) VerificarTamanho(c1); else VerificarTamanho(c2);
                break;

            case 10:
                printf("Testar se vazio qual? (1 ou 2): "); scanf("%d", &opc);
                if(opc == 1) VerificarVazio(c1); else VerificarVazio(c2);
                break;

            case 11:
                printf("Mostrar qual conjunto? (1 ou 2): "); scanf("%d", &opc);
                if(opc == 1) { printf("c1: "); MostrarConjunto(c1); }
                else { printf("c2: "); MostrarConjunto(c2); }
                break;

            case 0:
                printf("Saindo e liberando memoria...\n");
                break;

            default:
                printf("Opcao invalida!!\n");
        }
    } while(op != 0);

    destruir_conjunto(c1);
    destruir_conjunto(c2);

    return 0;
}