// 33. Escreva uma classe para armazenar dados de um estacionamento.
// Ela deve ser capaz de armazenar o número da chapa do carro, a marca, a hora de entrada e a hora de saída do estacionamento. Utilize dois membros da classe Tempo, definida no exercício anterior, para as horas de entrada e saída.
// a) Crie um construtor que inicialize os membros de dados com zero.
// b) Crie um segundo construtor que inicialize os membros de dados com os valores recebidos como argumento.
// c) Crie um método para imprimir os dados de um carro.
// d) Considere que o estacionamento cobre R$ 1,00 a hora. Escreva um método que retorne o valor cobrado. Utilize a função, da classe Tempo, que subtrai duas horas.
// e) Escreva um programa que crie uma matriz de cinco objetos da classe anterior, solicite os dados dos carros para o usuário e imprima um relatório dos dados e do valor cobrado.


#include <iostream>
#include <iomanip>
#include <cmath>    // Para usar std::abs na subtração de tempos
#include <string>

using namespace std;

class Tempo {
private:
    int hora, mins, segs;

public:
    Tempo() : hora(0), mins(0), segs(0) {}

    Tempo(int h, int m, int s) : hora(h), mins(m), segs(s) {}

    void init(int h, int m, int s) {
        hora = h;
        mins = m;
        segs = s;
    }

    void imprimir() const {
        cout << setw(2) << setfill('0') << hora << ":"
             << setw(2) << setfill('0') << mins << ":"
             << setw(2) << setfill('0') << segs << endl;
    }

    void Soma(const Tempo &t1, const Tempo &t2) {
        int totalSegundos = (t1.hora * 3600 + t1.mins * 60 + t1.segs) +
                            (t2.hora * 3600 + t2.mins * 60 + t2.segs);

        hora = totalSegundos / 3600;
        totalSegundos %= 3600;
        mins = totalSegundos / 60;
        segs = totalSegundos % 60;
    }

    Tempo Soma(const Tempo &t) const {
        int totalSegundos = (hora * 3600 + mins * 60 + segs) +
                            (t.hora * 3600 + t.mins * 60 + t.segs);

        int h = totalSegundos / 3600;
        totalSegundos %= 3600;
        int m = totalSegundos / 60;
        int s = totalSegundos % 60;

        return Tempo(h, m, s);
    }

    static int Subtrair(const Tempo &t1, const Tempo &t2) {
        int totalSegundos1 = t1.hora * 3600 + t1.mins * 60 + t1.segs;
        int totalSegundos2 = t2.hora * 3600 + t2.mins * 60 + t2.segs;

        return std::abs(totalSegundos1 - totalSegundos2);
    }
};

class Estacionamento {
private:
    string numero;
    string marca;
    Tempo entrada;
    Tempo saida;

public:
    // a)
    Estacionamento() {
        numero = "";
        marca = "";
        entrada.init(0, 0, 0);
        saida.init(0, 0, 0);
    }

    // b)
    Estacionamento(string n, string m, Tempo ent, Tempo sai) {
        numero = n;
        marca = m;
        entrada = ent;
        saida = sai;
    }

    // Destrutor vazio (não necessário, mas deixei definido)
    ~Estacionamento() {}

    // c)
    void imprimirDados() {
        cout << "Número do carro: " << numero << endl;
        cout << "Marca do carro: " << marca << endl;
        cout << "Entrada: ";
        entrada.imprimir();
        cout << "Saída: ";
        saida.imprimir();
    }

    // d)
    float calcularValor() {
        int segundos = Tempo::Subtrair(saida, entrada);
        int horas = segundos / 3600;
        return static_cast<float>(horas);
    }
};

int main() {
    Estacionamento carros[5];

    for (int i = 0; i < 5; i++) {
        string numero, marca;
        int entradaH, entradaM, entradaS;
        int saidaH, saidaM, saidaS;

        cout << "\nInforme os dados do carro " << i + 1 << ":\n";
        cout << "Número do carro: ";
        cin >> numero;
        cout << "Marca do carro: ";
        cin >> marca;
        cout << "Hora de entrada (h m s): ";
        cin >> entradaH >> entradaM >> entradaS;
        cout << "Hora de saída (h m s): ";
        cin >> saidaH >> saidaM >> saidaS;

        Tempo entrada(entradaH, entradaM, entradaS);
        Tempo saida(saidaH, saidaM, saidaS);

        carros[i] = Estacionamento(numero, marca, entrada, saida);
    }

    cout << "\n=== Relatório de Estacionamento ===\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nCarro " << i + 1 << ":\n";
        carros[i].imprimirDados();
        cout << fixed << setprecision(2);
        cout << "Valor do carro: R$ " << carros[i].calcularValor() << endl;
    }

    return 0;
}
