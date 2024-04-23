#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fmimports.h"

int realizarLogin(Usuario *usuarios, int quantidadeUsuarios) {
    char nome[MAX_NOME_USUARIO], senha[MAX_SENHA_USUARIO];
    printf("===== Login =====\n");
    printf("Usuario: ");
    scanf("%s", nome);
    printf("Senha: ");
    scanf("%s", senha);

    for (int i = 0; i < quantidadeUsuarios; i++) {
        if (strcmp(usuarios[i].nome, nome) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            printf("Login realizado com sucesso!\n");
            return 1; // Login bem-sucedido
        }
    }

    printf("Senha ou nome de usuário incorretos! Tente novamente.\n");
    return 0; // Login falhou
}

int validarEmail(char email[], Usuario *usuarios, int quantidadeUsuarios) {
    int i, atCount = 0;
    if (strlen(email) >= MAX_EMAIL_USUARIO)
        return 0; // E-mail muito longo
    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
            if (atCount > 1) // Mais de um "@" não é válido
                return 0;
        }
    }
    if (atCount == 1)
        for (i = 0; i < quantidadeUsuarios; i++)
            if (strcmp(email, usuarios[i].email) == 0)
                return 0; // E-mail já cadastrado
    return atCount;
}

void cadastrarUsuario(Usuario **usuarios, int *quantidadeUsuarios) {
    Usuario novoUsuario;
    printf("===== Cadastro de Novo Usuario =====\n");
    printf("Nome de usuario: ");
    scanf("%s", novoUsuario.nome);
    printf("Senha: ");
    scanf("%s", novoUsuario.senha);

    do {
        printf("E-mail: ");
        scanf("%s", novoUsuario.email);
        if (!validarEmail(novoUsuario.email, *usuarios, *quantidadeUsuarios))
            printf("E-mail invalido ou ja cadastrado! Por favor, insira um e-mail valido.\n");
        else
            break; // Sair do loop se o e-mail for válido
    } while (1); // Loop infinito, deve ser interrompido pelo `break`

    (*quantidadeUsuarios)++;
    *usuarios = realloc(*usuarios, (*quantidadeUsuarios) * sizeof(Usuario));
    (*usuarios)[*quantidadeUsuarios - 1] = novoUsuario;

    printf("Usuario cadastrado com sucesso!\n");
}

#include "fmimports.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarProduto(Produto **produtos, int *quantidadeProdutos) {
    Produto novoProduto;
    printf("===== Cadastro de Novo Produto =====\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]", novoProduto.nome);
    printf("Preco: ");
    scanf("%f", &novoProduto.preco);
    printf("Quantidade: ");
    scanf("%d", &novoProduto.quantidade);

    (*quantidadeProdutos)++;
    *produtos = realloc(*produtos, (*quantidadeProdutos) * sizeof(Produto));
    (*produtos)[*quantidadeProdutos - 1] = novoProduto;

    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos(Produto *produtos, int quantidadeProdutos) {
    printf("===== Lista de Produtos =====\n");
    if (quantidadeProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    for (int i = 0; i < quantidadeProdutos; i++) {
        printf("Nome: %s | Preco: R$%.2f | Quantidade: %d\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }
}

void buscarProdutoPorNome(Produto *produtos, int quantidadeProdutos) {
    char nomeBusca[MAX_NOME_PRODUTO];
    printf("Digite o nome do produto que deseja buscar: ");
    scanf(" %[^\n]", nomeBusca);
    printf("===== Resultado da Busca =====\n");
    int encontrado = 0;
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeBusca) == 0) {
            printf("Nome: %s | Preco: R$%.2f | Quantidade: %d\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
            encontrado = 1;
        }
    }
    if (!encontrado)
        printf("Nenhum produto encontrado com o nome '%s'.\n", nomeBusca);
}

// Função para excluir um produto
void excluirProduto(Produto **produtos, int *quantidadeProdutos) {
    printf("===== Produtos Disponiveis para Exclusao =====\n");
    if (*quantidadeProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    for (int i = 0; i < *quantidadeProdutos; i++) {
        printf("%d. Nome: %s\n", i + 1, (*produtos)[i].nome);
    }
    int indice;
    do {
        printf("Digite o numero do produto que deseja excluir (ou 0 para cancelar): ");
        scanf("%d", &indice);
        if (indice < 0 || indice > *quantidadeProdutos)
            printf("Índice invalido!\n");
    } while (indice < 0 || indice > *quantidadeProdutos);
    if (indice != 0) {
        for (int i = indice - 1; i < *quantidadeProdutos - 1; i++) {
            (*produtos)[i] = (*produtos)[i + 1];
        }
        (*quantidadeProdutos)--;
        *produtos = realloc(*produtos, (*quantidadeProdutos) * sizeof(Produto));
        printf("Produto excluido com sucesso!\n");
    } else {
        printf("Operacao de exclusao cancelada.\n");
    }
}

// Função para verificar o total de cada produto em estoque
void verificarTotalEstoque(Produto *produtos, int quantidadeProdutos) {
    printf("===== Total de Estoque por Produto =====\n");
    for (int i = 0; i < quantidadeProdutos; i++) {
        printf("Produto: %s | Total em estoque: %d\n", produtos[i].nome, produtos[i].quantidade);
    }
}

// Função para exibir mensagem de boas-vindas
void mensagemBoasVindas() {
    printf("\nBem-vindo a FMIMPORTS - Sua loja de importados!\n\n");
}

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\n===== Menu de Opcoes =====\n");
    printf("1. Cadastrar novo produto\n");
    printf("2. Listar produtos\n");
    printf("3. Buscar produto por nome\n");
    printf("4. Excluir produto\n");
    printf("5. Verificar total em estoque\n");
    printf("6. Ordenar produtos por preço\n"); // Nova opção
    printf("0. Sair\n");
    printf("Digite a opcao desejada: ");
}

void quickSort(Produto *produtos, int esquerda, int direita) {
    int i = esquerda, j = direita;
    float pivo = produtos[(esquerda + direita) / 2].preco;

    while (i <= j) {
        while (produtos[i].preco < pivo)
            i++;
        while (produtos[j].preco > pivo)
            j--;
        if (i <= j) {
            Produto temp = produtos[i];
            produtos[i] = produtos[j];
            produtos[j] = temp;
            i++;
            j--;
        }
    }

    if (esquerda < j)
        quickSort(produtos, esquerda, j);
    if (i < direita)
        quickSort(produtos, i, direita);
}


