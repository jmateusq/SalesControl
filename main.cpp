#include "Roupa.h"
#include "Camisa.h"
#include "Colete.h"
#include "CadastroDeVendas.h"

int main(){
    Cadastro cadastro("arquivo.dat");
    char op='T';
    string espera;
    string cliente;
    int codigo;

    
do {
    switch (toupper(op)) {
        case 'T':{
            cout<<"Selecione uma função"<<endl;
            cout<<"A - Adcionar venda"<<endl;
            cout<<"L - Lista Pedidos"<<endl;
            cout<<"C - Lista Pedidos do cliente"<<endl;
            cout<<"D - Mostra pedido pelo codigo"<<endl;
            cout<<"A - Adcionar venda"<<endl;
            cout<<"S - Altera Valor unitario por peça do pedido (pelo codigo)"<<endl;
            cout<<"R - Remove Pedido"<<endl;
            cout<<"F - Fechar Programa"<<endl;
            cin>>op;
            system("clear||cls");
            break;
        }
        case 'L': { 
            cadastro.imprime();
            cout<<"Envie qualquer tecla para sair"<<endl;
            cin>>espera;
            system("clear||cls");
            op='T';
            break;
        }
        case 'C': {
            cout << "Cliente: ";
            cin >> cliente;
            cadastro.imprime(cliente);
            cout<<"Envie qualquer tecla para voltar ao menu"<<endl;
            cin>>espera;
            system("clear||cls");
            op='T';
            break;
        }
        case 'D': {
            cout << "Codigo: ";
            cin >> codigo;
            cadastro.imprime(codigo);
            cout<<"Envie qualquer tecla para voltar ao menu"<<endl;
            cin>>espera;
            system("clear||cls");
            op='T';
            break;
        }
        case 'A': {
            cadastro.adcionaPedido();
            cout<<"Envie qualquer tecla para voltar ao menu"<<endl;
            cin>>espera;
            system("clear||cls");
            op='T';
            break;
        }
        case 'S': {
            cout << "Codigo: "<<endl;
            cin >> codigo;
            bool ok = cadastro.atualizaValor(codigo);
            cout << (ok ? "Valor atualizado. \nPedido atualizado:" : "Valor não atualizado") << endl;
            cadastro.imprime(codigo);
            cout<<"Envie qualquer tecla para voltar ao menu"<<endl;
            cin>>espera;
            system("clear||cls");
            op='T';
            break;
        }
        case 'R': {
            cout << "Codigo: ";
            cin >> codigo;
            bool ok = cadastro.remove(codigo);
            cout << (ok ? "PEDIDO REMOVIDO" : "ERRO: Pedido NÃO removido") << endl;
            cout<<"Envie qualquer tecla para voltar ao menu"<<endl;
            cin>>espera;
            system("clear||cls");
            op='T';
            break;
        }
    }
    cout << endl;
} while (toupper(op) != 'F');

    return 0;
}