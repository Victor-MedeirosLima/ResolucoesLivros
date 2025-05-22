// 25. Implemente a sobrecarga do operador de índice para a função `()` na classe `String`. O seu protótipo é o seguinte:  
// 
// void operator()(int n, char ch);
//
// Essa sobrecarga atribui o caractere `ch` ao enésimo caractere da cadeia. Escreva um programa teste.


#include <iostream>
#include <string>
using namespace std;

class String {
private:
    string texto;

public:
    // Construtor
    String(string t = "") {
        texto = t;
    }

    // Sobrecarga do operador () para modificar um caractere
    void operator()(int n, char ch) {
        if (n >= 0 && n < texto.size()) {
            texto[n] = ch;
        } else {
            cout << "Posicao invalida!" << endl;
        }
    }

    // Metodo para imprimir o texto
    void imprimir() const {
        cout << "Texto: " << texto << endl;
    }
};

// Programa de teste
int main() {
    String s("exemplo");

    cout << "Antes da mudanca:" << endl;
    s.imprimir();

    s(2, 'Z');  // Troca o caractere na posicao 2 por 'Z'

    cout << "Depois da mudanca:" << endl;
    s.imprimir();

    // Testando posicao invalida
    s(20, 'X');

    return 0;
}
