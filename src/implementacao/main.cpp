#include "../include/arquivo.hpp"
#include "../include/estoque.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // Estoque_filmes* estoque = new Estoque_filmes();
  bool exitloop = false;
  string comando;

  Estoque *estoque = new Estoque();

  while (!exitloop) {
    cin >> comando;

    if (comando == "LA") {
      // Ler arquivo de cadastro
      Arquivo arquivo_obj;
      arquivo_obj.ler_arquivo();

      // Percorre todas as linhas do arquivo
      for (auto it : arquivo_obj.get_vector_linhas()) {
        vector<string> linha_arq = arquivo_obj.separa_palavras(it);
        // Adiciona um filme para cada linha
        estoque->Adiciona_filme(linha_arq);
        arquivo_obj.conta_filmes();
      }
      cout << arquivo_obj.get_qtd_filmes()
           << " Filmes cadastrados com sucesso\n";

    }

    else if (comando == "CF") {
      // Obtem a linha com informações de cadastro
      string linhaInput;
      getline(cin, linhaInput);
      vector<string> infoFilme = Arquivo::separa_palavras(linhaInput);
      estoque->Adiciona_filme(infoFilme);
    }

    else if (comando == "RF") {
      // Remover filme
      int cdg;
      cin >> cdg;
      estoque->Remove_filme(cdg);
    }

    else if (comando == "LF") {
      // Listar filmes ordenador por código ou título
      estoque->listar_filmes();
    }

    else if (comando == "CC") {
      // Cadastrar cliente
      
    }

    else if (comando == "RC") {
      // Remover cliente
      
    }

    else if (comando == "LC") {
      // Listar clientes ordenados por CPF ou nome
      
    }

    else if (comando == "AL") {
      // Alugar filme(s)
      
    }

    else if (comando == "DV") {
      // Devolver filmes(s)
      
    }

    else if (comando == "FS") {
      // Finalizar sitema
      exitloop = true;
    }
    else {
      exitlopp = true;
      cout << "ERRO: Comando inválido\n";
    }
  }

  delete estoque;
  return 0;
}
