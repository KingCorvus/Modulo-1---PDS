#include "QuadroAlocacao.hpp"

void QuadroAlocacao::inserir_alocacao(std::string codigo, std::string nome, std::string dia, std::string horario, std::string sala){
    Disciplina* aux = new Disciplina;
    aux->nome = nome; aux->codigo;
    aux->inserir_alocacao(dia, horario, sala);
    
    quadroAlocacao.insert(std::pair<std::string, Disciplina*> (codigo, aux));
    delete aux;
}

/*void QuadroAlocacao::ordenarMap_QuadroAlocacao(){
    //cria um vetor vazio de pares
    std::vector<pair> vect;
    //copia os valores da alocacao para o vetor 
    //copia do inicio ao fim de alocacao para vector
    std::copy(quadroAlocacao.begin(), quadroAlocacao.end(), std::back_inserter<std::vector<pair>>(vect));
    //ordena
    std::sort(vect.begin(),vect.end(), [](const pair &esq, const pair &dir){
        if(esq.second != dir.second){
            return esq.second < dir.second;
        }
        return esq.first < dir.first;
    });
}*/
//Map ordena seus elementos pela chave

void QuadroAlocacao::remover_alocacao_disciplina(std::string codigo, std::string horario){
    std::map<std::string, Disciplina*>::iterator it;
    Disciplina* aux = new Disciplina;
    
    it = quadroAlocacao.find(codigo);
    aux = quadroAlocacao.find(codigo)->second;    
    
    aux->remover_alocacao(horario);
    quadroAlocacao.erase(it);
    
    delete aux;
}

void QuadroAlocacao::recuperar_disciplinas_mais_ofertadas(){
    std::string* aux = new std::string;
    aux = quadroAlocacao.
}
