
# Gestor de Vendas de Roupas

Um gestor (via terminal) de vendas de roupas personalizadas. Tendo a opção de cadastrar coletes ou camisas.


# Classes

* O codigo possui 6 classes:  
    - Roupa - Classe mãe que tem como subclasses cada tipo possivel de roupa  
    - Camisa - subclasse da classe roupa, sendo a classe responsavel por armazenar os dados de um pedido de camisas 
    - Colete - subclasse da classe roupa, sendo a classe responsavel por armazenar os dados de um pedido de coletes  
    - Cadastro - Classe que gerencia as operações CRUD e a iteração usuario/programa
    - qtde - Classe associada a classe roupa, sendo a classe responsavel por atrelar os dados de tamanho e quantidade em um unico elemento. Assim, não limitando o pedido a um unico tamanho por pedido


# Metodos de cada classe
* Roupa  
    - Roupa(vector <qtde*> qtde_tam,double preco, string tecido, int codigo,string cliente) - Construtor
    - virtual ~Roupa() - Destrutor
    - virtual void imprime() const - Imprime as informações do objeto Roupa 
    - getter's e setter's tem o funcionamento padrão desse tipo de método  
*  Camisa  
    - Camisa(vector <qtde*> qtde_tam,double preco, string tecido, int codigo,string cliente,bool bordado, bool serigrafia, bool sublimacao) - Construtor
    - virtual ~Camisa() - Destrutor
    - virtual void imprime() const - Imprime as informações de Camisa chamando também o imprime de Roupa
    - getter's e setter's tem o funcionamento padrão desse tipo de método
* Colete
    - Colete(vector <qtde*> qtde_tam,double preco, string tecido, int codigo,string cliente, char elastico, string vies) - Construtor
    - virtual ~Colete() - Destrutor
    - virtual void imprime() const - Imprime as informações de Colete chamando também o imprime de Roupa
    -  getter's e setter's tem o funcionamento padrão desse tipo de método
* Cadastro
    - Cadastro(string fileName) - Construtor que recebe o nome do arquivo
    - virtual ~Cadastro() - Destrutor
    - bool adcionaPedido() - Metodo responsavel por adcionar pedidos (ou seja, adcionar um objeto de Camisa ou Colete)
    - void imprime() - Imprime a lista de pedidos ordenada pelo nome dos clientes
    - void imprime(int codigo) const - imprime o pedido nro:  codigo
    - void imprime(string cliente) const - imprime todos os pedidos desse cliente
    - bool remove(int codigo) - Remoce o pedido Nro: codigo
    - bool atualizaValor(int codigo) - Atualiza o valor unitário da peça do pedido nro: codigo
* qtde  
    - qtde(int quantidade, std::string tamanho):quantidade(quantidade),tamanho(tamanho) - Construtor
    - virtual ~qtde() - Destrutor
    - getter's e setter's tem o funcionamento padrão desse tipo de método


# Instruções para compilação
A compilação desse codigo é bem simples.  

Se você usa Alguma base ubuntu LTS >= 22.04 O executavel pronto deve funcionar

Abaixo segue o paso a passo para linux para gerar o executavel "Sales" que pode ser executado no terminal por um ./Sales  

1 - Instale o g++ em sua distribuição  
2 - Para compilar rode o comando:   
g++ CadastroDeVendas.cpp Camisa.cpp Colete.cpp qtde_tam.cpp Roupa.cpp main.cpp -o Sales
