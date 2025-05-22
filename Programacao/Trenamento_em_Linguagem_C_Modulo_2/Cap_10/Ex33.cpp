// 33.Crie um programa para testar as classes dos exercícios 29, 30, 31 e 32.

#include <iostream>
#include <string>
using namespace std;

//CLASSE MOTOR
class Motor {
protected:
    int numCilindros;
    int potencia;

public:
    Motor() : numCilindros(0), potencia(0) {}
    Motor(int cilindros, int pot) : numCilindros(cilindros), potencia(pot) {}

    void Get() {
        cout << "Numero de cilindros: ";
        cin >> numCilindros;
        cout << "Potencia (CV): ";
        cin >> potencia;
    }

    void Print() const {
        cout << "Motor: " << numCilindros << " cilindros, " << potencia << " CV" << endl;
    }
};

//CLASSE VEICULO
class Veiculo {
protected:
    int peso;
    int velMax;
    float preco;

public:
    Veiculo() : peso(0), velMax(0), preco(0.0f) {}
    Veiculo(int p, int v, float pr) : peso(p), velMax(v), preco(pr) {}

    void Get() {
        cout << "Peso (kg): ";
        cin >> peso;
        cout << "Velocidade maxima (km/h): ";
        cin >> velMax;
        cout << "Preco (US$): ";
        cin >> preco;
    }

    void Print() const {
        cout << "Veiculo: " << peso << " kg, " << velMax << " km/h, US$ " << preco << endl;
    }
};

//CLASSE CARROPASSEIO
class CarroPasseio {
private:
    Motor motor;
    Veiculo veiculo;
    string cor;
    string modelo;

public:
    CarroPasseio() : motor(), veiculo(), cor(""), modelo("") {}

    CarroPasseio(int cilindros, int pot, int peso, int velMax, float preco,
                 const string& c, const string& m)
        : motor(cilindros, pot), veiculo(peso, velMax, preco), cor(c), modelo(m) {}

    void Get() {
        cout << "\n== Carro de Passeio ==" << endl;
        motor.Get();
        veiculo.Get();
        cin.ignore(); // limpar buffer
        cout << "Cor: ";
        getline(cin, cor);
        cout << "Modelo: ";
        getline(cin, modelo);
    }

    void Print() const {
        cout << "\n--- Dados do Carro de Passeio ---" << endl;
        motor.Print();
        veiculo.Print();
        cout << "Cor: " << cor << "\nModelo: " << modelo << endl;
    }
};

//CLASSE CAMINHAO
class Caminhao : public Motor, public Veiculo {
private:
    float toneladas;
    int alturaMax;
    int comprimento;

public:
    Caminhao() : Motor(), Veiculo(), toneladas(0), alturaMax(0), comprimento(0) {}

    Caminhao(int cilindros, int pot, int peso, int vel, float preco,
             float ton, int alt, int comp)
        : Motor(cilindros, pot), Veiculo(peso, vel, preco),
          toneladas(ton), alturaMax(alt), comprimento(comp) {}

    void Get() {
        cout << "\n== Caminhao ==" << endl;
        Motor::Get();
        Veiculo::Get();
        cout << "Carga maxima (toneladas): ";
        cin >> toneladas;
        cout << "Altura maxima (cm): ";
        cin >> alturaMax;
        cout << "Comprimento (cm): ";
        cin >> comprimento;
    }

    void Print() const {
        cout << "\n--- Dados do Caminhao ---" << endl;
        Motor::Print();
        Veiculo::Print();
        cout << "Carga Maxima: " << toneladas << " toneladas\n";
        cout << "Altura Maxima: " << alturaMax << " cm\n";
        cout << "Comprimento: " << comprimento << " cm\n";
    }
};

// FUNÇÃO MAIN
int main() {
    cout << "=== Teste das Classes ===" << endl;

    // Teste Motor
    Motor m;
    cout << "\n-- Motor --" << endl;
    m.Get();
    m.Print();

    // Teste Veiculo
    Veiculo v;
    cout << "\n-- Veiculo --" << endl;
    v.Get();
    v.Print();

    // Teste CarroPasseio
    CarroPasseio carro;
    carro.Get();
    carro.Print();

    // Teste Caminhao
    Caminhao caminhao;
    caminhao.Get();
    caminhao.Print();

    return 0;
}
