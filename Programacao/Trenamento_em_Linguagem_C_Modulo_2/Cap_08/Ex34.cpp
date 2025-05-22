// 34. Escreva uma classe para descrever um mês do ano.
// A classe deve ser capaz de armazenar o nome do mês, a abreviação em três letras, o número de dias e o número do mês.
// a) Crie um construtor que inicialize os membros de dados com o valor 1.
// b) Crie um segundo construtor que inicialize os membros de dados com os valores recebidos como argumento.
// c) Escreva um método que receba o número do mês como argumento e retorne o total de dias do ano até aquele mês.
// d) Escreva uma sobrecarga do método anterior que receba como argumento o nome do mês e retorne o total de dias até aquele mês.


#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

class Mes
{
private:
    string nome,abreviacao;
    int numeroDias, numeroMes;

    // Array com os dias dos meses
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    //a)
    Mes(){

        nome ="";
        abreviacao ="";
        numeroDias = 1;
        numeroMes =1;
    }
    
    //b)
    Mes(string n,string abrev, int dias, int numero){

        nome=n;
        abreviacao=abrev;
        numeroDias = dias;
        numeroMes = numero;

    }

    //c)
    int diasAteMes(int numero) {
        int total = 0;
        for (int i = 0; i < numero - 1 && i < 12; i++) {
            total += diasPorMes[i];
        }
        return total;
    }

    // d) Recebe nome do mês e retorna total de dias até aquele mês
    int diasAteMes(string nomeMes) {
        // Deixa tudo em minúsculo para comparar
        transform(nomeMes.begin(), nomeMes.end(), nomeMes.begin(), ::tolower);
        string nomes[12] = {"janeiro", "fevereiro", "marco", "abril", "maio", "junho",
                            "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

        for (int i = 0; i < 12; i++) {
            string temp = nomes[i];
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            if (nomeMes == temp) {
                return diasAteMes(i + 1);
            }
        }
        return -1; // Mês inválido
    }

    
};


int main(int argc, char const *argv[])
{
    Mes janeiro("Janeiro", "Jan", 31, 1);


    cout << "Dias até Março (por número): " << janeiro.diasAteMes(3) << endl;
    cout << "Dias até Julho (por nome): " << janeiro.diasAteMes("Julho") << endl;
    return 0;
}
