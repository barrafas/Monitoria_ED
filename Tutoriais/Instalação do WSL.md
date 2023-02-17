# Tutorial de instalação do WSL:
Fortemente baseado no [tutorial oficial da Microsoft](https://learn.microsoft.com/pt-br/windows/wsl/install).

Primeiramente, verifique a sua versão do Windows. Para fazer isso, aperte Win+R e rode o comando "winver". Uma janela será aberta detalhando as informações do seu sistema operacional. Os pré-requisitos do WSL são o Windows 10 versão 2004 e superior (Build 19041 e superior) ou o Windows 11.

Se seu Windows cumpre esses requisitos, vocẽ pode instalar tudo necessário para o WSL. Abra o Powershell como administrador e insira o comando:

```shell
wsl --install
```

Por padrão, esse comando irá instalar uma distribuição Ubuntu, mas caso vocẽ queira mudar isso, basta especificar um outro distrô através do comando `wsl --install -d <Nome da Distribuição>`. É possível ver uma lista de todas as opções disponíveis pelo comando `wsl --list --online`.

Após inserir o comando, tudo deve começar a ser instalado automaticamente. É possível que vocẽ tenha que reiniciar o computador como parte do processo.

OBS: Um erro comumente encontrado é o seguinte: `Please enable the Virtual Machine Platform Windows feature and ensure virtualization is enabled in the BIOS`. Caso isso aconteça, será necessário alterar uma configuração da BIOS de seu computador para habilitar a feature de virtualização, que permite que seus recursos sejam divididos em múltiplas máquinas virtuais. Os passos para realizar isso dependem da placa-mãe e processador de seu computador, então é impossível dar um tutorial genérico sobre isso, mas sinta-se a vontade para pedir uma ajuda a um dos monitores sobre como proceder caso esse erro ocorra.

Com a instalação finalizada, basta pesquisar pela distribuição instalada no menu Iniciar (por padrão, Ubuntu), ou rodar o comando `wsl` no Powershell, para começar a usar o WSL. Rodando pela primeira vez, será necessário definir coisas como seu nome de usuário e senha, que são totalmente independentes de seu usuário e senha Windows.

Assim, seu novo ambiente Linux deve estar funcionando! [Esse link da Microsoft](https://learn.microsoft.com/pt-br/windows/wsl/setup/environment) indica algumas dicas interessantes sobre como melhorar seu workflow no WSL. Dentre elas, eu recomendo fortemente a utilização do [Windows Terminal](https://apps.microsoft.com/store/detail/windows-terminal/9N0DX20HK701?hl=pt-br&gl=br), é uma interface de linha de comando mais inteligente que permite a abertura de diversas janelas de terminal, customização de aparências, dentre outras coisas.

Caso nunca tenha interagido com Linux antes, segue uma lista de comandos úteis:

- `ls`, lista os arquivos e pastas no diretório;
- `cd <path>`, muda o diretório atual;
- `mv <patharquivo> <pathdestino>`, move o arquivo para um determinado local de destino;
- `rm -d <path>`, deleta um diretório vazio ou um arquivo;
- `rm -r <path>`, deleta um diretório não-vazio;
- `pwd`, indica qual é o diretório presente;
- `touch <file>`, cria um novo arquivo;
- `mkdir <name>`, cria um novo diretório;
- `wget <url>`, baixa um arquivo da internet baseado em uma url;
- `apt install <package>`, instala um determinado pacote;   
- `sudo`, é um prefixo que pode ser usado antes de outros comandos (tipo `sudo apt`), que dá permissões de "super user"/administrador para o comando;

OBS: Caso esteja usando Windows 11 ou Windows 10 Build 19044+, é possível usar aplicativos com interface pelo WSL. Isso permite, por exemplo, que você instale um browser ou um explorador de arquivos para facilitar seu uso do WSL. Um tutorial mais detalhado sobre isso está disponível nesse [artigo da Microsoft](https://learn.microsoft.com/en-us/windows/wsl/tutorials/gui-apps).

## Integrando VSCode com o WSL
Fortemente baseado no [tutorial oficial do VSCode](https://code.visualstudio.com/docs/remote/wsl).

O VSCode possúi uma [extensão oficial](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl) que permite a integração da sua instalação do VSCode do Windows com seu WSL. Para isso, basta instalá-lo normalmente em seu Windows e baixar a extensão mencionada anteriormente.

Com o VSCode e a extensão instaladas, basta acessar seu terminal do WSL e digitar o comando `code .` no diretório que você deseja acessar.

Note que vocẽ terá que habilitar suas outras extensões instaladas para que elas também funcionem no WSL. Para checar se uma extensão está funcionando no WSL, basta abri-la na aba de Extensões:
