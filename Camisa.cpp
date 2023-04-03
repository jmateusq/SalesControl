#include "Camisa.h"

Camisa::Camisa(vector <qtde*> qtde_tam,double preco, string tecido, int codigo,string cliente,
bool bordado, bool serigrafia, bool sublimacao):Roupa(qtde_tam,preco,tecido,codigo,cliente),
bordado(bordado),serigrafia(serigrafia),sublimacao(sublimacao){
}

Camisa::~Camisa(){
}

int Camisa::getProduto()const{
    return 1;
}
void Camisa::imprime() const{
    cout<<"==========================================="<<endl;
    cout<<"Cliente: "<<this->getCliente()<<endl;
    cout<<"Produto: CAMISA"<<endl;
    Roupa::imprime();
}

bool Camisa::getBordado() const{
    return this->bordado;
}
bool Camisa::getSerigrafia() const{
    return this->serigrafia;
}
bool Camisa::getSublimacao() const{
    return this->sublimacao;
}
