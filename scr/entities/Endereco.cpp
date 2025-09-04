#ifndef ENDERECO_CPP
#define ENDERECO_CPP
#include <iostream>
using namespace std;

class Endereco {
    private:
        string rua;
        string numero;
        string bairro;
        string cidade;
        
    public:

    Endereco(string r, string n, string b, string c)
            : rua(r), numero(n), bairro(b), cidade(c) {}

    void exibirEndereco() {
        cout << "Endereço: " << rua << ", " << numero << ", " << bairro << ", " << cidade << endl;
    }
    void setRua(string rua){
        this->rua = rua;
    }
    string getRua(){
        return rua;
    }
    void setNumero(string numero){
        this->numero = numero;
    }
    string getNumero(){
        return numero;
    }
    void setBairro(string bairro){
        this->bairro = bairro;
    }
    string getBairro(){
        return bairro;
    }
    void setCidade(string cidade){
        this->cidade = cidade;
    }
    string getCidade(){
        return cidade;
    }
};

#endif