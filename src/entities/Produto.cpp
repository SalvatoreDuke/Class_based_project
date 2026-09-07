#include <iostream>
#include "Categoria.cpp"
#ifndef PRODUTO_CPP
#define PRODUTO_CPP

class Produto {
    private:
        int codigo;
        std::string nome;
        double preco;
        int quantEstoque;
        Categoria categoria;

    public:
    //construtor padrão 
    Produto(int c, std::string n, double p, const Categoria& cat)
        :codigo(c), nome(n), preco(p), categoria(cat) {}
    Produto(int c, std::string n, double p, int q, const Categoria& cat)
        :codigo(c), nome(n), preco(p), quantEstoque(q), categoria(cat) {}

    //método para exibir os dados de produto
void imprimirProduto(){
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Codigo: " << codigo << std::endl;
    std::cout << "Preço: " << preco << std::endl;
    std::cout << "Estoque: " << quantEstoque << std::endl;
    std::cout << "Categoria: " << categoria.toString() << std::endl;
    std::cout << "-----------------------" << std::endl;
}

    //métodos sets e gets
    void setCodigo(int codigo){
        this->codigo = codigo;
    }
    int getCodigo(){
        return codigo;
    }
    void setNome(std::string nome){
        this->nome = nome;
    }
    std::string getNome(){
        return nome;
    }
    void setPreco(double preco){
        this->preco = preco;
    }
    double getPreco(){
        return preco;
    }
    void setQuantEstoque(int quantEstoque){
        this->quantEstoque = quantEstoque;
    }
    int getQuantEstoque(){
        return quantEstoque;
    }
    void setCategoria(const Categoria& cat){
        this->categoria = cat;
    }
    Categoria getCategoria(){
      return this->categoria;
    }

    
    //Sobrecarga de == para comparar Produto com int
    bool operator==(int outroCodigo) const { //funcionando!!
        return this->codigo == outroCodigo;
    }

    //Sobrecarga de != para comparar Produto com int
    bool operator!=(int outroCodigo) const { //funcionando mas não implementado
        return this->codigo != outroCodigo;
        /*Dentro da main usar como: 
        if(prod != codigo){*/
    }

    //Sobrecarga de == para comparar Produto com outro Produto
     bool operator==(const Produto& outro) const { //funcionando mas não implementado
        return this->codigo == outro.codigo;
        /*Dentro da main usar como: 
        if(prod == prod){*/
    }

    //Sobrecarga de != para comparar Produto com outro Produto
    bool operator!=(const Produto& outro) const { //funcionando mas não implementado
        return this->codigo != outro.codigo;
        /*Dentro da main usar como: 
        if(prod != prod){*/
    }

    friend bool operator>(int valor, const Produto& prod);

    friend int operator+(const Produto& prod, int valor);

    //Declara que a classe 'Item' é uma classe amiga de 'Produto'.
    //Isso significa que TODAS as funções membro de Item
    //podem acessar os membros privados e protegidos de Produto.
    friend class Item;

};

#endif