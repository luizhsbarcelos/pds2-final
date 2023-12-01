#include "../include/arquivo.hpp"
#include "../include/cadastro_clientes.hpp"
#include "../include/estoque.hpp"
#include "../include/controle_locacao.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Função para processar os comandos lidos do arquivo
void processarComandos(Estoque *estoque, string comando, vector<string> parametros) {
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
        cout << arquivo_obj.get_qtd_filmes() << " Filmes cadastrados com sucesso\n";
    }
    else if (comando == "CF") {
        // Obtem a linha com informações de cadastro
        estoque->Adiciona_filme(parametros);
    }
    else if (comando == "RF") {
        // Remover filme
        int cdg = stoi(parametros[0]);
        estoque->Remove_filme(cdg);
    }
    else if (comando == "LF") {
        // Listar filmes ordenador por código ou título
        estoque->listar_filmes();
    }
    else if (comando == "CC") {
        // Cadastrar cliente
        string cpf = parametros[0];
        string nome = parametros[1];
        ControleClientes::cadastrarCliente(cpf, nome);
    }
    else if (comando == "RC") {
        // Remover cliente
        string cpf = parametros[0];
        ControleClientes::removerCliente(cpf);
    }
    else if (comando == "LC") {
        // Listar clientes ordenados por CPF ou nome
        ControleClientes::listarClientes();
    }
    else if (comando == "AL") {
        // Alugar filmes
        /*string cpf = parametros[0];
        vector<int> codigos;
        for (size_t i = 1; i < parametros.size(); ++i) {
            codigos.push_back(stoi(parametros[i]));
        }
        Controle_locacao::alugar(cpf, codigos);*/
    }
    else if (comando == "DV") {
        // Devolver filmes(s)
        /*string cpf = parametros[0];
        int dias = stoi(parametros[1]);
        Controle_locacao::devolver(cpf, dias);*/
    }
    else if (comando == "FS") {
        // Finalizar sistema
        delete estoque;
        exit(0);
    }
    else {
        cout << "ERRO: Comando inválido\n";
    }
}

int main() {
  bool exitloop = false;
  string comando;
  string linhaInput;

  Estoque *estoque = new Estoque();

  cout << "Deseja carregar os comandos de um arquivo? (S/N): ";
  char resposta;
  cin >> resposta;

  if (resposta == 'S' || resposta == 's') {
    // Abre o arquivo de comandos
    ifstream arquivoComandos("comandos.txt");
    if (!arquivoComandos.is_open()) {
      cout << "Erro ao abrir o arquivo de comandos.\n";
      return 1;
    }

    // Loop para ler os comandos do arquivo
    while (!exitloop && arquivoComandos >> comando) {
        vector<string> parametros;
        string linha;
        getline(arquivoComandos, linha);
        parametros = Arquivo::separa_palavras(linha);

        processarComandos(estoque, comando, parametros);
    }

    // Fecha o arquivo após a leitura
    arquivoComandos.close();
  } else {
    // Loop para ler comandos manualmente
    while (!exitloop) {
      cout << "Digite um comando (ou 'FS' para sair): ";
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

      } else if (comando == "CF") {
        // Obtem a linha com informações de cadastro
        getline(cin, linhaInput);
        vector<string> infoFilme = Arquivo::separa_palavras(linhaInput);
        estoque->Adiciona_filme(infoFilme);

      } else if (comando == "RF") {
        // Remover filme
        int cdg;
        cin >> cdg;
        estoque->Remove_filme(cdg);

      } else if (comando == "LF") {
        // Listar filmes ordenador por código ou título
        estoque->listar_filmes();

      } else if (comando == "CC") {
        // Cadastrar cliente
        string cpf;
        cin >> cpf;
        string nome;
        cin >> nome;
        ControleClientes::cadastrarCliente(cpf, nome);

      } else if (comando == "RC") {
        // Remover cliente
        string cpf;
        cin >> cpf;
        ControleClientes::removerCliente(cpf);

      } else if (comando == "LC") {
        // Listar clientes ordenados por CPF ou nome
        ControleClientes::listarClientes();

      } else if (comando == "AL") {
        // Alugar filmes

      } else if (comando == "DV") {
        // Devolver filmes(s)

      } else if (comando == "FS") {
        // Finalizar sitema
        exitloop = true;

      } else {
        exitloop = true;
        cout << "ERRO: Comando inválido\n";
      }
    }
  }

  delete estoque;
  return 0;
}
