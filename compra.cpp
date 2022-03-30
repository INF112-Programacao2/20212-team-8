#include <iostream>
#include "compra.h"
#include <ctime>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>

//Inicialização de atributos
Compra::Compra(){
	
    _numeropedido = 0;
	
    _data = "nulo";
    
    _cliente = "nulo";
}

//Mostra os jogos disponiveis
void Compra::exibirjogos(){
	
    std::cout << "::Jogos disponiveis em nossa plataforma::" << std::endl;
    
    char leitura[100]; //Variavel para capturar os jogos
	
    int n = 0;	//auxiliar para tamanho de linhas 
	
    int g = 0;	//auxiliar para capturar os jogos dentro do produtos.txt

    std::ifstream view_gamelist;	//Inicializacao para abertura de arquivo

    view_gamelist.open("produtos.txt",std::ios::in);	//Abertura do arquivo
	
	//Caso nao ache o arquivo para abrir
	if(!view_gamelist){
        std::cout << "Loja encontra-se sem produtos, em breve disponibilizaremos novos jogos..." << std::endl;
    }
	
	//Caso encontre o arquivo
	else{
	
	
		for(int i = 0; i <= n; i++){
			
			//Se chegar na ultima linha
			if(view_gamelist.eof()){
				break;
			}
			
			//Captura a linha inteira
			view_gamelist.getline(leitura,100);
			
			//Se for a linha do nome do jogo, imprime na tela
			if(i == g*6){
				
				std::cout << g << "- " << leitura << std::endl;
				
				g++;	//Aumenta para o caso de haver mais de um jogo cadastrado na loja
			}
			
			n++;	//Aumenta para registrar a proxima linha
		}
	}
    
}

bool Compra::comprar(){
	
	
		int opcao;	//Usado para marcar uma opcao
		
		char leitura[50];	//Leitura dos dados
		
		char d;		//Usado para marcar uma opcao
		
		int n = 0;	//Auxiliar para aumento de linhas
		
		double quant;	//Capta a quantidade de produtos a serem comprados pelo usuario
		
		double totalvalor;	//Capta o valor total do produto
			
		std::string nome;	//Captura nome do jogo
		
		double valor;	//Capta o valor unitario do jogo
		
		double quantidade;	//Capta a quantidade disponivel do produto da loja
		
		std::ifstream view_gamelist;	//Inicializacao do arquivo
		
		view_gamelist.open("produtos.txt",std::ios::in);	//Abertura do arquivo com os jogos apenas para verificacao
		
		if(!view_gamelist){	//Caso nao encontre o arquivo
		   
		   //Pula para o menu interrogativo de operacoes do progama no main
		
		}
		
		else{ //Caso encontre 
			
			view_gamelist.close(); //Fecha o arquivo para verificacao
			
			std::ifstream acc_saldo;
			std::ofstream acc_saldout;
			
			while(true){
				std::cout << "Digite o numero do jogo que deseja comprar: ";
				std::cin >> opcao;
				std::cin.ignore(); 

				std::cout << "Encaminhando para a pagina..." << std::endl;
				
				view_gamelist.open("produtos.txt",std::ios::in); //Abertura arquivo para ver os jogos disponiveis
				
				for(int i = 0; i <= n; i++){
					
					if(view_gamelist.eof()){ //Chegou na ultima linha
						break;
					}
					
					view_gamelist.getline(leitura,50); //Captura a linha inteira
					
					
					//Basicamente cada um capta a linha com a caracteristica designada no arquivo produtos.txt
					//A declaracao nos ifs e para captar exatamente a linha de cada jogo com suas caracteristicas
					//Em algumas delas o dados serao usados para formar o arquivo compra.txt
					//Porem no geral, e mais para ser imprimido e mostrado ao usuario da compra
					if(i == (opcao*6)){	
						
						std::cout << "Nome: " << leitura << std::endl;
						nome = leitura;
				  
					}if(i == (opcao*6)+1){
					   
						std::cout << "Codigo do jogo: " << leitura << std::endl;
						
					}if(i == (opcao*6)+2){

						std::cout << "R$ " << leitura << std::endl;
						valor = atof(leitura);

					}if(i == (opcao*6)+3){
						
						quantidade = atof(leitura);
						std::cout << "Em estoque: " << leitura << std::endl;
						
					}if(i == (opcao*6)+4){

						std::cout << "Descricao: " << leitura << std::endl; 
						
					}
					
					n++;
				
				}

				std::cout << "Deseja efetuar a compra?" << std::endl;
				std::cout << "Digite 'S' para efetuar a compra" << std::endl;
				std::cout << "Se nao, digite 'N' para cancelar a compra e voltar a pagina inicial." << std::endl;
				
				int verifica = 0; //Usado para condicao de parada do while em caso de opcao valida
				std::cin >> d;	//Entrada para realizar opcao

				while(verifica == 0){
					
					if(d == 'S' || d == 's'){
						
						verifica++;	//Para o while
						
					}
					
					else if(d == 'N' || d == 'n'){
						
						verifica++;	//Para o while
						
					}
					
					else if(verifica == 0){	//Se a opcao nao era valida
						
						std::cout << "Opcao invalida!" << std::endl;
						std::cout << "Digite 'S' para efetuar a compra" << std::endl;
						std::cout << "Se nao, digite 'N' para cancelar a compra e voltar a pagina inicial." << std::endl;
						std::cin >> d;
						
					}
					
				}
				
				if(d == 'S' || d == 's'){	
					
					std::cout << "Quantas unidades?" << std::endl;
					std::cin >> quant;

					while(quant < 1 || quant > quantidade){	
					
						std::cout << "Erro! Digite um valor valido de 1 a " << quantidade << ".";
						std::cin >> quant;
						
					}

					totalvalor = quant*valor;	//Multiplica quantidade escolhida pelo usuario pelo preco do produto

					acc_saldo.open("compra.txt",std::ios_base::app);	//Cria o compra.txt
					acc_saldout.open("compra.txt",std::ios::out);	//Abre ele para leitura

					acc_saldout << nome << std::endl;	//Nome do jogo
					acc_saldout << quant << std::endl;	//Quantidade comprada
					acc_saldout << std::fixed << std::setprecision(2) << totalvalor << std::endl;	//Valor final da compra

					acc_saldout.close();
					return true;	//Confirma que sera feita a compra para acessar o desconto e demais funcoes

				}
				
				else if(d == 'N' || d == 'n'){
				   
				   return false;	//Confirma que nao foi possivel comprar
				
				}
			}
		}
}

