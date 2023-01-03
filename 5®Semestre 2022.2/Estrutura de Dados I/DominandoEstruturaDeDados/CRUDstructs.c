#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct _livro {
    char titulo[100];
    unsigned int num_pag;
    float preco;
} Livro;

typedef struct _alunoc{
    char nome[100];
    int idade;
    Livro *livro_fav;
} Aluno;






// "Construtor" para livros. Ele aloca e faz uma atribuição
Livro *create_livro(const char *titulo, unsigned int num_pag, float preco){
    Livro *livro = (Livro *) calloc(1,sizeof(Livro));

    strcpy(livro->titulo, titulo);
    livro->num_pag = num_pag;
    livro->preco = preco;

    return livro;
}


void destroy_livro (Livro **livro_ref) {
    Livro *livro = *livro_ref;
    free(livro);
    *livro_ref = NULL;

}

Livro *copy_livro(const Livro *livro){

    return create_livro(livro->titulo, livro->num_pag, livro->preco);
}



void print_livro(const Livro *livro) {
    puts("--------------------------");
    printf("Titulo: %s\n", livro->titulo);
    printf("num pag: %d\n", livro->num_pag);
    printf("preco: R$ %.2f\n\n", livro->preco);
    puts("--------------------------");
}

Aluno *create_aluno(const char *nome, int idade, const Livro *livro_fav) {
    Aluno *aluno = (Aluno *) calloc (1, sizeof(Aluno));

    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    aluno->livro_fav = copy_livro(livro_fav);

    return aluno;
}


    void destroy_aluno(Aluno **aluno_ref) {
        Aluno *aluno = *aluno_ref;

        destroy_livro(&aluno->livro_fav);
        free(aluno);
        *aluno_ref = NULL;
    }



void print_aluno(const Aluno *aluno){
    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);
    puts("Livro Favorito");
    print_livro(aluno->livro_fav);

}

bool book_are_equal (const Livro *livro_1, const Livro *livro_2) {
        if (strcmp(livro_1->titulo, livro_2->titulo) == 0) {
            return true;
        }
        else {
            return false;
        }
                     }



int main(){
    Livro *livro_1 = create_livro("Harry Potter 1", 200, 30);

    print_livro(livro_1);
    livro_1->preco = 15;
    print_livro(livro_1);

    Aluno *rio = create_aluno("Rio", 20, livro_1);
    print_aluno(rio);

    puts("\nrio->livro_fav == livro_1");
    puts("Os exemplares sao iguais?");
    if (rio->livro_fav == livro_1) {
        puts("TRUE");
    }else {
        puts("FALSE");
    }
    puts("\n");

    puts("\nLivros sao iguais?");
    puts("A obra e a mesma?");
    if (book_are_equal(rio->livro_fav, livro_1)){
        puts("TRUE");
    } else {
        puts("FALSE");
    }
    puts("\n");
    
    destroy_livro(&livro_1);
    
    print_aluno(rio);

    destroy_aluno(&rio);

    return 0;
}


