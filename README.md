# Máquina de Estados 
## Gestor de paquetería

### Memoria descriptiva
Mi sistema representa un gestor de paquetería, el deposito cuenta con 3 categorías de vehículos para hacer los envíos, cada uno con capacidades máximas. Es por esto que el sistema debe catalogar según peso y volumen cada paquete para así despachar con el transporte adecuado. 

Inicialmente se consulta al usuario si desea iniciar la clasificación de un nuevo paquete o imprimir el listado de los transportes (en caso de no haber ningún paquete cargado se indicará con una leyenda al usuario).  

La clasificación inicia considerando el peso y contrastándolo con un valor de referencia (Pmax), el próximo parámetro a considerar es el volumen y según este se definirá la categoría del transporte. 
Una vez que el paquete tiene asignado su trasporte se carga el valor de distancia a recorrer y se calcula el costo del viaje. 

Si es necesario cargar otro paquete o salir de la carga, el usuario podrá seleccionar la bifurcación dentro del estado “¿CARGAR OTRO PAQUETE?”.
Así mismo, dentro del estado “SALIR” se elegirá volver al primer estado o salir del programa.  



### Diagrama:

![./recursos/Maquina de estados 1-1.jpg](https://github.com/Marcos-Alcat/Maquina-de-Estados/blob/master/recursos/Maquina%20de%20estados%201-1.jpg)


 - __P__: Lectura de peso.
 - __Pmax__: Peso de referencia.
 - __V__:  Lectura de volumen.
 - __VL__: Volumen cota inferior.
 - __Vp__: Volumen cota superior.
 - __dist__: carga de distancia por usuario. 