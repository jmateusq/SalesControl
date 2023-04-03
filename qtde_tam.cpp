#include "qtde_tam.h"

qtde::qtde(int quantidade, std::string tamanho):quantidade(quantidade),tamanho(tamanho){
}
qtde::~qtde(){
}
bool qtde::setQtde(int quantidade){
    this->quantidade=quantidade;
    return true;
}
bool qtde::setTamanho(std::string tamanho){
    this->tamanho=tamanho;
    return true;
}
int qtde::getQtde(){
    return this->quantidade;
}
std::string qtde::getTamanho(){
    return this->tamanho;
}