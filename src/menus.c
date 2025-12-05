#include "../include/menus.h"
#include "../include/utils.h"
#include "../include/types.h"
#include <stdio.h>

int menu_principal()
{
    int opc;
    limpar_tela();
    printf("...MENU PRINCIPAL...\n");
    printf("1. Cadastro (Aeronave ou Rota)\n");
    printf("2. Relatórios\n");
    printf("3. Buscas e Consultas\n");
    printf("4. Mudar status da aeronave (Operação/Manutenção)\n");
    printf("5. Quantidade de manutenções por aeronave\n");
    printf("0. Sair do programa\n");
    printf("::: ");
    scanf("%i", &opc);
    getchar();
    return opc;
}

int menu_cadastro()
{
    int opc;
    limpar_tela();
    printf("...CADASTRO...\n");
    printf("1. Cadastrar nova aeronave\n");
    printf("2. Cadastrar nova rota\n");
    printf("0. Voltar ao Menu Principal\n");
    printf("::: ");
    scanf("%i", &opc);
    getchar();
    return opc;
}

int menu_relatorios()
{
    int opc;
    limpar_tela();
    printf("...RELATÓRIOS...\n");
    printf("1. Relatório de todas as aeronaves\n");
    printf("2. Relatório de todas as rotas\n");
    printf("3. Listar rotas com maior número de passageiros\n");
    printf("4. Listar rotas com menor número de passageiros\n");
    printf("0. Voltar ao Menu Principal\n");
    printf("::: ");
    scanf("%i", &opc);
    getchar();
    return opc;
}

int menu_escolha_consultas()
{
    int opc;
    limpar_tela();
    printf("...BUSCAS E CONSULTAS...\n");
    printf("1. Aeronaves\n");
    printf("2. Rotas\n");
    printf("3. Estatísticas\n");
    printf("0. Voltar ao Menu Principal\n");
    printf("::: ");
    scanf("%i", &opc);
    getchar();
    return opc;
}

int menu_consultas_aeronaves()
{
    int opc;
    limpar_tela();
    printf("..AERONAVES..\n");
    printf("1. Buscar aeronave por prefixo (Matrícula)\n");
    printf("2. Listar aeronaves por fabricante\n");
    printf("3. Listar aeronaves por tipo (Carga/Passageiro)\n");
    printf("4. Listar aeronaves por modelo\n");
    printf("5. Listar aeronaves por ano de fabricação\n");
    printf("6. Listar aeronaves por situação (Operação/Manutenção)\n");
    printf("0. Voltar ao menu anterior\n");
    printf("::: ");
    scanf("%i", &opc);
    getchar();
    return opc;
}

int menu_consultas_rotas()
{
    int opc;
    limpar_tela();
    printf("..ROTAS..\n");
    printf("1. Consultar rota por data\n");
    printf("2. Consultar rota por origem\n");
    printf("3. Consultar rota por destino\n");
    printf("0. Voltar ao menu anterior\n");
    printf("::: ");
    scanf("%i", &opc);
    getchar();
    return opc;
}

int menu_consultas_estatisticas()
{
    int opc;
    limpar_tela();
    printf("..ESTATÍSTICAS..\n");
    printf("1. Consultar consumo total de combustível em intervalo de datas\n");
    printf("2. Verificar percentual de voos por aeronave\n");
    printf("3. Verificar percentual de voo por destino em intervalo de datas\n");
    printf("0. Voltar ao menu anterior\n");
    printf("::: ");
    scanf("%i", &opc);
    getchar();
    return opc;
}