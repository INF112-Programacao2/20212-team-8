#include <iostream>
#include "compra.h"
#include "conta.h"
#include <ctime>

Compra::Compra(){

_numeropedido = NULL;
_data = NULL;
_cliente = NULL;

}

void Compra::compra(){

srand(time(0));
_numeropedido = 1+rand()%100;

std::cout << "Digite a data: ";
std::cin >> _data;

_cliente= _nome;

}


void Compra::emitirboleto(){



}

