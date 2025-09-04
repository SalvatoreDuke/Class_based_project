#include <iostream>
#include <stdexcept>
#include "Produto.cpp"
#include "ClienteBase.cpp"
#include "ClienteF.cpp"
#include "ClienteJ.cpp"
#include "Template.cpp"
#include "Tratamento.cpp"
#include "Pedido.h"
#include <vector>
#include <string>
using namespace std;


//funcionando!!
void exibirMenu() {
    cout << "\nMenu:\n";
    cout << " 1. Cadastrar novo produto no estoque\n";
    cout << " 2. Alterar produto no estoque\n";
    cout << " 3. Remover produto no estoque\n";
    cout << " 4. Cadastrar novo pedido\n";
    cout << " 5. Adicionar produto no pedido\n";
    cout << " 6. Remover produto do pedido\n";
    cout << " 7. Cadastrar cliente\n";
    cout << " 8. Listar todos os produtos do estoque\n";
    cout << " 9. Listar todos os pedidos cadastrados\n";
    cout << "10. Listar clientes\n";
    cout << "11. Exibir valor total das compras\n";
    cout << "12. Sair do sistema\n" <<endl;
    cout << "-------------------------------" << endl;
    cout << "Escolha uma opcao: ";

}
//funcionando!!
void cadastrarProduto(vector<Produto>& produtos) {
    int codigo, quantEstoque = 0;
    string nome;
    float preco;
    int categEscolhida;

    cout << "\nCódigo do novo produto: ";
    cin >> codigo;
    
    //Verifica se o codigo do produto já existe
        for (auto& prod : produtos) {
            //if (prod.getCodigo() == codigo) {
            if(prod == codigo) { //sobrecarga
                cout << "Esse código já existe!\n";
                return;
            }  
        }
    
        
        cout << "Nome do novo produto: ";
        cin.ignore(); //Limpa o buffer antes de getline
        getline(cin, nome);

        cout << "Preço desse produto: R$";
        cin >> preco;

        do{
            cout << "\nCategoria desse produto:" <<endl;
            cout << "0 - Alimento\n";
            cout << "1 - Bebida\n";
            cout << "2 - Eletrônico\n";
            cout << "3 - Vestuário\n";
            cout << "4 - Livro\n";
            cout << "5 - Limpeza\n";
            cout << "\nEscolha a categoria (0 a 5): " ;
            cin >> categEscolhida;
            cout << "\n";
            if(categEscolhida < 0 || categEscolhida > 5){
                cout << "Categoria inválida! Tente novamente." << endl;
            }
        }
        while(categEscolhida < 0 || categEscolhida > 5);

        Categoria categoria(static_cast<Categoria::Valor>(categEscolhida)); //Função de "categoria.cpp"

        Produto prod(codigo, nome, preco, quantEstoque, categoria);
        produtos.push_back(prod);

        //Exibe a categoria do produto cadastrado
        cout << "Produto cadastrado na categoria: " << categoria.toString() << "\n" <<endl;
        cout << "Estoque atualizado.\n";
        cout << "---------------------" << endl;
}
//funcionando!!
void alterarProduto(vector<Produto>& produtos) {
    int codigo;

    cout << "\nDigite o código do produto a alterar: ";
    cin >> codigo;

    //Procura o produto pelo código
    for (auto& prod : produtos) {
        //if (prod.getCodigo() == codigo) {
        if (prod == codigo) {
            char opcao;
            cout << "Gostaria de adicionar quantidade de produtos no estoque? (s/n): ";
            cin >> opcao;
            if(opcao == 's' || opcao == 'S'){
                int quantEstoque;
                cout << "Quantidade a adicionar: ";
                cin >> quantEstoque;
                try{
                    while(quantEstoque < 0){
                        throw QuantNegativaException(quantEstoque);
                    }
                }catch(QuantNegativaException& e){
                    cerr << e.what() << endl;
                    return;
                }
                //prod.setQuantEstoque(prod.getQuantEstoque() + quantEstoque);
                prod.setQuantEstoque(prod + quantEstoque); //sobrecarga
                cout << "Estoque atualizado.\n";
                return;
            }

            string novoNome;
            float novoPreco;
            int novaCategoria;
            //Limpa o buffer antes de getline
            cin.ignore();
            cout << "Novo nome: ";
            getline(cin, novoNome);

            cout << "Novo preço: R$";
            cin >> novoPreco;

            do{
            cout << "\nAlterar categoria:\n";
            cout << "0 - Alimento\n";
            cout << "1 - Bebida\n";
            cout << "2 - Eletrônico\n";
            cout << "3 - Vestuário\n";
            cout << "4 - Livro\n";
            cout << "5 - Limpeza\n";
            cout << "Escolha a nova categoria (0 a 5): ";
            cin >> novaCategoria;
            if(novaCategoria < 0 || novaCategoria > 5){
                cout << "Categoria inválida! Tente novamente." << endl;
                }
            }
            while(novaCategoria < 0 || novaCategoria > 5);

            //Cria nova categoria
            Categoria novaCat((Categoria::Valor)novaCategoria);

            //Atualiza os dados do produto
            prod.setNome(novoNome);
            prod.setPreco(novoPreco);
            prod.setCategoria(novaCat);  //Atualiza a categoria

            cout << "Produto alterado no estoque.\n";
            return;
        }
    }

    cout << "Produto não encontrado no estoque.\n";
}
//funcionando!!
void removerProduto(vector<Produto>& produtos) {
    int codigo;
    cout << "\nDigite o código do produto a remover: ";
    cin >> codigo;

    for (auto it = produtos.begin(); it != produtos.end(); ++it) {  //usando um interador
        if (it->getCodigo() == codigo) {
            produtos.erase(it);
            cout << "Produto removido do estoque com sucesso!" << endl;
            return;
        }
    }

    cout << "Produto não encontrado no estoque.\n";
}
//funcionando!!
void cadastrarPedido(vector<Pedido>& pedidos, vector<Produto>& produtos, vector<ClienteBase*>& clientes) {
    int numPedido;
    string descricao;

    cout << "\nDigite um número para o pedido: ";
    cin >> numPedido;

    //Verifica se o pedido já existe (sobrecarga do operador ==)
    for (auto& ped : pedidos) {
        if (ped == numPedido) {
            cout << "Já existe um pedido com esse número!" << endl;
            return;
        }
    }

    cout << "Digite a descrição do pedido: ";
    cin.ignore();
    getline(cin, descricao);

    vector<Item> itensDoPedido;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        int codProd;
        cout << "Digite o código do produto: ";
        cin >> codProd;

        //Verifica se o produto já está no pedido
        bool produtoIncluso = false;
        for (auto& item : itensDoPedido) {
            if (item.getProduto().getCodigo() == codProd) {
                cout << "Esse produto já foi incluído ao pedido!\n";
                produtoIncluso = true;
                break;
            }
        }

        if (produtoIncluso) {
            cout << "Deseja adicionar outro produto? (s/n): ";
            cin >> continuar;
            continue;
        }

        //Procura o produto no estoque
        bool produtoEncontrado = false;
        Produto* produtoPtr = nullptr;
        for (auto& prod : produtos) {
            if (prod == codProd) {
                produtoEncontrado = true;
                produtoPtr = &prod;
                break;
            }
        }

        if (!produtoEncontrado) {
            cout << "Produto não encontrado no estoque!" << endl;
            cout << "Deseja tentar outro produto? (s/n): ";
            cin >> continuar;
            continue;
        }

        int quantProd;
        cout << "Digite a quantidade: ";
        cin >> quantProd;

        try {
            //sobrecarga do operador >
            if (quantProd > *produtoPtr) {
                throw QuantInsufException(quantProd, produtoPtr);
            }

            produtoPtr->setQuantEstoque(produtoPtr->getQuantEstoque() - quantProd);
            itensDoPedido.push_back(Item(quantProd, *produtoPtr));
            cout << "Produto adicionado ao pedido! Estoque restante: "
                 << produtoPtr->getQuantEstoque() << endl;
        }
        catch (const QuantInsufException& e) {
            cerr << e.what() << endl;
        }

        //Pergunta se deseja continuar independente de sucesso ou falha
        cout << "Deseja adicionar outro produto? (s/n): ";
        cin >> continuar;
    }

    //Associação do pedido ao cliente
    char tipoCliente;
    cout << "O pedido será associado a uma conta física ou jurídica? (J ou F): ";
    cin >> tipoCliente;

    //Normaliza entrada
    if (tipoCliente == 'j') tipoCliente = 'J';
    if (tipoCliente == 'f') tipoCliente = 'F';
    while(tipoCliente != 'J' && tipoCliente != 'F') {
            throw "Tipo inválido! Digite F ou J: ";
            cin >> tipoCliente;
        
    }


    int codCliente;
    cout << "Código do cliente: ";
    cin >> codCliente;

    //Busca cliente
    ClienteBase* clienteEncontrado = nullptr;
    for (auto& cli : clientes) {
        if (cli->getCodigo() == codCliente && cli->getTipoCliente() == tipoCliente) {
            clienteEncontrado = cli;
            break;
        }
    }

    if (clienteEncontrado == nullptr) {
        cout << "Cliente não encontrado! Pedido não cadastrado." << endl;
        return;
    }

    //Cria pedido se tiver itens
    if (!itensDoPedido.empty()) {
        Pedido novoPedido(numPedido, descricao, itensDoPedido);
        novoPedido.setClienteBase(clienteEncontrado);
        pedidos.push_back(novoPedido);
        cout << "Pedido cadastrado com sucesso!" << endl;
    } else {
        cout << "Pedido não cadastrado (nenhum item adicionado)!" << endl;
    }
}
//funcionando!!
void adicionarProdutoNoPedido(vector<Pedido>& pedidos, vector<Produto>& produtos) {
    int numPedido;

    cout << "\nDigite um número para o pedido: ";
    cin >> numPedido;

    for (auto& ped : pedidos) {
        //if (ped.getNumero() == numPedido) {
        if(ped == numPedido){ //sobrecarga 
            int codProd;
            cout << "Digite o código do produto: ";
            cin >> codProd;
            //Procurar se o produto já foi incluso no pedido
            bool produtoIncluso = false;
            vector<Item> itensExistentes = ped.getItens();

            for (auto& item : itensExistentes) {
                if (item.getProduto().getCodigo() == codProd) {
                    cout << "Esse produto já foi incluído ao pedido!\n";
                    produtoIncluso = true;
                    break;
                }
            }
        if (produtoIncluso) {
            cout << "Por favor, tente outro produto.\n";
            continue; 
        }
        bool produtoEncontrado = false;
        Produto* produtoPtr = nullptr;

        for (auto& prod : produtos) {
            if (prod == codProd){
            //if (prod.getCodigo() == codProd) {
                produtoEncontrado = true;
                produtoPtr = &prod;
                break;
            }
        }
        if (!produtoEncontrado) {
            cout << "Produto não encontrado no estoque!\n";
            continue;
        }
        int quantProd;
        cout << "Digite a quantidade: ";
        cin >> quantProd;

        try {
            if (quantProd > produtoPtr->getQuantEstoque()) {
                throw QuantInsufException(quantProd, produtoPtr);
            }

            ped.adicionarItem(Item(quantProd, *produtoPtr));
            cout << "Produto adicionado ao pedido!\n";
            }
            catch (const QuantInsufException& e) {
                cerr << e.what() << endl;
                return;  //Sai da função após o erro
            }

        ped.adicionarItem(Item(quantProd, *produtoPtr));
        cout << "Produto adicionado ao pedido!\n";

        return; 
        }
    }
}
//funcionando!!
void removerProdutoDoPedido(vector<Pedido>& pedidos) {
    int numPedido, codProd;
    cout << "\nNúmero do pedido: ";
    cin >> numPedido;

    for (auto& ped : pedidos) {
        //if (ped.getNumero() == numPedido) {
        if(ped == numPedido){ //sobrecarga
            cout << "Código do produto: ";
            cin >> codProd;
            ped.removerProduto(codProd);  
            cout << "Produto removido do pedido!\n";
            return;
        }
    }
    cout << "Pedido não encontrado!\n";
}
//funcionando!!
void cadastrarCliente(vector<ClienteBase*>& clientes){ //vetor de ClienteBase
    int codigo;
    string nome, rua, num, bairro, cidade, cnpj, cpf;
    char tipoCliente, tipoCategoria;

    cout << "\nA sua conta será fisica ou juridica? (J ou F): ";
    cin >>  tipoCliente;
    
    if(tipoCliente == 'j') { tipoCliente = 'J'; } //transforma minusculo em maiusculo
    if(tipoCliente == 'f') { tipoCliente = 'F'; } //transforma minusculo em maiusculo

    while(tipoCliente != 'J' && tipoCliente != 'F') {
        cout << "Tipo inválido! Digite F ou J: ";
        cin >> tipoCliente;
    }
    
    cout << "Codigo do cliente: ";
    cin >> codigo;
    //typecliente
    for (auto& cli : clientes) {
        if (cli->getCodigo() == codigo && cli->getTipoCliente() == tipoCliente) {
        //if(cliF == cliF)
            cout << "Esse cliente já existe!\n";
            return;
        }
    }

    cout << "A sua conta será gold? (S ou N): ";
    cin >>  tipoCategoria;

    if(tipoCategoria == 's') { tipoCategoria = 'S'; } //transforma minusculo em maiusculo
    if(tipoCategoria == 'n') { tipoCategoria = 'N'; } //transforma minusculo em maiusculo

    while(tipoCategoria != 'N' && tipoCategoria != 'S') {
        cout << "Tipo inválido! Digite S ou N: ";
        cin >> tipoCategoria;
    }

    cout << "Nome do Cliente: ";
    cin.ignore(); //Limpa buffer ANTES do getline
    getline(cin, nome);

    cout << "Rua: ";
    getline(cin, rua);

    cout << "Número: ";
    getline(cin, num);

    cout << "Bairro: ";
    getline(cin, bairro);

    cout << "Cidade: ";
    getline(cin, cidade);

    Endereco end = Endereco(rua, num, bairro, cidade);

    if(tipoCliente == 'J'){
        cout << "CNPJ: ";
        cin >> cnpj;
        clientes.push_back(new ClienteJ(codigo, nome, end, tipoCliente, tipoCategoria, cnpj));
        cout << "Cliente Juridico cadastrado!\n";
    }
else {
        cout << "CPF: ";
        cin >> cpf;
        clientes.push_back(new ClienteF(codigo, nome, end, tipoCliente, tipoCategoria, cpf));
        cout << "Cliente Fisico cadastrado!\n";
    }
    cout << "---------------------" << endl;
}
//funcionando!!
void estoqueProdutos(vector<Produto>& produtos){
    cout << "\n---LISTA DE PRODUTOS---\n";
    cout << "-----------------------\n";
    for (auto& prod : produtos) {
        prod.imprimirProduto();
    }
}
//funcionando!!
void exibirPedidos(vector<Pedido>& pedidos) {
    cout << "\n---LISTA DE PEDIDOS---\n";
    cout << "----------------------\n";
    for (auto& ped : pedidos) {
        ped.exibirPedido();
        //Poderia exibir o valor de cada pedido aqui
        //ped.exibirValorCompras(pedidos);
    }
}
//funcionando!!
void listarClientes(vector<ClienteBase*>& clientes){
    cout << "\nClientes Cadastrados:\n";
    cout << "------------------------\n";
    cout << "\nClientes Jurídicos:\n";
    for (auto& cli : clientes) {
        if(cli->getTipoCliente() == 'J'){
            cli->mostrarDados();
        }    
    }
    cout << "\nClientes Fisicos:\n";
    for (auto& cli : clientes) {
        if(cli->getTipoCliente() == 'F'){
            cli->mostrarDados();
        }
    }
}
//funcionando!!
void exibirValorCompras(vector<Pedido>& pedidos) {
    int numPedido;
    cout << "\nNúmero do pedido: ";
    cin >> numPedido;

    for (auto& ped : pedidos) {
        if (ped == numPedido) {
            double valorBruto = Pedido::calcularValorBrutoPedido(ped); //uso do método static

            //Tipos de desconto
            CalculadoraDesconto<DescontoClienteOuro> calcOuro;
            CalculadoraDesconto<DescontoPorQuantidade> calcQuant;

            double descontoOuro = calcOuro.aplicarDesconto(ped); //daria pra fazer método static
            double descontoQuant = calcQuant.aplicarDesconto(ped); //daria pra fazer método static

            cout << "1. Desconto por cliente Ouro" << endl;
            cout << "2. Desconto por quantidade de itens" << endl;
            cout << "3. Desconto exclusivo para o professor Valter" << endl;
            cout << "Escolha o método de desconto: ";
            int escolha;
            cin >> escolha;
            while(escolha != 1 && escolha != 2 && escolha != 3){
                cout << "Escolha inválida! Tente novamente." << endl;
                cin >> escolha;
            }
            if(escolha == 1){
                double valorLiquido = valorBruto - descontoOuro;
                cout << "-----------------------------" << endl;
                cout << "Valor Bruto: R$" << valorBruto << endl;
                cout << "Desconto: R$" << descontoOuro << endl;
                cout << "VALOR FINAL: R$" << valorLiquido << endl;
                cout << "-----------------------------" << endl;
                return;
            }else if(escolha == 2){
                double valorLiquido = valorBruto - descontoQuant;
                cout << "-----------------------------" << endl;
                cout << "Valor Bruto: R$" << valorBruto << endl;
                cout << "Desconto: R$" << descontoQuant << endl;
                cout << "VALOR FINAL: R$" << valorLiquido << endl;
                cout << "-----------------------------" << endl;
                return;
            }
            else if(escolha == 3){
                cout << "-----------------------------" << endl;
                cout << "Valor Bruto: R$" << valorBruto << endl;
                cout << "Desconto: R$" << valorBruto << endl;
                cout << "VALOR FINAL: R$0,00" << endl;
                cout << "-----------------------------" << endl;
                return;
            }
        }
    }
    cout << "Pedido não encontrado!\n";
}
    //sobrecarga 
    bool operator>(int valor, const Produto& prod) {
        return valor > prod.quantEstoque;
    }

    //sobrecarga 
    int operator+(const Produto& prod, int valor) {
        return prod.quantEstoque + valor;
    }
    //ou
    /*int operator+(const Produto& prod, int valor) {
        return prod.quantEstoque + 1;
    }*/
    
    //sobrecarga
    /*int operator+(const Item& item, int valor) {
        return item.quantidade + valor;
    }*/

