#ifndef TP2_PROPRIEDADE_H
#define TP2_PROPRIEDADE_H
#include <string>
#include <map>
using namespace std;

class Propriedade{
private:
    int valor;
public:
    Propriedade(int valor);
    int getValor();
    void setValor(int valor);
    virtual void modificaValor(int valor) = 0;
    virtual string actualizaValor(int valor) = 0;

};

#endif //TP2_PROPRIEDADE_H