void Compra::pedido(){
    
	char comentario1[100];	//Captura os strings designados abaixo
    
	char comentario3[100];	//Captura o nome do cliente

    std::string nome;
    
	std::string valor;
    
	std::string quantidade;

    srand(time(0));
    
	_numeropedido = 1+rand()%100;	
	
	std::string numeropedido(std::to_string(_numeropedido)); //Transforma _numeropedido em string

    std::ifstream acc_check1;	
    std::ofstream acc_out1;

    acc_check1.open("conta.txt",std::ios::in);	//Abre o conta.txt

    acc_check1.getline(comentario3,100);	//Captura o nome do cliente

    _cliente = comentario3;	//Atribui o nome

    acc_check1.close();

    acc_check1.open("compra.txt");	//Abre conta.txt

    int h = 0;

    while(h < 3){	//Captura de valores
        
		acc_check1.getline(comentario1,100);
        
        if(h == 0){	//Primeira linha
			
            nome = comentario1; //Nome do jogo
			
        }
		
		if(h == 1){ //Segunda linha
			
            quantidade = comentario1;	//Quantidade comprada
			
        }
		
		if(h == 2){ //Terceira linha
			
            valor = comentario1;	//Preco do produto
			
        }

        h++;	//Incrementador para percorrer linhas
    }
	
	//Imprime o pedido na tela para o usuario
	std::cout << "::Pedido::" << std::endl;
	std::cout << "Numero do pedido: ";
	std::cout << numeropedido << std::endl;
	std::cout << "Cliente: ";
	std::cout << _cliente << std::endl;
	std::cout << "Nome: ";
	std::cout << nome << std::endl;
	std::cout << "Quantidade: ";
	std::cout << quantidade << "x" << std::endl;
	std::cout << "Preco: R$";
	std::cout << valor << std::endl;
	
    acc_check1.open("pedido.txt",std::ios_base::app);	//Abertura do pedido
    acc_out1.open("pedido.txt",std::ios::out);	//Iniciacao da saida
	
    acc_out1 << _numeropedido << std::endl;
    acc_out1 << _cliente << std::endl;
    acc_out1 << nome << std::endl;
    acc_out1 << quantidade << std::endl;
    acc_out1 << valor << std::endl;
    
    acc_out1.close();
}


void Compra::emitirrecibo(){

    char comentario1[100];
    char comentario2[100];
   
	std::ifstream acc_entrada;
    std::ofstream acc_saida;
    
	std::string numeropedido;
    std::string nome;
    std::string nomepedido;
    std::string precoproduto;
    
	int h1 = 0;

    acc_entrada.open("pedido.txt",std::ios::in); //Le o pedido.txt

    while(h1 < 4){ //Captura de valores
		
        acc_entrada.getline(comentario1,100);

        if(h1 == 0){
			
           _cliente = comentario1;
		   
        }
		
		if(h1 == 1){
			
            precoproduto = comentario1;
			
        }
		
		if(h1 == 2){
			
            nomepedido = comentario1;
			
        }
		
		if(h1 == 3){
			
            numeropedido = comentario1;
			
        }
		
        h1++;
    }

    acc_entrada.close();
	
	//Imprime o recibo da compra na tela para o cliente
	std::cout << "Ola " << _cliente << std::endl;
	std::cout << "Obrigado por comprar na nossa loja."
	std::cout << "Numero do pedido: " << numeropedido << std::endl;
	std::cout << "Nome do produto: " << nomepedido << std::endl;
	std::cout << "Preco do produto: " << precoproduto << std::endl;

    acc_entrada.open("recibo.txt",std::ios_base::app);	//Criacao do recibo.txt
    acc_saida.open("recibo.txt",std::ios::in);	//Inicializacao da saida do recibo.txt

    acc_saida << "Ola ";
    acc_saida << _cliente << std::endl;
    acc_saida << "Obrigado por comprar na nossa loja." << std::endl;
    acc_saida << "Numero do pedido: " << numeropedido << std::endl;
    acc_saida << "Nome do produto: " << nomepedido << std::endl;
    acc_saida << "Preco do produto: " << precoproduto << std::endl;

    acc_saida.close();

}





