#include <iostream>
#include <fstream>
#include <string>
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
         quantidade = atoi(dados);
      }if(h == 3){
         valor = atoi(dados);
      }

      h++;
   }

   acc_reg.close();

   acc_reg.open("registro.txt",std::ios::in);

   if(!acc_reg){
      acc_reg.open("registro.txt",std::ios_base::app);
      acc_regout.open("registro.txt",std::ios::out);

      _saldo += quantidade*valor;

      acc_regout << "Saldo em caixa: R$" << _saldo << std::endl;
      acc_regout << "::Registro de vendas::" << std::endl;
      acc_regout << quantidade << "x " << nome << " (R$ " << valor << ")" << std::endl;
      acc_regout << "+" << std::endl;

      acc_regout.close();

   }else{
      char captura[100][100];
      int i = 0;
		
		while(true){
			if(acc_reg.eof()){
				break;
			}
			acc_reg.getline(captura[i],100);
         if(i == 0){
            _saldo = atoi(captura[i]);
         }
			i++;
		}

      _saldo = quantidade*valor;

      acc_regout.open("registro.txt",std::ios::out);
		
		for(int j = 0; j < i; j++){
			if(j == i-1){
				acc_regout << captura[j];
			}else{
				acc_regout << captura[j] << std::endl;
			}
		}

      acc_regout << quantidade << "x " << nome << " (R$ " << valor << ")" << std::endl;
      acc_regout << "+" << std::endl;
      
      acc_regout.close();
   }
}
