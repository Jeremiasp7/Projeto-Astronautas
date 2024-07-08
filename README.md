Passos para compilar o projeto:
- Certifique-se de que o compilador g++ esteja instalado no seu sistema. Você pode instalar o g++ usando os seguintes comandos, dependendo do seu sistema operacional:

  * Ubuntu / Debian:

        sudo apt-get update
        sudo apt-get install g++

  * Fedora:

        sudo dnf install g++

  * macOS (via Homebrew):
 
        brew install gcc

- Navegar até o Diretório do Projeto:

  * Abra o terminal e navegue até o diretório onde seu projeto está localizado. Supondo que o projeto esteja na pasta `PROJETO_DE_LP` no seu diretório home:

        cd ~/PROJETO_DE_LP

- Compilar o projeto:

  * Execute o comando make no terminal para compilar o projeto. O make utilizará o Makefile para compilar e linkar o projeto automaticamente:

        make

- Executar o programa:

  * Depois de compilar, você pode executar o programa gerado com o seguinte comando:

        ./meu_programa

- Limpar os arquivos compilados:

  * Se você quiser limpar os arquivos objeto (`.o`) e o executável (`meu_programa`), execute o comando abaixo:
 
        make clean

