#include "../include/exportar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exportar_aeronaves_csv(dados_aeronaves_t *inicio) {
    FILE *fp = fopen("aeronaves.csv", "w");

    fprintf(fp, "ID;Modelo;Fabricante;Matricula;Ano;Tipo (1=Carga, 2=Passageiro);Passageiros;Carga Util (kg);Status (1=Operacao, 2=Manutencao);Tripulantes;Manutencoes\n");

    dados_aeronaves_t *atual = inicio;
    while (atual != NULL) {
        fprintf(fp, "%d;%s;%s;%s;%d;%d;%d;%d;%d;%d;%d\n",
                atual->id_aeronave,
                atual->modelo,
                atual->fabricante,
                atual->matricula,
                atual->ano_fabricacao,
                atual->tipo,
                atual->num_passageiros,
                atual->qtd_carga_util,
                atual->status,
                atual->num_tripulantes,
                atual->qtd_manutencoes);
        atual = atual->prox;
    }

    fclose(fp);
    printf(" Aeronaves exportadas com sucesso.\n");
}

void exportar_rotas_csv(dados_rotas_t *inicio) {
    FILE *fp = fopen("rotas.csv", "w");

    fprintf(fp, "Codigo Rota;Data;Hora;Partida;Destino;Tempo Estimado (h);Combustivel (L);Qtd Passageiros;Carga Util (kg);ID Aeronave;Membros Tripulacao\n");

    dados_rotas_t *atual = inicio;
    while (atual != NULL) {
        fprintf(fp, "%d;%02u/%02u/%04u;%02u:%02u;%s;%s;%.2f;%.2f;%d;%d;%d",
                atual->codigo_rota,
                atual->data_e_hora.dia, atual->data_e_hora.mes, atual->data_e_hora.ano,
                atual->data_e_hora.hora, atual->data_e_hora.min,
                atual->local_partida, atual->local_destino, atual->tempo_estimado,
                atual->combustivel_voo, atual->qtd_passageiros, atual->carga_util,
                atual->id_aeronave);

        fprintf(fp, ";\"");
        for (int i = 0; i < atual->num_membros; i++) {
            fprintf(fp, "%s%s", atual->nomes_membros[i], (i < atual->num_membros - 1) ? ", " : "");
        }
        fprintf(fp, "\"\n");
        atual = atual->prox;
    }

    fclose(fp);
    printf(" Rotas exportadas com sucesso.\n");
}


void exportar_aeronaves_html(dados_aeronaves_t *inicio) {
    FILE *fp = fopen("aeronaves.html", "w");

    fprintf(fp, "<!DOCTYPE html><html><head><title>Aeronaves</title><style>table {border-collapse: collapse;} th, td {border: 1px solid black;}</style></head><body><h1>Aeronaves</h1><table><thead><tr><th>ID</th><th>Modelo</th><th>Fabricante</th><th>Tipo (1/2)</th><th>Status (1/2)</th></tr></thead><tbody>\n");

    dados_aeronaves_t *atual = inicio;
    while (atual != NULL) {
        fprintf(fp, "<tr><td>%d</td><td>%s</td><td>%s</td><td>%d</td><td>%d</td></tr>\n",
                atual->id_aeronave, atual->modelo, atual->fabricante,
                atual->tipo,
                atual->status);
        atual = atual->prox;
    }

    fprintf(fp, "</tbody></table></body></html>\n");

    fclose(fp);
    printf(" Aeronaves exportadas com sucesso.\n");
}

void exportar_rotas_html(dados_rotas_t *inicio) {
    FILE *fp = fopen("rotas.html", "w");
    
    fprintf(fp, "<!DOCTYPE html><html><head><title>Rotas</title><style>table {border-collapse: collapse;} th, td {border: 1px solid black;}</style></head><body><h1>Rotas</h1><table><thead><tr><th>Cód. Rota</th><th>Data/Hora</th><th>Origem</th><th>Destino</th><th>ID Aeronave</th></tr></thead><tbody>\n");

    dados_rotas_t *atual = inicio;
    while (atual != NULL) {
        fprintf(fp, "<tr><td>%d</td><td>%02u/%02u/%04u %02u:%02u</td><td>%s</td><td>%s</td><td>%d</td></tr>\n",
                atual->codigo_rota,
                atual->data_e_hora.dia, atual->data_e_hora.mes, atual->data_e_hora.ano,
                atual->data_e_hora.hora, atual->data_e_hora.min,
                atual->local_partida, atual->local_destino,
                atual->id_aeronave);

        atual = atual->prox;
    }

    fprintf(fp, "</tbody></table></body></html>\n");

    fclose(fp);
    printf(" Rotas exportadas com sucesso.\n");
}