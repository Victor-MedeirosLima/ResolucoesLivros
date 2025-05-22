// 21.Escreva a classe Veiculo contendo Peso em quilos (int), VelocMax em km/h (int) e Preco em USS (float).
// Inclua um construtor sem argumentos que inicialize os dados com zeros e um construtor que inicialize os dados com os valores recebidos como argumento.
// Acrescente um método de entrada de dados Get() e um segundo método que imprima os dados Print().

// Em seguida, crie a classe CarroPasseio usando a classe Veiculo como base. Inclua Cor (string) e Modelo (string).
// Inclua um construtor sem argumentos que inicialize os dados com zeros e um construtor que inicialize os dados com os valores recebidos como argumento.
// Acrescente um método para entrada de dados Get() e um segundo método que imprima os dados Print().

// Agora, crie a classe Caminhao derivada da classe Veiculo. Inclua Toneladas (carga máxima), 
// AlturaMax (int) e Comprimento (int). Inclua um construtor sem argumentos que 
// inicialize os dados com zeros e um construtor que inicialize os dados com os valores recebidos 
// como argumento. Acrescente um método para a entrada de dados Get() e um segundo método que imprima os dados Print().

// Faça um programa que declare uma matriz de ponteiros do tipo Veiculo. Inclua um laço que 
// pergunte ao usuário sobre o tipo de veículo a ser cadastrado e use o operador new para criar
// os objetos conforme o tipo escolhido (CarroPasseio ou Caminhao). Quando o usuário terminar 
// entrada dos dados de todos os veículos, imprima os resultados por meio de outro laço.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Classe base Veiculo
class Veiculo {
protected:
    int peso;
    int velMax;
    float preco;

public:
    Veiculo() : peso(0), velMax(0), preco(0.0f) {}

    Veiculo(int p, int v, float pr) : peso(p), velMax(v), preco(pr) {}

    virtual void Get() {
        cout << "Peso (kg): "; cin >> peso;
        cout << "Velocidade Maxima (km/h): "; cin >> velMax;
        cout << "Preco (US$): "; cin >> preco;
    }

    virtual void Print() const {
        cout << "Peso: " << peso << " kg\n";
        cout << "Velocidade Maxima: " << velMax << " km/h\n";
        cout << "Preco: $" << preco << "\n";
    }

    virtual ~Veiculo() {} // destrutor virtual
};

// Classe derivada CarroPasseio
class CarroPasseio : public Veiculo {
private:
    string cor;
    string modelo;

public:
    CarroPasseio() : Veiculo(), cor(""), modelo("") {}

    CarroPasseio(int p, int v, float pr, string c, string m)
        : Veiculo(p, v, pr), cor(c), modelo(m) {}

    void Get() override {
        Veiculo::Get();
        cout << "Cor: "; cin >> cor;
        cout << "Modelo: "; cin.ignore(); getline(cin, modelo);
    }

    void Print() const override {
        Veiculo::Print();
        cout << "Cor: " << cor << "\n";
        cout << "Modelo: " << modelo << "\n";
    }
};

// Classe derivada Caminhao
class Caminhao : public Veiculo {
private:
    int toneladas;
    int alturaMax;
    int comprimento;

public:
    Caminhao() : Veiculo(), toneladas(0), alturaMax(0), comprimento(0) {}

    Caminhao(int p, int v, float pr, int t, int a, int c)
        : Veiculo(p, v, pr), toneladas(t), alturaMax(a), comprimento(c) {}

    void Get() override {
        Veiculo::Get();
        cout << "Toneladas (Carga Max): "; cin >> toneladas;
        cout << "Altura Max (m): "; cin >> alturaMax;
        cout << "Comprimento (m): "; cin >> comprimento;
    }

    void Print() const override {
        Veiculo::Print();
        cout << "Carga Maxima: " << toneladas << " toneladas\n";
        cout << "Altura Maxima: " << alturaMax << " m\n";
        cout << "Comprimento: " << comprimento << " m\n";
    }
};

// Função principal
int main() {
    vector<Veiculo*> veiculos;
    int opcao;

    while (true) {
        cout << "\nCadastrar Veiculo:\n";
        cout << "1 - Carro de Passeio\n";
        cout << "2 - Caminhao\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 0) break;

        Veiculo* v = nullptr;

        switch (opcao) {
            case 1:
                v = new CarroPasseio();
                break;
            case 2:
                v = new Caminhao();
                break;
            default:
                cout << "Opcao invalida.\n";
                continue;
        }

        v->Get();
        veiculos.push_back(v);
    }

    cout << "\n--- Dados dos Veiculos Cadastrados ---\n";

    for (size_t i = 0; i < veiculos.size(); ++i) {
        cout << "\nVeiculo #" << i + 1 << ":\n";
        veiculos[i]->Print();
    }

    // Liberar memória
    for (Veiculo* v : veiculos) {
        delete v;
    }

    return 0;
}




