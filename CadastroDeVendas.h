#ifndef CADASTRO_H
#define CADASTRO_H
#include "Roupa.h"
#include "Camisa.h"
#include "Colete.h"
#include "qtde_tam.h"
#include <vector>
using std::vector;

class Cadastro{
    private:
        string fileName;
        vector <Roupa *> pedido;
        int codigo=0 ;

        bool salva();
    public:
        Cadastro(string fileName);//
        virtual ~Cadastro();
        bool adcionaPedido(); //
        void imprime(string cliente) const; //
        void imprime(int codigo) const; //
        void imprime() const; //
        bool remove(int codigo);
        bool atualizaValor(int codigo);

};

#endif