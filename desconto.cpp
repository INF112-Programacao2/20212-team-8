#include "desconto.h"
#include <iostream>
#include <fstream>
#include <cstring>

Desconto::Desconto(std::string verifica){	//String verifica se e conta normal ou premium
    int n = 0;
    char comentario1[100];
    double valor;

    std::cout << "Verificando desconto..." << std::endl;
     
    std::ifstream enter_descont;
    
    enter_descont.open("compra.txt",std::ios::in);

    while(true){
        
		enter_descont.getline(comentario1,100);

        if(n == 2){	//Pega o valor da compra
            valor = atof(comentario1);
            break;
        }

        n++;
    }

    if(valor > 100 && verifica == "normal"){	//Compras acima de 100 reais e sendo conta normal
        std::cout << "Desconto de 20% " << "disponivel!" << std::endl;
        _desconto = 0.20;
		_verifica = true;	//confirma desconto
    }

    else if(verifica == "premium"){	//Conta premium
        std::cout << "E assim que a gente gosta, e a PREMIUM trazendo economias para voce!" << std::endl;
        std::cout << "Desconto de 30% " << "preparado!" << std::endl;
        _desconto = 0.30;
		_verifica = true;
    }

    else if(valor < 100 && verifica == "normal"){	//Compras abaixo de 100 reais e conta normal
        std::cout << "Sinto muito! Mas o senhor(a) nao possui descontos disponiveis." << std::endl;
		_verifica = false;	//desconto nao existente
    }

}

void Desconto::descontar(){
	if(_verifica == true){	//Se confirmou desconto
	
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

			if(n == 2){	//Pega valor da compra

				valor = atof(comentario1[n]);
			}

			n++;
		
		}

		enter_descont.close();

		valor -= (valor*_desconto);                         // efetuando o desconto
		
		out_descont.open("compra.txt",std::ios::out);	//Inicializa saida do compra.txt
		
		for(int i = 0; i < n; i++){
			if(i == n-2){	//Ultima linha
				break;
			}

			out_descont << comentario1[i] << std::endl;	//Saida de linha anteriores do compra.txt
		
		}
		
		out_descont << valor << std::endl;	//Saida com o valor atualizado da compra com o desconto
		
		out_descont.close();
		
	}
	
	
	else{	//Se nao foi encontrado desconto, faz nada
		
	}

}
