// 22. Acrescente à classe `Ponto` os operadores: menos unário (`-`), menos binário (`-`), multiplicação
// (`*`), divisão (`/`), módulo (`%`), as operações aritméticas de atribuição (`+=`, `-=`, `*=`, `/=`, `%=`),
//  as operações relacionais (`>`, `>=`, `<`, `<=`, `==`, `!=`) e as operações lógicas (`&&`, `||`, `!`).



#include <iostream>
using namespace std;

class Ponto {
private:
    float x, y;

public:
    Ponto(float x = 0, float y = 0) : x(x), y(y) {}

    // Mostrar ponto
    void exibir() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // Operadores aritmeticos
    Ponto operator+(const Ponto& p) const { return Ponto(x + p.x, y + p.y); }
    Ponto operator-(const Ponto& p) const { return Ponto(x - p.x, y - p.y); }
    Ponto operator*(const Ponto& p) const { return Ponto(x * p.x, y * p.y); }
    Ponto operator/(const Ponto& p) const {
        return Ponto(p.x != 0 ? x / p.x : 0, p.y != 0 ? y / p.y : 0);
    }

    // Menos unario
    Ponto operator-() const { return Ponto(-x, -y); }

    // Operadores de atribuicao
    Ponto& operator+=(const Ponto& p) { x += p.x; y += p.y; return *this; }
    Ponto& operator-=(const Ponto& p) { x -= p.x; y -= p.y; return *this; }
    Ponto& operator*=(const Ponto& p) { x *= p.x; y *= p.y; return *this; }
    Ponto& operator/=(const Ponto& p) {
        if (p.x != 0) x /= p.x;
        if (p.y != 0) y /= p.y;
        return *this;
    }

    // Relacionais
    bool operator==(const Ponto& p) const { return x == p.x && y == p.y; }
    bool operator!=(const Ponto& p) const { return !(*this == p); }
    bool operator<(const Ponto& p) const { return x < p.x && y < p.y; }
    bool operator<=(const Ponto& p) const { return x <= p.x && y <= p.y; }
    bool operator>(const Ponto& p) const { return x > p.x && y > p.y; }
    bool operator>=(const Ponto& p) const { return x >= p.x && y >= p.y; }

    // Logicos
    bool operator&&(const Ponto& p) const { return (x != 0 || y != 0) && (p.x != 0 || p.y != 0); }
    bool operator||(const Ponto& p) const { return (x != 0 || y != 0) || (p.x != 0 || p.y != 0); }
    bool operator!() const { return x == 0 && y == 0; }
};

int main() {
    Ponto a(3, 4), b(1, 2), c;

    cout << "a = "; a.exibir();
    cout << "b = "; b.exibir();

    c = a + b;
    cout << "a + b = "; c.exibir();

    c = a - b;
    cout << "a - b = "; c.exibir();

    c = a * b;
    cout << "a * b = "; c.exibir();

    c = a / b;
    cout << "a / b = "; c.exibir();

    c = -a;
    cout << "-a = "; c.exibir();

    a += b;
    cout << "a += b => a = "; a.exibir();

    cout << "a == b? " << (a == b ? "Sim" : "Nao") << endl;
    cout << "a != b? " << (a != b ? "Sim" : "Nao") << endl;
    cout << "a > b? " << (a > b ? "Sim" : "Nao") << endl;

    cout << "a && b? " << (a && b ? "Verdadeiro" : "Falso") << endl;
    cout << "!c? " << (!c ? "Verdadeiro" : "Falso") << endl;

    return 0;
}
