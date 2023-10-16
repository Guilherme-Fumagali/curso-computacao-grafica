# Biblioteca de vetores e matrizes

## Visão geral

Esse projeto fornece uma biblioteca de vetores (vec2, vec3 e vec4) e matrizes (mat2, mat3 e mat4) para C++.
Consulta a documentação do código-fonte para mais detalhes sobre as classes e as funções implementadas: https://guilherme-fumagali.github.io/curso-computacao-grafica/Atividade_2/docs/html/index.html

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
Doxygen Doxyfile
```

A documentação será gerada na pasta `./docs`.

## Testes

Com a biblioteca compilada, execute o comando abaixo para executar os testes:

```bash
./build/tests/tests
```

## Exemplos

Em [`main.cpp`](src/main.cpp) há um código de exemplo exemplificado em [RayTracingInOneWeekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html#thevec3class), que em suma gerará uma imagem degradê utilizando o objeto vec3 da biblioteca.

Para executá-lo, execute o comando abaixo:

```bash
./build/main > image.ppm
```