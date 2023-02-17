# Monitoria_ED
Repositório para manter diversos recursos de monitoria para a disciplina de Estrutura de Dados.

**Monitores:**
- [Tiago Barradas Figueiredo](https://github.com/barrafas)
- [Wellington José Leite da Silva](https://github.com/wellington36)

**Horário de monitoria:**
- Presencial: Terça à tarde (16h até 18h) na sala (esperando reserva de sala)
- Online: Sextas às 14:30 no discord da EMAp

## Hello World em Cpp (Linux)

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

## Hello World (VSCode)

Tendo o VSCode instalado podemos baixar a extensão `Run Code`

![image](https://user-images.githubusercontent.com/61877847/219743160-d65d70d3-b28f-40e0-a44d-5d86022535e2.png)

No código do `Hello, World` acima clique com o botão direito do mouse e selecione a opção `Run Code`

![image](https://user-images.githubusercontent.com/61877847/219743738-046080ef-464c-4752-a9c0-4dafd14f9b77.png)

E pronto seu código é compilado e executado

![image](https://user-images.githubusercontent.com/61877847/219744465-2770d7f6-c680-4a00-9135-31c50380f0cb.png)
