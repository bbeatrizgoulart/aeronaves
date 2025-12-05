#include "../include/arquivos.h"
#include "../include/cadastros.h"
#include "../include/types.h"
#include "../include/relatorios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void salvar_dados_aeronaves_bin(dados_aeronaves_t *lista, string nome_arq)
{
    FILE *fp_arquivo = NULL;
    fp_arquivo = fopen(nome_arq, "wb"); 

    if (fp_arquivo == NULL) {
        printf("Erro na abertura do arquivo %s para salvar aeronaves.\n", nome_arq);
        return;
    }

    dados_aeronaves_t *atual = lista;

    while (atual) {
        fwrite(atual, sizeof(dados_aeronaves_t), 1, fp_arquivo);
        atual = atual->prox;
    }

    fclose(fp_arquivo); 
}

void ler_dados_aeronaves_bin(string nome_arq, dados_aeronaves_t **lista)
{
    FILE *fp_arquivo = NULL;
    dados_aeronaves_t *aeronave_lida = NULL;
    
    fp_arquivo = fopen(nome_arq, "rb");

    if (fp_arquivo == NULL) {
        printf("Arquivo %s de aeronaves não encontrado. Criando nova lista.\n", nome_arq);
        return;
    }
    
    *lista = NULL;

    while (!feof(fp_arquivo)) {
        aeronave_lida = (dados_aeronaves_t*)malloc(sizeof(dados_aeronaves_t));
        if (aeronave_lida == NULL) break; 

        fread(aeronave_lida, sizeof(dados_aeronaves_t), 1, fp_arquivo);
        
        aeronave_lida->prox = NULL;

        if (!feof(fp_arquivo)) {
            inserir_aeronave_lista_pelo_fim(lista, aeronave_lida);
        } else {
            free(aeronave_lida);
        }
    }

    fclose(fp_arquivo);
}

void salvar_dados_rotas_bin(dados_rotas_t *lista, string nome_arq)
{
    FILE *fp_arquivo = NULL;
    fp_arquivo = fopen(nome_arq, "wb");

    if (fp_arquivo == NULL) {
        printf("Erro na abertura do arquivo %s para salvar rotas.\n", nome_arq);
        return;
    }

    dados_rotas_t *atual = lista;

    while (atual) {
        fwrite(atual, sizeof(dados_rotas_t), 1, fp_arquivo);
        atual = atual->prox;
    }

    fclose(fp_arquivo);
}

void ler_dados_rotas_bin(string nome_arq, dados_rotas_t **lista)
{
    FILE *fp_arquivo = NULL;
    dados_rotas_t *rota_lida = NULL;
    
    fp_arquivo = fopen(nome_arq, "rb");

    if (fp_arquivo == NULL) {
        printf("Arquivo %s de rotas não encontrado. Criando nova lista.\n", nome_arq);
        return;
    }
    
    *lista = NULL;

    while (!feof(fp_arquivo)) {
        rota_lida = (dados_rotas_t*)malloc(sizeof(dados_rotas_t));
        if (rota_lida == NULL) break; 

        fread(rota_lida, sizeof(dados_rotas_t), 1, fp_arquivo);
        
        rota_lida->prox = NULL;

        if (!feof(fp_arquivo)) {
            inserir_rota_lista_pelo_fim(lista, rota_lida);
        } else {
            free(rota_lida); 
        }
    }

    fclose(fp_arquivo);
}

void exportar_aeronaves_txt(dados_aeronaves_t *lista_aeronaves, string nome_arq)
{
    FILE *fp =  NULL;

    fp = fopen(nome_arq, "w");

    if(!fp){
        printf("Erro ao tentar abrir arquivo %s/n", nome_arq);
        return;
    }

    dados_aeronaves_t *atual = lista_aeronaves;

    while(atual){
        mostrar_dados_aeronaves(atual, fp);
        fprintf(fp, "\n");
        atual = atual->prox;
    }

    fclose(fp);
    printf("Dados de aeronaves exportados com sucesso para %s:\n", nome_arq);
}

void exportar_aeronaves_csv(dados_aeronaves_t *lista_aeronaves, string nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "ID;MODELO;FABRICANTE;MATRICULA;ANO_FABRICACAO;TIPO;PASSAGEIROS;CARGA_UTIL;STATUS;TRIPULANTES;QTD_MANUTENCOES\n");
    
    dados_aeronaves_t *atual = lista_aeronaves;
    while (atual) {
        char tipo_str[20];
        char status_str[20];

        if (atual->tipo == CARGA) {
            strcpy(tipo_str, "CARGA");
        } else {
            strcpy(tipo_str, "PASSAGEIRO");
        }

        if (atual->status == OPERACAO) {
            strcpy(status_str, "OPERACAO");
        } else {
            strcpy(status_str, "MANUTENCAO");
        }

        
        fprintf(fp, "%i;%s;%s;%s;%i;%s;%i;%i;%s;%i;%i\n", 
            atual->id_aeronave, 
            atual->modelo, 
            atual->fabricante, 
            atual->matricula, 
            atual->ano_fabricacao,
            tipo_str, 
            atual->num_passageiros,
            atual->qtd_carga_util,
            status_str, 
            atual->num_tripulantes,
            atual->qtd_manutencoes
        );
        atual = atual->prox;
    }

    fclose(fp);
    printf("Dados de aeronaves exportados com sucesso para %s\n", nome_arq);
}

