#ifndef COLETE_H
#define COLETE_H
#include "Roupa.h"

class Colete : public Roupa{
    private:
        char elastico; //P ou B (preto ou branco)
        string vies; //cor do viés
    public:
        Colete(vector <qtde*> qtde_tam,double preco, string tecido, int codigo,string cliente, char elastico, string vies);
        virtual ~Colete();
        virtual int getProduto() const;
        virtual void imprime() const;
        char getElastico();
        string getVies();
};

#endif

