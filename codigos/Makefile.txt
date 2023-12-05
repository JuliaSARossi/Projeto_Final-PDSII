CC = g++
CFLAGS = -std=c++11 -Wall -I./include

# Diretórios
SRC_DIR = codigos/src
INCLUDE_DIR = codigos/include
OBJ_DIR = codigos/obj
BIN_DIR = codigos/bin

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = $(BIN_DIR)/sistema_academico

# Compilação
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Limpeza
clean:
	rm -f $(OBJS) $(TARGET)

# Regras adicionais
.PHONY: all clean

# Regra padrão
all: $(TARGET)
