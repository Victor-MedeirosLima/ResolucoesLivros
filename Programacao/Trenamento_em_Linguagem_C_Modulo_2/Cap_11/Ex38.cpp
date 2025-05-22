// 38. Adicione um destrutor à classe ListaLigada que destrua todos os itens da lista quando um objeto é liberado da memória.


#include <iostream>
#include <cstdio> //para gets()
#include <conio.h> //para getch()
using namespace std;

struct Livro
{
    char Titulo[30];
    char Autor[30];
    int NumReg;
    double Preco;
    Livro *Anterior;
};

class ListaLigada
{
    private:
        Livro *Fim;
    public:
        ListaLigada() //Construtor default
        {
            Fim=(Livro *)NULL;
        }
        void GetLivro();
        void PrintLivro();
        ~ListaLigada(); // Destrutor para liberar memória
};

void ListaLigada::GetLivro()
{
    Livro *NovoLivro = new Livro;
    cout << "\nDigite titulo: ";
    gets(NovoLivro->Titulo);
    cout << "Digite autor: ";
    gets(NovoLivro->Autor);
    cout << "Digite o número de registro: ";
    cin >> NovoLivro->NumReg;
    cout << "Digite o preço: ";
    cin >> NovoLivro->Preco;
    //Limpar teclado após uso de cin
    cin.ignore(10,'\n'); //Limpa teclado
    NovoLivro->Anterior = Fim;
    Fim = NovoLivro;
}

void ListaLigada::PrintLivro()
{
    Livro *Atual = Fim;
    while(Atual != NULL)
    {
        cout << endl;
        cout << "Título: " << Atual->Titulo << endl;
        cout << "Autor: " << Atual->Autor << endl;
        cout << "No.Reg: " << Atual->NumReg << endl;
        cout << "Preço: " << Atual->Preco << endl;
        Atual = Atual->Anterior;
    }
}

ListaLigada::~ListaLigada()
{
    Livro *Atual = Fim, *Anterior;
    while(Atual != NULL)
    {
        Anterior = Atual->Anterior;
        delete Atual;  // Libera memória do livro
        Atual = Anterior;
    }
}

int main()
{
    ListaLigada lista;
    
    // Adicionando livros à lista
    lista.GetLivro();
    lista.GetLivro();
    
    // Imprimindo os livros da lista
    cout << "\nLivros na lista:\n";
    lista.PrintLivro();
    
    // O destrutor será chamado automaticamente quando a lista sair do escopo
    
    return 0;
}
