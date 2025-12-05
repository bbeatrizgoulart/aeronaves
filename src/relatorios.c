#include "../include/relatorios.h"
#include "../include/utils.h"
#include <stdio.h>

void mostrar_dados_aeronaves(dados_aeronaves_t *aeronave, FILE *fp)
{
    fprintf(fp, "\n......DADOS DA AERONAVE......\n");
    fprintf(fp, "Identificação........: %i\n", aeronave->id_aeronave);
    fprintf(fp, "Modelo...............: %s\n", aeronave->modelo);
    fprintf(fp,"Fabricante...........: %s\n", aeronave->fabricante);
    fprintf(fp, "Matrícula............: %s\n", aeronave->matricula);
    fprintf(fp, "Ano de fabricação....: %i\n", aeronave->ano_fabricacao);
    
    if(aeronave->tipo == CARGA){
        fprintf(fp, "Tipo.................: CARGA (Capacidade: %i)\n", aeronave->qtd_carga_util);
    }
    else{
        fprintf(fp, "Tipo.................: PASSAGEIROS (Capacidade: %i)\n", aeronave->num_passageiros);
    }

    if(aeronave->status == OPERACAO){
        fprintf(fp, "Status...............: EM OPERAÇÃO\n");
    }
    else{
        fprintf(fp, "Status...............: EM MANUTENÇÃO (Qtd. Manutenções: %i)\n", aeronave->qtd_manutencoes);
    }

    fprintf(fp, "Tripulantes necessários: %i\n", aeronave->num_tripulantes);
}

void mostrar_dados_rotas(dados_rotas_t *rota, FILE *fp)
{
    fprintf(fp, "\n......DADOS DA ROTA......\n");
    fprintf(fp, "Código da rota..................: %d\n", rota->codigo_rota);
    fprintf(fp, "Aeronave alocada................: %i\n", rota->id_aeronave);
    fprintf(fp, "Data do voo.....................: %i/%i/%i \n", rota->data_e_hora.dia, rota->data_e_hora.mes, rota->data_e_hora.ano);
    fprintf(fp, "Horario do voo..................: %i:%i \n", rota->data_e_hora.hora, rota->data_e_hora.min);
    fprintf(fp, "Local de partida................: %s\n", rota->local_partida);        
    fprintf(fp, "Local de destino................: %s\n", rota->local_destino);
    fprintf(fp, "Tempo estimado de voo...........: %.2f horas\n", rota->tempo_estimado);
    fprintf(fp, "Combustivel necessário..........: %.2f litros\n", rota->combustivel_voo);
    fprintf(fp, "Quantidade de passageiros.......: %i\n", rota->qtd_passageiros);
    fprintf(fp, "Quantidade de carga util........: %i\n", rota->carga_util);
    fprintf(fp, "Número de tripulantes...........: %i\n", rota->num_membros);

    for(int i = 0; i < rota->num_membros; i++){
        fprintf(fp, "  - Membro %i: %s\n", i + 1, rota->nomes_membros[i]);
    }
}

void relatorio_aeronaves(dados_aeronaves_t *lista, FILE *fp)
{
    dados_aeronaves_t *atual = lista;
    int contador = 0;

    printf("......RELATÓRIO DE AERONAVES CADASTRADAS......\n");

    if(lista == NULL){
        printf("Nenhuma aeronave cadastrada!\n");
        mensagem("Pressione ENTER para continuar!");
        return;
    }

    while(atual != NULL) {
        printf("--- AERONAVE %i ---\n", contador + 1);
        mostrar_dados_aeronaves(atual, stdout);
        contador++;
        atual = atual->prox;
    }

    printf("\nTotal de aeronaves: %i\n", contador); 
    mensagem("Pressione ENTER para continuar!");
}

void relatorio_rotas(dados_rotas_t *lista, FILE *fp)
{
    dados_rotas_t *atual = lista;
    int contador = 0;

    printf("......RELATÓRIO DE ROTAS CADASTRADAS......\n");

    if(lista == NULL){
        printf("Nenhuma rota cadastrada!\n");
        mensagem("Pressione ENTER para continuar!");
        return;
    }

    while(atual != NULL) {
        printf("--- ROTA %i ---\n", contador + 1);
        mostrar_dados_rotas(atual, stdout);
        contador++;
        atual = atual->prox;
    }

    printf("\nTotal de rotas: %i\n", contador); 
    mensagem("Pressione ENTER para continuar!");
}

void listar_rotas_maiornumero_passageiros(dados_rotas_t *lista, FILE *fp)
{
    int max_passageiros = -1;
    dados_rotas_t *atual = lista;

    printf("......ROTAS COM O MAIOR NÚMERO DE PASSAGEIROS......\n");

    if(lista == NULL){
        printf("Nenhuma rota cadastrada!");
        mensagem("Pressione ENTER para continuar!");
        return;
    }

    while(atual != NULL) {
        if(atual->qtd_passageiros > max_passageiros){
            max_passageiros = atual->qtd_passageiros;
        }
        atual = atual->prox;
    }
    
    printf("Maior número de passageiros em uma rota: %i\n", max_passageiros);

    atual = lista; 
    while(atual != NULL) {
        if(atual->qtd_passageiros == max_passageiros){
            mostrar_dados_rotas(atual, stdout);
        }
        atual = atual->prox;
    }

    mensagem("Pressione ENTER para continuar!");
}

void listar_rotas_menornumero_passageiros(dados_rotas_t *lista, FILE *fp)
{
    int min_passageiros = 2147483647; 
    dados_rotas_t *atual = lista;

    printf("......ROTAS COM O MENOR NÚMERO DE PASSAGEIROS......\n");

    if(lista == NULL){
        printf("Nenhuma rota cadastrada!");
        mensagem("Pressione ENTER para continuar!");
        return;
    }

    while(atual != NULL) {
        if(atual->qtd_passageiros < min_passageiros){
            min_passageiros = atual->qtd_passageiros;
        }
        atual = atual->prox;
    }

    printf("Menor número de passageiros em uma rota: %i\n", min_passageiros);

    atual = lista; 
    while(atual != NULL) {
        if(atual->qtd_passageiros == min_passageiros){
            mostrar_dados_rotas(atual, stdout);
        }
        atual = atual->prox;
    }

    mensagem("Pressione ENTER para continuar!");
}