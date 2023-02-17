# Monitoria_ED
Repositório para manter diversos recursos de monitoria para a disciplina de Estrutura de Dados.

**Monitores:**
- [Tiago Barradas Figueiredo](https://github.com/barrafas)
- [Wellington José Leite da Silva](https://github.com/wellington36)

**Horário de monitoria:**
- Presencial: Terça à tarde (16h até 18h) na sala (esperando reserva de sala)
- Online: Sextas às 14:30 no discord da EMAp

## Hello World em Cpp

Para instalar o compilador em Linux é recomendado usar o seguinte comando:

```
sudo apt install build-essential
```

Caso não funcione pode instalar o compilador a parte

```
sudo apt install g++
```

Pode checar a instalação rodando (que se tudo der certo deve retornar a versão do compilador):

```
g++ --version
```

#### Primeiro código

Como Cpp é uma linguagem compilada precisamos de um passo a mais durante a execução, crie um arquivo `hello.cpp` (por exemplo), com o seguinte código que printa "Hello, World!" e uma linha em branco.

```cpp
#include <iostream>
using namespace std;

int main() 
{
    cout << "Hello, World!" << endl;
    return 0;
}
```

Para executar nosso primeiro código precisamos primeiro gerar um executável, o que pode ser feito com o g++ rodando o seguinte comando `g++ -o NOME_DO_EXECUTAVEL NOME_DO_ARQUIVO.cpp`, no caso aqui rodamos

```
g++ -o hello hello.cpp
```

Agora temos um executável chamado `hello`, para rodado basta rodar o seguinte e teremos nosso "Hello, World!" printado

```
./hello
```
