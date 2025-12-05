#include "../include/utils.h"
#include "../include/types.h"
#include "../include/cadastros.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void limpar_tela()
{
    system("clear"); 
}

void to_upper_string(char *str)
{
    for(int i = 0; str[i] != '\0'; i++){
        str[i] = toupper(str[i]);
    }
}

int data_maior_ou_igual(data_t primeira_data, data_t segunda_data)
{
    if(primeira_data.ano > segunda_data.ano) return 1;
    if(primeira_data.ano == segunda_data.ano) {
        if(primeira_data.mes > segunda_data.mes) return 1;
        if(primeira_data.mes == segunda_data.mes){
            if(primeira_data.dia >= segunda_data.dia) return 1;
        }
    }
    return 0;
}

void mensagem(char* msg)
{
    printf("%s\n", msg);
    getchar();
}

void remover_enter(char *str)
{
    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}

int validar_aeronave(int id_aeronave, dados_aeronaves_t *lista)
{
    return localizar_aeronave_por_id(id_aeronave, lista) != NULL;
}