void exportar_aeronaves_html(dados_aeronaves_t *lista_aeronaves, string nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "<!DOCTYPE html>\n<HTML>\n<HEAD>\n<TITLE> RELATORIO DE AERONAVES </TITLE>\n<style>table {border-collapse: collapse;} th, td {border: 1px solid black; padding: 8px; text-align: left;}</style>\n</HEAD>\n<BODY>\n");
    fprintf(fp, "<h1>Relatorio de Aeronaves</h1>");
    fprintf(fp, "<TABLE>\n <TR>\n <TH> ID </TH> <TH> MATRICULA </TH> <TH> MODELO </TH> <TH> FABRICANTE </TH> <TH> TIPO </TH> <TH> STATUS </TH>\n </TR>\n");
    
    dados_aeronaves_t *atual = lista_aeronaves;
    while (atual) {
        char tipo_str[20];
        char status_str[20];

        if (atual->tipo == CARGA) {
            strcpy(tipo_str, "CARGA");
        } else {
            strcpy(tipo_str, "PASSAGEIRO");
        }

        if (atual->status == OPERACAO) {
            strcpy(status_str, "EM OPERACAO");
        } else {
            strcpy(status_str, "EM MANUTENCAO");
        }
        
        fprintf(fp, "<TR>\n <TD> %i </TD> <TD> %s </TD> <TD> %s </TD> <TD> %s </TD> <TD> %s </TD> <TD> %s </TD>\n </TR>\n", 
            atual->id_aeronave, 
            atual->matricula, 
            atual->modelo, 
            atual->fabricante, 
            tipo_str, 
            status_str 
        );
        atual = atual->prox;
    }
    
    fprintf(fp, "</TABLE>\n</BODY>\n</HTML>\n");

    fclose(fp);
    printf("Dados de aeronaves exportados com sucesso para %s\n", nome_arq);
}

void exportar_rotas_txt(dados_rotas_t *lista_rotas, string nome_arq)
{
    FILE *fp = NULL;
    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    dados_rotas_t *atual = lista_rotas;
    
    while (atual) {
        mostrar_dados_rotas(atual, fp);
        
        fprintf(fp, "\n");
    
        atual = atual->prox;
    }

    fclose(fp);
    printf("Dados de rotas exportados com sucesso para %s\n", nome_arq);
}

void exportar_rotas_csv(dados_rotas_t *lista_rotas, string nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "CODIGO_ROTA;ID_AERONAVE;DATA;HORA;ORIGEM;DESTINO;TEMPO_ESTIMADO;COMBUSTIVEL;PASSAGEIROS;CARGA_UTIL;TRIPULANTES\n");
    
    dados_rotas_t *atual = lista_rotas;
    while (atual) {
        fprintf(fp, "%i;%i;%02i/%02i/%i;%02i:%02i;%s;%s;%.2f;%.2f;%i;%i;%i\n", 
            atual->codigo_rota, 
            atual->id_aeronave,
            atual->data_e_hora.dia, atual->data_e_hora.mes, atual->data_e_hora.ano,
            atual->data_e_hora.hora, atual->data_e_hora.min,
            atual->local_partida,
            atual->local_destino,
            atual->tempo_estimado,
            atual->combustivel_voo,
            atual->qtd_passageiros,
            atual->carga_util,
            atual->num_membros
        );
        atual = atual->prox;
    }

    fclose(fp);
    printf("Dados de rotas exportados com sucesso para %s\n", nome_arq);
}

void exportar_rotas_html(dados_rotas_t *lista_rotas, string nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "<!DOCTYPE html>\n<HTML>\n<HEAD>\n<TITLE> RELATORIO DE ROTAS </TITLE>\n<style>table {border-collapse: collapse;} th, td {border: 1px solid black; padding: 8px; text-align: left;}</style>\n</HEAD>\n<BODY>\n");
    fprintf(fp, "<h1>Relatorio de Rotas de Voo</h1>");
    fprintf(fp, "<TABLE>\n <TR>\n <TH> CODIGO </TH> <TH> AERONAVE (ID) </TH> <TH> DATA </TH> <TH> HORA </TH> <TH> ORIGEM </TH> <TH> DESTINO </TH>\n </TR>\n");
    
    dados_rotas_t *atual = lista_rotas;
    while (atual) {
        fprintf(fp, "<TR>\n <TD> %i </TD> <TD> %i </TD> <TD> %02i/%02i/%i </TD> <TD> %02i:%02i </TD> <TD> %s </TD> <TD> %s </TD>\n </TR>\n", 
            atual->codigo_rota, 
            atual->id_aeronave, 
            atual->data_e_hora.dia, atual->data_e_hora.mes, atual->data_e_hora.ano,
            atual->data_e_hora.hora, atual->data_e_hora.min,
            atual->local_partida, 
            atual->local_destino
        );
        atual = atual->prox;
    }
  
    fprintf(fp, "</TABLE>\n</BODY>\n</HTML>\n");

    fclose(fp);
    printf("Dados de rotas exportados com sucesso para %s\n", nome_arq);
}