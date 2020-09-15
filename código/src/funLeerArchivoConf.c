#include "../libs/mylib.h"

//obtengo valores de configuración del archivo config.conf
paquete_t leerArchivoConf(char* nombreDeArchivo){ 
  paquete_t configInicioArchivo;
  printf("\nIniciando Archivo de configuraciones...\n");

  FILE * archivo;
    char cadena[40],*clave,*valor;
    char vars[][40]={"Pmax","VL","Vp","costL", "costSP", "costP"};
    float num;
    printf("%s\n",nombreDeArchivo);
    if ((archivo = fopen (nombreDeArchivo,"rt")) == NULL){
		printf ("Error al abrir archivo configuracion: %s \n",nombreDeArchivo);
        exit (-1); //para salir del programa.
	}else{
		fgets(cadena,40,archivo);
               if (feof(archivo)) {
            //return 0;
            exit (-1); //para salir del programa.
        }

		do {
			clave = cadena;
			if (*clave != '#' && *clave != '\n' && strlen(clave)>0){
				char i=0;
	            while (*(clave+i)!=' ') i++;
	            *(clave+i)=0; valor = clave+i+1;
    			for (unsigned int i = 0; i < sizeof(vars)/sizeof(vars[0]); i++){
					if (strcmp(clave,vars[i]) == 0){
                        num = atof(valor);
						switch(i){
                            case PESO_MAX:
                                configInicioArchivo.Pmax = num;
                                break;
                            case VOLUMEN_LIGERO:
                                configInicioArchivo.VL = num;
                                break;
                            case VOLUMEN_PESADO:
                                configInicioArchivo.Vp = num;
                                break;
                            case COSTO_LIGERO:
                                configInicioArchivo.costL = num;
                                break;
                            case COSTO_SEMI_PESADO:
                                configInicioArchivo.costSP = num;
                                break;
                            case COSTO_PESADO:
                                configInicioArchivo.costP = num;
                                break;                                                                                                
						}
					}
				}
			}

			fgets(cadena,40,archivo);
		} while(!feof(archivo));
	}

  configInicioArchivo.peso = 0;
  configInicioArchivo.volumen = 0;
  configInicioArchivo.distancia = 0;
  configInicioArchivo.costoDeEnvio = 0;
  printf("Pmax= %.2f\n",configInicioArchivo.Pmax);
  printf("VL= %.2f\n",configInicioArchivo.VL);
  printf("Vp= %.2f\n",configInicioArchivo.Vp);
  printf("costL= %.2f\n",configInicioArchivo.costL);
  printf("costSP= %.2f\n",configInicioArchivo.costSP);
  printf("costP= %.2f",configInicioArchivo.costP);

  return configInicioArchivo;
}

