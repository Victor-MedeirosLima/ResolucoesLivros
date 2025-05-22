// 29. O programa seguinte imprime 21. Analise o código e explique o resultado. Se substituirmos a constante 8,
// usada na função main(), por uma variável, o programa não funcionará. Explique.


// A sequência de Fibonacci é a seguinte: o primeiro termo vale 1,
// o segundo termo vale 2, o próximo é a soma dos dois anteriores,
// o próximo é a soma dos dois anteriores e assim por diante


#include <iostream>
using namespace std;

template <int N>
class Fibonacci {
public:
    enum { num = Fibonacci<N - 2>::num + Fibonacci<N - 1>::num };
};

template <>
class Fibonacci<2> {
public:
    enum { num = 1 };
};

template <>
class Fibonacci<1> {
public:
    enum { num = 1 };
};

int main() {
    cout << "Fibonacci<8> = " << Fibonacci<8>::num << endl;
    return 0;
}


