#include "Temperatura.h"

Temperatura::Temperatura(int valor): Propriedade(valor){}

string Temperatura::actualizaValor(int valor) {
    if (valor < minValor) {
        return "Valor deve ser maior que " + std::to_string(minValor) + ".";
    }
    this->setValor(valor);
    return "OK";
}

void Temperatura::modificaValor(int valor) {
    int novoValor = this->getValor()+ valor;

    if(novoValor < minValor){
        this->setValor(minValor);
    }
    else{
        this->setValor(novoValor);
    }
}

//Temperatura t = new Temperatura(0);
//string err = t.setValor(-300);

//if (err == "OK") {
    //Apresenta sucesso ao utilizador
//} else {
    //Apresenta o erro ao utilizador (err)
//}