#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct product{
    string nameProduct;
    float price;
    int codeProduct;
    int quantityProduct;
    int quantityProductV;

} structProducts;



int main(){

    int opcao;
    string nomeBuscado;
    float totalVendas = 0;
    vector<product> produtos;

    do{
        product newProduct;

        cout << "Escolha uma opcao: " << endl;
        cout << "1 - cadastrar produto" << endl;
        cout << "2 - Listar produtos" << endl;
        cout << "3 - Buscar por nome" << endl;
        cout << "4 - Realizar venda" << endl;
        cout << "5 - sair" << endl; 
        cin >> opcao;
        cin.ignore();

        switch (opcao){
        case 1:

            cout << "Digite o nome do produto: " << endl;
            getline(cin, newProduct.nameProduct);

            cout << "Digite o codigo do produto: " << endl;
            cin >> newProduct.codeProduct;

            cout << "Digite o preco do produto: " << endl;
            cin >> newProduct.price;
            
            cout << "Digite a quantidade em estoque: " << endl;
            cin >> newProduct.quantityProduct;

            produtos.push_back(newProduct);
            cin.ignore();
        break;
        case 2:
            cout << "Lista de produtos: " << endl;
            for(int i = 0; i < produtos.size(); i++){
                cout << "Produto: " << produtos[i].nameProduct << endl;
                cout << "Nome: " << produtos[i].nameProduct << endl;
                cout << "Codigo: " << produtos[i].codeProduct << endl;
                cout << "Preco: " << produtos[i].price << endl;
                cout << "Quantidade: " << produtos[i].quantityProduct << endl;
                cout << "-------------------------------------------------------" << endl;
            }
            
        break;
        case 3:{
            
            cout << "Digite o nome do produto: " << endl;
            getline(cin, nomeBuscado);
            
            auto it = find_if(produtos.begin(), produtos.end(), [&](const product& p) {
            return p.nameProduct == nomeBuscado;
        });

         if (it != produtos.end()) {
            cout << "Produto encontrado:" << endl;
            cout << "Nome: " << it->nameProduct << endl;
            cout << "Codigo: " << it->codeProduct << endl;
            cout << "Preco: " << it->price << endl;
            cout << "Quantidade: " << it->quantityProduct << endl;
        } else {
            cout << "Produto nao encontrado." << endl;
        }

        break;
        cin.ignore();
    }
    case 4:{
            cout << "Digite o nome do produto para comprar: " << endl;
            getline(cin, nomeBuscado);
            
            auto it = find_if(produtos.begin(), produtos.end(), [&](const product& p) {
                return p.nameProduct == nomeBuscado;
            });

            if (it != produtos.end()) {
                int quantidadeComprar;
                cout << "Digite a quantidade que deseja comprar: " << endl;
                cin >> quantidadeComprar;
                
                if(quantidadeComprar <= it->quantityProduct){
                    it->quantityProduct -= quantidadeComprar;
                    float valorVenda = quantidadeComprar * it->price;
                    totalVendas += valorVenda;

                    cout << "Produto vendido com sucesso!" << endl;
                    cout << "Quantidade comprada: " << quantidadeComprar << endl;
                    cout << "Valor total da compra: R$ " << valorVenda << endl;
                }else{
                    cout << "Quantidade indisponivel em estoque!" << endl;                
                }
                cout << "Produto nao encontrado!" << endl;
        }
        break;
    }

    case 5:

        cout << "Encerrando programa" << endl;
        cout << "Total de vendas do dia: RS$ " << totalVendas << endl;
        break;
        
        default:
            cout << "Opcao Invalida!" <<  endl;
            break;
        }
    } while (opcao != 5);   

    return 0;
}