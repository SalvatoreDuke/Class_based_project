#ifndef CLIENTEBASE_CPP
#define CLIENTEBASE_CPP
#include <iostream>
#include <string>
#include "Endereco.cpp"
using namespace std;

class ClienteBase {
    protected:
        int codigo;
        string nome;
        Endereco endereco;
        char tipoCliente;
        char tipoCategoria;

    public:
        ClienteBase(int codigo, string nome, Endereco& endereco)
            : codigo(codigo), nome(nome), endereco(endereco) {}
        ClienteBase(int codigo, string nome, Endereco& endereco, char tipoCliente, char tipoCategoria)
        : codigo(codigo), nome(nome), endereco(endereco), tipoCliente(tipoCliente), tipoCategoria(tipoCategoria) {}

        void setCodigo(int codigo){
            this->codigo = codigo;
        }
        int getCodigo(){
            return codigo;
        }

        void setNome(string nome){
            this->nome = nome;
        }
        string getNome(){
            return nome;
        }

        void setEndereco(Endereco& endereco){
            this->endereco = endereco;
        }
        Endereco getEndereco(){
            return this->endereco;
        }

        void setTipoCliente(char tipoCliente){
            this->tipoCliente = tipoCliente;
        }
        char getTipoCliente(){
            return this->tipoCliente;
        }

        void setTipoCategoria(char tipoCategoria){
            this->tipoCategoria = tipoCategoria;
        }
        char getTipoCategoria(){
            return this->tipoCategoria;
        }

        virtual void mostrarDados() = 0;
        //virtual double calcularDesconto(double valorBruto) const = 0;    

        virtual ~ClienteBase() {} //destrutor virtual
};
#endif