// 30.Escreva a classe Veiculo contendo Peso em quilos (int), VelocMax em km/h (int) e Preco em US$ (float).
// Inclua um construtor com argumentos que inicialize os dados com zeros e outro com dados como os valores recebidos como argumento.
// Acrescente duas funções (Get() e Print()) como nos exercícios anteriores.


#include <iostream>
using namespace std;

class Veiculo {
private:
    int peso;
    int velMax;
    float preco;

public:
    // Construtor sem argumentos (inicializa com zeros)
    Veiculo() : peso(0), velMax(0), preco(0.0f) {}

    // Construtor com argumentos
    Veiculo(int p, int v, float pr) : peso(p), velMax(v), preco(pr) {}

    // Entrada de dados
    void Get() {
        cout << "Digite o peso do veiculo (kg): ";
        cin >> peso;
        cout << "Digite a velocidade maxima (km/h): ";
        cin >> velMax;
        cout << "Digite o preco (em US$): ";
        cin >> preco;
    }

    // Impressão dos dados
    void Print() const {
        cout << "\n--- Dados do Veiculo ---" << endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "Velocidade Maxima: " << velMax << " km/h" << endl;
        cout << "Preco: US$ " << preco << endl;
    }
};
