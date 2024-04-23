#ifndef FMIMPORTS_H
#define FMIMPORTS_H

#define MAX_NOME_PRODUTO 20
#define MAX_NOME_USUARIO 20
#define MAX_SENHA_USUARIO 20
#define MAX_EMAIL_USUARIO 80

// Estrutura para representar um produto
typedef struct {
    char nome[MAX_NOME_PRODUTO];
    float preco;
    int quantidade;
} Produto;

// Estrutura para representar um usuário
typedef struct {
    char nome[MAX_NOME_USUARIO];
    char senha[MAX_SENHA_USUARIO];
    char email[MAX_EMAIL_USUARIO];
} Usuario;

int realizarLogin(Usuario *usuarios, int quantidadeUsuarios);
int validarEmail(char email[], Usuario *usuarios, int quantidadeUsuarios);
void cadastrarUsuario(Usuario **usuarios, int *quantidadeUsuarios);
void cadastrarProduto(Produto **produtos, int *quantidadeProdutos);
void listarProdutos(Produto *produtos, int quantidadeProdutos);
void buscarProdutoPorNome(Produto *produtos, int quantidadeProdutos);
void excluirProduto(Produto **produtos, int *quantidadeProdutos);
void verificarTotalEstoque(Produto *produtos, int quantidadeProdutos);
void mensagemBoasVindas();
void exibirMenu();
void quickSort(Produto *produtos, int esquerda, int direita);

#endif /* FMIMPORTS_H */
