// 37. Escreva um programa que solicite ao usuário o número de notas a serem digitadas, crie uma matriz com a dimensão especificada para armazenar as entradas, solicite as notas e chame uma função que retorne a média aritmética das notas. Após imprimir a média, o programa libera a memória alocada para a matriz.

#include <iostream>
using namespace std;

// Função que calcula a média aritmética
double calcularMedia(double** notas, int numNotas) {
    double soma = 0;
    for (int i = 0; i < numNotas; i++) {
        soma += *notas[i]; // Acessa a nota armazenada
    }
    return soma / numNotas;
}

int main() {
    int numNotas;

    // Solicitar ao usuário o número de notas
    cout << "Digite o número de notas: ";
    cin >> numNotas;

    // Alocar memória para a matriz de notas
    double** notas = new double*[numNotas]; // Aloca um vetor de ponteiros para as notas

    // Solicitar as notas
    for (int i = 0; i < numNotas; i++) {
        notas[i] = new double; // Aloca memória para cada nota individualmente
        cout << "Digite a nota " << i + 1 << ": ";
        cin >> *notas[i]; // Armazena a nota
    }

    // Calcular a média
    double media = calcularMedia(notas, numNotas);

    // Imprimir a média
    cout << "A média das notas é: " << media << endl;

    // Liberar a memória alocada
    for (int i = 0; i < numNotas; i++) {
        delete notas[i]; // Libera a memória alocada para cada nota
    }
    delete[] notas; // Libera o vetor de ponteiros

    return 0;
}
