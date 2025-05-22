// 24. Escreva um template da função localizar() que receba três argumentos: um ponteiro para 
// indicar o endereço de uma matriz, um valor do tipo dos elementos da matriz e um int informando 
// o tamanho da matriz. A função deve procurar o valor do segundo argumento entre os elementos da 
// matriz e retornar o índice da matriz correspondente ao elemento encontrado ou menos um (-1) para 
// indicar que o elemento não existe


#include <iostream>
using namespace std;

template <typename T>
int localizar(T* matriz, T valor, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        if (matriz[i] == valor)
            return i;
    }
    return -1;
}

int main() {
    int v[] = {1, 2, 3, 4, 5};
    cout << "Posição de 3: " << localizar(v, 3, 5) << endl;
    cout << "Posição de 10: " << localizar(v, 10, 5) << endl;
    return 0;
}
