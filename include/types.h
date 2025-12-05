#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define STR_SIZE 100
#define FIM 0
#define TRUE 1
#define FALSE 0
#define ARQUIVO_AERONAVES "aeronaves.bin"
#define ARQUIVO_ROTAS "rotas.bin"

typedef char string[STR_SIZE];
typedef enum {OPERACAO = 1, MANUTENCAO = 2} status_t;
typedef enum {CARGA = 1, PASSAGEIRO = 2} tipo_aeronave_t;

typedef struct dados_aeronaves {
    int id_aeronave;
    string modelo;
    string fabricante;
    string matricula;
    int ano_fabricacao;
    tipo_aeronave_t tipo;
    int num_passageiros;
    int qtd_carga_util;
    status_t status;
    int num_tripulantes;
    int qtd_manutencoes;
    struct dados_aeronaves *prox;
} dados_aeronaves_t;

typedef struct data {
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
    unsigned int hora;
    unsigned int min;
} data_t;

typedef struct dados_rotas{
    int codigo_rota;
    data_t data_e_hora;
    string local_partida;
    string local_destino;
    float tempo_estimado;
    float combustivel_voo;
    int qtd_passageiros;
    int carga_util;
    string nomes_membros[10];
    int num_membros;
    int id_aeronave;
    struct dados_rotas *prox;
} dados_rotas_t;

#endif 