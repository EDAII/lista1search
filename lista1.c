/*
Lista 01 - Métodos de Busca 
Busca sequencial com sentinela, usando vetor alocado dinamicamente populado por números aleatórios.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Gerador de números aleatórios */
int numeroRand(int range){
    int num;

    num = rand() % (range+1);
    return num;
}

/* Gerador de vetor */
int *criaVetor(int size, int range){
    int *vector;
    int cont;

    vector = (int * ) malloc (sizeof(int) * (size+1)); /* Alocação de memória para o vetor */
    srand((unsigned)time(NULL));
    for(cont = 0; cont < size; cont++){
        vector[cont] = numeroRand(range);
    }
    vector[cont] = -1; /* Evitando que sentinela tenha um valor antes da busca */
    return vector;
}

/* Gerador de vetor ordenado */
int *criaVetorOrdenado(int size){
    int *vector;
    int cont;

    vector = (int *) malloc (sizeof(int) * (size+1)); 
    srand((unsigned)time(NULL));
    for(cont = 0; cont < size; cont++){
        if(cont == 0){
            vector[cont] = numeroRand(size);
        }
        else{
            vector[cont] = vector[cont-1] + numeroRand(size) + 1;
        }
    }
    vector[cont] = -1;

    return vector;
}

/* Imprime vetor */
void imprimeVetor(int *vector, int size){
    int cont;
    printf("\n\n ==================\n");
    for(cont = 0; cont < size; cont++){
        printf("%d: %d\n", cont+1, vector[cont]);
    }
    printf(" ==================\n\n");
}


/* Imprime menu de métodos de busca */
void imprimeMenuBuscas(){
    printf("\n\n1 - Busca sequencial\n");
    printf("2 - Busca binária\n");
    printf("0 - Sair\n");
}

/* Imprime menu */
void imprimeMenu(){
    printf("\n\n1 - Listar vetor\n");
    printf("2 - Buscar no vetor\n");
    printf("0 - Sair\n\n");
}

/* Destrói vetor alocado */
void destroiVetor(int *vector){
    if(vector != NULL){
        free(vector);
    }
}

/* Algoritmo de Busca */
int buscaSequencial(int *vector, int size, int valor){
    int cont, qtyResults;

    qtyResults = 0;
    vector[size] = valor; /* Sentinela */
    for(cont = 0; cont <= size; cont++){
        if(vector[cont] == valor){
            qtyResults++;
        }
    }

    return qtyResults; /* Retorna quantidade de acertos na busca */
}


int buscaBinaria(int *vector, int size, int valor){
    int cont, qtyResults;

    qtyResults = 0;
    cont = (size+1)/2;
    do{
        if(valor > vector[cont]){
            cont+= cont/2;
        }
        else if(cont < vector[cont]){
            cont-= cont/2;
        }
        else{
            qtyResults++;
            return qtyResults;
        }
    }while(cont < size && cont > 0);
    return qtyResults;
}

int main(void){
    int size, range, opt, valor;
    int *vector;

    do{
        imprimeMenuBuscas();
        scanf("%d", &opt);
        switch(opt){
            case 1:
                printf("Digite o tamanho do vetor: \n");
                do{
                    scanf("%d", &size);
                    if(size <= 0){
                        printf("Por favor, digite um valor maior que 0. \n");
                    }
                }while(size <= 0);
                printf("Digite o intervalo dos números do vetor (de 0 até esse valor): \n");
                do{
                    scanf("%d", &range);
                    if(range <= 0){
                        printf("Por favor, digite um valor maior que 0. \n");
                    }
                }while(range <= 0);
                vector = criaVetor(size, range);
                do{
                    imprimeMenu();
                    scanf("%d", &opt);
                    switch(opt){
                        case 1:
                            imprimeVetor(vector, size);
                            break;
                        case 2:
                            do{
                                printf("Digite o valor a ser pesquisado: \n");
                                scanf("%d", &valor);
                                if(valor < 0){
                                    printf("Por favor, digite um valor maior ou igual a 0.\n");
                                }
                            }while(valor < 0);
                            if(buscaSequencial(vector, size, valor) > 1){
                                printf("Valor encontrado!\n");
                            }
                            else{
                                printf("Valor não encontrado.\n");
                            }
                            break;
                        case 0:
                            break;
                        default:
                            printf("Digite uma opção válida.\n");
                    }
                }while(opt);
                destroiVetor(vector);
                break;
            case 2:
                printf("Digite o tamanho do vetor: \n");
                do{
                    scanf("%d", &size);
                    if(size <= 0){
                        printf("Por favor, digite um valor maior que 0. \n");
                    }
                }while(size <= 0);
                vector = criaVetorOrdenado(size);
                do{
                    imprimeMenu();
                    scanf("%d", &opt);
                    switch(opt){
                        case 1:
                            imprimeVetor(vector, size);
                            break;
                        case 2:
                            do{
                                printf("Digite o valor a ser pesquisado: \n");
                                scanf("%d", &valor);
                                if(valor < 0){
                                    printf("Por favor, digite um valor maior ou igual a 0.\n");
                                }
                            }while(valor < 0);
                            if(buscaBinaria(vector, size, valor) >= 1){
                                printf("Valor encontrado!\n");
                            }
                            else{
                                printf("Valor não encontrado.\n");
                            }
                            break;
                        case 0:
                            break;
                        default:
                            printf("Digite uma opção válida.\n");
                    }
                }while(opt);
                destroiVetor(vector);
            case 0:
                break;
            default:
                printf("Digite uma opção válida.\n");
        }
    }while(opt);
}
