#include <iostream>
#include <string>
#include <vector>

using namespace std;

string busca;

struct Pessoa {
    string nome;
    float altura;
    float peso;
    int idade;
    float imc;
};


vector<Pessoa> pessoas; // Vetor para armazenar os skates cadastrados

void cadastrarPessoa() {
    Pessoa pessoa;
    cout << "Nome da Pessoa: ";
    cin.ignore(); 
    getline(cin, pessoa.nome);

    cout << "Idade: ";
    cin >> pessoa.idade;

    cout << "Altura: ";
    cin >> pessoa.altura;

    cout << "Peso: ";
    cin >> pessoa.peso;

   pessoa.imc = pessoa.peso / (pessoa.altura * pessoa.altura);
    cout << "Seu IMC: " << pessoa.imc << endl;

    pessoas.push_back(pessoa); // Adiciona a pessoa ao vetor de pessoa
    cout << " Cadastrado com sucesso!\n";

}


void pessoasCad() {
    if (pessoas.empty()) { // Verifica se o vetor de pessoas está vazio
        cout << "Nenhuma pessoa cadastrada.\n";
        return;
    }

    cout << "Lista todas as pessoas cadastradas:\n";
    for (const Pessoa& pessoa : pessoas) { // Loop para percorrer as pessoas cadastrados
        cout << "Nome: " << pessoa.nome << "\n";
        cout << "Idade: " << pessoa.idade << "\n";
        cout << "Altura: " << pessoa.altura << "\n";
        cout << "Peso: " << pessoa.peso << "\n";
        cout << "IMC: " << pessoa.imc << "\n";
      
    }
}

void buscaPessoas() {

    cout << "Digite o nome: " << endl;
    cin.ignore();
    getline(cin, busca);

    for (const Pessoa& pessoa : pessoas) {
        if (pessoa.nome == busca) {
            cout << "Nome: " << pessoa.nome << "\n";
            cout << "Idade: " << pessoa.idade << "\n";
            cout << "Altura: " << pessoa.altura << "\n";
            cout << "Peso: " << pessoa.peso << "\n";
            cout << "IMC: " << pessoa.imc << "\n";
        }
    }
}
  
int main() {
    int opcao;

    do {
        cout << "=========== Menu ===========\n";
        cout << "1 - Cadastrar Pessoa\n";
        cout << "2 - Listar pessoas cadastradas\n";
        cout << "3 - Pesquisar por nome\n";
        cout << "4 - Sair\n";
        cout << "============================\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cadastrarPessoa(); // Chama a função para cadastrar uma nova Pessoa
            break;
        case 2:
            pessoasCad(); // Chama a função para exibir a lista de Pessoas cadastrados
            break;
        case 3:
            buscaPessoas(); // Chama a função para exibir a pesquisa por nomes
            break;
        case 4:
            cout << "Saindo...\n"; 
            break;
        default:
            cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 4);

    return 0;
}