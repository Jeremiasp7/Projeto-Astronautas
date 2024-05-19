#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "voo.h"
#include "astronauta.h"

//Lista com todos os voos criados
std::vector<voo> voo::voosCriados;

//Construtor da classe
voo::voo(int codigoDeVoo, const std::vector<std::string>& listaDePassageiros, const std::string& situacao) : codigoDeVoo(codigoDeVoo), listaDePassageiros(listaDePassageiros), situacao(situacao) {}

//Getters
int voo::getCodigoDeVoo() const {
    return codigoDeVoo;
}

const std::vector<std::string>& voo::getlistaDePassageiros() const{
    return listaDePassageiros;
}

const std::string& voo::getSituacao() const {
    return situacao;
}

//Setters
void voo::setCodigoDeVoo(int codigoDeVoo) {
    this->codigoDeVoo = codigoDeVoo;
}

void voo::setListaDePassageiros(const std::string cpfDoAstronauta) {
    listaDePassageiros.push_back(cpfDoAstronauta);
}

void voo::setSituacao(const std::string situacao) {
    this->situacao = situacao;
}

void voo::setVoosCriados(voo voos) {
    voosCriados.push_back(voos);
}

//Funções auxiliares
bool verificandoApenasNumerosAstronautas(const std::string& str){
    for (char c : str) {
        if(!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

//Métodos
void cadastrarVoo() {
    int codigoDoVoo;
    int numeroDePassageiros;
    std::string cpfDoPassageiro;
    std::vector<std::string> listaDePassageiros;

    int contador = 0;
    int segundoContador = 0;
    int contadorAlternativo = 0;

    std::cout << "Digite abaixo as informações do voo: " << std::endl;
    while (contador == 0) { 
        std::cout << "Código(3 números): ";
        std::cin >> codigoDoVoo;
        if(voo::voosCriados.empty()) {
            contadorAlternativo = 1;
        } else {
            for (voo& voo : voo::voosCriados) {
                if (voo.getCodigoDeVoo() == codigoDoVoo) {
                    std::cout << "Existe um voo com esse mesmo código. Digite novamente." << std::endl;
                } else {
                    contadorAlternativo = 1; 
                }
            }
        }
        std::string intParaString = std::to_string(codigoDoVoo);
        if (intParaString.length() != 3) {
            std::cout << "Código inválido, digite novamente." << std::endl;
            contadorAlternativo = 0;
        } else {
             if (contadorAlternativo == 1) {
                contador = 1;
             }
        }
        
    }
    
    std::cout << "Informe quantos astronautas estarão no voo: ";
    std::cin >> numeroDePassageiros;
    for (int i = 0; i < numeroDePassageiros; i++) { //For para cadastrar a quantidade de passageiros informada pelo usuário
        contador = 1;
        while (contador == 1) { //While para verificar se existe algum astronauta com esse cpf
            segundoContador = 0;
            while (segundoContador == 0) { //While para verificar se o cpf é válido
                std::cout << "Digite o cpf do passageiro " << i+1 << ": " << std::endl;
                std::cin >> cpfDoPassageiro;
                if (verificandoApenasNumerosAstronautas(cpfDoPassageiro) && cpfDoPassageiro.length() == 11) {
                     segundoContador = 1;
                } else {
                    std::cout << "Cpf inválido, digite novamente" << std::endl;
                }
            }
            for (astronauta& astro : astronauta::astronautasCriados) { //For para verificar se existe algum astronauta com o cpf digitado 
                if (astro.getCpf() == cpfDoPassageiro) {
                    listaDePassageiros.push_back(astro.getCpf());
                    contador = 2;
                } 
            }
            if (listaDePassageiros.size() == i) {
                std::cout << "Não existe nenhum astronauta com esse cpf, digite novamente." << std::endl;
            }
        }
    }

    voo voo(codigoDoVoo, listaDePassageiros, "Em planejamento");

    voo::setVoosCriados(voo);

    std::cout << "Voo cadastrado com sucesso!" << std::endl;
}

void lancarVoo() {
    int codigoDoVoo;
    int contador = 0;
    int contadorAlternativo = 0;
    int contadorDeElementos = 0;
    int contadorDeCodigosDiferentes = 0;
    bool existeVoo = true;
    int elementos = voo::voosCriados.size();

    for (voo& voo : voo::voosCriados) {
        if (voo.getSituacao() != "Em planejamento") {
            contadorDeElementos++;
        }
    }
    if (voo::voosCriados.empty() == true) {
        std::cout << "Não existem voos para serem lançados." << std::endl;
        existeVoo = false;
    } else if (contadorDeElementos == elementos) {
        std::cout << "Não existem voos para serem lançados." << std::endl;
        existeVoo = false;
    } else {
        while (contador == 0) {
        contadorDeCodigosDiferentes = 0;
        contadorAlternativo = 0;
        std::cout << "Digite o código do voo que você deseja lançar: ";
        std::cin >> codigoDoVoo;
            for (voo& voo : voo::voosCriados) {
                if (codigoDoVoo == voo.getCodigoDeVoo()) {
                    if (voo.getSituacao() != "Em planejamento") {
                        std::cout << "Esse voo está " << voo.getSituacao() << ", digite novamente." <<  std::endl;
                    } else {
                        contadorAlternativo = 1;
                    }
                } else {
                    contadorDeCodigosDiferentes++;
                }   
            }
            if (contadorDeCodigosDiferentes == elementos) {
                std::cout << "Não existe nenhum voo com esse código, digite novamente." << std::endl;
            }
            std::string intParaString = std::to_string(codigoDoVoo);
            if (intParaString.length() != 3) {
                std::cout << "Código inválido, digite novamente." << std::endl;
            } else {
                if (contadorAlternativo == 1) {
                    contador = 1;    
                }
            }
        }
    }

    

    int verificador = 0;
    if (existeVoo == true) {
        for (voo& voos : voo::voosCriados) {
            if (voos.getCodigoDeVoo() == codigoDoVoo) {
                //Mudando a situação do astronauta
                for (astronauta& astro : astronauta::astronautasCriados) {
                    for (int i = 0; i < voos.getlistaDePassageiros().size(); i++) {
                        if (astro.getCpf() == voos.getlistaDePassageiros()[i]) {
                            if (astro.getSituacao() != "Disponível") {
                                std::cout << "Esse voo não pode ser lançado pois o astronauta " << astro.   getNome() << " está " << astro.getSituacao() << std::endl;
                                verificador = 1;
                            } 
                        }
                    }
                }
                if (verificador != 1) {
                    for (astronauta& astro : astronauta::astronautasCriados) {
                        for (int i = 0; i < voos.getlistaDePassageiros().size(); i++) {
                            if (astro.getCpf() == voos.getlistaDePassageiros()[i]) {
                                astro.setSituacao("Voando");
                                astro.adicionarVoosParticipados(codigoDoVoo);
                            }
                        }
                    }
                    voos.setSituacao("Voando");
                    verificador = 2;
                    std::cout << "Voo lançado com sucesso!" << std::endl;
                } 
            } 
        }
    } 
}

void explodirVoo() {
    int codigoDoVoo;
    int contadorDeElementos = 0;
    int contador = 0;
    int contadorDeCodigosDiferentes;
    int contadorAlternativo;
    bool existeVoo = true;
    int elementos = voo::voosCriados.size();

    for (voo& voo : voo::voosCriados) {
        if (voo.getSituacao() != "Voando") {
            contadorDeElementos++;
        }
    }
    if (voo::voosCriados.empty() == true) {
        std::cout << "Não existem voos para serem explodidos." << std::endl;
        existeVoo = false;
    } else if (contadorDeElementos == elementos) {
        std::cout << "Não existem voos para serem explodidos." << std::endl;
        existeVoo = false;
    } else {
        while (contador == 0) {
        contadorDeCodigosDiferentes = 0;
        contadorAlternativo = 0;
        std::cout << "Digite o código do voo que você deseja explodir: ";
        std::cin >> codigoDoVoo;
            for (voo& voo : voo::voosCriados) {
                if (codigoDoVoo == voo.getCodigoDeVoo()) {
                    if (voo.getSituacao() != "Voando") {
                        std::cout << "Esse voo está " << voo.getSituacao() << ", digite novamente." <<  std::endl;
                    } else {
                        contadorAlternativo = 1;
                    }
                } else {
                    contadorDeCodigosDiferentes++;
                }   
            }
            if (contadorDeCodigosDiferentes == elementos) {
                std::cout << "Não existe nenhum voo com esse código, digite novamente." << std::endl;
            }
            std::string intParaString = std::to_string(codigoDoVoo);
            if (intParaString.length() != 3) {
                std::cout << "Código inválido, digite novamente." << std::endl;
            } else {
                if (contadorAlternativo == 1) {
                    contador = 1;    
                }
            }
        }
    }

    int verificador = 0;
    if (existeVoo == true) {
        for (voo& voos : voo::voosCriados) {
            if (voos.getCodigoDeVoo() == codigoDoVoo) {
                //Mudando a situação do astronauta
                for (astronauta& astro : astronauta::astronautasCriados) {
                    for (int i = 0; i < voos.getlistaDePassageiros().size(); i++) {
                        if (astro.getCpf() == voos.getlistaDePassageiros()[i]) {
                            if (astro.getSituacao() != "Voando") {
                                std::cout << "Esse voo não pode ser lançado pois o astronauta " << astro.   getNome() << " está " << astro.getSituacao() << std::endl;
                                verificador = 1;
                            } 
                        }
                    }
                }
                if (verificador != 1) {
                    for (astronauta& astro : astronauta::astronautasCriados) {
                        for (int i = 0; i < voos.getlistaDePassageiros().size(); i++) {
                            if (astro.getCpf() == voos.getlistaDePassageiros()[i]) {
                                astro.setSituacao("Morto");
                            }
                        }
                    }
                    voos.setSituacao("Destruido");
                    verificador = 2;
                    std::cout << "Voo explodido com sucesso!" << std::endl;
                } 
            } 
        }
    }
    
}
