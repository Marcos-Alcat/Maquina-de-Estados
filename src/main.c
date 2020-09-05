#include "../libs/mylib.h"

int main(void){
 estados_t estados;
 paquete_t paquete;
 estados_t (*fsm[])(paquete_t) = {funClasificar, funDistanciaTL, funDistanciaTSP, funDistanciaTP};

 paquete = inicio();
 estados = CLASIFICAR;

 while(1) estados = (*fsm[estados])(paquete);

 return 0;
}