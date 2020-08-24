# Máquina de Estados 
## Gestor de paquetería

### Memoria descriptiva
Mi sistema representa un gestor de paquetería, el deposito cuenta con 3 categorías de vehículos para hacer los envíos, cada uno con capacidades máximas. Es por esto que el sistema debe catalogar según peso y volumen cada paquete para así despachar con el transporte adecuado. 

Inicialmente se consulta al usuario si desea iniciar la clasificación de un nuevo paquete o imprimir el listado de los transportes (en caso de no haber ningún paquete cargado se indicará con una leyenda al usuario).  

La clasificación inicia considerando el peso y contrastándolo con un valor de referencia "Pmax", el próximo parámetro a considerar es el volumen que tendrá dos valores de referencia "Vp" y "VL", según estos se definirá la categoría del transporte. 
Una vez que el paquete tiene asignado su trasporte se carga el valor de distancia a recorrer y se calcula el costo del viaje. 



### Diagrama:

![./recursos/Maquina de estados 1-2.jpg](https://github.com/Marcos-Alcat/Maquina-de-Estados/blob/master/recursos/Maquina%20de%20estados%201-2.jpg)

 - __V__: Volumen leído.
 - __P__: Peso leído.
 - __C1__:   si P y/o V son iguales a cero.
 - __TL__:   (P ≤ Pmax)  y  (V ≤ VL).  
 - __TSP__:  (P ≤ Pmax)  y  (VL < V < Vp).
 - __TP__:   (P > Pmax) y/o (V ≥ Vp).
 - __dist__: carga de distancia por usuario. 