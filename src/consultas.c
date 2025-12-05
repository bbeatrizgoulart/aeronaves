#include "../include/consultas.h"
#include "../include/utils.h"
#include "../include/relatorios.h"
#include "../include/cadastros.h"
#include "../include/types.h"
#include "../include/menus.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void buscar_aeronave_por_prefixo(dados_aeronaves_t *lista)
{
    char buscar_prefixo[STR_SIZE];
    int encontrou = FALSE;
    dados_aeronaves_t *atual = lista;

    printf("......BUSCAR AERONAVE POR PREFIXO (MATRÍCULA)......\n");
    printf("Digite o prefixo (matrícula) da aeronave: ");
    fgets(buscar_prefixo, STR_SIZE, stdin);
    remover_enter(buscar_prefixo);
    to_upper_string(buscar_prefixo);

    while(atual != NULL){
        if(strcmp(atual->matricula, buscar_prefixo) == 0){ 
            mostrar_dados_aeronaves(atual, stdout);
            encontrou = TRUE;
            break;
        }
        atual = atual->prox;
    }

    if(encontrou == FALSE){
        printf("Nenhuma aeronave encontrada com o prefixo informado!\n");
    }

    mensagem("Pressione ENTER para continuar!");
}

void listar_aeronaves_por_fabricante(dados_aeronaves_t *lista)
{
    char buscar_fabricante[STR_SIZE];
    int encontrou = FALSE;
    dados_aeronaves_t *atual = lista;

    printf("......LISTAR AERONAVE POR FABRICANTE......\n");
    printf("Digite o nome do fabricante: ");
    fgets(buscar_fabricante, STR_SIZE, stdin);
    remover_enter(buscar_fabricante);
    to_upper_string(buscar_fabricante);

    printf("Aeronaves do fabricante %s: \n", buscar_fabricante);

    while(atual != NULL){
        if(strcmp(atual->fabricante, buscar_fabricante) == 0){
            mostrar_dados_aeronaves(atual, stdout);
            encontrou = TRUE;
        }
        atual = atual->prox;
    }

    if(encontrou == FALSE){
        printf("Nenhuma aeronave encontrada com o fabricante informado!\n");
    }

    mensagem("Pressione ENTER para continuar!");
}

void listar_aeronaves_por_tipo(dados_aeronaves_t *lista)
{
    int tipo_escolhido;
    int encontrou = FALSE;
    dados_aeronaves_t *atual = lista;

    printf("......LISTAR AERONAVE POR TIPO (CARGA OU PASSAGEIRO)......\n");
    printf("Digite o tipo da aeronave (1- CARGA OU 2- PASSAGEIRO): ");
    scanf("%i", &tipo_escolhido);
    while (getchar() != '\n');

    if(tipo_escolhido != CARGA && tipo_escolhido != PASSAGEIRO) {
        printf("\nTipo de aeronave inválido!\n");
        mensagem("Pressione ENTER para continuar!");
        return;
    }

    if(tipo_escolhido == CARGA){
        printf("Aeronaves de carga: \n");
    }
    else {
        printf("Aeronaves de passageiros: \n");
    }

    while(atual != NULL) {
        if(atual->tipo == (tipo_aeronave_t)tipo_escolhido){
            mostrar_dados_aeronaves(atual, stdout);
            encontrou = TRUE;
        }
        atual = atual->prox;
    }

    if(encontrou == FALSE){
        printf("Nenhuma aeronave encontrada com o tipo informado!\n");
    }

    mensagem("Pressione ENTER para continuar!");
}

void listar_aeronaves_por_modelo(dados_aeronaves_t *lista)
{
    char buscar_modelo[STR_SIZE];
    int encontrou = FALSE;
    dados_aeronaves_t *atual = lista;

    printf("......BUSCAR AERONAVE POR MODELO......\n");
    printf("Digite o modelo da aeronave: ");
    fgets(buscar_modelo, STR_SIZE, stdin);
    remover_enter(buscar_modelo);
    to_upper_string(buscar_modelo);

    printf("Aeronaves do modelo: %s: \n", buscar_modelo);

    while(atual != NULL){
        if(strcmp(atual->modelo, buscar_modelo) == 0){
            mostrar_dados_aeronaves(atual, stdout);
            encontrou = TRUE;
        }
        atual = atual->prox;
    }

    if(encontrou == FALSE){
        printf("Nenhuma aeronave encontrada com o modelo informado!\n");
    }

    mensagem("Pressione ENTER para continuar!");
}

