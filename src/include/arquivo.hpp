#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <string>
#include <vector>

class Arquivo {
private:
  std::string _nome_arquivo;
  std::string _path_arquivo = "../data/";
  std::vector<std::string> _vector_linhas;
  std::string _linha;

public:
  void ler_arquivo();
  std::vector<std::string> get_linha();
    
}
#endif



