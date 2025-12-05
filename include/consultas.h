#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "types.h"

void buscar_aeronave_por_prefixo(dados_aeronaves_t *lista);
void listar_aeronaves_por_fabricante(dados_aeronaves_t *lista);
void listar_aeronaves_por_tipo(dados_aeronaves_t *lista);
void listar_aeronaves_por_modelo(dados_aeronaves_t *lista);
void listar_aeronaves_por_fabricacao(dados_aeronaves_t *lista);
void listar_aeronaves_por_situacao(dados_aeronaves_t *lista);
void consultar_rota_por_data(dados_rotas_t *lista);
void consultar_rota_por_origem(dados_rotas_t *lista);
void consultar_rota_por_destino(dados_rotas_t *lista);
double percentual_voos_em_destino_por_intervalo_datas(dados_rotas_t *lista);
double percentual_voos_por_aeronaves(dados_rotas_t *lista_rotas, dados_aeronaves_t *lista_aeronaves);
double consumototal_combustivel_por_data(dados_rotas_t *lista);
int buscar_qtd_manutencao_por_aeronaves(dados_aeronaves_t *lista);

#endif