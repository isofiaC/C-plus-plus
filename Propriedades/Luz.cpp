#include "Luz.h"

Luz::Luz(int valor): Propriedade(valor){}

string Luz::actualizaValor(int valor) {
    if (valor < minValor) {
        return "Valor deve ser maior que " + std::to_string(minValor) + ".";
    }
    this->setValor(valor);
    return "OK";
}

void Luz::modificaValor(int valor) {
    int novoValor = this->getValor() + valor;

    if(novoValor < minValor){
        this->setValor(minValor);
    }
    else{
        this->setValor(novoValor);
    }
}