#define MAX 5 //Maximo de animais no torneio de corrida

//Definicao do Struct animal
struct animal{
    int posicao;
    char especie[25];
    char codigo[4];
};

//Definicao do Struct Lista
typedef struct lista Lista;

//Cria lista
Lista *criarLista();

//Insere nos a lista, ordenados decrescentemente pela posicao alcancada na corrida
int inserirOrdenado(Lista *l, struct animal a);

//Retorna a concatenacao entre duas listas
Lista *MergeListas(Lista *l1, Lista *l2);

//Remove o animal informado atraves de seu codigo
int removerAnimal(Lista *l, char cod[4]);

//Remove o primeiro animal da lista
int removerInicio(Lista *l);

//Remove o ultimo animal da lista
int removerFinal(Lista *l);

//Retorna o tamanho da lista (contando apenas os espacos alocados)
int tamLista(Lista *l);

//Imprime lista
void imprimirLista(Lista *l);
