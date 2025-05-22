// 14.Escreva uma classe-base denominada Animal e as classes Vaca e Bufalo derivadas desta. Em seguida, escreva a classe Bezerro derivada de Vaca e de Bufalo.

#include <iostream>
using namespace std;

// Classe base
class Animal {
public:
    Animal() {
        cout << "Animal criado." << endl;
    }
    void respirar() {
        cout << "Animal respirando..." << endl;
    }
};

// Classe derivada de Animal
class Vaca : public Animal {
public:
    Vaca() {
        cout << "Vaca criada." << endl;
    }
    void mugir() {
        cout << "Vaca mugindo..." << endl;
    }
};

// Outra classe derivada de Animal
class Bufalo : public Animal {
public:
    Bufalo() {
        cout << "Búfalo criado." << endl;
    }
    void bufar() {
        cout << "Búfalo bufando..." << endl;
    }
};

// Classe derivada de Vaca e Bufalo (herança múltipla)
class Bezerro : public Vaca, public Bufalo {
public:
    Bezerro() {
        cout << "Bezerro criado." << endl;
    }
    void berrar() {
        cout << "Bezerro berrando..." << endl;
    }
};

int main() {
    Bezerro b;

    // Atenção: como Animal é herdado duas vezes (via Vaca e Bufalo), precisamos especificar qual caminho usar:
    b.Vaca::respirar();     // chamada via Vaca
    b.Bufalo::respirar();   // chamada via Bufalo

    b.mugir();
    b.bufar();
    b.berrar();

    return 0;
}
