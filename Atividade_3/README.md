# Classe de leitura de modelos .obj

## Visão geral

Esse projeto fornece uma classe para leitura de modelos .obj para C++.

Essa classe, chamada de [Loader](src/Loader.h), recebe o caminho para um arquivo .obj e ponteiros de vetores, que serão escritos com os dados de vértices, normais, índices do modelo e informações das faces dos triângulos.

Para armazenar os dados das faces, foi criada a classe [Triangle](src/Triangle.h), que armazena os índices dos vértices e normais de cada face.

Consulte a documentação do código-fonte para mais detalhes sobre as classes e as funções implementadas: https://guilherme-fumagali.github.io/curso-computacao-grafica/Atividade_3/docs/html/index.html

## Compilação

#### Dependências

- [gcc](https://gcc.gnu.org/), compilador C++.
- [CMake](https://cmake.org/), ferramenta para geração de arquivos de compilação.
- [Doxygen](https://www.doxygen.nl/index.html), ferramenta para geração de documentação.


Compile o código-fonte com o comando abaixo:

```bash 
cmake -B build CMakeLists.txt && cmake --build build
```

Os arquivos compilados serão gerados na pasta `./build`.

#### Gerando documentação

Para gerar a documentação do código, execute o comando abaixo:

```bash
doxygen Doxyfile
```

A documentação será gerada na pasta `./docs`.

## Testes

Com a aplicação compilada, execute o comando abaixo para executar os testes:

```bash
./build/src/tests/tests
```