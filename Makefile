# Variáveis do compilador
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Nome do executável no Windows
TARGET = meu_programa

# Arquivos de origem
SRCS = main.cpp voo.cpp astronauta.cpp

# Arquivos objeto (gerados a partir dos arquivos de origem)
OBJS = $(SRCS:.cpp=.o)

# Regra padrão para construir o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra para construir os arquivos objeto a partir dos arquivos de origem
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e do executável no Windows
clean:
	del $(OBJS) $(TARGET)
