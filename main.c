#include "./include/types.h"
#include "./include/menus.h"
#include "./include/cadastros.h"
#include "./include/relatorios.h"
#include "./include/consultas.h"
#include "./include/arquivos.h"
#include <stdio.h>

int main ()
{
    dados_aeronaves_t *lista_aeronaves = NULL;
    dados_rotas_t *lista_rotas = NULL;
    int opc_main, opc_sub, opc_sub_sub; 
    
    ler_dados_aeronaves_bin(ARQUIVO_AERONAVES, &lista_aeronaves);
    ler_dados_rotas_bin(ARQUIVO_ROTAS, &lista_rotas);
    
    do { 
        opc_main = menu_principal();

        switch (opc_main) {
            case 1: // CADASTRO
                opc_sub = menu_cadastro();
                if(opc_sub == 1) {
                    dados_aeronaves_t *nova = nova_aeronave();
                    if(nova != NULL) inserir_aeronave_lista_pelo_fim(&lista_aeronaves, nova);
                }
                if(opc_sub == 2) {
                    dados_rotas_t *nova = nova_rota(lista_aeronaves); 
                    if(nova != NULL) inserir_rota_lista_pelo_fim(&lista_rotas, nova);
                }
                break;
            case 2: // RELATÓRIOS
                opc_sub = menu_relatorios();
                switch (opc_sub) {
                    case 1: relatorio_aeronaves(lista_aeronaves, stdout); break;
                    case 2: relatorio_rotas(lista_rotas, stdout); break;
                    case 3: listar_rotas_maiornumero_passageiros(lista_rotas, stdout); break;
                    case 4: listar_rotas_menornumero_passageiros(lista_rotas, stdout); break;
                }
                break;
            case 3: // BUSCAS E CONSULTAS 
                opc_sub = menu_escolha_consultas();
                if(opc_sub == 1) { // AERONAVES
                    opc_sub_sub = menu_consultas_aeronaves();
                    switch (opc_sub_sub) {
                        case 1: buscar_aeronave_por_prefixo(lista_aeronaves); break;
                        case 2: listar_aeronaves_por_fabricante(lista_aeronaves); break;
                        case 3: listar_aeronaves_por_tipo(lista_aeronaves); break;
                        case 4: listar_aeronaves_por_modelo(lista_aeronaves); break;
                        case 5: listar_aeronaves_por_fabricacao(lista_aeronaves); break;
                        case 6: listar_aeronaves_por_situacao(lista_aeronaves); break;
                    }
                } else if (opc_sub == 2) { // ROTAS
                    opc_sub_sub = menu_consultas_rotas();
                     switch (opc_sub_sub) {
                        case 1: consultar_rota_por_data(lista_rotas); break;
                        case 2: consultar_rota_por_origem(lista_rotas); break;
                        case 3: consultar_rota_por_destino(lista_rotas); break;
                    }
                } else if (opc_sub == 3) { // ESTATÍSTICAS
                    opc_sub_sub = menu_consultas_estatisticas();
                    switch (opc_sub_sub) {
                        case 1: consumototal_combustivel_por_data(lista_rotas); break;
                        case 2: percentual_voos_por_aeronaves(lista_rotas, lista_aeronaves); break;
                        case 3: percentual_voos_em_destino_por_intervalo_datas(lista_rotas); break;
                    }
                }
                break;
            case 4: // MUDAR STATUS
                alterar_status_aeronave(&lista_aeronaves);
                break;
            case 5: // CONTAR MANUTENÇÕES
                buscar_qtd_manutencao_por_aeronaves(lista_aeronaves);
                break;

            case 0: 
                printf("Fechando o programa. Os dados cadastrados serão perdidos.\n");
                // SALVAR DADOS ANTES DE SAIR
                salvar_dados_aeronaves_bin(lista_aeronaves, ARQUIVO_AERONAVES);
                salvar_dados_rotas_bin(lista_rotas, ARQUIVO_ROTAS);
                printf("Dados salvos em arquivos binários.\n");
                break;
        }

    } while (opc_main != FIM);

    return 0;
}