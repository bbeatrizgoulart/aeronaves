#ifndef EXPORTAR_H
#define EXPORTAR_H

#include "types.h"

void exportar_aeronaves_csv(dados_aeronaves_t *inicio);
void exportar_rotas_csv(dados_rotas_t *inicio);
oid exportar_aeronaves_html(dados_aeronaves_t *inicio);
void exportar_rotas_html(dados_rotas_t *inicio);

#endif