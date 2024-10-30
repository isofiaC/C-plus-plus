#include <string>
#include "Simulador.h"

using namespace term;
using namespace std;


int main() {
    //int i;

    //for (i = 1; i < 20; i++) {
    //    t.init_color(i, i, 0);
    //}
    Simulador *simulador = new Simulador();
    simulador->executar();
    delete simulador;
    return 0;
}
