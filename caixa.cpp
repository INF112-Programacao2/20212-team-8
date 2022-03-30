#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "caixa.h"



Caixa::Caixa(){

   _saldo = 0; //Saldo da loja

}


void Caixa::registro(){

   char dados[50];
   int h = 0;
   std::string nome; //Nome do jogo
   double quantidade;   //Quantidade comprada
   double valor;  //Valor total da compra
   std::ifstream acc_reg;
   std::ofstream acc_regout;
   
   acc_reg.open("compra.txt",std::ios::in);

   while(true){   //Captura de valores para colocar no registro
      if(acc_reg.eof()){
         break;
      }

      acc_reg.getline(dados,50);

      if(h == 0){
         nome = dados;
      }
      
      
      if(h == 1){
         quantidade = atof(dados);  
      }
      
      
      if(h == 2){
         valor = atof(dados);
      }

      h++;
   }

   acc_reg.close();  //Fecha leitura

   acc_reg.open("registro.txt",std::ios::in);

   if(!acc_reg){  //Se nao tiver nenhum registro, cria e acrescenta os valores nele
      acc_reg.open("registro.txt",std::ios_base::app);
      acc_regout.open("registro.txt",std::ios::out);

      _saldo += valor;  //Valor a ser acrescido no saldo

      //Imprime na tela o registro
      std::cout << "Saldo em caixa: R$" << _saldo << std::endl;
      std::cout << "::Registro de vendas::" << std::endl;
      std::cout << quantidade << "x " << nome << " (R$ " << std::fixed << std::setprecision(2) << valor << ")" << std::endl;
      std::cout << "+" << std::endl;

      //Saida no registro.txt
      acc_regout << "Saldo em caixa: R$" << _saldo << std::endl;
      acc_regout << "::Registro de vendas::" << std::endl;
      acc_regout << quantidade << "x " << nome << " (R$ " << std::fixed << std::setprecision(2) << valor << ")" << std::endl;
      acc_regout << "+" << std::endl;

      acc_regout.close();

   }
   
   
   else{
      
      char captura[100][100];
	   char captura2[100];
      int i = 0;
	   char *t;
	  
		while(true){
			
         if(acc_reg.eof()){
				break;
			}
			
         acc_reg.getline(captura[i],100);
         
         if(i == 0){
			t = strtok(captura[i],"Saldo em caixa: R$");		//Separação da string em tokens
			
			while(t != NULL){
				strcpy(captura2, t);		//Captura do saldo antigo
				t = strtok(NULL,"Saldo em caixa: R$");
			}

            _saldo = atof(captura2);   //Atribui o saldo anterior
         
         }
			
         i++;
		
      }
	  
		  acc_reg.close();
		  
		  _saldo += valor;   //Acrescenta o valor da nova compra do cliente
			
		  acc_regout.open("registro.txt",std::ios::out);
		
	   for(int j = 0; j < i; j++){
			if(j == i-1){  //Leitura final do registro anterior
				acc_regout << captura[j];  //Saida final antiga
			}
         
         
         else if(j == 0){  //Leitura e saida do registro antigo, porem atualizado
            std::cout <<  "Saldo em caixa: R$" << std::fixed << std::setprecision(2) << _saldo << std::endl;   //Imprime na tela
				acc_regout << "Saldo em caixa: R$" << std::fixed << std::setprecision(2) << _saldo << std::endl;   //Saida atualizada no registro atualizado
			}
         
         else if(j != 0 & j != i-1){   //Leitura geral
				acc_regout << captura[j] << std::endl; //Saida geral no registro
			}
		
      }

      std::cout << quantidade << "x " << nome << " (R$ " << valor << ")" << std::endl; //Imprime na tela
      acc_regout << quantidade << "x " << nome << " (R$ " << valor << ")" << std::endl;   //Saida atualizada no registro
      acc_regout << "+" << std::endl;
      
      acc_regout.close();
   
   }

}
