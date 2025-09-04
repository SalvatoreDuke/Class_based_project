#include <stdexcept>
#include <string>
#include "Produto.cpp"
using namespace std;

class QuantInsufException : public runtime_error {
    public:
        QuantInsufException(int quantProd, Produto* quantEstoque) 
        : runtime_error("Estoque insuficente para a quantidade de produtos:"){}
};

class QuantNegativaException : public std::invalid_argument {
    public:
        QuantNegativaException(int quantEstoque) 
        : invalid_argument("Valor inválido, insira apenas valores positivos ") {}
};