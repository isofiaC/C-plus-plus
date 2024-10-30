#include "Propriedade.h"
using namespace std;

Propriedade::Propriedade(int valor) : valor(valor){}

int Propriedade::getValor() {
    return valor;
}

void Propriedade::setValor(int valor) {
    this->valor = valor;
}