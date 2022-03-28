#include "desconto.h"
#include <iostream>
#include <fstream>
#include <cstring>

Desconto::Desconto(){
    int n = 0;
    char comentario1[100];
    char comentario2[100];
    char *t;
    double valor;

    std::cout << "Verificando desconto..." << std::endl;
     
    std::ifstream enter_descont;
    
    enter_descont.open("compra.txt",std::ios::in);

    while(true){
        enter_descont.getline(comentario1,100);

        if(n == 1){
            t = strtok(comentario1,"#");		//Separação da string em tokens
                            
            while(t != NULL){
                strcpy(comentario2, t);		//Captura do nome
                t = strtok(NULL,"#");
            }
            valor = atoi(comentario2);
            break;
        }

        n++;
    }

    if(valor > 100){
        _desconto = 0.20;
    }

    if(){
        _desconto = 0.30;
    }

    if(valor < 100 &&){
        std::cout << "Sinto muito! Mas o senhor(a) nao possui descontos disponiveis." << std::endl;
    }

}

void Desconto::descontar(){
    int n = 0;
    char comentario1[100];
    char comentario2[100];
    char *t;
    double valor;

    std::ifstream enter_descont;
    std::ofstream out_descont;
    
    enter_descont.open("compra.txt",std::ios::in);

    while(true){
        enter_descont.getline(comentario1,100);

        if(n == 1){
            t = strtok(comentario1,"#");		//Separação da string em tokens
                            
            while(t != NULL){
                strcpy(comentario2, t);		//Captura do nome
                t = strtok(NULL,"#");
            }
            valor = atoi(comentario2);
            break;
        }

        n++;
    }

    enter_descont.close();

    valor *= _desconto;

    enter_descont("compra.txt",std::ios::in);

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
