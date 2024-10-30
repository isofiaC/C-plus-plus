#include "Som.h"

Som::Som(int valor): Propriedade(valor){}

string Som::actualizaValor(int valor) {
    if (valor < minValor) {
        return "Valor deve ser maior que " + std::to_string(minValor) + ".";
    }
    this->setValor(valor);
    return "OK";
}

void Som::modificaValor(int valor) {
    int novoValor = this->getValor()+ valor;

    if(novoValor < minValor){
        this->setValor(minValor);
    }
    else{
        this->setValor(novoValor);
    }
}
