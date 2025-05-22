// 24. Defina uma classe denominada fração. Essa classe deve armazenar o numerador e o denominador de uma fração em duas variáveis inteiras. Inclua:  
// a) Um construtor default e outro que receba numerador e denominador da fração;  
// b) Um método que retorne o numerador e outro que retorne o denominador;  
// c) Métodos para soma, subtração, multiplicação e divisão;  
// d) Sobrecarga dos operadores de incremento e decremento para pré-fixadas;  
// e) Sobrecarga dos operadores de incremento e decremento para pós-fixadas;  
// f) Métodos para conversão de fração para float e para um tipo `float`.  



#include <iostream>
using namespace std;

class Fracao {
private:
    int numerador;
    int denominador;

    // Funcao auxiliar para simplificar fracoes
    void simplificar() {
        int a = abs(numerador);
        int b = abs(denominador);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        if (a != 0) {
            numerador /= a;
            denominador /= a;
        }

        if (denominador < 0) {
            numerador *= -1;
            denominador *= -1;
        }
    }

public:
    // a) Construtor default
    Fracao() {
        numerador = 0;
        denominador = 1;
    }

    // a) Construtor com parametros
    Fracao(int num, int den) {
        numerador = num;
        denominador = (den == 0) ? 1 : den;
        simplificar();
    }

    // b) Metodos get
    int getNumerador() const {
        return numerador;
    }

    int getDenominador() const {
        return denominador;
    }

    // c) Operacoes com fracoes
    Fracao soma(const Fracao &outra) const {
        int num = numerador * outra.denominador + outra.numerador * denominador;
        int den = denominador * outra.denominador;
        return Fracao(num, den);
    }

    Fracao subtrai(const Fracao &outra) const {
        int num = numerador * outra.denominador - outra.numerador * denominador;
        int den = denominador * outra.denominador;
        return Fracao(num, den);
    }

    Fracao multiplica(const Fracao &outra) const {
        return Fracao(numerador * outra.numerador, denominador * outra.denominador);
    }

    Fracao divide(const Fracao &outra) const {
        return Fracao(numerador * outra.denominador, denominador * outra.numerador);
    }

    // d) Pre-incremento (++f)
    Fracao& operator++() {
        numerador += denominador;
        simplificar();
        return *this;
    }

    // d) Pre-decremento (--f)
    Fracao& operator--() {
        numerador -= denominador;
        simplificar();
        return *this;
    }

    // e) Pos-incremento (f++)
    Fracao operator++(int) {
        Fracao temp = *this;
        numerador += denominador;
        simplificar();
        return temp;
    }

    // e) Pos-decremento (f--)
    Fracao operator--(int) {
        Fracao temp = *this;
        numerador -= denominador;
        simplificar();
        return temp;
    }

    // f) Conversao para float
    float paraFloat() const {
        return static_cast<float>(numerador) / denominador;
    }

    operator float() const {
        return paraFloat();
    }

    // Utilitario para exibir a fracao
    void imprimir() const {
        cout << numerador << "/" << denominador << endl;
    }
};



int main(int argc, char const *argv[])
{
    Fracao f1(1, 2), f2(3, 4);

    cout << "Fracao 1: ";
    f1.imprimir();

    cout << "Fracao 2: ";
    f2.imprimir();

    Fracao soma = f1.soma(f2);
    cout << "Soma: ";
    soma.imprimir();

    Fracao mult = f1.multiplica(f2);
    cout << "Multiplicacao: ";
    mult.imprimir();

    Fracao pre = ++f1;
    cout << "Pre-incremento: ";
    pre.imprimir();

    Fracao pos = f2++;
    cout << "Pos-incremento: ";
    pos.imprimir();
    cout << "Depois do pós-incremento: ";
    f2.imprimir();

    cout << "Fracao como float: " << static_cast<float>(f1) << endl;
    return 0;
}
