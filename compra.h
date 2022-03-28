#ifndef TPFINAL_COMPRA_H
#define TPFINAL_COMPRA_H
#include <string>

class Compra : public Jogos{
private:
    int _numeropedido;
    std::string _data;
    std::string _cliente;

public:
    Compra();
    virtual void exibirjogos();
    void comprar();
    void pedido();
    void emitirrecibo();

};

#endif