//funcionando!!
int main(){
    vector<Produto> produtos;
    vector<Pedido> pedidos;
    vector<Item> itens;
    vector<ClienteBase*> clientes;
    int opcao;
    do {
        try{
            exibirMenu();
            cin >> opcao;
            if(opcao < 1 || opcao > 12){
                throw out_of_range("Entrada inválida! Digite um número entre 1 e 12.");
            }
            switch (opcao) {
                case 1:
                    cadastrarProduto(produtos);
                    break;
                case 2:
                    alterarProduto(produtos);
                    break;
                case 3:
                    removerProduto(produtos);
                    break;
                case 4:
                    cadastrarPedido(pedidos, produtos, clientes);
                    break;
                case 5:
                    adicionarProdutoNoPedido(pedidos, produtos);
                    break;
                case 6:
                    removerProdutoDoPedido(pedidos);
                    break;
                case 7:
                    cadastrarCliente(clientes);
                    break;
                case 8:
                    estoqueProdutos(produtos);
                    break;
                case 9:
                    exibirPedidos(pedidos);
                    break;
                case 10:
                    listarClientes(clientes);
                    break;
                case 11:
                    exibirValorCompras(pedidos);
                    break; 
                case 12:
                    cout << "Saindo...\n";
                    break;
                default:
                    cout << "Opcao invalida! Tente novamente.\n";
            }
        } catch (const exception& e) {
                cerr << "Deu erro patrão: " << e.what() << endl; 
        }
    }while(opcao != 12);
    
    return 0;
}
