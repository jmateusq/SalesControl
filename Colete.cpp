#include "Colete.h"

Colete::Colete(vector <qtde*> qtde_tam,double preco, string tecido, int codigo,string cliente, char elastico, string vies):
Roupa(qtde_tam,preco,tecido,codigo,cliente),elastico(elastico),vies(vies){
}

Colete::~Colete(){
}

int Colete::getProduto() const{
    return 2;
}

void Colete::imprime() const{
    cout<<"==========================================="<<endl;
    cout<<"Cliente: "<<this->getCliente()<<endl;
    cout<<"Produto: COLETE"<<endl;
    Roupa::imprime();
}

char Colete::getElastico(){
    return this->elastico;
}
string Colete::getVies(){
    return this->vies;
}