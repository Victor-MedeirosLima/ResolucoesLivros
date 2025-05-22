// 36. Escreva uma função que inverta a ordem dos caracteres de uma cadeia de caracteres que ela recebe como argumento. Use ponteiros.  
//    - Exemplo: "Saudações" resulta "seõçaduaS".  

#include <iostream>
#include <cstring> // Para usar a função strlen

void inverterString(char* str) {
    // Encontrar o comprimento da string
    int n = strlen(str);
    
    // Ponteiros para o início e o final da string
    char* inicio = str;
    char* fim = str + n - 1;
    
    // Trocar os caracteres até o meio da string
    while (inicio < fim) {
        // Troca de caracteres
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        
        // Avança os ponteiros
        inicio++;
        fim--;
    }
}

int main() {
    char str[] = "Saudações";
    
    std::cout << "Original: " << str << std::endl;
    
    inverterString(str);
    
    std::cout << "Invertida: " << str << std::endl;
    
    return 0;
}
