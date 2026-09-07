#include <iostream>
#include <string>
#ifndef CATEGORIA_CPP
#define CATEGORIA_CPP
using namespace std;

class Categoria{

public:
    enum Valor{
        alimento,
        bebida,
        eletronico,
        vestuario,
        livro,
        limpeza
    };

private:
    Valor valor;

public:
    Categoria(Valor v):valor(v){}
    Categoria():valor(){} //construtor padrão

    static string toString(Valor v) {
        switch (v) {
            case alimento: return "Alimento";
            case bebida: return "Bebida";
            case eletronico: return "Eletronico";
            case vestuario: return "Vestuario";
            case livro: return "Livro";
            case limpeza: return "Limpeza";
            default: return "Desconhecido";
        }
    }

    string toString() const { 
        return toString(valor); 
    }
};

#endif