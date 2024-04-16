#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H
#include <iostream>
#include <vector>
#include <string>
#include "voo.h"

class astronauta {
    public:
        //Construtor da classe astronauta
        astronauta(const std::string& nome, int idade, const std::string& situacao, const std::string& cpf);

        //Vetor de astronautas criados
        static std::vector<astronauta> astronautasCriados;

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
        void setCpf(const std::string& cpf);
        static void setAstronautasCriados(astronauta astronautasCriados);
        void adicionarVoosParticipados(int codigoDeVoo);     
        
    private:
        std::string nome ;
        int idade;
        std::string situacao;
        std::string cpf;
        std::vector<int> listaDeVoosParticipados;
};
//Métodos de controle dos astronautas
void listarAstronautasMortos();
void cadastrarAstronauta();

#endif