#include "Pedido.h"
#include "Produto.cpp"
#include "Tratamento.cpp"
#include <iostream>
#include <string>
#include <vector>

//Construtor com parâmetros
Pedido::Pedido(const int n, const std::string& d, const std::vector<Item>& its)
: numero(n), descricao(d), itens(its), clienteBase(nullptr) {}
Pedido::Pedido(const std::vector<Item>& its)
: itens(its), clienteBase(nullptr) {}
 
/*void Pedido::quantidade(int quantProd, Produto* produtoPtr){
    if (quantProd > *produtoPtr) {
        throw QuantInsufException(quantProd, produtoPtr);
    }
}*/

//método exibir pedido
void Pedido::exibirPedido() {
    cout << "---- PEDIDO #" << numero << " ----" << endl;
    cout << "Descrição: " << descricao << endl;

    if (clienteBase != nullptr) {
        cout << "-----CLIENTE-----" << endl;
        clienteBase->mostrarDados();
    } else {
        cout << "Cliente: Não associado!" << endl; 
    }

    cout << "---ITENS DESSE PEDIDO---" << endl;
    for (auto& item : itens) {
        item.exibirItem();
        
    }
}
//Métodos set
void Pedido::setNumero(const int n) {
    this->numero = n;
}

void Pedido::setDescricao(const std::string& d) {
    this->descricao = d;
}

void Pedido::setItens(vector<Item>& ite){
    this->itens = ite;
}

void Pedido::setClienteBase(ClienteBase* cliente){
    this->clienteBase = cliente;
}

//Métodos get
int Pedido::getNumero() const {
    return numero;
}

std::string Pedido::getDescricao() const {
    return descricao;
}

vector<Item> Pedido::getItens(){
    return this->itens;
}

ClienteBase* Pedido::getClienteBase(){
    return this->clienteBase;
}

void Pedido::removerProduto(int codigoProduto) {
    for (auto it = itens.begin(); it != itens.end(); ) {
        if (it->getProduto().getCodigo() == codigoProduto) {
            it = itens.erase(it);  // Remove o item e atualiza o iterador
        } else {
            ++it;
        }
    }
}

void Pedido::adicionarItem(const Item& novoItem) {
    itens.push_back(novoItem);
}

//Sobrecarga de == para comparar Produto com int
bool Pedido::operator==(int outroNumero) const { //funcionando!!
    return this->numero == outroNumero;
}


