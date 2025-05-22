// 26. Defina uma classe de nome Aluno com membros de dados privados para armazenar o nome do aluno, a série e o grau. Inclua dois métodos públicos: um para solicitar os dados para o usuário e outro para imprimir os dados.
// a) Escreva uma instrução que declare um objeto denominado Alu1 da classe Aluno.
// b) Escreva uma instrução para executar o método que solicite os dados de entrada para o usuário.
// c) Escreva uma instrução para executar o método que imprima os dados digitados.
// d) Inclua um membro static privado para contar o número de alunos cadastrados.
// e) Inclua um construtor que incremente o contador de alunos cadastrados.
// f) Inclua um destrutor que decrementa o contador de alunos cadastrados.
// g) Inclua um método static que imprima o número de alunos cadastrados.
// h) Escreva a instrução necessária para declarar uma matriz de dez objetos da classe Aluno.
// i) Escreva a instrução necessária para preencher o primeiro elemento da matriz anterior com os dados digitados pelo usuário.


#include <stdio.h>
#include <string>
#include <cstring> // Necessário para trabalhar com c_str() no caso de std::string

using namespace std;

class Aluno {
private:
    string nome;
    string serie;
    string grau;
    static int contador; // d)

public:
    Aluno() {
        contador++; // e)
    }

    ~Aluno() {
        contador--; // f)
    }

    void solicitaDados() {
        char tempNome[100], tempSerie[100], tempGrau[100];
        printf("Informe seu nome: ");
        scanf("%s", tempNome); // Usando array de char temporário para entrada
        nome = tempNome;       // Convertendo para std::string

        printf("Informe sua serie: ");
        scanf("%s", tempSerie); 
        serie = tempSerie;      

        printf("Informe seu grau: ");
        scanf("%s", tempGrau); 
        grau = tempGrau;       
    }

    void exibirDados() const {
        printf("Nome: %s\n", nome.c_str());  // Usando c_str() para converter std::string para const char*
        printf("Série: %s\n", serie.c_str());
        printf("Grau: %s\n", grau.c_str());
    }

    static void imprimirContador() {
        printf("Contador de alunos: %d\n", contador); // g)
    }
};


int Aluno::contador = 0;

int main(int argc, char const *argv[]) {
    Aluno Alu1; // a)

    Alu1.solicitaDados(); // b)

    Alu1.exibirDados(); // c)

    Aluno alunos[10]; // h)

    alunos[0].solicitaDados(); // i)
    alunos[0].exibirDados();

    Aluno::imprimirContador(); // g)

    return 0;
}
