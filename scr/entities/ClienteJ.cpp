#include "Endereco.cpp"
#include "ClienteBase.cpp"
#include "Pedido.h"
#include <iostream>
#include <string>
using namespace std;

class ClienteJ : public ClienteBase {
    protected:
        string CNPJ;

    public:
    ClienteJ(int codigo, string nome, Endereco& endereco, char tipoCliente, char tipoCategoria, string cnpj)
        : ClienteBase(codigo, nome, endereco, tipoCliente, tipoCategoria), CNPJ(cnpj) {}

    void mostrarDados() override{
        if(tipoCategoria == 'S'){cout << "Tipo do cliente: Gold" << endl;} else cout << "Tipo do cliente: Ralé" << endl;
        //cout << "Tipo do cliente: Jurídico" << endl; vai ser gold
        //cout << "Tipo do cliente: " << tipoCliente << endl;
        cout << "Código: " << codigo << endl;
        cout << "Nome: " << nome << endl;
        cout << "CNPJ: " << CNPJ << endl;
        endereco.exibirEndereco();
        cout << "---------------------" << endl;
    }

    /*double calcularDesconto(double valorBruto) const override {
        return valorBruto * 0.10; //10% desconto
    }*/

    void setCPNJ(string cnpj){
        this->CNPJ = cnpj;
    }
    string getCNPJ(){
        return CNPJ;
    }
    //sobrecarga de operador
    bool operator==(int outroCodigo) const { //funcionando!!
        return this->codigo == outroCodigo;
    }
};