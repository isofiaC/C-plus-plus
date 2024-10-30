#include "Vibracao.h"

Vibracao::Vibracao(int valor): Propriedade(valor){}

string Vibracao::actualizaValor(int valor) {
    if (valor < minValor) {
        return "Valor deve ser maior que " + std::to_string(minValor) + ".";
    }
    this->setValor(valor);
    return "OK";
}

void Vibracao::modificaValor(int valor) {
    int novoValor = this->getValor() + valor;

    if(novoValor < minValor){
        this->setValor(minValor);
    }
    else{
        this->setValor(novoValor);
    }
}