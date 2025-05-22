// 31.Crie a classe CarroPasseio usando as classes Motor e Veiculo como base.
// Inclua Cor (string) e Modelo (string).
// Inclua os construtores com e sem argumentos que inicializem todos os membros da classe.
// Inclua funções de entrada de dados (Get()) e uma função que imprima os dados (Print()).


#include <iostream>
#include <string>
using namespace std;

// Classe Motor
class Motor {
private:
    int numCilindros;
    int potencia;

public:
    Motor() : numCilindros(0), potencia(0) {}

    Motor(int cilindros, int pot) : numCilindros(cilindros), potencia(pot) {}

    void Get() {
        cout << "Digite o numero de cilindros: ";
        cin >> numCilindros;
        cout << "Digite a potencia (CV): ";
        cin >> potencia;
    }

    void Print() const {
        cout << "--- Motor ---" << endl;
        cout << "Cilindros: " << numCilindros << endl;
        cout << "Potencia: " << potencia << " CV" << endl;
    }
};

// Classe Veiculo
class Veiculo {
private:
    int peso;
    int velMax;
    float preco;

public:
    Veiculo() : peso(0), velMax(0), preco(0.0f) {}

    Veiculo(int p, int v, float pr) : peso(p), velMax(v), preco(pr) {}

    void Get() {
        cout << "Digite o peso (kg): ";
        cin >> peso;
        cout << "Digite a velocidade maxima (km/h): ";
        cin >> velMax;
        cout << "Digite o preco (US$): ";
        cin >> preco;
    }

    void Print() const {
        cout << "--- Veiculo ---" << endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "Velocidade Maxima: " << velMax << " km/h" << endl;
        cout << "Preco: US$ " << preco << endl;
    }
};

// Classe CarroPasseio
class CarroPasseio {
private:
    Motor motor;
    Veiculo veiculo;
    string cor;
    string modelo;

public:
    // Construtor sem argumentos
    CarroPasseio() : motor(), veiculo(), cor(""), modelo("") {}

    // Construtor com argumentos
    CarroPasseio(int cilindros, int pot, int peso, int velMax, float preco,
                 string c, string m)
        : motor(cilindros, pot), veiculo(peso, velMax, preco), cor(c), modelo(m) {}

    // Função de entrada de dados
    void Get() {
        cout << "=== Dados do Carro de Passeio ===" << endl;
        motor.Get();
        veiculo.Get();
        cin.ignore(); // Limpa o buffer antes de getline
        cout << "Digite a cor: ";
        getline(cin, cor);
        cout << "Digite o modelo: ";
        getline(cin, modelo);
    }

    // Função para imprimir os dados
    void Print() const {
        cout << "\n=== Informacoes do Carro de Passeio ===" << endl;
        motor.Print();
        veiculo.Print();
        cout << "--- Dados adicionais ---" << endl;
        cout << "Cor: " << cor << endl;
        cout << "Modelo: " << modelo << endl;
    }
};


