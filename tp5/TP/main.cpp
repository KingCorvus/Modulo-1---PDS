#include <iostream>
#include "Processo.hpp"
#include "ListaProcessos.hpp"
#include "avaliacao_basica_escalonador.hpp"

int main() {
    ListaProcessos Lista;

    char data;
    while (std::cin >> data) {
        switch (data) {
            // Insere processo
            case 'a':
            {
                int id; std::string nome; int prioridade;
                std::cin >> id >> nome >> prioridade;
                
                Lista.adicionar_processo(new Processo(id,nome,prioridade));
            break;
            }
            // Remove maior prioridade
            case 'm': 
            {
                Lista.remover_processo_maior_prioridade();
            break;
            }
            // Remove menor prioridade
            case 'n': 
            {                 
                Lista.remover_processo_menor_prioridade(); 
            break;
            }
            // Remove por id
            case 'r':
            {                  
                int id;
                std::cin >> id;
                Lista.remover_processo_por_id(id);    
            break;
            }
            // Imprime lista
            case 'p':
            {                  
                Lista.imprimir_lista();
            break;
            }
            case 'b':
            {
                avaliacao_basica();
            break;
            }
        }
    }
    return 0;
}