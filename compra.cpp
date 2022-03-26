#include <iostream>
#include "compra.h"
#include "conta.h"
#include <ctime>
#include <fstream>

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

_cliente = _nome;

}


void Compra::emitirrecibo(){


    std::string arquivor("recibo.txt");
    std::ifstream acc_entrada;
    std::ofstream acc_saida;

    acc_entrada.open(arquivor,std::ios_base::app);
	acc_saida.open(arquivor,std::ios::out);
     

     acc_saida << "Olá ";
     acc_saida << _nome << std::endl;
     acc_saida << " Obrigado por comprar na nossa loja." << std::endl;
     acc_saida << "Nome do Produto: " << _nomeproduto << std::endl;
     acc_saida << "Preco do produto: " << _precoproduto << std::endl;

     acc_saida.close();

}





