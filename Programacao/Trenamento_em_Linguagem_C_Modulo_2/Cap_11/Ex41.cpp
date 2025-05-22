// 41.Escreva uma classe chamada Fruta. Não defina nenhum membro privado. Inclua três métodos
// públicos do tipo void que não recebam nada como argumento. Os nomes dos métodos são Pe-
// ra, Banana e Goiaba. Cada método tem uma única instrução que imprime o nome dele.

// A função main() declara uma matriz de três ponteiros para os métodos da classe Fruta e ini-
// cializa a matriz com os endereços dos métodos. O usuário digita um número entre 0 e 2, e o
// método correspondente é chamado.


#include <iostream>
using namespace std;

class Fruta {
public:
    // Métodos que imprimem o nome da fruta
    void Pera() {
        cout << "Pera" << endl;
    }

    void Banana() {
        cout << "Banana" << endl;
    }

    void Goiaba() {
        cout << "Goiaba" << endl;
    }
};

int main() {
    // Declaração de uma matriz de ponteiros para os métodos
    void (Fruta::*frutas[3])() = { &Fruta::Pera, &Fruta::Banana, &Fruta::Goiaba };
    
    Fruta f;  // Criando um objeto da classe Fruta
    
    int escolha;
    cout << "Escolha um número entre 0 e 2 para selecionar uma fruta: ";
    cin >> escolha;

    // Verifica se a escolha está dentro do intervalo válido
    if (escolha >= 0 && escolha <= 2) {
        // Chama o método correspondente à escolha
        (f.*frutas[escolha])();  
    } else {
        cout << "Número inválido!" << endl;
    }

    return 0;
}
