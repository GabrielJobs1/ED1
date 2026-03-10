#include<stdio.h>
#include<stdlib.h>

typedef struct Contato{
    char nome[128];
    char telefone[32];
}contato;

void cadastrarContato(contato **c, int *capacidade);
void exibirContato(contato *c, int capacidade);
void salvarArquivo(contato *c, int capacidade);
int main(){
    contato *c = NULL;
    int capacidade = 0;
    int op;
    
    c =(contato*)malloc(sizeof(contato));
    if(c == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    FILE*f = fopen("contatos.csv","r");
    if(f == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    char linha[160];
    while(fgets(linha,sizeof(linha),f)){
        if(capacidade == 0){
            sscanf(linha, "%[^,],%s", c->nome, c->telefone);
            capacidade++;
        }else{
            c = (contato *)realloc(c,sizeof(contato)*(capacidade + 1));
            sscanf(linha,"%[^,],%s",c->nome,c->telefone);
            capacidade++;
        }
    }
    do{
        printf("Menu:\n(1)Cadastrar contato\n(2)Exibir contato\n(3)Salvar Arquivo\n(0)Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cadastrarContato(&c,&capacidade);
            break;
        case 2:
            exibirContato(c,capacidade);
            break;
        case 3:
            salvarArquivo(c,capacidade);
            break;
        case 0:
            break;
        default:
            break;
        }
    }while(op != 0);
    return 0;

}
void cadastrarContato(contato **c, int *capacidade){
    if(*capacidade < 100){
        printf("Digite o nome do contato:");
        scanf("%s", (*c)[*capacidade].nome);
        printf("Digite o telefone do contato:");
        scanf("%s", (*c)[*capacidade].telefone);
        (*capacidade)++;
    }else{
        printf("Limite de contatos atingido");
    }
}
void exibirContato(contato *c, int capacidade){
    int op;
    printf("Digite qual contato voce deseja exibir(1-%d):",capacidade);
    scanf("%d", &op);
    if(op > 0 && op <= capacidade){
        printf("Nome: %s\n", c[op-1].nome);
        printf("Telefone: %s\n", c[op-1].telefone);
    }else{
        printf("Contato invalido"); 
    }
}
void salvarArquivo(contato *c,int capacidade){
    FILE*f = fopen("contatos.csv","w");
    if(f == NULL){
        printf("Arquivo não encontrado!");
    }
    for(int i = 0; i < capacidade;i++){
        fprintf(f,"%s,%s\n",c[i].nome,c[i].telefone);
    }
    fclose(f);
}