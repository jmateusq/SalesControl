#ifndef QTDE_H
#define QTDE_H
#include <string>

class qtde{
    private:
        int quantidade;
        std::string tamanho;
    public:
        qtde(int quantidade, std::string tamanho):quantidade(quantidade),tamanho(tamanho){
        }
        virtual ~qtde(){
        }
        bool setQtde(int quantidade){
            this->quantidade=quantidade;
            return true;
        }
        bool setTamanho(std::string tamanho){
            this->tamanho=tamanho;
            return true;
        }
        int getQtde(){
            return this->quantidade;
        }
        std::string getTamanho(){
            return this->tamanho;
        }
};

#endif