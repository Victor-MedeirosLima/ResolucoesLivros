// 25. Filas são listas de dados acessadas na ordem “o primeiro a entrar, o primeiro a sair”,
// também denominado FIFO (First In, First Out). As filas fazem uso de dois índices: um para o 
// início da fila, onde os dados são retirados, e outro para indicar o final, onde os novos elementos 
// são inseridos. Quando o início e o fim se encontram, a fila está vazia. Escreva um template de classe 
// para manipular a fila


#include <iostream>
using namespace std;

template <typename T, int tamanho>
class Fila {
    T dados[tamanho];
    int inicio, fim;

public:
    Fila() : inicio(0), fim(0) {}

    void enfileirar(T valor) {
        if ((fim + 1) % tamanho == inicio)
            cout << "Fila cheia!" << endl;
        else {
            dados[fim] = valor;
            fim = (fim + 1) % tamanho;
        }
    }

    T desenfileirar() {
        if (inicio == fim) {
            cout << "Fila vazia!" << endl;
            return T();  // Retorna valor padrão
        }
        T temp = dados[inicio];
        inicio = (inicio + 1) % tamanho;
        return temp;
    }

    bool vazia() const {
        return inicio == fim;
    }
};

int main() {
    Fila<int, 5> fila;
    fila.enfileirar(10);
    fila.enfileirar(20);
    cout << fila.desenfileirar() << endl;
    cout << fila.desenfileirar() << endl;
    cout << fila.desenfileirar() << endl; // Deve exibir "Fila vazia!"
    return 0;
}
