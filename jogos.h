#ifndef TPFINAL_Jogos_H
#define TPFINAL_Jogos_H
#include <string>

class Jogos{
  private:

  
  std::string _categoria;
  std::string _plataforma;
  
  std::string _listadejogos[][];

  public:


  void filtroaz();
  void listanomecapa();
  void listaplataformas();
  void maisvendidos();
  void pesquisar();
  void filtrolancamento();



};

#endif
