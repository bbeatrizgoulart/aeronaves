#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "types.h"

void mostrar_dados_aeronaves(dados_aeronaves_t *aeronave, FILE *fp);
void mostrar_dados_rotas(dados_rotas_t *rota, FILE *fp);
void relatorio_aeronaves(dados_aeronaves_t *lista, FILE *fp);
void relatorio_rotas(dados_rotas_t *lista, FILE *fp);
void listar_rotas_maiornumero_passageiros(dados_rotas_t *lista, FILE *fp);
void listar_rotas_menornumero_passageiros(dados_rotas_t *lista, FILE *fp);

#endif