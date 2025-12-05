#ifndef CADASTROS_H
#define CADASTROS_H

#include "types.h"

dados_aeronaves_t *nova_aeronave();
dados_rotas_t *nova_rota(dados_aeronaves_t *lista_aeronaves);
void inserir_aeronave_lista_pelo_fim(dados_aeronaves_t **lista, dados_aeronaves_t *nova_aeronave);
void inserir_rota_lista_pelo_fim(dados_rotas_t **lista, dados_rotas_t *nova_rota);
dados_aeronaves_t *localizar_aeronave_por_id(int id_aeronave, dados_aeronaves_t *lista);
void alterar_status_aeronave(dados_aeronaves_t **lista_aeronaves);

#endif