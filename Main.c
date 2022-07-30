/*
Crie um programa para realizar merge entre duas listas ordenadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include "EDAS2_A02.h"

int main(){
    //Declaracao das listas
    Lista *l1 = criarLista();
    Lista *l2 = criarLista();

    struct animal vet1[MAX] = { //Declaracao do primeiro vetor com animais
                        {1, "Pardal", "323"},
                        {3, "Jaguar", "002"},
                        {3, "Leao Marinho", "050"},
                        {4, "Lebre", "072"},
	};

	 struct animal vet2[MAX] = { //Declaracao do segundo vetor com animais
                        {2, "Arraia", "476"},
                        {5, "Jaguatirica", "222"},
                        {6, "Tartaruga", "699"} //Testa o limite de competidores (nao deve aparecer caso exceda a posicao maxima)
	 };

    //Incorporacao dos vetores as listas
    for(int i = 0; i < MAX; i++){
        inserirOrdenado(l1, vet1[i]);
    }
    for(int i = 0; i < MAX; i++){
        inserirOrdenado(l2, vet2[i]);
    }

    //Remocao de um animal
    removerAnimal(l1, "050");
    //removerInicio(l1);
    //removerFinal(l1);

    //Concatenacao entre as duas listas
    Lista *lConcatenada = MergeListas(l1, l2);

    //Saida da lista concatenada
    imprimirLista(lConcatenada);
    printf("\n");

    system("PAUSE");
    return 0;
}
