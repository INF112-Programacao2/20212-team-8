#ifndef TPFINAL_Desconto_H
#define TPFINAL_Desconto_H


class Desconto{
private:

    double _desconto;
	bool _verifica;

    
 public:

    Desconto(std::string verifica);

    void descontar();

};

#endif
