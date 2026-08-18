# 🌐 http-server
em progresso e feito na raça sem ia (obs atualmente usei par debugar e acabou que alguma partes ela mexeu sem eu querer entao talvez tenha partes em portugues onde nao deve estar mas a base do codigo continua sendo na raça so 4% de ia)


![C](https://img.shields.io/badge/language-C-00599C.svg)
![Platform](https://img.shields.io/badge/platform-Linux%20%2F%20Arch-1793D1.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

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

```bash
git clone git@github.com:jeffer-linuxid/http-server.git
cd http-server
gcc -o http-server main.c
./http-server
```

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
