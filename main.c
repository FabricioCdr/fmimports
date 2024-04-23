#include <stdio.h>
#include <stdlib.h>
#include "fmimports.h"

int main() {
    // Variáveis para armazenar os produtos e usuários
    Produto *produtos = NULL;
    int quantidadeProdutos = 0;
    Usuario *usuarios = NULL;
    int quantidadeUsuarios = 0;
    int opcao;

    // Menu inicial
    do {
        printf("===== Seja bem-vindo a FMIMPORTS - Sua loja de importados =====\n");
        printf("1. Faca seu login\n");
        printf("2. Realize seu cadastro\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                if (!realizarLogin(usuarios, quantidadeUsuarios)) {
                    printf("Senha incorreta! Tente novamente.\n");
                }
                break;
            case 2:
                cadastrarUsuario(&usuarios, &quantidadeUsuarios);
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 1); // Continua mostrando o menu inicial até o usuário fazer login

    // Menu principal
    do {
        printf("\n===== Menu Principal =====\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Buscar Produto por Nome\n");
        printf("4. Excluir Produto\n");
        printf("5. Verificar Total do Estoque\n");
        printf("6. Ordenar Produtos por Preco\n");
        printf("0. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastrarProduto(&produtos, &quantidadeProdutos);
                break;
            case 2:
                listarProdutos(produtos, quantidadeProdutos);
                break;
            case 3:
                buscarProdutoPorNome(produtos, quantidadeProdutos);
                break;
            case 4:
                excluirProduto(&produtos, &quantidadeProdutos);
                break;
            case 5:
                verificarTotalEstoque(produtos, quantidadeProdutos);
                break;
            case 6:
                if (quantidadeProdutos > 0) {
                    quickSort(produtos, 0, quantidadeProdutos - 1);
                    printf("Produtos ordenados por preco!\n");
                } else {
                    printf("Nao ha produtos cadastrados para ordenar!\n");
                }
                break;
            case 0:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    // Liberando memória alocada
    free(produtos);
    free(usuarios);

    return 0;
}
