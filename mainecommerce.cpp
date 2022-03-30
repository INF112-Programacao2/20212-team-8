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
			
			while(verifica == 0){	//While para verificacao de opcao
				
				
				if(option == 'a'){
					verifica++;
				}
				
				
				else if(option == 'b'){
					verifica++;
				}
				
				
				else if(verifica == 0){
					std::cout << "Erro!Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
					std::cout << "Ver e comprar jogos (a); Ver minha conta (b)" << std::endl;
					std::cin >> option;
					std::cin.ignore();
				}
			
			}
			
			if(option == 'a'){	//Aba de ver e comprar jogos
				char captura[100];
				std::string status;
				std::ifstream status_check;
				
				status_check.open("conta.txt",std::ios::in);
				
				for(int i = 0; i < 9; i++){
					status_check.getline(captura,100);
					
					if(i == 8){	//Captura o tipo de conta
						status = captura;
					}
				}
				
				if(status == "normal"){		//Se for conta normal
					bool verf;
					Compra cp1;
					
					cp1.exibirjogos();
					verf = cp1.comprar();
					
					if(verf == true){
						Desconto d(status);
						d.descontar();
						
						cp1.pedido();
						cp1.emitirrecibo();
					}
					
					
					else{
						
					}
					
				
				}
				   
				   
				else if(status == "premium"){	//Se for conta premium
					bool verf1;
					
					Compra cp2;
					Cpremium cn2;
					
					cp2.exibirjogos();
					verf1 = cp2.comprar();
					
					if(verf1 == true){
						Desconto d2(status);
						d2.descontar();
						
						cp2.pedido();
						cp2.emitirrecibo();
					}
					
					
					else{
						
					}
				}
				
				status_check.close();
				
			}
			
			
			else if(option == 'b'){	//Ver informacoes e alterar dados de contas
				
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
						
						while(verifica1 == 0){//While para verificar opcoes
							
							if(option2 == 'a'){
								verifica1++;
							
							}
							
							else if(option2 == 'b'){
								verifica1++;
							
							}
							
							else if(verifica1 == 0){
								std::cout << "Erro!Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
								std::cout << "Ver todas as informacoes de minha conta (a); Alterar dados de minha conta (b)" << std::endl;
								std::cin >> option2;
								std::cin.ignore();
							}
						}
					
					
						if(option2 == 'a'){	//Se opcao for ver informacoes da conta
							cn1.conta();
						
						}
						
						
						else if(option2 == 'b'){	//Se opcao for alterar dados
							cn1.alterardados();
						}
				
				}
				
				
				else if(status == "premium"){
					Cpremium cpm1;
					
					char option3;
					int verifica2 = 0;
					
				
						std::cout << "Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
						std::cout << "Ver todas as informacoes de minha conta (a); Alterar dados de minha conta (b)" << std::endl;
						std::cin >> option3;
						std::cin.ignore();
						
						while(verifica2 == 0){//While para verificar opcoes
							if(option3 == 'a'){
								verifica2++;
							}
							
							
							else if(option3 == 'b'){
								verifica2++;
							}
							
							
							else if(verifica2 == 0){
								std::cout << "Erro!Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
								std::cout << "Ver todas as informacoes de minha conta (a); Alterar dados de minha conta (b)" << std::endl;
								std::cin >> option3;
								std::cin.ignore();
							}
						}
					
						
					if(option3 == 'a'){	//Se for ver informacoes
						cpm1.conta();
					}
					
					
					else if(option3 == 'b'){	//Se for alterar dados
						
						cpm1.alterardados1();
					
					}
				}
			}
			
			std::cout << "Deseja continuar realizando operacoes? Digite 's' ou 'n':";
			std::cin >> option;
			
			while(verifica == 0){//While para verificar opcoes
				if(option == 's'){
					verifica++;
				}
				
				
				else if(option == 'n'){
					verifica++;
				}
				
				else if(verifica == 0){
					std::cout << "Erro!Deseja continuar realizando operacoes? Digite 's' ou 'n':" << std::endl;
					std::cin >> option;
				}
			
			}
			
			if(option == 's'){	//Continua fazendo operacoes
				continue;
			}
			
			
			else if(option == 'n'){	//Termina o programa
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
			std::cout << "Ver o caixa (a); Cadastrar produto (b)" << std::endl;
			std::cin >> option2;
			
			while(verifica2 == 0){//While para verificar opcoes
				if(option2 == 'a'){
					verifica2++;
				}
				
				else if(option2 == 'b'){
					verifica2++;
				}
				
				
				else if(verifica2 == 0){
					std::cout << "Erro!Digite a opcao correspondente ao acesso que voce deseja realizar:" << std::endl;
					std::cout << "Ver o caixa (a); Cadastrar produto (b)" << std::endl;
					std::cin >> option2;
				}
			
			}
			
			if(option2 == 'a'){	//Vai para o registro
				Caixa cx;
				
				cx.registro();
				
				
			}
			
			
			else if(option2 == 'b'){	//Cadastra produto
				c1.cadastrarproduto();
			}
			
			std::cout << "Deseja continuar realizando operacoes? Digite 's' ou 'n':";
			std::cin >> option2;
			
			while(verifica2 == 0){	//While para verificar opcoes
				if(option2 == 's'){
					verifica2++;
				}
				
				else if(option2 == 'n'){
					verifica2++;
				}
				
				
				else if(verifica2 == 0){
					std::cout << "Erro! Deseja continuar realizando operacoes? Digite 's' ou 'n':";
					std::cin >> option2;
				}
			
			}
			
			if(option2 == 's'){	//Continua operacoes
				continue;
			}
			
			
			else if(option2 == 'n'){	//Termina o programa
				std::cout << "Ate logo ADM! :D" << std::endl;
				break;
			}
		
		}
		
		
	}


    return 0;
}