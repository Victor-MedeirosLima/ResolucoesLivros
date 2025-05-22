// 06. Defina uma classe para ser usada como classe de exceção. A classe deve ser capaz de armazenar o número do erro e a descrição do erro. Inclua um construtor


#include <iostream>
#include <string>
using namespace std;

// Classe de exceção personalizada
class ErroPersonalizado {
    int codigo;
    string descricao;

public:
    // Construtor
    ErroPersonalizado(int cod, const string& desc)
        : codigo(cod), descricao(desc) {}

    // Métodos para acessar os dados
    int getCodigo() const {
        return codigo;
    }

    string getDescricao() const {
        return descricao;
    }
};

// Exemplo de uso
int main() {
    try {
        // Simulando um erro
        throw ErroPersonalizado(404, "Recurso não encontrado");
    }
    catch (const ErroPersonalizado& erro) {
        cout << "Erro capturado!" << endl;
        cout << "Código: " << erro.getCodigo() << endl;
        cout << "Descrição: " << erro.getDescricao() << endl;
    }

    return 0;
}
