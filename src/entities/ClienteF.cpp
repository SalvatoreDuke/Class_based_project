#include "Endereco.cpp"
#include "ClienteBase.cpp"
#include "Pedido.h"
#include <iostream>
#include <string>
using namespace std;

class ClienteF : public ClienteBase {
    protected:
        string CPF;

    public:
        ClienteF (int codigo, string nome, Endereco& endereco, char tipoCliente, char tipoCategoria, string cpf)
        : ClienteBase(codigo, nome, endereco, tipoCliente, tipoCategoria), CPF(cpf)  {}

    void mostrarDados() override{
        if(tipoCategoria == 'S'){cout << "Tipo do cliente: Gold" << endl;}else cout << "Tipo do cliente: Ralé" << endl;
        //cout << "Tipo do cliente: Físico" << endl; vai ser gold
        //cout << "Tipo do cliente: " << tipoCliente << endl;
        cout << "Código: " << codigo << endl;
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << CPF << endl;
        endereco.exibirEndereco();
        cout << "---------------------" << endl;
    }
    /*double calcularDesconto(double valorBruto) const override {
        return valorBruto * 0.05; //
    }*/
    void setCPF(string cpf){
        this->CPF = cpf;
    }
    string getCPF(){
        return CPF;
    }


    //sobrecarga de operador
    /*bool operator==(int outroCodigo) const { //funcionando!!
        return this->codigo == outroCodigo;
    }*/
};
