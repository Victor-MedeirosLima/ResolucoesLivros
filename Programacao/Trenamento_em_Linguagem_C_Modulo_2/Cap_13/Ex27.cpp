// 27. Modifique o programa anterior para que a classe de exceção seja somente uma

#include <iostream>
using namespace std;

// Classe de exceção personalizada com mensagem
class ErroFila {
    const char* mensagem;
public:
    ErroFila(const char* msg) : mensagem(msg) {}

    const char* what() const {
        return mensagem;
    }
};

template <typename T, int tamanho>
class Fila {
    T dados[tamanho];
    int inicio, fim;

public:
    Fila() : inicio(0), fim(0) {}

    void enfileirar(T valor) {
        if ((fim + 1) % tamanho == inicio)
            throw ErroFila("Erro: a fila está cheia.");
        dados[fim] = valor;
        fim = (fim + 1) % tamanho;
    }

    T desenfileirar() {
        if (inicio == fim)
            throw ErroFila("Erro: a fila está vazia.");
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
        cout << "Desenfileirado: " << fila.desenfileirar() << endl; // Vai gerar exceção
    }
    catch (ErroFila& e) {
        cout << e.what() << endl;
    }

    return 0;
}
