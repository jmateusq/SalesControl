#include "Roupa.h"

Roupa::Roupa(vector <qtde*> qtde_tam,double preco, string tecido, int codigo,string cliente):qtde_tam(qtde_tam),
preco(preco), tecido(tecido),codigo(codigo),cliente(cliente){

}

Roupa::~Roupa(){

}

void Roupa::imprime() const{
    int total=0;
    cout<<"Pedido Nro: "<<this->codigo<<endl;
    cout<<"Tecido: "<<this->tecido<<endl;
    cout<<"Preço Unitario: "<<this->preco<<endl;
    for (unsigned long int i = 0; i < this->qtde_tam.size(); i++){
        cout<<"-----------------------------"<<endl;
        cout<<"Tamanho: "<<this->qtde_tam[i]->getTamanho()<<endl;
        cout<<"Quantidade: "<<this->qtde_tam[i]->getQtde()<<endl;
        total+=this->qtde_tam[i]->getQtde();
    }
    cout<<"-----------------------------"<<endl;
    cout<<"Preço do pedido: "<<total*this->preco<<endl;
}

double Roupa::getPreco() const{
    return this->preco;
}
string Roupa::getTecido() const{
    return this->tecido;
}

string Roupa::getCliente() const{
    return this->cliente;
}

bool Roupa::compara(Roupa *p1, Roupa *p2){
    return p1->getCliente()<p2->getCliente();
}

int Roupa::getCodigo()const{
    return this->codigo;
}

void Roupa::setValor(double valor){
    this->preco=valor;
}

vector <qtde*> Roupa::getQtde_tam() const{
    return this->qtde_tam;
}
