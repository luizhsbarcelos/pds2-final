#include "../include/estoque.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // Estoque_filmes* estoque = new Estoque_filmes();
  string nomeArquivo;
  bool exitloop = false;
  string comando;
  string linha;
  vector<string> linhas;
  Estoque estoque;

  while (!exitloop) {
    cin >> comando;

    if (comando == "LA") {
      // Ler arquivo de cadastro
      continue;
    }

    else if (comando == "CF") {
        estoque.Adiciona_filme();
    }

    else if (comando == "RF") {
      // Remover filme

    }

    else if (comando == "LF") {
      // Listar filmes ordenador por código ou título
      continue;
    }

    else if (comando == "CC") {
      // Cadastrar cliente
      continue;
    }

    else if (comando == "RC") {
      // Remover cliente
      continue;
    }

    else if (comando == "LC") {
      // Listar clientes ordenados por CPF ou nome
      continue;
    }

    else if (comando == "AL") {
      // Alugar filme(s)
      continue;
    }

    else if (comando == "DV") {
      // Devolver filmes(s)
      continue;
    }

    else if (comando == "FS") {
      // Finalizar sitema
      exitloop = true;
      continue;
    }
  }

  return 0;
}
