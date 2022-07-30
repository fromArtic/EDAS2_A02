#include <stdio.h>
#include <stdlib.h>
#include "EDAS2_A02.h"

//Definicao do Struct lista
struct lista{
    struct animal animais[MAX];
    int prox;
};

//Cria lista
Lista *criarLista(){
    Lista *l; //Cria ponteiro
    l = (Lista*)malloc(sizeof(Lista)); //Aloca espaco

    if(l != NULL){
        (*l).prox = 0; //Caso valido, indica que a proxima posicao vazia eh a primeira (pois ainda nenhum valor foi incorporado)
    }

    return l;
}

//Insere nos a lista, ordenados decrescentemente pela posicao alcancada na corrida
int inserirOrdenado(Lista *l, struct animal a){
    int i = 0, k;

    if(l == NULL){ //Ha algo de errado com a lista (nao foi criada, p. ex.)
        return 0;
    }
    if((*l).prox == MAX){ //Lista ja esta cheia
        return 0;
    }
    if(a.posicao < 0){ //Posicao invalida
        printf("ERRO. %s [%s]\n", a.especie, a.codigo);
        printf("-> Insira uma posicao valida: ");
        scanf("%d", &a.posicao);
    }

    if(a.posicao != 0){ //Desconsidera entradas nulas
        while(i < (*l).prox && (*l).animais[i].posicao < a.posicao){ //Busca onde inserir
            i++; //Posicao a ser ocupada
        }

        //Desloca os elementos p/ frente, do final ate a posicao encontrada
        for(k = (*l).prox - 1; k >= i; k--){
            (*l).animais[k+1] = (*l).animais[k];
        }

        (*l).animais[i] = a; //Insere na posicao encontrada
        (*l).prox++;
    }

    return 1;
}

//Retorna a concatenacao entre duas listas
Lista *MergeListas(Lista *l1, Lista *l2){
    Lista *listaConcatenada = criarLista();

    for(int i = 0; i < (*l1).prox; i++){ //Incorpora os animais da lista 1
        inserirOrdenado(listaConcatenada, (*l1).animais[i]);
    }
    for(int j = 0; j < (*l2).prox; j++){ //Incorpora os animais da lista 2
        inserirOrdenado(listaConcatenada, (*l2).animais[j]);
    }

    return listaConcatenada;
}

//Remove o animal informado atraves de seu codigo
int removerAnimal(Lista *l, char cod[4]){
   int i = 0, k;

   if(l == NULL){ //Ha algo de errado com a lista (nao foi criada, p. ex.)
        return 0;
    }
    if((*l).prox == 0){ //Lista vazia
        return 0;
    }

    while(i < (*l).prox && strcmp((*l).animais[i].codigo, cod) != 0){ //Percorre a lista ate encontrar o codigo ou ate chegar no final
        i++;
        if(i == (*l).prox){ //Chegou no final e nao encontrou o elemento na lista
            return 0;
        }
    }

    //Desloca todos os elementos seguintes para a posicao anterior
    for(k = i; k < (*l).prox - 1; k++){
        (*l).animais[k] = (*l).animais[k+1];
    }

    (*l).prox--;
    return 1;
}

//Remove o primeiro animal da lista
int removerInicio(Lista *l){
    int i = 0;

   if(l == NULL){ //Ha algo de errado com a lista (nao foi criada, p. ex.)
        return 0;
    }
    if((*l).prox == 0){ //Lista vazia
        return 0;
    }

    //Desloca todos os elementos em uma posicao para tras
    for(i = 0; i < (*l).prox - 1; i++){
        (*l).animais[i] = (*l).animais[i+1];
    }

    (*l).prox--;
    return 1;
}

//Remove o ultimo animal da lista
int removerFinal(Lista *l){
    if(l == NULL){ //Ha algo de errado com a lista (nao foi criada, p. ex.)
        return 0;
    }
    if((*l).prox == 0){ //Lista vazia
        return 0;
    }

    (*l).prox--; //Pode-se apenas atualizar prox, nao eh necessario realocar
    return 1;
}

//Retorna o tamanho da lista (contando somente os espacos alocados)
int tamLista(Lista *l){
    //Ha algo de errado com a lista (nao foi criada, p. ex.)
    if(l == NULL){
        return 0;
    }

    return (*l).prox; //Se ok, retorna o tamanho
}

//Imprime lista
void imprimirLista(Lista *l){
    int i;

    //Ha algo de errado com a lista (nao foi criada, p. ex.)
    if(l == NULL){
        return 0;
    }

    printf("\n\tFIM DE CORRIDA - DADOS DA COMPETICAO\n");
	printf("\t------------------------------------\n");
    for(i = 0; i < (*l).prox; i++){
        printf("\t%d.\t%s [%s]\n", (*l).animais[i].posicao, (*l).animais[i].especie, (*l).animais[i].codigo);
        printf("\t------------------------------------\n");
    }
}