void listar_aeronaves_por_fabricacao(dados_aeronaves_t *lista)
{
    int buscar_ano;
    int encontrou = FALSE;
    dados_aeronaves_t *atual = lista;

    printf("......LISTAR AERONAVES POR ANO DE FABRICAÇÃO......\n");
    printf("Digite o ano de fabricação da aeronave: ");
    scanf("%i", &buscar_ano);
    while(getchar() != '\n');

    printf("Aeronaves fabricadas no ano de %i: \n", buscar_ano);

    while(atual != NULL){
        if(atual->ano_fabricacao == buscar_ano){
            mostrar_dados_aeronaves(atual, stdout);
            encontrou = TRUE;
        }
        atual = atual->prox;
    }

    if(encontrou == FALSE){
        printf("Nenhuma aeronave fabricada no ano informado encontrada!\n");
    }

    mensagem("Pressione ENTER para continuar!");
}

void listar_aeronaves_por_situacao(dados_aeronaves_t *lista)
{
    int situacao_escolhida;
    int encontrou = FALSE;
    dados_aeronaves_t *atual = lista;

    printf("......LISTAR AERONAVE POR SITUAÇÃO (OPERAÇÃO OU MANUTENÇÃO)......\n");
    printf("Digite a situação das aeronaves (1- Em operação ou 2- Em manutenção): ");
    scanf("%i", &situacao_escolhida);
    while (getchar() != '\n');

    if(situacao_escolhida != OPERACAO && situacao_escolhida != MANUTENCAO) {
        printf("\nSituação de aeronave inválida!\n");
        mensagem("Pressione ENTER para continuar!");
        return;
    }

    if(situacao_escolhida == OPERACAO){
        printf("Aeronaves em operação: \n");
    }
    else {
        printf("Aeronaves em manutenção: \n");
    }

    while(atual != NULL) {
        if(atual->status == (status_t)situacao_escolhida){
            mostrar_dados_aeronaves(atual, stdout);
            encontrou = TRUE;
        }
        atual = atual->prox;
    }

    if(encontrou == FALSE){
        printf("Nenhuma aeronave encontrada com a situação informada!\n");
    }

    mensagem("Pressione ENTER para continuar!");
}

void consultar_rota_por_data(dados_rotas_t *lista)
{
    data_t buscar_data;
    int encontrou = FALSE;
    dados_rotas_t *atual = lista;

    printf("......CONSULTAR ROTA POR DATA......\n");
    printf("Digite a data do voo (dd/mm/aaaa): ");
    scanf("%i/%i/%i", &buscar_data.dia, &buscar_data.mes, &buscar_data.ano);
    getchar();

    printf("Rotas na data %i/%i/%i:\n", buscar_data.dia, buscar_data.mes, buscar_data.ano);

    while(atual != NULL){
        data_t rota_data = atual->data_e_hora;

        if(rota_data.dia == buscar_data.dia &&
            rota_data.mes == buscar_data.mes &&
            rota_data.ano == buscar_data.ano){
                mostrar_dados_rotas(atual, stdout);
                encontrou = TRUE;
            }
        atual = atual->prox;
    }

    if(encontrou == FALSE){
        printf("Nenhuma rota encontrada com a data informada!");
    }

    mensagem("Pressione ENTER para continuar!");
}

void consultar_rota_por_origem(dados_rotas_t *lista)
{
    char buscar_origem[STR_SIZE];
    int encontrou = FALSE;
    dados_rotas_t *atual = lista;

    printf("......CONSULTAR ROTA POR ORIGEM......\n");
    printf("Digite o local de origem: ");
    fgets(buscar_origem, STR_SIZE, stdin);
    remover_enter(buscar_origem);
    to_upper_string(buscar_origem);

    while(atual != NULL){
        if(strcmp(atual->local_partida, buscar_origem) == 0){
            mostrar_dados_rotas(atual, stdout);
            encontrou = TRUE;
        }
        atual = atual->prox;
    }

    if (encontrou == FALSE){
        printf("Nenhuma rota encontrada para a origem informada!");
    }

    mensagem("Pressione ENTER para continuar!");
}

