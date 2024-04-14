#ifndef VOO_H
#define VOO_H
#include <iostream>
#include <vector>
#include <string>
#include "astronauta.h"

class voo {
    public:
        //Construtor da classe voo
        voo(int codigoDeVoo, const std::vector<std::string> listaDePassageiros, const std::string situacao);

        //Getters
        int getCodigoDeVoo() const;
        const std::vector<std::string>& getlistaDePassageiros() const;
        const std::string& getSituacao() const;

        //Setters
        void setCodigoDeVoo(int codigoDeVoo);
        void setListaDePassageitos(const std::vector<std::string> listaDePassageiros);
        void setSituacao(const std::string situacao);

        //Métodos
        void adicionarAstronautaEmVoo();
        void removerAstronautaDeVoo();
        void cadastrarVoo();
        void lancarVoo();
        void explodirVoo();
        void finalizarVoo();
        void listarTodosOsVoos();


    private:
        int codigoDeVoo;
        std::vector<std::string> listaDePassageiros;
        std::string situacao;
};

#endif