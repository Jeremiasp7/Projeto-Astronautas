#ifndef VOO_H
#define VOO_H
#include <iostream>
#include <vector>
#include <string>
#include "astronauta.h"

class voo {
    public:
        //Construtor da classe voo
        voo(int codigoDeVoo, const std::vector<std::string>& listaDePassageiros, const std::string& situacao);

        //Vetor com os voos criados
        static std::vector<voo> voosCriados;

        //Getters
        int getCodigoDeVoo() const;
        std::vector<std::string>& getlistaDePassageiros();
        const std::string& getSituacao() const;

        //Setters
        void setCodigoDeVoo(int codigoDeVoo);
        void setListaDePassageiros(std::string cpfDoPassageiro);
        void setSituacao(const std::string situacao);
        static void setVoosCriados(voo voos);

    private:
        int codigoDeVoo;
        std::vector<std::string> listaDePassageiros;
        std::string situacao;
};
//Métodos de controle da classe voo
void adicionarAstronautaEmVoo();
void removerAstronautaDeVoo();
void cadastrarVoo();
void lancarVoo();
void explodirVoo();
void finalizarVoo();
void listarTodosOsVoos();

#endif