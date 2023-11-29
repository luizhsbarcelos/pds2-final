#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//#include "estoque.hpp"

int main()
{   
    //Estoque_filmes* estoque = new Estoque_filmes();
    std::string nomeArquivo;
    bool exitLoop = false;
    std::string comando;
	std::string linha;

    while(!exitloop)
    {
    	std::cin >> comando;   

        switch (comando)
        {
            case "LA":  // Ler arquivo de cadastro
        		std::cin >> nomeArquivo;
				std::ifstream arquivo(nomeArquivo);
				// Checa se o arquivo está aberto
				if (!arquivo.is_open())
				{
					std::cout << "ERRO: arquivo inexistente\n";
					break;
				}
				// Cadastro dos filmes
				while (std::getline(arquivo, linha))
				{
                    
				}
		}

            case "CF":
                break;  // Cadastrar filme

            case "RF":  // Remover filme
                break;

            case "LF":  // Listar filmes ordenador por código ou título
                break;

            case "CC":  // Cadastrar cliente
                break;

            case "RC":  // Remover cliente
                break;

            case "LC":  // Listar clientes ordenados por CPF ou nome
                break;

            case "AL":  // Alugar filme(s) 
                break;

            case "DV":  // Devolver filmes(s)
                break;

            case "FS":  // Finalizar sitema
                exitloop == true;
                break;

            default:
                exitloop == true;    // Default finaliza o sistema
        }

    }


    return 0;
}
