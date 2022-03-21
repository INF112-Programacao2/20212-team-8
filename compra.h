#ifndef TPFINAL_COMPRA_H
#define TPFINAL_COMPRA_H
#include <string>

class Compra{
private:
    std::string _numeropedido;
    std::string _data;
    std::string _cliente;

public:
    Compra();
    void descontar();
    void comprar();
    void emitirboleto();

};

#endif