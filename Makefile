CC = gcc
SRC = ./src
OBJS = ./objs
TARGET = aeronaves
LIMPAR = rm

all: objetos
	$(CC) $(OBJS)/menus.o $(OBJS)/cadastros.o $(OBJS)/relatorios.o $(OBJS)/consultas.o $(OBJS)/utils.o $(OBJS)/arquivos.o $(OBJS)/main.o -o $(TARGET)


objetos:
	$(CC) -c $(SRC)/menus.c -o $(OBJS)/menus.o
	$(CC) -c $(SRC)/cadastros.c -o $(OBJS)/cadastros.o
	$(CC) -c $(SRC)/relatorios.c -o $(OBJS)/relatorios.o
	$(CC) -c $(SRC)/consultas.c -o $(OBJS)/consultas.o
	$(CC) -c $(SRC)/utils.c -o $(OBJS)/utils.o
	$(CC) -c $(SRC)/arquivos.c -o $(OBJS)/arquivos.o
	$(CC) -c main.c -o $(OBJS)/main.o


clear:
	$(LIMPAR) $(OBJS)/*.o
	$(LIMPAR) $(TARGET)

aeronaves: $(OBJ)
	$(CC) $(OBJ) -o aeronaves