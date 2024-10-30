#ifndef TP_HABITACAO_H
#define TP_HABITACAO_H
#include <vector>
#include <iostream>
#include "Zona.h"
#include "Terminal.h"
#include "curses.h"
using namespace std;

class Habitacao {
    int tempo;
    int linhas;
    int colunas;
    map<string ,Zona*> mapZonas;

public:
    Habitacao(int linhas, int colunas);
    string gerarKey(int i, int j);
    string criarZona(int i, int j, term::Window* window);
    Zona* getZona(int id);
    string removerZona(int id);
    void processarInstante();
    void desenhaHabitacao();
    void imprimirZonas(term:: Window* window);
    int getLinhas() const;
    int getColunas() const;
    ~Habitacao();
};

#endif //TP_HABITACAO_H
