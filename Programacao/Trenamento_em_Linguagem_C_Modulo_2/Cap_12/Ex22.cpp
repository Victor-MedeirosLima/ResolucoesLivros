// 22. Inclua na classe String:

// Sobrecargas do operador + binário:

// a) soma dois objetos String;

// b) soma uma cadeia de caracteres a um objeto String;

// c) soma um objeto String a uma cadeia de caracteres.

// Sobrecargas do operador == relacional:

// a) compara dois objetos String;

// b) compara um objeto String com uma cadeia de caracteres;

// c) compara uma cadeia de caracteres com um objeto String.

// Sobrecargas do operador != relacional:

// a) compara dois objetos String;

// b) compara um objeto String com uma cadeia de caracteres;

// c) compara uma cadeia de caracteres com um objeto String.

// Sobrecarrega o operador < relacional:

// a) compara dois objetos String;

// b) compara um objeto String com uma cadeia de caracteres;

// c) compara uma cadeia de caracteres com um objeto String.

// Sobrecargas do operador >= relacional:

// a) compara dois objetos String;

// b) compara um objeto String com uma cadeia de caracteres;

// c) compara uma cadeia de caracteres com um objeto String.


#include <iostream>
#include <cstring>

class String {
private:
    char* str;

public:
    // Construtores
    String() {
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Destrutor
    ~String() {
        delete[] str;
    }

    // Operador de atribuição
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Getter para uso interno
    const char* c_str() const {
        return str;
    }

    // ---------- Operador + (concatenação) ----------
    
    // a) soma dois objetos String
    String operator+(const String& other) const {
        char* temp = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        String result(temp);
        delete[] temp;
        return result;
    }

    // b) soma uma cadeia de caracteres a um objeto String
    String operator+(const char* s) const {
        char* temp = new char[strlen(str) + strlen(s) + 1];
        strcpy(temp, str);
        strcat(temp, s);
        String result(temp);
        delete[] temp;
        return result;
    }

    // c) soma um objeto String a uma cadeia de caracteres (função amiga)
    friend String operator+(const char* s, const String& obj) {
        char* temp = new char[strlen(s) + strlen(obj.str) + 1];
        strcpy(temp, s);
        strcat(temp, obj.str);
        String result(temp);
        delete[] temp;
        return result;
    }

    // ---------- Operador == (igualdade) ----------

    // a) compara dois objetos String
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    // b) compara um objeto String com uma cadeia de caracteres
    bool operator==(const char* s) const {
        return strcmp(str, s) == 0;
    }

    // c) compara uma cadeia de caracteres com um objeto String
    friend bool operator==(const char* s, const String& obj) {
        return strcmp(s, obj.str) == 0;
    }

    // ---------- Operador != (diferente) ----------

    // a) compara dois objetos String
    bool operator!=(const String& other) const {
        return strcmp(str, other.str) != 0;
    }

    // b) compara um objeto String com uma cadeia de caracteres
    bool operator!=(const char* s) const {
        return strcmp(str, s) != 0;
    }

    // c) compara uma cadeia de caracteres com um objeto String
    friend bool operator!=(const char* s, const String& obj) {
        return strcmp(s, obj.str) != 0;
    }

    // ---------- Operador < (menor) ----------

    // a) compara dois objetos String
    bool operator<(const String& other) const {
        return strcmp(str, other.str) < 0;
    }

    // b) compara um objeto String com uma cadeia de caracteres
    bool operator<(const char* s) const {
        return strcmp(str, s) < 0;
    }

    // c) compara uma cadeia de caracteres com um objeto String
    friend bool operator<(const char* s, const String& obj) {
        return strcmp(s, obj.str) < 0;
    }

    // ---------- Operador >= (maior ou igual) ----------

    // a) compara dois objetos String
    bool operator>=(const String& other) const {
        return strcmp(str, other.str) >= 0;
    }

    // b) compara um objeto String com uma cadeia de caracteres
    bool operator>=(const char* s) const {
        return strcmp(str, s) >= 0;
    }

    // c) compara uma cadeia de caracteres com um objeto String
    friend bool operator>=(const char* s, const String& obj) {
        return strcmp(s, obj.str) >= 0;
    }

    // ---------- Operador << para impressão ----------
    friend std::ostream& operator<<(std::ostream& os, const String& obj) {
        os << obj.str;
        return os;
    }
};


int main() {
    String a("C++");
    String b(" é bom");
    String c = a + b;
    String d = "Muito " + c;

    std::cout << d << "\n"; // Resultado: Muito C++ é bom

    if (d == "Muito C++ é bom") {
        std::cout << "Strings iguais!\n";
    }

    if ("ABC" < a) {
        std::cout << "\"ABC\" vem antes de \"" << a << "\"\n";
    }

    return 0;
}

