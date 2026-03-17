#include <stdio.h>
#include <stdlib.h>
#include "Ex02.h"

struct _conjunto {
    int elementos[MAX];
    int qtd;
};

Conjunto* CriarConjunto() {
    Conjunto *c = (Conjunto*) malloc(sizeof(Conjunto));
    if (c != NULL) {
        c->qtd = 0;
    }
    return c;
}

int pertence(Conjunto *c, int elemento) {
    for (int i = 0; i < c->qtd; i++) {
        if (c->elementos[i] == elemento) return 1;
    }
    return 0;
}

int InserirElemento(Conjunto *c, int elemento) {
    if (c->qtd >= MAX) {
        printf("Erro: Conjunto cheio!\n");
        return 0;
    }
    if (pertence(c, elemento)) {
        printf("Elemento %d ja existe no conjunto.\n", elemento);
        return 0;
    }
    c->elementos[c->qtd] = elemento;
    c->qtd++;
    return 1;
}

int removerElemento(Conjunto *c) {
    if (c->qtd == 0) {
        printf("Nao existem elementos para remover!\n");
        return 0;
    }
    int pos;
    printf("Posicao a remover (1-%d): ", c->qtd);
    scanf("%d", &pos);
    int indice = pos - 1;

    if (indice < 0 || indice >= c->qtd) {
        printf("Posicao invalida!\n");
        return 0;
    }
    for (int j = indice; j < c->qtd - 1; j++) {
        c->elementos[j] = c->elementos[j + 1];
    }
    c->qtd--;
    printf("Removido com sucesso!\n");
    return 1;
}

Conjunto* IntersecaoConjuntos(Conjunto *c1, Conjunto *c2) {
    Conjunto *res = CriarConjunto();
    if (res == NULL) return NULL;
    for (int i = 0; i < c1->qtd; i++) {
        if (pertence(c2, c1->elementos[i])) {
            InserirElemento(res, c1->elementos[i]);
        }
    }
    return res;
}

Conjunto* DiferencaConjuntos(Conjunto *c1, Conjunto *c2) {
    Conjunto *res = CriarConjunto();
    if (res == NULL) return NULL;
    for (int i = 0; i < c1->qtd; i++) {
        if (!pertence(c2, c1->elementos[i])) {
            InserirElemento(res, c1->elementos[i]);
        }
    }
    return res;
}

Conjunto* UnirConjuntos(Conjunto *c1, Conjunto *c2) {
    Conjunto *res = CriarConjunto();
    if (res == NULL) return NULL;
    for (int i = 0; i < c1->qtd; i++) InserirElemento(res, c1->elementos[i]);
    for (int i = 0; i < c2->qtd; i++) InserirElemento(res, c2->elementos[i]);
    return res;
}

int MaiorValor(Conjunto *c) {
    if (c->qtd == 0) return 0;
    int maior = c->elementos[0];
    for (int i = 1; i < c->qtd; i++) {
        if (c->elementos[i] > maior) maior = c->elementos[i];
    }
    return maior;
}

int MenorValor(Conjunto *c) {
    if (c->qtd == 0) return 0;
    int menor = c->elementos[0];
    for (int i = 1; i < c->qtd; i++) {
        if (c->elementos[i] < menor) menor = c->elementos[i];
    }
    return menor;
}

void TestarIgualdade(Conjunto *c1, Conjunto *c2) {
    if (c1->qtd != c2->qtd) {
        printf("Conjuntos diferentes (tamanhos distintos).\n");
        return;
    }
    for (int i = 0; i < c1->qtd; i++) {
        if (!pertence(c2, c1->elementos[i])) {
            printf("Conjuntos diferentes (elementos distintos).\n");
            return;
        }
    }
    printf("Os conjuntos sao iguais!\n");
}

void VerificarTamanho(Conjunto *c) {
    printf("Tamanho atual: %d\n", c->qtd);
}

void VerificarVazio(Conjunto *c) {
    if (c->qtd == 0) printf("O conjunto esta vazio!\n");
    else printf("O conjunto possui elementos.\n");
}

void MostrarConjunto(Conjunto *c) {
    if (c == NULL || c->qtd == 0) { printf("{ }\n"); return; }
    printf("{ ");
    for (int i = 0; i < c->qtd; i++) {
        printf("%d%s", c->elementos[i], (i < c->qtd - 1) ? ", " : "");
    }
    printf(" }\n");
}

void destruir_conjunto(Conjunto *c) {
    free(c);
}