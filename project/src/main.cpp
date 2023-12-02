#include "../include/arquivo.hpp"
#include "../include/cadastro_clientes.hpp"
#include "../include/controle_locacao.hpp"
#include "../include/estoque.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  // Estoque_filmes* estoque = new Estoque_filmes();
  bool exitloop = false;
  string comando;
  string linhaInput;

  Estoque *estoque = new Estoque();

  while (!exitloop)
  {
    cin >> comando;

    if (comando == "LA")
    {
      // Ler arquivo de cadastro
      Arquivo arquivo_obj;
      arquivo_obj.ler_arquivo();

      // Percorre todas as linhas do arquivo
      for (auto it : arquivo_obj.get_vector_linhas())
      {
        vector<string> linha_arq = arquivo_obj.separa_palavras(it);
        // Adiciona um filme para cada linha
        if (estoque->Adiciona_filme(linha_arq))
        {
          arquivo_obj.conta_filmes();
        }
      }
      cout << arquivo_obj.get_qtd_filmes()
           << " Filmes cadastrados com sucesso\n";
    }

    else if (comando == "CF")
    {
      // Obtem a linha com informações de cadastro
      getline(cin, linhaInput);
      vector<string> infoFilme = Arquivo::separa_palavras(linhaInput);
      estoque->Adiciona_filme(infoFilme);
    }

    else if (comando == "RF")
    {
      // Remover filme
      int cdg;
      cin >> cdg;
      estoque->Remove_filme(cdg);
    }

    else if (comando == "LF")
    {
      // Listar filmes ordenador por código ou título
      estoque->listar_filmes();
    }

    else if (comando == "CC")
    {
      // Cadastrar cliente
      string cpf;
      cin >> cpf;
      string nome;
      cin >> nome;
      ControleClientes::cadastrarCliente(cpf, nome);
    }
    else if (comando == "RC")
    {
      // Remover cliente
      string cpf;
      cin >> cpf;
      ControleClientes::removerCliente(cpf);
    }

    else if (comando == "LC")
    {
      // Listar clientes ordenados por CPF ou nome
      ControleClientes::listarClientes();
    }

    else if (comando == "AL")
    {
      // Alugar filmes
      ControleLocacao::adicionarLocacao(estoque);
    }

    else if (comando == "DV")
    {
      // Devolver filmes(s)
      string cpf;
      cin >> cpf;
      int dias;
      cin >> dias;
      ControleLocacao::removerLocacao(cpf, dias);
    }

    else if (comando == "FS")
    {
      // Finalizar sitema
      exitloop = true;
    }
    else
    {
      cout << "ERRO: Comando inválido\n";
    }
  }
  delete estoque;
  return 0;
}
