#include <iostream>
#include "conta.h"
#include <fstream>

Conta::Conta(){


}

void contapadrao(){




}

void contapremium(){




}


void alterardados(){



    std::string arquivoc("conta.txt");
    std::ifstream acc_entrada;
    std::ofstream acc_saida;

    acc_entrada.open(arquivop,std::ios_base::app);
	
	acc_saida.open(arquivop,std::ios::out);

}




void pedido(){


    std::string arquivop("pedido.txt");
    std::ifstream acc_entrada;
    std::ofstream acc_saida;

    acc_entrada.open(arquivop,std::ios_base::app);
	
	acc_saida.open(arquivop,std::ios::out);

}


