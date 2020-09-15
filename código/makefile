CC=gcc
IN=$(wildcard src/*.c)
OUT=ejecutable/gestor

#Build all target
all : $(OUT)

#arma comando
ejecutable/gestor: $(IN)
	$(CC) $^ -o $(OUT)
	
	
#limpia
clean :
	rm $(OUT)

.PHONY : all clean

# gcc funLeerArchivoConf.c gestor.c main.c -o ejecutable/gestor 