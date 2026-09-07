#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include "Produto.cpp"
#include "ClienteBase.cpp"
#include <string>
#include <vector>
#include "Item.cpp"

class Pedido{
    private:
        int numero;
        std::string descricao;
        vector<Item> itens;
        ClienteBase* clienteBase;

    public:
        //const da descrição pode ser removido para alterar a descrição do pedido
        Pedido(const int n, const std::string& d, const std::vector<Item>& its);
        Pedido(const std::vector<Item>& its);
         
        void adicionarItem(const Item& novoItem);

        //método exibir pedido
        void exibirPedido();

        //void quantidade(int quantProd, Produto* produtoPtr);


    //funcionando!!
    static double calcularValorBrutoPedido(Pedido& ped) {
        double total = 0.0;
        for (auto& item : ped.getItens()) { //sobrecarga com pedido[]
            total += item.getQuantidade() * item.getProduto().getPreco(); //total += pedido[i].getQuantidade * pedido[i].getProduto.getPreco
        }
        return total;
    }

        void setNumero(const int n);
        int getNumero()const;

        void setDescricao(const std::string& d);
        std::string getDescricao()const;

        void setItens(vector<Item>&);
        vector<Item> getItens();

        void setClienteBase(ClienteBase* cliente);
        ClienteBase* getClienteBase();

        void removerProduto(int codigoProduto);

        bool operator==(int outroCodigo) const;
};

#endif

