// 22. Escreva um template da função max() que retorna o maior entre dois valores recebidos como argumentos.

#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max entre 10 e 20: " << Max(10, 20) << endl;
    cout << "Max entre 5.5 e 3.2: " << Max(5.5, 3.2) << endl;
    return 0;
}
