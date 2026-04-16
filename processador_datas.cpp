#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

struct Pessoa {
    std::string nome;
    std::vector<std::string> datas;
};

// Função para converter data no formato DDMMYY para um número comparável
int converterDataParaNumero(const std::string& data) {
    if (data.length() != 6) return 0;
    
    int dia = std::stoi(data.substr(0, 2));
    int mes = std::stoi(data.substr(2, 2));
    int ano = std::stoi(data.substr(4, 2));
    
    // Adicionar 2000 para anos entre 00-99 (assumindo anos 2000-2099)
    // Você pode ajustar isso conforme necessário
    if (ano < 100) {
        ano += 2000;
    }
    
    // Retornar um número no formato AAAAMMDD para fácil comparação
    return ano * 10000 + mes * 100 + dia;
}

// Função para ordenar datas cronologicamente
void ordenarDatas(std::vector<std::string>& datas) {
    std::sort(datas.begin(), datas.end(), 
        [](const std::string& a, const std::string& b) {
            return converterDataParaNumero(a) < converterDataParaNumero(b);
        });
}

// Função para ler arquivo de entrada
bool lerArquivo(const std::string& nomeArquivo, std::vector<Pessoa>& pessoas) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro: Não foi possível abrir o arquivo " << nomeArquivo << std::endl;
        return false;
    }
    
    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;
        
        // Encontrar onde termina o nome (até encontrar o primeiro dígito)
        size_t pos = 0;
        while (pos < linha.length() && !std::isdigit(linha[pos])) {
            pos++;
        }
        
        if (pos == 0 || pos >= linha.length()) {
            std::cerr << "Linha inválida: " << linha << std::endl;
            continue;
        }
        
        std::string nome = linha.substr(0, pos);
        
        // Extrair as 3 datas (cada uma com 6 caracteres)
        std::vector<std::string> datas;
        for (int i = 0; i < 3; i++) {
            size_t inicioData = pos + i * 6;
            if (inicioData + 6 <= linha.length()) {
                std::string data = linha.substr(inicioData, 6);
                datas.push_back(data);
            }
        }
        
        if (datas.size() == 3) {
            pessoas.push_back({nome, datas});
        }
    }
    
    arquivo.close();
    return true;
}

// Função para escrever arquivo de saída
bool escreverArquivo(const std::string& nomeArquivo, const std::vector<Pessoa>& pessoas) {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro: Não foi possível criar o arquivo " << nomeArquivo << std::endl;
        return false;
    }
    
    for (const auto& pessoa : pessoas) {
        arquivo << pessoa.nome;
        for (const auto& data : pessoa.datas) {
            arquivo << data;
        }
        arquivo << std::endl;
    }
    
    arquivo.close();
    return true;
}

int main() {
    std::string arquivoEntrada = "entrada.txt";
    std::string arquivoSaida = "saida.txt";
    
    std::vector<Pessoa> pessoas;
    
    // Ler arquivo de entrada
    std::cout << "Lendo arquivo " << arquivoEntrada << "..." << std::endl;
    if (!lerArquivo(arquivoEntrada, pessoas)) {
        return 1;
    }
    
    if (pessoas.empty()) {
        std::cout << "Nenhum dado válido encontrado no arquivo." << std::endl;
        return 1;
    }
    
    // Ordenar datas de cada pessoa cronologicamente
    std::cout << "Ordenando datas cronologicamente..." << std::endl;
    for (auto& pessoa : pessoas) {
        ordenarDatas(pessoa.datas);
    }
    
    // Ordenar pessoas alfabeticamente pelo nome
    std::cout << "Ordenando nomes alfabeticamente..." << std::endl;
    std::sort(pessoas.begin(), pessoas.end(),
        [](const Pessoa& a, const Pessoa& b) {
            return a.nome < b.nome;
        });
    
    // Escrever arquivo de saída
    std::cout << "Escrevendo arquivo " << arquivoSaida << "..." << std::endl;
    if (!escreverArquivo(arquivoSaida, pessoas)) {
        return 1;
    }
    
    // Exibir resultado
    std::cout << "\nProcessamento concluído com sucesso!" << std::endl;
    std::cout << "Resultado:" << std::endl;
    for (const auto& pessoa : pessoas) {
        std::cout << pessoa.nome;
        for (const auto& data : pessoa.datas) {
            std::cout << data;
        }
        std::cout << std::endl;
    }
    
    return 0;
}