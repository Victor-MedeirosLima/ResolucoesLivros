// 35. Crie uma classe para descrever restaurantes.
// Os membros devem armazenar o nome, o endereço, o preço médio e o tipo de comida.
// a) Crie um construtor que inicialize os dados com zero.
// b) Crie um segundo construtor que inicialize os membros de dados com os valores recebidos como argumento.
// c) Crie um método init() que executa a mesma tarefa do construtor do item b.
// d) Crie um método para imprimir os dados de um restaurante.
// e) Escreva um programa que crie uma matriz de objetos restaurante e solicite a entrada dos dados pelo usuário. Em seguida, o programa pergunta o tipo de comida ao usuário e lista todos os restaurantes que oferecem aquele tipo de comida.


#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

class Restaurante {
private:
    string nome, endereco, tipoComida;
    float precoMedio;

public:
    // a) Construtor padrão
    Restaurante() {
        nome = "";
        endereco = "";
        tipoComida = "";
        precoMedio = 0.0;
    }

    // b) Construtor com parâmetros
    Restaurante(string n, string e, string tipo, float preco) {
        nome = n;
        endereco = e;
        tipoComida = tipo;
        precoMedio = preco;
    }

    // c) Método init
    void init(string n, string e, string tipo, float preco) {
        nome = n;
        endereco = e;
        tipoComida = tipo;
        precoMedio = preco;
    }

    // d) Imprimir os dados
    void imprimirDados() {
        cout << "Nome: " << nome << endl;
        cout << "Endereço: " << endereco << endl;
        cout << "Tipo de comida: " << tipoComida << endl;
        cout << "Preço médio: R$ " << precoMedio << endl;
    }

    string getTipoComida() {
        return tipoComida;
    }
};

int main() {
    const int linhas = 2;
    const int colunas = 2;
    Restaurante matriz[linhas][colunas];

    cout << "Cadastro de Restaurantes" << endl;

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            string nome, endereco, tipo;
            float preco;

            cout << "\nRestaurante [" << i << "][" << j << "]" << endl;
            cout << "Nome: ";
            getline(cin, nome);
            cout << "Endereço: ";
            getline(cin, endereco);
            cout << "Tipo de comida: ";
            getline(cin, tipo);
            cout << "Preço médio: ";
            cin >> preco;
            cin.ignore(); // Limpar o buffer

            matriz[i][j].init(nome, endereco, tipo, preco);
        }
    }

    string tipoBusca;
    cout << "\nDigite o tipo de comida que deseja buscar: ";
    getline(cin, tipoBusca);

    // Padronizar tipoBusca para minúsculas
    transform(tipoBusca.begin(), tipoBusca.end(), tipoBusca.begin(), ::tolower);

    cout << "\nRestaurantes que servem \"" << tipoBusca << "\"\n";

    bool encontrou = false;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            string tipo = matriz[i][j].getTipoComida();
            string tipoFormatado = tipo;
            transform(tipoFormatado.begin(), tipoFormatado.end(), tipoFormatado.begin(), ::tolower);

            if (tipoFormatado == tipoBusca) {
                matriz[i][j].imprimirDados();
                cout << "-----------------------------" << endl;
                encontrou = true;
            }
        }
    }

    if (!encontrou) {
        cout << "Nenhum restaurante encontrado com esse tipo de comida." << endl;
    }

    return 0;
}
