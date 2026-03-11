#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;


void codificar(Pixel *imagem, char *mensagem);
void salvarArquivo(Pixel *imagem, int pixels_necessarios, char *NomeArquivo);
void validarFormato(char *NomeArquivo);
void carregarEdecodificar(char *NomeArquivo);

int main() {
    char mensagem[128];
    Pixel *imagem = NULL;
    char NomeArquivo[128];
    int op;

    do {
        printf("\nO que deseja fazer?\n(1) Codificar e Salvar Arquivo.\n(2) Carregar e decodificar Arquivo.\n(0) Sair\nEscolha: ");
        if (scanf("%d", &op) != 1) break;

        switch (op) {
            case 1:
                printf("\nDigite o nome do Arquivo (ex: resultado): ");
                scanf("%127s", NomeArquivo);
                validarFormato(NomeArquivo);
                
                getchar();
                printf("Digite a mensagem: ");
                fgets(mensagem, 128, stdin);
                mensagem[strcspn(mensagem, "\n")] = 0;

                int msg_len = strlen(mensagem) + 1;

                int pixels_necessarios = (msg_len * 4 / 3) + 1;

                imagem = (Pixel *)malloc(pixels_necessarios * sizeof(Pixel));
                if (imagem == NULL) {
                    printf("Erro ao alocar memoria!\n");
                    return 1;
                }

                for (int i = 0; i < pixels_necessarios; i++) {
                    imagem[i].r = 255; imagem[i].g = 255; imagem[i].b = 255;
                }

                codificar(imagem, mensagem);
                salvarArquivo(imagem, pixels_necessarios, NomeArquivo);
                
                free(imagem);
                break;

            case 2:
                printf("\nDigite o nome do Arquivo para abrir(incluir .ppm ao final): ");
                scanf("%127s", NomeArquivo);
                validarFormato(NomeArquivo);
                carregarEdecodificar(NomeArquivo);
                break;
        }
    } while (op != 0);

    return 0;
}

void codificar(Pixel *imagem, char *mensagem) {
    int msg_len = strlen(mensagem) + 1;
    int pixel_idx = 0;
    int componente = 0;

    for (int i = 0; i < msg_len; i++) {
        unsigned char letra = mensagem[i];
        for (int j = 0; j < 4; j++) {
            unsigned char dois_bits = (letra >> (j * 2)) & 0x03;
            unsigned char *cor;

            if (componente == 0) cor = &imagem[pixel_idx].r;
            else if (componente == 1) cor = &imagem[pixel_idx].g;
            else cor = &imagem[pixel_idx].b;

            *cor = (*cor & 0xFC) | dois_bits;

            componente++;
            if (componente > 2) {
                componente = 0;
                pixel_idx++;
            }
        }
    }
}

void salvarArquivo(Pixel *imagem, int pixels_necessarios, char *NomeArquivo) {
    FILE *arq = fopen(NomeArquivo, "wb");
    if (arq == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }
    fprintf(arq, "P6\n%d 1\n255\n", pixels_necessarios);
    fwrite(imagem, sizeof(Pixel), pixels_necessarios, arq);
    fclose(arq);
    printf("Imagem salva como '%s' com sucesso!\n", NomeArquivo);
}

void validarFormato(char *NomeArquivo) {
    if (strstr(NomeArquivo, ".ppm") == NULL) {
        strcat(NomeArquivo, ".ppm");
    }
}

void carregarEdecodificar(char *NomeArquivo) {
    FILE *arq = fopen(NomeArquivo, "rb");
    if (arq == NULL) {
        printf("Arquivo '%s' nao encontrado!\n", NomeArquivo);
        return;
    }

    int larg, alt, max;
    if (fscanf(arq, "P6 %d %d %d", &larg, &alt, &max) != 3) {
        fclose(arq);
        printf("Erro no cabecalho do arquivo!\n");
        
        return;
    }
    fgetc(arq);

    int total_pixels = larg * alt;
    Pixel *imagem = (Pixel *)malloc(total_pixels * sizeof(Pixel));
    fread(imagem, sizeof(Pixel), total_pixels, arq);
    fclose(arq);

    printf("Mensagem Extraida: ");
    int pixel_idx = 0, componente = 0;
    while (pixel_idx < total_pixels) {
        char letra = 0;
        for (int j = 0; j < 4; j++) {
            unsigned char cor;
            if (componente == 0) cor = imagem[pixel_idx].r;
            else if (componente == 1) cor = imagem[pixel_idx].g;
            else cor = imagem[pixel_idx].b;

            letra |= ((cor & 0x03) << (j * 2));
            componente++;
            if (componente > 2) {
                componente = 0;
                pixel_idx++;
            }
        }
        if (letra == '\0') break;
        printf("%c", letra);
    }
    printf("\n");
    free(imagem);
}