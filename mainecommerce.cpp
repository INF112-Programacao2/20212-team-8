#include <iostream>
#include <string>
#include <fstream>
#include "compra.h"
#include "compra.cpp"
#include "jogos.h"
#include "cadastro.h"
#include "cadastro.cpp"
#include "caixa.h"
#include "caixa.cpp"
#include "desconto.h"
#include "desconto.cpp"
#include "conta.h"
#include "contanormal.h"
#include "contanormal.cpp"
#include "contapremium.h"
#include "contapremium.cpp"

int main(){
	bool log;
	
    Cadastro c1;

    log = c1.login();
	
	if(log == true){
		char option;
		int verifica = 0;
		
		while(true){
			std::cout << "Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
			std::cout << "Ver e comprar jogos (a); Ver minha conta (b)" << std::endl;
			std::cin >> option;
			std::cin.ignore();
			
			while(verifica == 0){
				if(option == 'a'){
					verifica++;
				}else if(option == 'b'){
					verifica++;
				}else if(verifica == 0){
					std::cout << "Erro!Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
					std::cout << "Ver e comprar jogos (a); Ver minha conta (b)" << std::endl;
					std::cin >> option;
					std::cin.ignore();
				}
			}
			
			if(option == 'a'){
				char captura[100];
				std::string status;
				std::ifstream status_check;
				
				status_check.open("conta.txt",std::ios::in);
				
				for(int i = 0; i < 9; i++){
					status_check.getline(captura,100);
					
					if(i == 8){
						status = captura;
					}
				}
				
				if(status == "normal"){
					bool verf;
					Compra cp1;
					
					cp1.exibirjogos();
					verf = cp1.comprar();
					
					if(verf == true){
						Desconto d(status);
						d.descontar();
						
						cp1.pedido();
						cp1.emitirrecibo();
					}else{
						
					}
					
				
				}else if(status == "premium"){
					bool verf1;
					
					Compra cp2;
					Cpremium cn2;
					
					cp2.exibirjogos();
					cp2.comprar();
					
					if(verf == true){
						Desconto d2(status);
						d2.descontar();
						
						cp2.pedido();
						cp2.emitirrecibo();
					}else{
						
					}
				}
				
				status_check.close();
				
			}else if(option == 'b'){
				char captura1[100];
				std::string status;
				std::ifstream status_check;
				
				status_check.open("conta.txt",std::ios::in);
				
				for(int i = 0; i < 9; i++){
					status_check.getline(captura1,100);
					if(i == 8){
						status = captura1;
					}
					
				}
				
				if(status == "normal"){
					Cnormal cn1;
					
					char option2;
					int verifica1 = 0;
					
				
					std::cout << "Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
					std::cout << "Ver todas as informacoes de minha conta (a); Alterar dados de minha conta (b)" << std::endl;
					std::cin >> option2;
					std::cin.ignore();
						
						while(verifica1 == 0){
							if(option2 == 'a'){
								verifica1++;
							}else if(option2 == 'b'){
								verifica1++;
							}else if(verifica1 == 0){
								std::cout << "Erro!Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
								std::cout << "Ver todas as informacoes de minha conta (a); Alterar dados de minha conta (b)" << std::endl;
								std::cin >> option2;
								std::cin.ignore();
							}
						}
					
					
						if(option2 == 'a'){
							cn1.conta();
						}else if(option2 == 'b'){
							cn1.alterardados();
						}
				
				}else if(status == "premium"){
					Cpremium cpm1;
					
					char option3;
					int verifica2 = 0;
					
				
						std::cout << "Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
						std::cout << "Ver todas as informacoes de minha conta (a); Alterar dados de minha conta (b)" << std::endl;
						std::cin >> option3;
						std::cin.ignore();
						
						while(verifica2 == 0){
							if(option3 == 'a'){
								verifica2++;
							}else if(option3 == 'b'){
								verifica2++;
							}else if(verifica2 == 0){
								std::cout << "Erro!Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
								std::cout << "Ver todas as informacoes de minha conta (a); Alterar dados de minha conta (b)" << std::endl;
								std::cin >> option3;
								std::cin.ignore();
							}
						}
					
						
					if(option3 == 'a'){	
						cpm1.conta();
					}else if(option3 == 'b'){
						cpm1.alterardados1();
					}
				}
			}
			
			std::cout << "Deseja continuar realizando operacoes? Digite 's' ou 'n':";
			std::cin >> option;
			
			while(verifica == 0){
				if(option == 's'){
					verifica++;
				}else if(option == 'n'){
					verifica++;
				}else if(verifica == 0){
					std::cout << "Erro!Deseja continuar realizando operacoes? Digite 's' ou 'n':" << std::endl;
					std::cin >> option;
				}
			}
			
			if(option == 's'){
				continue;
			}else if(option == 'n'){
				std::cout << "Volte sempre! :)" << std::endl;
				break;
			}
		}
		
	}
	
	else{
		char option2;
		int verifica2 = 0;
		
		while(true){
			std::cout << "Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
			std::cout << "Ver o caixa (a); Ver o estoque (b); Cadastrar produto (c)" << std::endl;
			std::cin >> option2;
			
			while(verifica2 == 0){
				if(option2 == 'a'){
					verifica2++;
				}else if(option2 == 'b'){
					verifica2++;
				}else if(option2 == 'c'){
					verifica2++;
				}else if(verifica2 == 0){
					std::cout << "Erro!Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
					std::cout << "Ver o caixa (a); Ver o estoque (b)" << std::endl;
					std::cin >> option2;
				}
			}
			
			if(option2 == 'a'){
				Caixa cx;
				
				cx.registro();
				
				
			}else if(option2 == 'b'){
				Estoque etq;
				
				etq.fluxoproduto();
			}else if(option2 == 'c'){
				c1.cadastrarproduto();
			}
			
			std::cout << "Deseja continuar realizando operacoes? Digite 's' ou 'n':";
			std::cin >> option2;
			
			while(verifica2 == 0){
				if(option2 == 's'){
					verifica2++;
				}else if(option2 == 'n'){
					verifica2++;
				}else if(verifica2 == 0){
					std::cout << "Erro! Deseja continuar realizando operacoes? Digite 's' ou 'n':";
					std::cin >> option2;
				}
			}
			
			if(option2 == 's'){
				continue;
			}else if(option2 == 'n'){
				std::cout << "Ate logo ADM! :D" << std::endl;
				break;
			}
		}
		
		
	}


    return 0;
}