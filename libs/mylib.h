#ifndef MAQUINA_DE_ESTADOS_LIBS_MYLIB_H_
#define MAQUINA_DE_ESTADOS_LIBS_MYLIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  CLASIFICAR=0,
  TRANS_LIGERO,
  TRANS_SEMI_PESADO,
  TRANS_PESADO,
}estados_t;

typedef struct {
 float peso;
 float volumen;
 float distancia;
 float costoDeEnvio;
 float Pmax;
 float VL;
 float Vp;
 float costL;
 float costSP;
 float costP;
}paquete_t;

paquete_t inicio(void);                  //seteo de valores iniciales.   
paquete_t leerArchivoConf(char*);        //lectura y extracción de datos de archivo config.conf
float calculoDeCosto(float);             //se calcula el costo del viaje, basados en el costo por KM según tipo de transporte y distancia a recorrer. 
estados_t funClasificar(paquete_t*);     //estado clasificar.
estados_t funDistanciaTL(paquete_t*);    //estado transporte ligero.
estados_t funDistanciaTSP(paquete_t*);   //estado transporte semi-pesado.
estados_t funDistanciaTP(paquete_t*);    //estado transporte pesado.

#endif