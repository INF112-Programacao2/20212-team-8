#include "desconto.h"
#include <iostream>
#include <fstream>
#include <cstring>

Desconto::Desconto(bool verifica){
    int n = 0;
    char comentario1[100];
    double valor;

    std::cout << "Verificando desconto..." << std::endl;
     
    std::ifstream enter_descont;
    
    enter_descont.open("compra.txt",std::ios::in);

    while(true){
        enter_descont.getline(comentario1,100);

        if(n == 1){
            valor = atoi(comentario1);
            break;
        }

        n++;
    }

    if(valor > 100 && verifica == false){
        std::cout << "Desconto de 20% " << "disponivel!" << std::endl;
        _desconto = 0.20;
    }

    if(verifica == true){
        std::cout << "E assim que a gente gosta, e a PREMIUM trazendo economias para voce!" << std::endl;
        std::cout << "Desconto de 30% " << "preparado!" << std::endl;
        _desconto = 0.30;
    }

    if(valor < 100 && verifica == false){
        std::cout << "Sinto muito! Mas o senhor(a) nao possui descontos disponiveis." << std::endl;
    }

}

void Desconto::descontar(bool verifica){
    int n = 0;
    char comentario1[100];
    double valor;

    std::ifstream enter_descont;
    std::ofstream out_descont;
    
    enter_descont.open("compra.txt",std::ios::in);

    while(true){
        enter_descont.getline(comentario1,100);

        if(n == 1){

            valor = atoi(comentario1);
            break;
        }

        n++;
    }

    enter_descont.close();

    valor *= _desconto;

    enter_descont.open("compra.txt",std::ios::in);

    char captura1[100][100];
		int i = 0;
		
		while(true){
			if(i == 1){
				break;
			}
			enter_descont.getline(captura1[i],100);
			i++;
		}

        enter_descont.close();

		out_descont.open("compra.txt",std::ios::out);
		
		out_descont << "#";
        out_descont << captura1[i] << std::endl;
        out_descont << "#";
        out_descont << valor << std::endl;
        
        out_descont.close();


}
