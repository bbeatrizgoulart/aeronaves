#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "types.h"

void salvar_dados_aeronaves_bin(dados_aeronaves_t *lista, string nome_arq);
void ler_dados_aeronaves_bin(string nome_arq, dados_aeronaves_t **lista);
void salvar_dados_rotas_bin(dados_rotas_t *lista, string nome_arq);
void ler_dados_rotas_bin(string nome_arq, dados_rotas_t **lista);
void exportar_aeronaves_txt(dados_aeronaves_t *lista_aeronaves, string nome_arq);
void exportar_aeronaves_csv(dados_aeronaves_t *lista_aeronaves, string nome_arq);
void exportar_aeronaves_html(dados_aeronaves_t *lista_aeronaves, string nome_arq);
void exportar_rotas_txt(dados_rotas_t *lista_rotas, string nome_arq);
void exportar_rotas_csv(dados_rotas_t *lista_rotas, string nome_arq);
void exportar_rotas_html(dados_rotas_t *lista_rotas, string nome_arq);

#endif