// 26. Adicione classes de exceções à fila do exercício anterior. 
// Os métodos da classe principal devem lançar exceções: fila cheia e fila vazia

#include <iostream>
using namespace std;

// Classes de exceção simples
class FilaCheia {};
class FilaVazia {};

template <typename T, int tamanho>
class Fila {
    T dados[tamanho];
    int inicio, fim;

public:
    Fila() : inicio(0), fim(0) {}

    void enfileirar(T valor) {
        if ((fim + 1) % tamanho == inicio)
            throw FilaCheia();
        dados[fim] = valor;
        fim = (fim + 1) % tamanho;
    }

    T desenfileirar() {
        if (inicio == fim)
            throw FilaVazia();
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

    try {
        fila.enfileirar(10);
        fila.enfileirar(20);
        fila.enfileirar(30);

        cout << "Desenfileirado: " << fila.desenfileirar() << endl;
        cout << "Desenfileirado: " << fila.desenfileirar() << endl;
        cout << "Desenfileirado: " << fila.desenfileirar() << endl;
        cout << "Desenfileirado: " << fila.desenfileirar() << endl; // Vai lançar exceção
    }
    catch (FilaCheia) {
        cout << "Erro: a fila está cheia." << endl;
    }
    catch (FilaVazia) {
        cout << "Erro: a fila está vazia." << endl;
    }

    return 0;
}
