// 39.Crie uma estrutura para descrever restaurantes. Os membros devem armazenar o nome, o
// endereço, o preço médio e o tipo de comida. Crie uma lista ligada que apresente os restau-
// rantes de um certo tipo de comida indexados pelo preço. O menor preço deve ser o primeiro
// da lista. Escreva um programa que peça o tipo de comida para o usuário e imprima os restau-
// rantes que oferecem esse tipo de comida.


#include <iostream>
#include <string>
using namespace std;

struct Restaurante
{
    string nome;
    string endereco;
    double precoMedio;
    string tipoComida;
    Restaurante *proximo;
};

class ListaRestaurantes
{
private:
    Restaurante *inicio;

public:
    ListaRestaurantes() : inicio(nullptr) {}

    // Função para adicionar um restaurante na lista, mantendo a lista ordenada por preço médio
    void adicionarRestaurante(const string& nome, const string& endereco, double precoMedio, const string& tipoComida)
    {
        Restaurante *novoRestaurante = new Restaurante{nome, endereco, precoMedio, tipoComida, nullptr};

        // Se a lista estiver vazia ou o preço do novo restaurante for menor que o primeiro
        if (!inicio || precoMedio < inicio->precoMedio)
        {
            novoRestaurante->proximo = inicio;
            inicio = novoRestaurante;
        }
        else
        {
            // Percorre a lista para encontrar a posição correta para inserir
            Restaurante *atual = inicio;
            while (atual->proximo && atual->proximo->precoMedio < precoMedio)
            {
                atual = atual->proximo;
            }

            novoRestaurante->proximo = atual->proximo;
            atual->proximo = novoRestaurante;
        }
    }

    // Função para imprimir os restaurantes de um determinado tipo de comida
    void imprimirRestaurantesPorTipo(const string& tipoComida)
    {
        Restaurante *atual = inicio;
        bool encontrou = false;

        while (atual)
        {
            if (atual->tipoComida == tipoComida)
            {
                cout << "Nome: " << atual->nome << endl;
                cout << "Endereco: " << atual->endereco << endl;
                cout << "Preco Medio: R$ " << atual->precoMedio << endl;
                cout << "Tipo de Comida: " << atual->tipoComida << endl;
                cout << "----------------------------------" << endl;
                encontrou = true;
            }
            atual = atual->proximo;
        }

        if (!encontrou)
        {
            cout << "Nenhum restaurante encontrado para o tipo de comida " << tipoComida << "." << endl;
        }
    }

    // Destrutor para liberar a memória
    ~ListaRestaurantes()
    {
        Restaurante *atual = inicio;
        while (atual)
        {
            Restaurante *temp = atual;
            atual = atual->proximo;
            delete temp;
        }
    }
};

int main()
{
    ListaRestaurantes lista;

    // Adicionando alguns restaurantes à lista
    lista.adicionarRestaurante("Sushi Bar", "Rua dos Sushis, 100", 50.0, "Japonesa");
    lista.adicionarRestaurante("Pizzaria Bella", "Avenida das Pizzas, 250", 40.0, "Italiana");
    lista.adicionarRestaurante("Temakeria Samurai", "Rua do Temaki, 75", 30.0, "Japonesa");
    lista.adicionarRestaurante("Cantinho do Pastel", "Rua do Pastel, 120", 10.0, "Brasileira");
    lista.adicionarRestaurante("La Trattoria", "Avenida da Trattoria, 350", 60.0, "Italiana");

    // Solicitando o tipo de comida ao usuário
    string tipoComida;
    cout << "Digite o tipo de comida que você deseja: ";
    getline(cin, tipoComida);

    // Imprimindo os restaurantes que oferecem o tipo de comida solicitado
    cout << "\nRestaurantes que oferecem " << tipoComida << ":\n";
    lista.imprimirRestaurantesPorTipo(tipoComida);

    return 0;
}
