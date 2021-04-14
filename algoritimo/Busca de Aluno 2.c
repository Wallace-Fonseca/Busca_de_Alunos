#include<stdio.h>
#include<string.h> //Biblioteca para concatenar
#include<stdlib.h>


int menu(); //Função do Menu
struct Lista *CriarLista(int quantidade); //Criação de lista de aluno
int procurar(struct Lista* Lista); //Função para procurar pelo codigo digitado

struct Aluno { //Estrutura de dados Heterogeneos
    char nome[30];
    char email[30];
    int codigo;
    struct Aluno *proximo;
};

struct Lista { //Lista dos Alunos
    int quantidade;
    struct Aluno **todos;
};

struct Lista *CriarLista(int quantidade);

int main() { //Lista de dados já criados com o nome, e-mail, codigo e posicao.
    struct Lista *Lista_Temporaria = CriarLista(10);
    
    //Lista de Nomes
    char nome0[30] = "Paulo"; 
    char nome1[30] = "Joaquin";
    char nome2[30] = "Jorge";    
    char nome3[30] = "Natalia";
    char nome4[30] = "Algusto";
    char nome5[30] = "Wallace";
    char nome6[30] = "Carolina";
    char nome7[30] = "Lilian";
    char nome8[30] = "Caio";
    char nome9[30] = "Fermamda";

    //Lista de E-mails
    char email0[30] = "paulo@remail.net";
    char email1[30] = "joaquin@remail.net";
    char email2[30] = "jorge@remail.net";
    char email3[30] = "natalia@remail.net";
    char email4[30] = "algusto@remail.net";
    char email5[30] = "wallace@remail.net";
    char email6[30] = "carolina@remail.net";
    char email7[30] = "lilian@remail.net";
    char email8[30] = "caio@remail.net";
    char email9[30] = "fernanda@remail.net";

    //Inserindo o codigo no nome e email em cada posição
    Inserir_Aluno(Lista_Temporaria, nome0, email0, 1528744, 0);
    Inserir_Aluno(Lista_Temporaria, nome1, email1, 2589746, 1);
    Inserir_Aluno(Lista_Temporaria, nome2, email2, 1987468, 2);
    Inserir_Aluno(Lista_Temporaria, nome3, email3, 2846823, 3);
    Inserir_Aluno(Lista_Temporaria, nome4, email4, 1758935, 4);
    Inserir_Aluno(Lista_Temporaria, nome5, email5, 1921380, 5);
    Inserir_Aluno(Lista_Temporaria, nome6, email6, 1248560, 6);
    Inserir_Aluno(Lista_Temporaria, nome7, email7, 1875423, 7);
    Inserir_Aluno(Lista_Temporaria, nome8, email8, 2140796, 8);
    Inserir_Aluno(Lista_Temporaria, nome9, email9, 1625489, 9);

    int iniciar = NULL; //Menu inicial
    do {
        printf("***Programa Busca de Alunos***\n\n");
        printf("1 - Procurar Aluno. \n");
        printf("0 - Fechar.\n");
        printf("\nInforme sua opção: ");
        scanf("%d", &iniciar);
        system("clear"); //Utilizando o VS Code e o Linux Mint, está é a forma de limpar a tela.
        
        switch (iniciar) {
            case 1:
            procurar(Lista_Temporaria);
            break;
            case 0:
            return 0;
            break;
            default:
            printf("Digito Invalido! Tente novamente. \n");
        }
    } while(iniciar);
}

//Alocando espaço e inicialização da lista
struct Lista *CriarLista(int quantidade) { 
    struct Lista *Lista = (struct Lista*)malloc(sizeof(struct Lista));
    Lista->quantidade = quantidade;
    Lista->todos = (struct Aluno **)malloc(quantidade* sizeof(struct Aluno*));
    for(int i = 0; i < quantidade ; i++)
    Lista->todos[i] = NULL;
    return Lista;
}

//Inserindo os Alunos na lista
void Inserir_Aluno(struct Lista* Lista, char *nome, char *email , int codigo, int posicao){ 
    struct Aluno *NovoElemento = (struct Aluno*)malloc(sizeof(struct Aluno));
    strcpy(NovoElemento->nome, nome);
    strcpy(NovoElemento->email, email);
    NovoElemento->codigo = codigo;
    NovoElemento->proximo = NULL;
    NovoElemento->proximo = Lista->todos[posicao];
    Lista->todos[posicao] = NovoElemento;
}

int menu() {//Função do Menu
    int op;
    system("clear");
    printf("***Programa Busca de Alunos***\n\n");
    printf("1 - Procurar Aluno.\n");
    printf("0 - Fechar.\n");
    printf("\nInforme sua opção: ");
    scanf("%d" , &op);
    system("clear");
    return op;
}

int procurar(struct Lista* Lista) {//Função para Procurar o codigo desejado
    int num;
    printf("Procurar o codigo: ");
    scanf("%d", &num);
    system("clear");
    for(int i = 0; i < Lista->quantidade; i++) {
        struct Aluno *Elemento_Varredura = Lista->todos[i];
        while(Elemento_Varredura != NULL) {
            if(Elemento_Varredura->codigo == num){ //Achando o codigo ira imprimir os dados do aluno na tela
                printf("Nome do Aluno: %s\n ", Elemento_Varredura->nome);
                printf("E-mail: %s\n ", Elemento_Varredura->email);
                printf("Codigo: %d\n ", Elemento_Varredura->codigo);
            }
            Elemento_Varredura = Elemento_Varredura->proximo; 
        }     
    }
    printf("\n");
}