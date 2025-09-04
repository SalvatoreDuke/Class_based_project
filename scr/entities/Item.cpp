#include <iostream>
#include "Produto.cpp"
#ifndef ITEM_CPP
#define ITEM_CPP

class Item {
    private:
        int numero;
        int quantidade;
        Produto produto;

    public:
    Item(Produto& produto)
        : quantidade(1), produto(produto) {}
    Item(int q, Produto& produto)
        :quantidade(q), produto(produto) {}
    Item(int n, int q, Produto& produto)
        :numero(n), quantidade(q), produto(produto) {}
    //Item::Item() {}

    void exibirItem(){
        std::cout<<"Quantidade de Itens: "<<quantidade<<std::endl;
        std::cout << "Nome: " << produto.nome << std::endl;
        std::cout << "Codigo: " << produto.codigo << std::endl;
        std::cout << "Preço: " << produto.preco << std::endl;
        std::cout << "Categoria: " << produto.categoria.toString() << std::endl;
        std::cout << "-----------------------" << std::endl;
        //produto.imprimirProduto();
    }

    void setNumero(int numero){
        this->numero = numero;
    }
    int getNumero(){
        return numero;
    }
    void setQuantidade(int quantidade){
        this->quantidade = quantidade;
    }
    int getQuantidade(){
        return quantidade;
    }
    void setProduto(Produto& produto){
        this->produto = produto;
    }
    Produto getProduto(){
        return this->produto;
    }

    //friend int operator+(const Item& item, int valor);

};
#endif