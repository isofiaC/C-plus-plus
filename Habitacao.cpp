#include "Habitacao.h"

Habitacao::Habitacao(int linhas, int colunas) : linhas(linhas), colunas(colunas), tempo(0) {
}

string Habitacao::gerarKey(int i, int j) {
    return to_string(i) + "," + to_string(j);
}

string Habitacao::criarZona(int i, int j, term::Window *window) {
    if (i >= 0 && i < linhas && j >= 0 && j < colunas) {
        string key = gerarKey(i, j);
        if (mapZonas.find(key) != mapZonas.end()) {
            return "Zona ja existe neste indice";
        }

        mapZonas[key] = new Zona(window);
        return "OK";
    } else {
        return "Indices invalidos";
    }
}

Zona *Habitacao::getZona(int id) {
    for (auto it = mapZonas.begin(); it != mapZonas.end(); ++it) {
        if (it->second->getId() == id) {
            return it->second;
        }
    }

    return nullptr;
}

string Habitacao::removerZona(int id) {
    for (auto it = mapZonas.begin(); it != mapZonas.end(); ++it) {
        if (it->second->getId() == id) {
            delete it->second;
            mapZonas.erase(it);
            return "OK";
        }
    }
    return "Nao existe uma zona com o id indicado";
}

void Habitacao::processarInstante() {
    for (auto it = mapZonas.begin(); it != mapZonas.end(); ++it) {
        it->second->processarInstante();
    }
    tempo ++;
}

void Habitacao::desenhaHabitacao() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            string key = gerarKey(i, j);
            if (mapZonas.find(key) != mapZonas.end()) {
                mapZonas[key]->desenhaZona();
            }
        }
    }
}

void Habitacao::imprimirZonas(term::Window *window) {
    for (auto it = mapZonas.begin(); it != mapZonas.end(); ++it) {
        it->second->imprimir(window);
    }
}


int Habitacao::getLinhas() const {
    return linhas;
}

int Habitacao::getColunas() const {
    return colunas;
}

Habitacao::~Habitacao() {
    for (auto it = mapZonas.begin(); it != mapZonas.end(); ++it) {
        delete it->second;
    }
    mapZonas.clear();
}
