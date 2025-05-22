// 23. Escreva um template da função print() que imprima qualquer tipo de argumento (int, float, double etc.). Utilize o objeto cout para a impressão


#include <iostream>
using namespace std;

template <typename T>
void print(T valor) {
    cout << valor << endl;
}

int main() {
    print(42);
    print(3.14);
    print("Olá, mundo!");
    return 0;
}
