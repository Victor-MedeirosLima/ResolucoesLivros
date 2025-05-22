// 29.Imagine que você deva escrever um programa para armazenar dados de veículos.
// Primeiramente, crie a classe Motor que contenha NumCilindro (int) e Potencia (int).
// Inclua um construtor sem argumentos que inicialize os dados com zeros e um que inicialize os dados com os valores recebidos como argumentos.
// Escreva duas funções, uma para a entrada de dados (Get()), e uma que imprima os dados (Print()).

#include <iostream>
using namespace std;

class Motor {
private:
    int numCilindros;
    int potencia;

public:
    // Construtor sem argumentos (inicializa com zeros)
    Motor() : numCilindros(0), potencia(0) {}

    // Construtor com argumentos
    Motor(int cilindros, int pot) : numCilindros(cilindros), potencia(pot) {}

    // Entrada de dados
    void Get() {
        cout << "Digite o numero de cilindros: ";
        cin >> numCilindros;
        cout << "Digite a potencia (em cavalos): ";
        cin >> potencia;
    }

    // Impressão dos dados
    void Print() const {
        cout << "\n--- Dados do Motor ---" << endl;
        cout << "Numero de cilindros: " << numCilindros << endl;
        cout << "Potencia: " << potencia << " CV" << endl;
    }
};
