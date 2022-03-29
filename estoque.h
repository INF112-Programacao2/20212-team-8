#ifndef TPFINAL_Estoque_H
#define TPFINAL_Estoque_H


class Estoque{
 private:

  char _nomeproduto[5][50];
  int _estoque[5];


 public:
     
     Estoque();

     void fluxoproduto();

};

#endif