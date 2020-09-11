#include "../libs/mylib.h"

//función para configurar valores del momento de iniciar la maquina de estados.
paquete_t inicio(void){  
	paquete_t configInicio;
	configInicio = leerArchivoConf("../config/config.conf");   //se hace una llamda a la funcion leerArchivoConf(chat*) para que lea el archivo config.conf y extraiga los valores de seteo.
    printf("\nArchivo de configuraciones cargado con exito...\n");
	return configInicio; 
}

//función para clasificar paquetes tomando como parámetro peso y volumen.
estados_t funClasificar(paquete_t* paquete){     

        printf("\nIngrese datos del paquete: \n");
        paquete->peso = cargarDato("Peso: ");
        paquete->volumen = cargarDato("Volumen: ");

        //en caso de que alguno de los valores sea menor a cero, devuelvo el estado clasificar para que retorne a si mismo.
		if ((paquete->volumen <= 0) || (paquete->peso <= 0)){
          printf ("\nError valores ingresados, debe ser mayor a 0\n");
          return CLASIFICAR;
        }
	    
        //condición para ir a estado "transporte Ligero", TL: (P ≤ Pmax) y (V ≤ VL):
        if ((paquete->peso <= paquete->Pmax) && (paquete->volumen < paquete->VL)){
          return TRANS_LIGERO;
        }

        //condición para ir a estado "transporte Semi-pesado", TSP: (P ≤ Pmax) y (VL < V < Vp):
        if ((paquete->peso <= paquete->Pmax) && (paquete->volumen > paquete->VL) && (paquete->volumen < paquete->Vp)){
          return TRANS_SEMI_PESADO;
        }

        //condición para ir a estado "transporte Pesado", TP: (P > Pmax) y/o (V ≥ Vp):
        if ((paquete->peso > paquete->Pmax) || (paquete->volumen >= paquete->Vp)){
          return TRANS_PESADO;
        }
}


//recibe paquete clasificado(mediante puntero) y calcula su costo para ser transportado como ligero. 
estados_t funDistanciaTL(paquete_t* paquete){                                      
    paquete->costoDeEnvio = 0;
    paquete->costoDeEnvio = calculoDeCosto(paquete->costL); //hago una llamada a la función "calculoDeCosto(int)" pasándole como parámetro el costo por KM del transporte ligero, me retornara el costo del viaje.
    printf("Categoria de transporte: Ligero\nCosto calculado: %.2f\n",paquete->costoDeEnvio);
return CLASIFICAR;
}


//recibe paquete clasificado(mediante puntero) y calcula su costo para ser transportado como semi-pesado.
estados_t funDistanciaTSP(paquete_t* paquete){    
    paquete->costoDeEnvio = 0;
    paquete->costoDeEnvio = calculoDeCosto(paquete->costSP); //hago una llamada a la función "calculoDeCosto(int)" pasándole como parámetro el costo por KM del transporte semi-pesado, me retornara el costo del viaje.
    printf("Categoria de transporte: Semi-Pesado\nCosto calculado: %.2f\n",paquete->costoDeEnvio);
return CLASIFICAR;
}


//recibe paquete clasificado(mediante puntero) y calcula su costo para ser transportado como pesado.
estados_t funDistanciaTP(paquete_t* paquete){     
    paquete->costoDeEnvio = 0;
    paquete->costoDeEnvio = calculoDeCosto(paquete->costP);  //hago una llamada a la función "calculoDeCosto(int)" pasándole como parámetro el costo por KM del transporte pesado, me retornara el costo del viaje.
    printf("Categoria de transporte: Pesado\nCosto calculado: %.2f\n",paquete->costoDeEnvio);
return CLASIFICAR;
}


 //función para calcular costo del envió, recibe el costo por KM según el tipo de transporte y retorna el costo.
 float calculoDeCosto(float costoKM){  
   float distancia = 0;
   float calcDeCosto=0;
   calcDeCosto = cargarDato("Distancia: ")*costoKM;
   return calcDeCosto;
}


 //función para validar datos ingresados por el usuario.
 float cargarDato(char *mensaje){ 
    float dato = 0;
    printf("%s",mensaje);
    while ((scanf("%f", &dato)!=1)||(dato<=0)) {
      printf("Solo se admiten numeros mayores a 0...\n");  
      fflush(stdin);
      printf("%s",mensaje);
    } ;
    return dato;
 }


