# Variáveis
CC = g++
CXXFLAGS = -std=c++11 -Wall
OBJ_DIR = coverage
BIN = testa_SDES
SRC = SDES.cpp testa_SDES.cpp
HEADERS = SDES.hpp
OBJS = $(OBJ_DIR)/SDES.o

# Alvo default
all: $(BIN)

# Compilar e rodar o programa
$(BIN): $(OBJS) testa_SDES.cpp $(HEADERS)
	$(CC) $(CXXFLAGS) $(OBJS) testa_SDES.cpp -o $(BIN)
	./$(BIN)

# Gerar o objeto no diretório de objetos
$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

# Criar o diretório de objetos
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rodar os testes
test: $(BIN)
	./$(BIN)

# Verificar o código com cpplint
cpplint: $(SRC) $(HEADERS)
	cpplint --filter=-whitespace/tab $(SRC)

# Limpar arquivos temporários
clean:
	@if [ "$(OS)" = "Windows_NT" ]; then \
		del /f /q $(OBJ_DIR)\*.o $(BIN).exe *.gc* 2>nul || exit 0; \
	else \
		rm -rf $(OBJ_DIR) $(BIN) *.gc*; \
	fi

# Dependências automáticas
-include $(OBJ_DIR)/*.d

# Gerar arquivos de dependência
$(OBJ_DIR)/%.d: %.cpp | $(OBJ_DIR)
	@$(CC) $(CXXFLAGS) -MM -MT "$(@:.d=.o)" $< -MF $@

.PHONY: all test clean cpplint

	
	
