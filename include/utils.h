#ifndef UTILS_H
#define UTILS_H

#include "types.h"

void limpar_tela();
void to_upper_string(char *str);
int data_maior_ou_igual(data_t primeira_data, data_t segunda_data);
void mensagem(char* msg);
void remover_enter(char *str);
int validar_aeronave(int id_aeronave, dados_aeronaves_t *lista);

#endif