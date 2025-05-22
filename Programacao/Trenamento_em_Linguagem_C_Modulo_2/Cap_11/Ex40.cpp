//40. Escreva a função RetornaPFunc() que retorne um ponteiro para função correspondente ao inteiro recebido como argumento. Declare o seu protótipo e teste com o seguinte programa:


#include <iostream>
using namespace std;

void func0(void), func1(void), func2(void); // Protótipos

typedef void (*PFunc)(void); // O tipo PFunc é ponteiro para a função void

int main()
{
    PFunc ptr;

    do
    {
        int i;
        cout << "0 - ABRIR" << endl;
        cout << "1 - FECHAR" << endl;
        cout << "2 - SALVAR" << endl;
        cout << "\nEscolha um item: ";
        cin >> i;
        if(i < 0 || i > 2) break;

        ptr = RetornaPFunc(i);
        (ptr)(); // Chama função
    } while(true);
    
    system("PAUSE");
    return 0;
}



// Implementação das funções
void func0(void) {
    cout << "Abrindo..." << endl;
}

void func1(void) {
    cout << "Fechando..." << endl;
}

void func2(void) {
    cout << "Salvando..." << endl;
}

PFunc RetornaPFunc(int i) {
    switch(i) {
        case 0: return func0;  // Retorna ponteiro para func0
        case 1: return func1;  // Retorna ponteiro para func1
        case 2: return func2;  // Retorna ponteiro para func2
        default: return nullptr; // Caso o número não seja válido
    }
}