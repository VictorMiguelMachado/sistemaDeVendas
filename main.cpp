#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct product{
    string nameProduct;
    float price;
    int codeProduct;
    int quantityProduct;

} structProducts;

int main(){

    int opcao;
    vector<product> produtos;

    do{
        product newProduct;

        cout << "Escolha uma opcao: " << endl;
        cout << "1 - cadastrar produto" << endl;
        cout << "2 - Listar produtos" << endl;
        cout << "3 - Buscar por nome" << endl;
        cout << "4 - sair" << endl; 
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
        default:
            cout << "Opcao Invalida!" <<  endl;
            break;
        }
    } while (opcao != 4);   

    return 0;
}