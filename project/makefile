# Makefile do sistema de Locadora

# Compilador
COMP = g++

# Flags do g++ / versão e Warnings
COMPFLAGS = -std=c++11 -Wall

# Diretórios do projeto
SRCDIR = src
INCLDIR = include
BUILDDIR = build

# Arquivos source
SRC = $(wildcard $(SRCDIR)/*.cpp)

# Include
INCLUDE = -I$(INCLDIR)

# Arquivos objeto
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRC))

# Nome do executável criado
EXECUTAVEL = controle_locadora

# Regras de build
all: $(BUILDDIR) $(EXECUTAVEL)

# Cria todos os arquivos objeto mantendo o nome
$(EXECUTAVEL): $(OBJ)
	$(COMP) $(COMPFLAGS) $(OBJ) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(COMP) $(COMPFLAGS) $(INCLUDE) -c $< -o $@

# Certifique-se de criar o diretório de build
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# make clean
clean:
	rm -rf $(BUILDDIR) $(EXECUTAVEL)
