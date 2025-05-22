// 27.Crie uma classe chamada de Empresa capaz de armazenar os dados de uma empresa (Nome, Endereço, Cidade, Estado, CEP e Fone).
// Inclua um construtor sem argumentos e um que receba os dados como argumentos e os inicialize.
// Escreva duas funções, uma para fazer a interface com o usuário da entrada de dados (Get()), e outra para imprimir os dados (Print()).


#include <iostream>
#include <string>
using namespace std;

class Empresa {
private:
    string nome;
    string endereco;
    string cidade;
    string estado;
    string cep;
    string fone;

public:
    // Construtor sem argumentos
    Empresa() : nome(""), endereco(""), cidade(""), estado(""), cep(""), fone("") {}

    // Construtor com argumentos
    Empresa(string n, string e, string c, string s, string cp, string f)
        : nome(n), endereco(e), cidade(c), estado(s), cep(cp), fone(f) {}

    // Função para entrada de dados
    void Get() {
        cout << "Digite o nome da empresa: ";
        getline(cin, nome);

        cout << "Digite o endereco: ";
        getline(cin, endereco);

        cout << "Digite a cidade: ";
        getline(cin, cidade);

        cout << "Digite o estado: ";
        getline(cin, estado);

        cout << "Digite o CEP: ";
        getline(cin, cep);

        cout << "Digite o telefone: ";
        getline(cin, fone);
    }

    // Função para exibir os dados
    void Print() const {
        cout << "\n--- Dados da Empresa ---" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Endereco: " << endereco << endl;
        cout << "Cidade: " << cidade << endl;
        cout << "Estado: " << estado << endl;
        cout << "CEP: " << cep << endl;
        cout << "Telefone: " << fone << endl;
    }
};