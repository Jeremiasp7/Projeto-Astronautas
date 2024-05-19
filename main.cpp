#include <iostream>
#include "astronauta.h"
#include "voo.h"

int main() {
    bool booleano = false;
    int opcao;
    std::cout << "Bem vindo ao menu!" << std::endl;
    std::cout << "1 - Cadastrar um astronauta" << std::endl;
    std::cout << "2 - Cadastrar um voo" << std::endl;
    std::cout << "3 - Adicionar astronauta em um voo" << std::endl;
    std::cout << "4 - Remover astronauta de um voo" << std::endl;
    std::cout << "5 - Listar todos os voos" << std::endl;
    std::cout << "6 - Lançar um voo" << std::endl;
    std::cout << "7 - Finalizar voo" << std::endl;
    std::cout << "8 - Explodir voo" << std::endl;
    std::cout << "9 - Listar os astronautas mortos" << std::endl;
    std::cout << "0 - Encerrar aplicação" << std::endl;
    while (booleano == false) {
        std::cout << "Escolha um opção: ";
        std::cin >> opcao;
        switch (opcao) {
            case 1:
                cadastrarAstronauta();
                break;
            case 2:
                cadastrarVoo();
                break;
            case 3:
                //adicionarAstronauta()
            case 4:
                //removerAstronauta()
            case 5:
                listarTodosOsVoos();
                break;
            case 6:
                lancarVoo();
                break;
            case 7:
                finalizarVoo();
                break;
            case 8:
                explodirVoo();
                break;
            case 9:
                listarAstronautasMortos();
                break;
            case 0:
                std::cout << "Aplicação encerrada!" << std::endl;
                booleano = true;
                break;
            default:
                std::cout << "Opção inválida!" <<std::endl;
                break;
        }
    }
    

    return 0;
}