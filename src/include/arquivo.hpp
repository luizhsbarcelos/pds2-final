#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <string>
#include <vector>


class Arquivo {
private:
  int qtd_filmes_arquivo = 0;
  std::string _nome_arquivo;
  std::vector<std::string> _vector_linhas;
  std::string _linha;

public:
  void ler_arquivo();
  void conta_filmes();
  int get_qtd_filmes();
  std::vector<std::string> get_vector_linhas();
  // Método estático para ser acessado sem necessidade de objeto
  static std::vector<std::string> separa_palavras(std::string str);
  // Construtor e destrutor default
  Arquivo();
  ~Arquivo();

};

#endif

