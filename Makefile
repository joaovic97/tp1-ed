CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = processador_datas
SRC = processador_datas.cpp
OUTPUT_FILE = saida.txt

all:
	@if [ -f $(OUTPUT_FILE) ]; then \
		rm -f $(OUTPUT_FILE); \
	fi
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)
	@./$(TARGET)

.PHONY: all