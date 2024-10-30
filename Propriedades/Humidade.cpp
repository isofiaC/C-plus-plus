#include "Humidade.h"

Humidade::Humidade(int valor) : Propriedade(valor) {}

string Humidade::actualizaValor(int valor) {
    if (valor < minValor || valor > maxValor) {
        return "Valor deve estar entre " + std::to_string(minValor) + " e " + std::to_string(maxValor) + ".";
    }
    this->setValor(valor);
    return "OK";
}

void Humidade::modificaValor(int valor) {
    int novoValor = this->getValor() + valor;

    if(novoValor < minValor) {
        this->setValor(minValor);
    }
    else if (novoValor > maxValor) {
        this->setValor(maxValor);
    }
    else {
        this->setValor(novoValor);
    }
}