void consultar_rota_por_destino(dados_rotas_t *lista)
{
    char buscar_destino[STR_SIZE];
    int encontrou = FALSE;
    dados_rotas_t *atual = lista;

    printf("......CONSULTAR ROTA POR DESTINO......\n");
    printf("Digite o local de destino: ");
    fgets(buscar_destino, STR_SIZE, stdin);
    remover_enter(buscar_destino);
    to_upper_string(buscar_destino);

    printf("Rotas com destino em %s: \n", buscar_destino);

    while(atual != NULL){
        if(strcmp(atual->local_destino, buscar_destino) == 0){
            mostrar_dados_rotas(atual, stdout);
            encontrou = TRUE;
        }
        atual = atual->prox;
    }

    if (encontrou == FALSE){
        printf("Nenhuma rota encontrada para o destino informado!");
    }

    mensagem("Pressione ENTER para continuar!");
}

double consumototal_combustivel_por_data(dados_rotas_t *lista)
{
    data_t data_inicio, data_fim;
    double consumo_total = 0.0;
    dados_rotas_t *atual = lista;
    int encontrou_voo = FALSE;

    printf("......CONSULTAR CONSUMO TOTAL DE COMBUSTÍVEL EM INTERVALOS DE DATAS......\n");
    
    printf("Data de início do intervalo (dd/mm/aaaa): ");
    scanf("%i/%i/%i", &data_inicio.dia, &data_inicio.mes, &data_inicio.ano);
    while(getchar() != '\n');

    printf("Data de fim do intervalo (dd/mm/aaaa): ");
    scanf("%i/%i/%i", &data_fim.dia, &data_fim.mes, &data_fim.ano);
    while(getchar() != '\n');

    while(atual != NULL){
        int depois_ou_igual_inicio = data_maior_ou_igual(atual->data_e_hora, data_inicio);
        int antes_ou_igual_fim = data_maior_ou_igual(data_fim, atual->data_e_hora);
        
        if(depois_ou_igual_inicio && antes_ou_igual_fim) {
            consumo_total += atual->combustivel_voo;
            encontrou_voo = TRUE;
        }
        atual = atual->prox;
    }

    printf("......RESULTADO DE CONSUMO......\n");
    printf("Intervalo: %i/%i/%i a %i/%i/%i\n", data_inicio.dia, data_inicio.mes, data_inicio.ano, data_fim.dia, data_fim.mes, data_fim.ano);
    
    if(encontrou_voo == FALSE) {
        printf("Nenhuma rota encontrada nesse intervalo!\n");
    } else {
        printf("Consumo total de combustível no período: %.2f Litros\n", consumo_total);
    }

    mensagem("Pressione ENTER para continuar!");

    return consumo_total;
}

double percentual_voos_por_aeronaves(dados_rotas_t *lista_rotas, dados_aeronaves_t *lista_aeronaves)
{
    int id_procurado;
    int voos_aeronave = 0;
    int total_rotas = 0;
    dados_rotas_t *atual_rota = lista_rotas;
    dados_aeronaves_t *aeronave_buscada = NULL;
    double percentual = 0.0;

    printf("......PERCENTUAL DE VOOS POR AERONAVE......\n");

    if(lista_rotas == NULL){
        printf("Nenhuma rota cadastrada para calcular o percentual!\n");
        mensagem("Pressione ENTER para continuar!");
        return 0.0;
    }

    printf("Digite o ID da aeronave: ");
    scanf("%i", &id_procurado);
    while(getchar() != '\n');

    aeronave_buscada = localizar_aeronave_por_id(id_procurado, lista_aeronaves);
    if(aeronave_buscada == NULL){
        printf("Aeronave com ID: %i não encontrada!\n", id_procurado);
        mensagem("Pressione ENTER para continuar!");
        return 0.0;
    }

    while(atual_rota != NULL) {
        total_rotas++;
        if(atual_rota->id_aeronave == id_procurado){
            voos_aeronave++;
        }
        atual_rota = atual_rota->prox;
    }
    
    if (total_rotas != 0) {
        percentual = (double)voos_aeronave / total_rotas * 100.0;
    } else {
        percentual = 0.0;
    }

    printf("......RESULTADO DO PERCENTUAL......\n");
    printf("Aeronave: %s (ID %i)\n", aeronave_buscada->matricula, id_procurado);
    printf("Total de rotas cadastradas: %i\n", total_rotas);
    printf("Voos realizados pela aeronave: %i\n", voos_aeronave);
    printf("Percentual de voos realizados pela aeronave: %.2f%%\n", percentual);

    mensagem("Pressione ENTER para continuar!");

    return percentual;
}

