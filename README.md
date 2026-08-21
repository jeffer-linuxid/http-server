# 🌐 http-server
em progresso e feito na raça sem ia (obs atualmente usei par debugar e acabou que alguma partes ela mexeu sem eu querer entao talvez tenha partes em portugues onde nao deve estar mas a base do codigo continua sendo na raça so 4% de ia)


![C](https://img.shields.io/badge/language-C-00599C.svg)
![Platform](https://img.shields.io/badge/platform-Linux%20%2F%20Arch-1793D1.svg)
> Servidor HTTP simples, implementado do zero em C, como projeto de estudo sobre sockets, TCP/IP e o protocolo HTTP.

## 📌 Sobre

Este projeto é uma implementação minimalista de um servidor HTTP, construída para entender na prática como funciona a comunicação cliente-servidor na camada de aplicação sobre TCP/IP — sem frameworks, apenas C e a API de sockets do sistema.

## ✨ Funcionalidades

- [ ] Abertura de socket TCP e escuta em uma porta
- [ ] Aceitação de conexões de clientes
- [ ] Parsing básico de requisições HTTP (método, path, headers)
- [ ] Envio de respostas HTTP (status line, headers, body)
- [ ] Servir arquivos estáticos

> ⚠️ Ajuste os itens marcados/desmarcados acima conforme o que já está implementado no código.

## 🛠️ Como compilar e rodar

### Pré-requisitos
- Linux (ou WSL)
- `gcc` instalado

### 1. Clonar o repositório
```bash
git clone git@github.com:jeffer-linuxid/http-server.git
cd http-server
```

### 2. Estrutura de pastas
O servidor serve arquivos estáticos de dentro da pasta `public/`, então garanta que ela existe no mesmo diretório de onde você vai **executar** o binário (não de onde está o `.c`):


### 3. Compilar
```bash
gcc -o http-server main.c
```

### 4. Rodar
```bash
./http-server
```

O servidor sobe em `http://localhost:8080` e serve qualquer arquivo dentro de `public/` (ex: `/index.html`, `/style.css`, `/script.js`). Acessar `/` serve automaticamente `public/index.html`.

### 5. Testar
No navegador:


> ⚠️ Use `http://`, não `https://` — o servidor não fala TLS/SSL. Se o navegador redirecionar sozinho pra `https://` (HSTS), digite o endereço manualmente ou teste via terminal.

Ou via terminal:
```bash
curl -v http://localhost:8080/
```

### Encerrar
`Ctrl+C` no terminal onde o servidor está rodando.
> ⚠️ Ajuste os comandos de compilação e execução conforme a estrutura real do projeto (Makefile, nome dos arquivos-fonte, porta padrão, etc.)


## 📚 Referências e material de estudo

Este projeto foi construído com apoio dos seguintes materiais:

- [How I Built a Simple HTTP Server From Scratch Using C](https://dev.to/jeffreythecoder/how-i-built-a-simple-http-server-from-scratch-using-c-739) — guia principal usado como base
- [`man tcp(7)`](https://man.archlinux.org/man/tcp.7.en) — documentação do protocolo TCP, via Arch Wiki / man pages
- Páginas de manual do Arch Linux sobre TCP e HTTP, consultadas com `man` durante o desenvolvimento

## 🎓 Aprendizados

Durante o desenvolvimento, o foco foi entender:

- Como funciona a criação e o gerenciamento de sockets TCP em C (`socket`, `bind`, `listen`, `accept`)
- A estrutura de uma requisição e resposta HTTP "crua", sem abstrações de frameworks
- Uso do `man` como ferramenta de consulta para documentação de baixo nível do sistema (rede, protocolos)


---

Feito por [jeffer-linuxid](https://github.com/jeffer-linuxid) 🚀
