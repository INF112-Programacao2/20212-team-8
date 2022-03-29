#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "caixa.h"



Caixa::Caixa(){

   _saldo = 0;

}


void Caixa::registro(){

   char dados[50];
   int h = 0;
   std::string nome;
   double quantidade;
   double valor;
   std::ifstream acc_reg;
   std::ofstream acc_regout;
   
   acc_reg.open("compra.txt",std::ios::in);

   while(true){
      if(acc_reg.eof()){
         break;
      }

      acc_reg.getline(dados,50);

      if(h == 0){
         nome = dados;
      }if(h == 1){
         quantidade = atof(dados);
      }if(h == 2){
         valor = atof(dados);
      }

      h++;
   }

   acc_reg.close();

   acc_reg.open("registro.txt",std::ios::in);

   if(!acc_reg){
      acc_reg.open("registro.txt",std::ios_base::app);
      acc_regout.open("registro.txt",std::ios::out);

      _saldo += valor;

      acc_regout << "Saldo em caixa: R$" << _saldo << std::endl;
      acc_regout << "::Registro de vendas::" << std::endl;
      acc_regout << quantidade << "x " << nome << " (R$ " << std::fixed << std::setprecision(2) << valor << ")" << std::endl;
      acc_regout << "+" << std::endl;

      acc_regout.close();

   }else{
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
				strcpy(captura2, t);		//Captura do nome
				t = strtok(NULL,"Saldo em caixa: R$");
			}
            _saldo = atof(captura2);
         }
			i++;
		}
	  
		  acc_reg.close();
		  
		  _saldo += valor;
			
		  acc_regout.open("registro.txt",std::ios::out);
		
		for(int j = 0; j < i; j++){
			if(j == i-1){
				acc_regout << captura[j];
			}else if(j == 0){
				acc_regout << "Saldo em caixa: R$" << std::fixed << std::setprecision(2) << _saldo << std::endl;
			}else if(j != 0 & j != i-1){
				acc_regout << captura[j] << std::endl;
			}
		}
	
      acc_regout << quantidade << "x " << nome << " (R$ " << valor << ")" << std::endl;
      acc_regout << "+" << std::endl;
      
      acc_regout.close();
   }
}
