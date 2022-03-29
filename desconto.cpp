#include "desconto.h"
#include <iostream>
#include <fstream>
#include <cstring>

Desconto::Desconto(std::string verifica){
    int n = 0;
    char comentario1[100];
    double valor;

    std::cout << "Verificando desconto..." << std::endl;
     
    std::ifstream enter_descont;
    
    enter_descont.open("compra.txt",std::ios::in);

    while(true){
        enter_descont.getline(comentario1,100);

        if(n == 2){
            valor = atof(comentario1);
            break;
        }

        n++;
    }

    if(valor > 100 && verifica == "normal"){
        std::cout << "Desconto de 20% " << "disponivel!" << std::endl;
        _desconto = 0.20;
		_verifica = true;
    }

    else if(verifica == "premium"){
        std::cout << "E assim que a gente gosta, e a PREMIUM trazendo economias para voce!" << std::endl;
        std::cout << "Desconto de 30% " << "preparado!" << std::endl;
        _desconto = 0.30;
		_verifica = true;
    }

    else if(valor < 100 && verifica == "normal"){
        std::cout << "Sinto muito! Mas o senhor(a) nao possui descontos disponiveis." << std::endl;
		_verifica = false;
    }

}

void Desconto::descontar(){
	if(_verifica == true){
	
		int n = 0;
		char comentario1[100][100];
		double valor;

		std::ifstream enter_descont;
		std::ofstream out_descont;
		
		enter_descont.open("compra.txt",std::ios::in);

		while(true){
			if(enter_descont.eof()){
				break;
			}
			
			enter_descont.getline(comentario1[n],100);

			if(n == 2){

				valor = atof(comentario1[n]);
			}

			n++;
		}

		enter_descont.close();

		valor -= (valor*_desconto);
		
		out_descont.open("compra.txt",std::ios::out);
		
		for(int i = 0; i < n; i++){
			if(i == n-2){
				break;
			}
			out_descont << comentario1[i] << std::endl;
		}
		
		out_descont << valor << std::endl;
		
		out_descont.close();
		
	}else{
		
	}

}
