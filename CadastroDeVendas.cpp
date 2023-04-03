#include "CadastroDeVendas.h"
#include <fstream>
#include <algorithm>
using std::ifstream;

Cadastro::Cadastro(string fileName):fileName(fileName){
    string tamanho, tecido, cliente,vies;
    double preco;
    int quantidade,codigo;
    bool bordado,serigrafia,sublimacao;
    char elastico;
    vector <qtde*> qtde_tam;
    int produto; //camisa 1, e colete 2
    long int tam=0,tam2=0;

    ifstream entrada(fileName, std::ios::binary);

    if(entrada.is_open()){
        this->pedido.clear();

        entrada.read(reinterpret_cast<char *>(&produto), sizeof(produto));
        while(!entrada.eof()){

            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam)); //lendo string tecido
            tecido.resize((long unsigned int)tam);
            entrada.read(reinterpret_cast<char *>(&tecido[0]),tam);

            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam)); //lendo string cliente
            cliente.resize((long unsigned int)tam);
            entrada.read(reinterpret_cast<char *>(&cliente[0]),tam);

            entrada.read(reinterpret_cast<char *>(&preco), sizeof(preco));

            entrada.read(reinterpret_cast<char *>(&codigo), sizeof(codigo));

            entrada.read(reinterpret_cast<char *>(&tam2), sizeof(tam2));
            qtde_tam.resize(0);
            for (unsigned long int i = 0; i < (unsigned long int)tam2; i++){
                entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam)); 
                tamanho.resize((long unsigned int)tam);
                entrada.read(reinterpret_cast<char *>(&tamanho[0]),tam);   

                entrada.read(reinterpret_cast<char *>(&quantidade), sizeof(quantidade));

                qtde_tam.push_back(new qtde(quantidade,tamanho));         
            }
            

            switch (produto){
                case 1: {
                    entrada.read(reinterpret_cast<char *>(&bordado), sizeof(bordado));
                    entrada.read(reinterpret_cast<char *>(&serigrafia), sizeof(serigrafia));
                    entrada.read(reinterpret_cast<char *>(&sublimacao), sizeof(sublimacao));

                    this->pedido.push_back(new Camisa(qtde_tam,preco,tecido,codigo,cliente,bordado,serigrafia,sublimacao));
                    break;
                }
                case 2: {
                    entrada.read(reinterpret_cast<char *>(&elastico), sizeof(elastico));
                    entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam)); //lendo string cliente
                    vies.resize((long unsigned int)tam);
                    entrada.read(reinterpret_cast<char *>(&vies[0]),tam);
                    
                    this->pedido.push_back(new Colete(qtde_tam,preco,tecido,codigo,cliente,elastico, vies));
                    break;

                }
            }
            entrada.read(reinterpret_cast<char *>(&produto), sizeof(produto));
        }
    }
    entrada.close();
}


Cadastro::~Cadastro(){
}

bool Cadastro::adcionaPedido(){
    string tamanho, tecido, cliente,vies;
    double preco;
    int codigo;
    int servico;
    bool bordado,serigrafia,sublimacao;
    char elastico;
    char in='N';
    int produto;
    this->pedido.size()==0 ? codigo=1 : codigo = this->pedido.back()->getCodigo()+1;
    cout<<"Cadastro de Vendas: "<<endl;
    cout<<"Digite o numero do produto: Camisa-1 ou Colete-2"<<endl;
    cin>>produto;
    if(produto == 1){
        cout<<"Nome do cliente: "<<endl;
        cin>>cliente;
        std::transform(cliente.begin(), cliente.end(), cliente.begin(), ::toupper);
        cout<<"Tecido: "<<endl;
        cin>>tecido;
        cout<<"Preço de venda: "<<endl;
        cin>>preco;
        cout<<"Selecione uma das opções \n1-Bordada e Pintada\n2-Bordada e Sublimada\n3-Somente Bordada\n4-Somente Pintada\n5-Somente Sublimada"<<endl;
        cin>>servico;
        switch(servico){
            case 1:
            bordado=serigrafia=true;
            sublimacao=false;
            break;
            case 2:
            bordado=sublimacao=true;
            serigrafia = false;
            break;
            case 3:
            bordado=true;
            serigrafia=sublimacao=false;
            break;
            case 4:
            serigrafia=true;
            bordado=sublimacao=false;
            break;
            case 5:
            sublimacao=true;
            bordado=serigrafia=false;
            break;
        }
        cout<<"Insira o pedido separado por tamanho: "<<endl;
        char in='N';
        string aux1;
        int aux2;
        vector <qtde*> qtde_tam;
        while (toupper(in)=='N'){
            cout<<"Tamaho: "<<endl;
            cin>>aux1;
            cout<<"Quantidade: "<<endl;
            cin>>aux2;
            qtde_tam.push_back(new qtde(aux2,aux1));
            cout<<"Selecione ""N"" para adcionar mais um tamanho\nSelecione qualquer outra tecla para encerrar " <<endl;
            cin>>in;
        }
        
        
        this->pedido.push_back(new Camisa(qtde_tam,preco,tecido,codigo,cliente,bordado,serigrafia,sublimacao));

    }else if(produto==2){
        cout<<"Nome do cliente: "<<endl;
        cin>>cliente;
        std::transform(cliente.begin(), cliente.end(), cliente.begin(), ::toupper);
        cout<<"Tecido: "<<endl;
        cin>>tecido;
        cout<<"Preço de venda: "<<endl;
        cin>>preco;
        cout<<"selecione P para elastico preto e B para elastico branco:"<<endl;
        cin>>elastico;
        cout<<"Cor do viés:"<<endl;
        cin>>vies;
        cout<<"Insira o pedido separado por tamanho: "<<endl;
        string aux1;
        int aux2;
        vector <qtde*> qtde_tam;
        while (toupper(in)=='N'){
            cout<<"Tamaho: "<<endl;
            cin>>aux1;
            cout<<"Quantidade: "<<endl;
            cin>>aux2;
            qtde_tam.push_back(new qtde(aux2,aux1));
            cout<<"Selecione ""N"" para adcionar mais um tamanho\nSelecione qualquer outra tecla para encerrar " <<endl;
            cin>>in;
        }
        this->pedido.push_back(new Colete(qtde_tam,preco,tecido,codigo,cliente,elastico, vies));
    }
    else{
        return false;
    }
    salva();
    return true;
}

