// 32.Crie a classe Caminhao derivada das classes Motor e Veiculo. Inclua os atributos Toneladas (carga máxima), AlturaMax (int) e Comprimento (int).- Adicione um construtor sem argumentos que inicialize os dados com zeros.
// Adicione outro construtor que inicialize os dados com os valores recebidos como argumentos.
// Acrescente duas funções:- Uma para entrada de dados chamada Get().
// Outra que imprima os dados chamada Print().



#include <iostream>
using namespace std;

// Classe Motor
class Motor {
protected:
    int numCilindros;
    int potencia;

public:
    Motor() : numCilindros(0), potencia(0) {}

    Motor(int cilindros, int pot) : numCilindros(cilindros), potencia(pot) {}

    void Get() {
        cout << "Digite o numero de cilindros: ";
        cin >> numCilindros;
        cout << "Digite a potencia (CV): ";
        cin >> potencia;
    }

    void Print() const {
        cout << "--- Motor ---" << endl;
        cout << "Cilindros: " << numCilindros << endl;
        cout << "Potencia: " << potencia << " CV" << endl;
    }
};

// Classe Veiculo
class Veiculo {
protected:
    int peso;
    int velMax;
    float preco;

public:
    Veiculo() : peso(0), velMax(0), preco(0.0f) {}

    Veiculo(int p, int v, float pr) : peso(p), velMax(v), preco(pr) {}

    void Get() {
        cout << "Digite o peso (kg): ";
        cin >> peso;
        cout << "Digite a velocidade maxima (km/h): ";
        cin >> velMax;
        cout << "Digite o preco (US$): ";
        cin >> preco;
    }

    void Print() const {
        cout << "--- Veiculo ---" << endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "Velocidade Maxima: " << velMax << " km/h" << endl;
        cout << "Preco: US$ " << preco << endl;
    }
};

// Classe Caminhao
class Caminhao : public Motor, public Veiculo {
private:
    float toneladas;
    int alturaMax;
    int comprimento;

public:
    // Construtor sem argumentos
    Caminhao()
        : Motor(), Veiculo(), toneladas(0.0f), alturaMax(0), comprimento(0) {}

    // Construtor com argumentos
    Caminhao(int cilindros, int pot, int p, int v, float pr,
             float ton, int alt, int comp)
        : Motor(cilindros, pot), Veiculo(p, v, pr),
          toneladas(ton), alturaMax(alt), comprimento(comp) {}

    // Entrada de dados
    void Get() {
        cout << "=== Dados do Caminhao ===" << endl;
        Motor::Get();
        Veiculo::Get();
        cout << "Digite a carga maxima (toneladas): ";
        cin >> toneladas;
        cout << "Digite a altura maxima (cm): ";
        cin >> alturaMax;
        cout << "Digite o comprimento (cm): ";
        cin >> comprimento;
    }

    // Impressão dos dados
    void Print() const {
        cout << "\n=== Informacoes do Caminhao ===" << endl;
        Motor::Print();
        Veiculo::Print();
        cout << "--- Dimensoes e Carga ---" << endl;
        cout << "Carga Maxima: " << toneladas << " toneladas" << endl;
        cout << "Altura Maxima: " << alturaMax << " cm" << endl;
        cout << "Comprimento: " << comprimento << " cm" << endl;
    }
};

// Programa de teste
int main() {
    Caminhao cam;
    cam.Get();
    cam.Print();
    return 0;
}