double percentual_voos_em_destino_por_intervalo_datas(dados_rotas_t *lista)
{
    data_t data_inicio, data_fim;
    char destino_procurado[STR_SIZE];
    int voos_no_intervalo = 0;
    int voos_no_destino = 0;
    dados_rotas_t *atual = lista;

    printf("......VERIFICAR O PERCENTUAL DE VOOS POR DESTINO EM INTERVALO DE DATAS......\n");

    if(lista == NULL){
        printf("Nenhuma rota cadastrada para calcular o percentual!\n");
        mensagem("Pressione ENTER para continuar!");
        return 0.0;
    }

    printf("Data de início do intervalo (dd/mm/aaaa): ");
    scanf("%i/%i/%i", &data_inicio.dia, &data_inicio.mes, &data_inicio.ano);
    while(getchar () != '\n');

    printf("Data de fim do intervalo (dd/mm/aaaa): ");
    scanf("%i/%i/%i", &data_fim.dia, &data_fim.mes, &data_fim.ano);
    while(getchar() != '\n');

    printf("Destino a ser verificado: ");
    fgets(destino_procurado, STR_SIZE, stdin);
    remover_enter(destino_procurado);
    to_upper_string(destino_procurado);

    while(atual != NULL){
        int depois_ou_igual_inicio = data_maior_ou_igual(atual->data_e_hora, data_inicio);
        int antes_ou_igual_fim = data_maior_ou_igual(data_fim, atual->data_e_hora);

        if(depois_ou_igual_inicio && antes_ou_igual_fim){
            voos_no_intervalo++;
            if(strcmp(atual->local_destino, destino_procurado) == 0){
                voos_no_destino++;
            }
        }
        atual = atual->prox;
    }

    if(voos_no_intervalo == 0){
        printf("Nenhuma rota encontrada nesse intervalo!");
        mensagem("Pressione ENTER para continuar!");
        return 0.0;
    }

    double percentual = (double)voos_no_destino / voos_no_intervalo * 100.0;

    printf("......RESULTADO DO PERCENTUAL...... \n");
    printf("Intervalo: %i/%i/%i a %i/%i/%i\n", data_inicio.dia, data_inicio.mes, data_inicio.ano, data_fim.dia, data_fim.mes, data_fim.ano);
    printf("Total de voos no intervalo: %i\n", voos_no_intervalo);
    printf("Voos para o destino %s no intervalo: %i\n", destino_procurado, voos_no_destino);
    printf("Percentual de voos para o destino: %.2f%%\n", percentual);

    mensagem("Pressione ENTER para continuar!");

    return percentual;
}

int buscar_qtd_manutencao_por_aeronaves(dados_aeronaves_t *lista)
{
    int id_procurado;
    dados_aeronaves_t *aeronave = NULL;

    printf("......QUANTIDADE DE VEZES QUE A AERONAVE ENTROU EM MANUTENÇÃO......\n");
    printf("Digite o ID da aeronave: ");
    scanf("%i", &id_procurado);
    while (getchar() != '\n');

    aeronave = localizar_aeronave_por_id(id_procurado, lista);

    if(aeronave != NULL){
        int manutencoes = aeronave->qtd_manutencoes;
        printf("Aeronave ID: %i (%s) entrou em manutenção: %i vezes.\n", id_procurado, aeronave->matricula, manutencoes);
    }
    else{
        printf("Aeronave não encontrada!");
    }

    mensagem("Pressione ENTER para continuar!");
    if(aeronave != NULL){
        return aeronave->qtd_manutencoes;
    }
    else{
        return 0;
    }
}