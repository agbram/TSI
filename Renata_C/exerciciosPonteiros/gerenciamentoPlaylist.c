#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Musica
{
    char titulo[100];
    char artista[100];
    int duracaoMusica;

    struct Musica *prox;
} Musica;

void menu();
void limpar_tela();
void aguardar_tecla();
void limpar_buffer_entrada();
void addMusica(Musica **inicioPlaylist);
void exibirPlaylist(Musica *inicioPlaylist);
void atualizarMusica(Musica **inicioPlaylist);
void informacoesPlaylist(Musica *inicioPlaylist);

int main()
{
    Musica *inicioPlaylist = NULL;
    int opcao;

    do
    {
        limpar_tela();
        menu();
        scanf("%d", &opcao);
        limpar_buffer_entrada();

        switch (opcao)
        {
        case 1:
            addMusica(&inicioPlaylist);
            break;
        case 2:
            exibirPlaylist(inicioPlaylist);
            break;
        case 3:
            atualizarMusica(&inicioPlaylist);
            break;
        case 4:
            informacoesPlaylist(inicioPlaylist);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            aguardar_tecla();
        }

    } while (opcao != 0);

    return 0;
}

void menu()
{
    limpar_tela();
    printf("=== SISTEMA DE PLAYLIST ===\n");
    printf("\n1. Adicionar musica\n");
    printf("2. Exibir playlist completa\n");
    printf("3. Atualizar uma musica\n");
    printf("4. Exibir o total de musicas e duracao da playlist\n");
    printf("0. Sair\n");
    printf("=============\n");
    printf("Escolha a opcao: ");
}

void limpar_tela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void aguardar_tecla()
{
    printf("\n\nPressione Enter para continuar...");
    getchar(); // Lê o Enter do usuário
}

void limpar_buffer_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ; // Descarta todos os caracteres até o fim da linha
    }
}

void addMusica(Musica **inicioPlaylist)
{
    limpar_tela();
    printf("=== Adicionar musica ===\n");

    Musica *nova = (Musica *)malloc(sizeof(Musica));

    if (nova == NULL)
    {
        printf("Erro em alocar a memoria");
        return;
    }

    printf("Digite o titulo: ");
    fgets(nova->titulo, sizeof(nova->titulo), stdin);
    nova->titulo[strcspn(nova->titulo, "\n")] = 0; // remover \n

    printf("Digite o artista: ");
    fgets(nova->artista, sizeof(nova->artista), stdin);
    nova->artista[strcspn(nova->artista, "\n")] = 0;

    printf("Digite a duracao (em segundos): ");
    scanf("%d", &nova->duracaoMusica);
    limpar_buffer_entrada();

    nova->prox = NULL;

    if (*inicioPlaylist == NULL)
    {
        *inicioPlaylist = nova;
    }
    else
    {
        Musica *atual = *inicioPlaylist;

        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }

        atual->prox = nova;
    }
    printf("Musica adicionada com sucesso!");
    aguardar_tecla();
}

void exibirPlaylist(Musica *inicioPlaylist)
{
    limpar_tela();

    printf("=== PLAYLIST ===\n");

    if (inicioPlaylist == NULL)
    {
        printf("Playlist vazia!\n");
    }
    else
    {
        Musica *atual = inicioPlaylist;

        int i = 1;

        while (atual != NULL)
        {
            printf("%d. %s - %s (%d seg)\n", i, atual->titulo, atual->artista, atual->duracaoMusica);
            atual = atual->prox;
            i++;
        }
    }
    aguardar_tecla();
}

void atualizarMusica(Musica **inicioPlaylist)
{
    limpar_tela(); // Limpa a tela

    char buffer[200]; // Buffer para leitura de strings
    Musica *musicaAtual = *inicioPlaylist;
    int encontrada = 0;            // Flag para verificar se encontrou a música
    char musicaParaAtualizar[200]; // Armazena o título da música a ser atualizada
    int escolhaUsuario;            // Armazena a escolha do usuário

    printf("==== ATUALIZA MUSICA DA PLAYLIST ====\n");

    if (*inicioPlaylist == NULL)
    {
        printf("Playlist vazia\n"); // Se a lista está vazia, informa ao usuário
        return;
    }

    // Lê o título da música que o usuário deseja atualizar
    printf("\nInforme qual titulo da musica que deseja atualizar: ");
    fgets(buffer, 200, stdin);
    int tamanho = strlen(buffer);
    if (buffer[tamanho - 1] == '\n')
        buffer[tamanho - 1] = '\0';
    strcpy(musicaParaAtualizar, buffer);

    // Percorre a lista para encontrar a música
    while (musicaAtual != NULL)
    {
        if (strcmp(musicaAtual->titulo, musicaParaAtualizar) == 0)
        {
            encontrada = 1; // Marca que encontrou a música

            // Pergunta ao usuário o que deseja atualizar
            do
            {
                limpar_tela();
                printf("\nO que deseja atualizar da musica escolhida?\n");
                printf("1. Nome da musica\n");
                printf("2. Nome do artista\n");
                printf("3. Duracao da musica\n");
                scanf("%d", &escolhaUsuario);
                limpar_buffer_entrada();
            } while (escolhaUsuario != 1 && escolhaUsuario != 2 && escolhaUsuario != 3);

            // Atualiza conforme a escolha do usuário
            if (escolhaUsuario == 1)
            {
                printf("\nInforme o novo titulo: ");
                fgets(buffer, 200, stdin);
                tamanho = strlen(buffer);
                if (buffer[tamanho - 1] == '\n')
                    buffer[tamanho - 1] = '\0';

                strcpy(musicaAtual->titulo, buffer); // Copia novo título
            }
            else if (escolhaUsuario == 2)
            {
                printf("\nInforme o novo artista: ");
                fgets(buffer, 200, stdin);
                tamanho = strlen(buffer);
                if (buffer[tamanho - 1] == '\n')
                    buffer[tamanho - 1] = '\0';

                strcpy(musicaAtual->artista, buffer); // ✅ apenas copia
            }

            else
            {
                printf("\nInforme a duracao em segundos: ");
                scanf("%d", &musicaAtual->duracaoMusica); // Atualiza duração
                limpar_buffer_entrada();
            }

            printf("\nMusica atualizada com sucesso!\n");
            break; // Sai do loop após atualizar
        }

        musicaAtual = musicaAtual->prox; // Avança para próxima música
    }

    if (!encontrada)
        printf("\nMusica nao encontrada\n"); // Informa se não encontrou a música
}

void informacoesPlaylist(Musica *inicioPlaylist) // ✅ Alterado para ponteiro simples
{
    limpar_tela();
    int qtdMusicas = 0, totalDuracao = 0;
    printf("==== Informacoes da playlist ====\n");

    Musica *musicaAtual = inicioPlaylist; // ✅ Usando parâmetro diretamente

    if (musicaAtual == NULL)
    {
        printf("\nPlaylist vazia");
        aguardar_tecla(); // ✅ Adicione pausa mesmo quando vazia
        return;
    }

    while (musicaAtual != NULL)
    {
        totalDuracao += musicaAtual->duracaoMusica;
        qtdMusicas++;
        musicaAtual = musicaAtual->prox;
    }

    printf("\nTotal de musicas: %d", qtdMusicas);
    printf("\nDuracao total da playlist: %d segundos", totalDuracao);
    aguardar_tecla(); // ✅ Pausa para visualizar
}
