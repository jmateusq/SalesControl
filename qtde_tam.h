#ifndef QTDE_H
#define QTDE_H
#include <string>

class qtde{
    private:
        int quantidade;
        std::string tamanho;
    public:
        qtde(int quantidade, std::string tamanho);
        ~qtde();
        bool setQtde(int quantidade);
        bool setTamanho(std::string tamanho);
        int getQtde();
        std::string getTamanho();
};

#endif