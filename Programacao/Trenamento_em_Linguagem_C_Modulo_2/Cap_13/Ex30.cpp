// 30. Escreva um template para a classe Potencia3 que calcula o valor de 3 elevado à potência n 
// (inteiro positivo). A classe é semelhante à do exercício anterior. Teste com o seguinte programa:



#include <iostream>
using namespace std;

template <int N>
class Potencia3 {
public:
    enum { num = 3 * Potencia3<N - 1>::num };
};

template <>
class Potencia3<0> {
public:
    enum { num = 1 };
};

int main() {
    cout << "Potencia3<5> = " << Potencia3<5>::num << endl;
    return 0;
}

