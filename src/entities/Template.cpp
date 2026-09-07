#ifndef ESTRATEGIA_DESCONTO_H
#define ESTRATEGIA_DESCONTO_H
#include "Pedido.h"


template <typename Strategy>
class CalculadoraDesconto {
public:
    double aplicarDesconto(Pedido& pedido)  {
        Strategy estrategia;
        return estrategia.calcularDesconto(pedido);
    }
};

class EstrategiaDesconto {
public:
    virtual double calcularDesconto(Pedido& pedido)  = 0;
    virtual ~EstrategiaDesconto() = default;
};

class DescontoClienteOuro : public EstrategiaDesconto {
public:
    double calcularDesconto(Pedido& pedido)  override {
        if (ClienteBase* cliente = pedido.getClienteBase()) {
            //Verifica se é cliente "Ouro" (categoria 'S')
            if (cliente->getTipoCategoria() == 'S') {
                double valorBruto = Pedido::calcularValorBrutoPedido(pedido);
                return valorBruto * 0.15; //15% de desconto
            }
        }
        return 0.0; //Sem desconto
    }
};

class DescontoPorQuantidade : public EstrategiaDesconto {
public:
    double calcularDesconto(Pedido& pedido)  override {
        int totalItens = 0;
        for ( auto& item : pedido.getItens()) {
            totalItens += item.getQuantidade();
        }

        
        if (totalItens >= 10) { //estilo atacadão forçando a pessoa a comprar 10 produto
            double valorBruto = Pedido::calcularValorBrutoPedido(pedido);
            return valorBruto * 0.05; //5% de desconto
        }
        return 0.0; //Sem desconto
    }
};

#endif