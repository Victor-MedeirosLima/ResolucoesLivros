// // 23. Crie uma classe que defina um número complexo (`x + yi`, onde `x` e `y` são do tipo `float` e `i` 
// é a raiz quadrada de -1). Defina as operações aritméticas entre números complexos nesta 
// classe


#include <iostream>
using namespace std;

class Complexo {
private:
    float real;
    float imag;

public:
    // Construtor default
    Complexo(float r = 0.0, float i = 0.0) {
        real = r;
        imag = i;
    }

    // Metodo para imprimir o numero complexo
    void imprimir() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }

    // Soma
    Complexo operator+(const Complexo& c) const {
        return Complexo(real + c.real, imag + c.imag);
    }

    // Subtracao
    Complexo operator-(const Complexo& c) const {
        return Complexo(real - c.real, imag - c.imag);
    }

    // Multiplicacao
    Complexo operator*(const Complexo& c) const {
        float r = real * c.real - imag * c.imag;
        float i = real * c.imag + imag * c.real;
        return Complexo(r, i);
    }

    // Divisao
    Complexo operator/(const Complexo& c) const {
        float denominador = c.real * c.real + c.imag * c.imag;
        float r = (real * c.real + imag * c.imag) / denominador;
        float i = (imag * c.real - real * c.imag) / denominador;
        return Complexo(r, i);
    }
};

// Programa de teste
int main() {
    Complexo c1(4, 3);
    Complexo c2(2, -1);

    cout << "c1 = ";
    c1.imprimir();

    cout << "c2 = ";
    c2.imprimir();

    Complexo soma = c1 + c2;
    cout << "Soma: ";
    soma.imprimir();

    Complexo sub = c1 - c2;
    cout << "Subtracao: ";
    sub.imprimir();

    Complexo mult = c1 * c2;
    cout << "Multiplicacao: ";
    mult.imprimir();

    Complexo div = c1 / c2;
    cout << "Divisao: ";
    div.imprimir();

    return 0;
}