bool Cadastro::salva(){
    string tamanho, tecido, cliente,vies;
    double preco;
    int quantidade,codigo;
    bool bordado,serigrafia,sublimacao;
    char elastico;
    int produto; //camisa 1, e colete 2
    long int tam=0,tam2=0;
    Camisa *camisa;
    Colete *colete;
    vector <qtde*> qtde_tam;
    std::ofstream saida(fileName,std::ios::binary);

    std::sort(this->pedido.begin(), this->pedido.end(), Roupa::compara);

    for (unsigned long int i = 0; i < this->pedido.size(); i++){
        produto = this->pedido[i]->getProduto();
        saida.write(reinterpret_cast<char *>(&produto), sizeof(produto));

        tecido = this->pedido[i]->getTecido();
        tam = (long int)tecido.size();
        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        saida.write(reinterpret_cast<char *>(&tecido[0]),tam);   

        cliente = this->pedido[i]->getCliente();
        tam = (long int)cliente.size();
        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        saida.write(reinterpret_cast<char *>(&cliente[0]),tam);    

        preco=this->pedido[i]->getPreco();
        saida.write(reinterpret_cast<char *>(&preco), sizeof(preco));

        codigo=this->pedido[i]->getCodigo();
        saida.write(reinterpret_cast<char *>(&codigo), sizeof(codigo));
        qtde_tam.resize(this->pedido[i]->getQtde_tam().size());
        qtde_tam=this->pedido[i]->getQtde_tam();
        tam2 = (long int)qtde_tam.size();
        saida.write(reinterpret_cast<char *>(&tam2), sizeof(tam2));
        for (unsigned long int j = 0; j < (unsigned long int)tam2; j++){
            tam=(long int)qtde_tam[j]->getTamanho().size();
            tamanho=qtde_tam[j]->getTamanho();
            saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
            saida.write(reinterpret_cast<char *>(&tamanho[0]),tam);

            quantidade=qtde_tam[j]->getQtde();
            saida.write(reinterpret_cast<char *>(&quantidade), sizeof(quantidade));

        }
        
 
        switch (produto){
            case 1:{
                camisa = dynamic_cast<Camisa*>(pedido[i]);
                bordado = camisa->getBordado();
                saida.write(reinterpret_cast<char *>(&bordado), sizeof(bordado));

                serigrafia = camisa->getSerigrafia();
                saida.write(reinterpret_cast<char *>(&serigrafia), sizeof(serigrafia));

                sublimacao = camisa->getSublimacao();
                saida.write(reinterpret_cast<char *>(&sublimacao), sizeof(sublimacao));
                break;
            }
            case 2:
                colete = dynamic_cast<Colete*>(pedido[i]);
                elastico = colete->getElastico();
                saida.write(reinterpret_cast<char *>(&elastico), sizeof(elastico));

                vies = colete->getVies();
                tam = (long int)colete->getVies().size();
                string help;
                help = colete->getVies();
                saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                saida.write(reinterpret_cast<char *>(&help),(long int)tam);  
                break;
        }
    }
    saida.close();
    return true;
}

void Cadastro::imprime(string cliente) const{
    std::transform(cliente.begin(), cliente.end(), cliente.begin(), ::toupper);
    for (unsigned long int i = 0; i < this->pedido.size(); i++){
        if(this->pedido[i]->getCliente()==cliente){
            this->pedido[i]->imprime();
        }
    } 
    cout<<"==========================================="<<endl;
}

void Cadastro::imprime(int codigo) const{
    for (unsigned long int i = 0; i < this->pedido.size(); i++){
        if(this->pedido[i]->getCodigo()==codigo){
            this->pedido[i]->imprime();
        }
    } 
    cout<<"==========================================="<<endl;

}

void Cadastro::imprime() const{
    for (unsigned long int i = 0; i < this->pedido.size(); i++){
        this->pedido[i]->imprime();
    } 
    cout<<"==========================================="<<endl;

}

bool Cadastro::remove(int codigo){
    for (unsigned long int i = 0; i < this->pedido.size(); i++){
        if(this->pedido[i]->getCodigo()==codigo){
            this->pedido.erase(pedido.begin()+(long int)i);
            salva();
            return true;
        }
    } 
salva();
return false;
}

bool Cadastro::atualizaValor(int codigo){
    for (unsigned long int i = 0; i < this->pedido.size(); i++){
        if(this->pedido[i]->getCodigo()==codigo){
            cout<<"Insira o novo valor unitario: "<<endl;
            double valor;
            cin>>valor;
            this->pedido[i]->setValor(valor);
        }
    } 
    salva();
    return true;
}
