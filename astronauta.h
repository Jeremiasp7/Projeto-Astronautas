#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H
#include <iostream>
#include <vector>
#include <string>
#include "voo.h"

class astronauta {
    public:
        //Construtor da classe astronauta
        astronauta(const std::string nome, int idade, const std::string situacao, const std::string cpf);

        //Getters 
        const std::string& getNome() const;
        int getIdade() const;
        const std::string& getSituacao() const;
        const std::string& getCpf() const;
        const std::vector<int>& getVoosParticipados() const;

        //Setters
        void setNome(const std::string& nome);
        void setIdade(int idade);
        void setSituacao(const std::string& situcao);
        void setCpf(const std::string cpf);
        void setVooParticipado(int codigoDeVoo);

        //Métodos
        void listarAstronautasMortos();
        void cadastrarAstronauta();
        
    private:
        std::string nome ;
        int idade;
        std::string situacao;
        std::string cpf;
        std::vector<int> listaDeVoosParticipados;
};

#endif