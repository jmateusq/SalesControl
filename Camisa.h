#ifndef CAMISA_H
#define CAMISA_H
#include "Roupa.h"

class Camisa:public Roupa{
    private:
        bool bordado;
        bool serigrafia;
        bool sublimacao;
    public:
        Camisa(vector <qtde*> qtde_tam,double preco, string tecido, int codigo,string cliente,
        bool bordado, bool serigrafia, bool sublimacao);
        virtual ~Camisa();
        virtual int getProduto() const;
        virtual void imprime() const;
        bool getBordado() const;
        bool getSerigrafia() const;
        bool getSublimacao() const;
};

#endif