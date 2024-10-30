#include "Processador.h"

ProcessadorRegras::ProcessadorRegras(const string &comando) : comando(comando) {}

void ProcessadorRegras::adicionarRegra(Regra* regra) {
    regras.push_back(regra);
}

void ProcessadorRegras::processarRegras() {
    if (!aparelhos.empty() && !regras.empty()) {
        bool regrasValidas = true;

        for (Regra* regra: regras) {
            if (!regra->verificar()) {
                regrasValidas = false;
            }
        }

        if (regrasValidas) {
           for(Aparelho * aparelho: aparelhos){
               aparelho->executarComando(comando);
           }
        }
    }
}

void ProcessadorRegras::removeRegra(int id) {
    for (int i = 0; i < regras.size(); i++) {
        if (regras[i]->getId() == id) {
            regras.erase(regras.begin() + i);
            break;
        }
    }
}

void ProcessadorRegras::imprimir(term::Window* window) {
    (*window) << "Tipo: P, ID: " << this->getId() << ", Processador, Regras: " << to_string(regras.size()) << "\n";
}

void ProcessadorRegras::imprimirRegras(term::Window* window){
    for (Regra* regra: regras) {
        regra->imprimir(window);
    }
}

void ProcessadorRegras::setComando(const string &comando) {
    ProcessadorRegras::comando = comando;
}

void ProcessadorRegras::adicionaAparelho(Aparelho* aparelho){
    aparelhos.push_back(aparelho);
}
void ProcessadorRegras::removeAparelho(int id){
    for (int i = 0; i < aparelhos.size(); i++) {
        if (aparelhos[i]->getId() == id) {
            aparelhos.erase(aparelhos.begin() + i);
            break;
        }
    }
}

ProcessadorRegras::~ProcessadorRegras() {
    for (int i = 0; i < regras.size(); i++) {
        delete regras[i];
    }
    regras.clear();
}
