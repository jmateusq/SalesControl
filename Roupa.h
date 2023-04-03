#ifndef ROUPA_H
#define ROUPA_H
#include <iostream>
#include <string>
#include <vector>
#include "qtde_tam.h"

using std::string,std::cout,std::endl,std::cin,std::vector;

class Roupa{
    private:
        vector <qtde*> qtde_tam;
        double preco;
        string tecido;
        int codigo;
        string cliente;
    public:
        Roupa(vector <qtde*> qtde_tam,double preco, string tecido, int codigo,string cliente);
        virtual ~Roupa();
        virtual void imprime() const;
        double getPreco() const;
        string getTecido() const;
        virtual int getProduto() const = 0;
        string getCliente() const;
        int getCodigo()const;
        void setValor(double valor);
        vector <qtde*> getQtde_tam() const;

        static bool compara(Roupa *p1, Roupa *p2);
};
#endif