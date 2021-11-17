#include "Disciplina.hpp"
Disciplina::Disciplina(std::string codigo, std::string nome){
    this->codigo = codigo;  this->nome = nome;
}

Disciplina::Disciplina(){
}

void Disciplina::inserir_alocacao(std::string dia, std::string horario, std::string sala){
    Alocacao* aux = new Alocacao;
    aux->dia = dia; aux->horario = horario;aux->sala;

    alocacao.insert(std::pair<std::string, Alocacao*> (horario, aux));
    delete aux;
}

/*void Disciplina::ordenarMap_alocacao(){
    //cria um vetor vazio de pares
    std::vector<pair> vect;
    //copia os valores da alocacao para o vetor 
    //copia do inicio ao fim de alocacao para vector
    std::copy(alocacao.begin(), alocacao.end(), std::back_inserter<std::vector<pair>>(vect));
    //ordena
    std::sort(vect.begin(),vect.end(), [](const pair &esq, const pair &dir){
        if(esq.second != dir.second){
            return esq.second < dir.second;
        }
        return esq.first < dir.first;
    });
}*/
//Map já entrega a lista ordenada pela chave

void Disciplina::remover_alocacao(std::string horario){
    std::map<std::string, Alocacao*>::iterator it;
    it = alocacao.find(horario);
    alocacao.erase(it);
}

void Disciplina::imprimir_alocacao(){
    std::map<std::string, Alocacao*>::iterator it;
    it = alocacao.begin();
    Alocacao* aux = new Alocacao;
    while (it != alocacao.end()){
        aux = it->second;
        std::cout << this->codigo << " " << this->nome << " " ;
        aux->imprimir_dados();
        it++;
    }
    delete aux;
}

