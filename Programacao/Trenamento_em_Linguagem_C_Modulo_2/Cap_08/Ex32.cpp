// 32. Escreva uma classe para conter três membros de dados do tipo int denominados hora, mins e segs e chame-a de Tempo.
// a) Crie um construtor que inicialize os membros de dados com zero.
// b) Crie um segundo construtor que inicialize os membros de dados com os valores recebidos como argumento.
// c) Crie um método init() que executa a mesma tarefa do construtor do item b.
// d) Crie um método para imprimir a hora no formato hh:mm:ss.
// e) Crie um método Soma() que soma dois objetos da classe Tempo passados como argumentos e coloca o resultado no objeto do qual ele é membro.
// f) Crie uma sobrecarga do método Soma() que soma o objeto que recebe como argumento com o objeto do qual é membro e retorna um novo objeto com o total.
// g) Crie um método que subtraia duas horas e retorne o número de segundos entre elas. A função recebe dois objetos da classe Tempo passados como argumentos.



#include <iostream>
#include <iomanip>
#include <cmath> // Para usar std::abs na subtração de tempos

class Tempo {
private:
    int hora, mins, segs;

public:
    // a) Construtor que inicializa os membros de dados com zero
    Tempo() : hora(0), mins(0), segs(0) {}

    // b) Construtor que inicializa os membros com valores recebidos como argumento
    Tempo(int h, int m, int s) : hora(h), mins(m), segs(s) {}

    // c) Método init() que executa a mesma tarefa do construtor do item b
    void init(int h, int m, int s) {
        hora = h;
        mins = m;
        segs = s;
    }

    // d) Método para imprimir a hora no formato hh:mm:ss
    void imprimir() const {
        std::cout << std::setw(2) << std::setfill('0') << hora << ":"
                  << std::setw(2) << std::setfill('0') << mins << ":"
                  << std::setw(2) << std::setfill('0') << segs << std::endl;
    }

    // e) Método Soma() que soma dois objetos e coloca o resultado no objeto do qual é membro
    void Soma(const Tempo &t1, const Tempo &t2) {
        int totalSegundos = (t1.hora * 3600 + t1.mins * 60 + t1.segs) +
                            (t2.hora * 3600 + t2.mins * 60 + t2.segs);

        hora = totalSegundos / 3600;
        totalSegundos %= 3600;
        mins = totalSegundos / 60;
        segs = totalSegundos % 60;
    }

    // f) Método Soma() sobrecarregado que soma o objeto atual com outro objeto e retorna um novo objeto
    Tempo Soma(const Tempo &t) const {
        int totalSegundos = (hora * 3600 + mins * 60 + segs) +
                            (t.hora * 3600 + t.mins * 60 + t.segs);

        int h = totalSegundos / 3600;
        totalSegundos %= 3600;
        int m = totalSegundos / 60;
        int s = totalSegundos % 60;

        return Tempo(h, m, s);
    }

    // g) Método para subtrair duas horas e retornar o número de segundos entre elas
    static int Subtrair(const Tempo &t1, const Tempo &t2) {
        int totalSegundos1 = t1.hora * 3600 + t1.mins * 60 + t1.segs;
        int totalSegundos2 = t2.hora * 3600 + t2.mins * 60 + t2.segs;

        return std::abs(totalSegundos1 - totalSegundos2); // Valor absoluto da diferença
    }
};

int main() {
    // Testando os métodos
    Tempo t1; // Inicializado com zero
    Tempo t2(2, 30, 45); // Inicializado com valores específicos

    std::cout << "Tempo 1: ";
    t1.imprimir();

    std::cout << "Tempo 2: ";
    t2.imprimir();

    // c) Inicializando t1 com novos valores usando init()
    t1.init(1, 15, 30);
    std::cout << "Tempo 1 após init(): ";
    t1.imprimir();

    // e) Soma de t1 e t2, resultado armazenado em t3
    Tempo t3;
    t3.Soma(t1, t2);
    std::cout << "Soma de Tempo 1 e Tempo 2: ";
    t3.imprimir();

    // f) Soma de t1 com t2, retornando um novo objeto t4
    Tempo t4 = t1.Soma(t2);
    std::cout << "Soma de Tempo 1 e Tempo 2 (nova instância): ";
    t4.imprimir();

    // g) Subtraindo t1 e t2
    int diferenca = Tempo::Subtrair(t1, t2);
    std::cout << "Diferença em segundos entre Tempo 1 e Tempo 2: " << diferenca << " segundos" << std::endl;

    return 0;
}