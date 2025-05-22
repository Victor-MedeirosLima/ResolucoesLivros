// 23. Defina uma classe denominada Fracao. Esta deve armazenar o numerador e o denominador 
// de uma fração em duas variáveis inteiras. Inclua as operações de adição, subtração, multiplicação 
// e divisão entre objetos e entre um número inteiro e um objeto.

#include <iostream>
#include <numeric>  // std::gcd (C++17 ou superior)
using namespace std;

class Fracao {
private:
    int numerador;
    int denominador;

    void simplificar() {
        int mdc = gcd(numerador, denominador);
        numerador /= mdc;
        denominador /= mdc;
        // manter o sinal no numerador
        if (denominador < 0) {
            numerador *= -1;
            denominador *= -1;
        }
    }

public:
    // Construtor
    Fracao(int num = 0, int den = 1) {
        if (den == 0) {
            throw invalid_argument("Denominador não pode ser zero.");
        }
        numerador = num;
        denominador = den;
        simplificar();
    }

    // Operador +
    Fracao operator+(const Fracao& f) const {
        int num = numerador * f.denominador + f.numerador * denominador;
        int den = denominador * f.denominador;
        return Fracao(num, den);
    }

    Fracao operator+(int inteiro) const {
        return *this + Fracao(inteiro);
    }

    // Operador -
    Fracao operator-(const Fracao& f) const {
        int num = numerador * f.denominador - f.numerador * denominador;
        int den = denominador * f.denominador;
        return Fracao(num, den);
    }

    Fracao operator-(int inteiro) const {
        return *this - Fracao(inteiro);
    }

    // Operador *
    Fracao operator*(const Fracao& f) const {
        return Fracao(numerador * f.numerador, denominador * f.denominador);
    }

    Fracao operator*(int inteiro) const {
        return *this * Fracao(inteiro);
    }

    // Operador /
    Fracao operator/(const Fracao& f) const {
        if (f.numerador == 0) {
            throw invalid_argument("Divisão por zero.");
        }
        return Fracao(numerador * f.denominador, denominador * f.numerador);
    }

    Fracao operator/(int inteiro) const {
        if (inteiro == 0) {
            throw invalid_argument("Divisão por zero.");
        }
        return *this / Fracao(inteiro);
    }

    // Impressão
    void mostrar() const {
        cout << numerador << "/" << denominador << endl;
    }

    // friend para operações com int à esquerda
    friend Fracao operator+(int i, const Fracao& f) { return Fracao(i) + f; }
    friend Fracao operator-(int i, const Fracao& f) { return Fracao(i) - f; }
    friend Fracao operator*(int i, const Fracao& f) { return Fracao(i) * f; }
    friend Fracao operator/(int i, const Fracao& f) { return Fracao(i) / f; }
};

// Exemplo de uso
int main() {
    Fracao f1(2, 3);
    Fracao f2(3, 4);
    Fracao soma = f1 + f2;
    Fracao sub = f1 - 1;
    Fracao mult = 2 * f1;
    Fracao div = f1 / f2;

    cout << "f1 + f2 = "; soma.mostrar();
    cout << "f1 - 1 = "; sub.mostrar();
    cout << "2 * f1 = "; mult.mostrar();
    cout << "f1 / f2 = "; div.mostrar();

    return 0;
}
