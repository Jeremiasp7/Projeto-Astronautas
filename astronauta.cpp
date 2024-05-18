#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <limits>
#include "astronauta.h"

std::vector<astronauta> astronauta::astronautasCriados;

//Construtor da classe
astronauta::astronauta(const std::string& nome, int idade, const std::string& situacao, const std::string& cpf) : nome(nome), idade(idade), situacao(situacao), cpf(cpf) {}

//Getters
const std::string& astronauta::getNome() const {
    return nome;
}

int astronauta::getIdade() const {
    return idade;
}

const std::string& astronauta::getSituacao() const {
    return situacao;
}

const std::string& astronauta::getCpf() const {
    return cpf;
}

const std::vector<int>& astronauta::getVoosParticipados() const {
    return listaDeVoosParticipados;
}

//Setters
void astronauta::setNome(const std::string& nome) {
    this->nome = nome;
}

void astronauta::setIdade(int idade){
    this->idade = idade;
}

void astronauta::setSituacao(const std::string& situacao){
    this->situacao = situacao;
}

void astronauta::setCpf(const std::string& cpf){
    this->cpf = cpf;
}

void astronauta::setAstronautasCriados(astronauta astronautasCriado){
    astronautasCriados.push_back(astronautasCriado);
}

void astronauta::adicionarVoosParticipados(int numeroVoo){
    listaDeVoosParticipados.push_back(numeroVoo);
}

//Funções auxiliares
bool verificandoApenasNumeros(const std::string& str){
    for (char c : str) {
        if(!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool verificandoApenasLetras(const std::string& str) {
    for (char c : str) {
        if(!std::isalpha(c) && !std::isspace(c)) {
            return false;
        }
    }
    return true;
}

//Métodos
void cadastrarAstronauta(){
    std::string nome;
    int idade;
    std::string cpf;
    std::string situacao;
    
    int contador = 0;

    std::cout << "Digite abaixo as informações do astronauta:" << std::endl;   
    while (contador == 0) {
        std::cout << "Nome: ";
        std::getline(std::cin, nome);
        if (verificandoApenasLetras(nome)) {
            contador = 1;
        } else {
            std::cout << "Nome inválido, digite novamente" << std::endl;
        }
    }

    std::cout << "Idade: ";
    std::cin >> idade;

    int contadorAlternativo = 0;
    
    while (contador == 1) {
        std::cout << "Cpf: ";
        std::cin >> cpf; 
        if (astronauta::astronautasCriados.empty()) {
            contadorAlternativo = 1;
        } else {
            for (astronauta& astro : astronauta::astronautasCriados) {
                if (astro.getCpf() == cpf) {
                    std::cout << "Existe outro astronauta com o mesmo cpf, digite novamente." << std::endl;
                } else {
                    contadorAlternativo = 1;
                }
            }
        }
        if (verificandoApenasNumeros(cpf) && cpf.length() == 11) {
            if (contadorAlternativo == 1) {
                contador = 0;
            }
        } else {
            std::cout << "Cpf inválido, digite novamente" << std::endl;
            contadorAlternativo = 0;
        }
    }
    
    astronauta astronauta(nome, idade, "Disponível", cpf);

    astronauta::setAstronautasCriados(astronauta);

    std::cout << "Astronauta cadastrado com sucesso!" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //limpando o buffer após um getline
}

void listarAstronautasMortos(){
    int contador = 0;
    for (astronauta& astro : astronauta::astronautasCriados) {
        if (astro.getSituacao() == "morto") {
            contador+=1;
            std::cout << "Nome: " << astro.getNome() << std::endl;
            std::cout << "Cpf: " << astro.getCpf() << std::endl;
            std::cout << "Voos participados: " << std::endl;
            for (int numeroDoVoo : astro.getVoosParticipados()) {
                std::cout << "Voo: " << numeroDoVoo << std::endl;
            }
        }
    }

    if (contador == 0) {
            std::cout << "Nenhum astronauta morreu." << std::endl;
        }
}



