// 28.Use a classe Empresa como base para criar a classe Restaurante.
// Inclua o tipo de comida, o preço médio de um prato, duas funções construtoras, a interface de entrada de dados (Get()), e a função que imprima os dados (Print()).
// Construa um programa para testar a classe Restaurante.



#include <iostream>
#include <string>
using namespace std;

// Classe base
class Empresa {
protected:
    string nome;
    string endereco;
    string cidade;
    string estado;
    string cep;
    string fone;

public:
    Empresa() : nome(""), endereco(""), cidade(""), estado(""), cep(""), fone("") {}

    Empresa(string n, string e, string c, string s, string cp, string f)
        : nome(n), endereco(e), cidade(c), estado(s), cep(cp), fone(f) {}

    // Torne estas funções virtual para permitir override
    virtual void Get() {
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

    virtual void Print() const {
        cout << "\n--- Dados da Empresa ---" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Endereco: " << endereco << endl;
        cout << "Cidade: " << cidade << endl;
        cout << "Estado: " << estado << endl;
        cout << "CEP: " << cep << endl;
        cout << "Telefone: " << fone << endl;
    }
};

// Classe derivada
class Restaurante : public Empresa {
private:
    string tipoComida;
    float precoMedio;

public:
    Restaurante() : Empresa(), tipoComida(""), precoMedio(0.0f) {}

    Restaurante(string n, string e, string c, string s, string cp, string f, string tipo, float preco)
        : Empresa(n, e, c, s, cp, f), tipoComida(tipo), precoMedio(preco) {}

    
    void Get() override {
        Empresa::Get();
        cout << "Digite o tipo de comida: ";
        getline(cin, tipoComida);
        cout << "Digite o preco medio de um prato: ";
        cin >> precoMedio;
        cin.ignore(); // Limpa buffer
    }

    void Print() const override {
        Empresa::Print();
        cout << "Tipo de Comida: " << tipoComida << endl;
        cout << "Preco Medio: R$ " << precoMedio << endl;
    }
};


