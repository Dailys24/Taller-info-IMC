/*
Integrante: Angelo Gonzalez
Profesor(a): Jorge cornejo
Sección: 301
Compilador utilizado: repl.it
*/

#include <stdio.h>

//Funcion de calculo de IMC
float IMC(float x, float y){
  return x/(y*y);
}

//Funcion void
void riesgo(int riesgo, int rango_edad, float rango_edad2){

  //Rangos de riesgos de IMC
  if(rango_edad<45 && rango_edad2<22)
        printf("La persona N°%d tiene un >> riesgo bajo <<\n", riesgo);
  if(rango_edad>=45 && rango_edad2<22)
        printf("La persona N°%d tiene un >> riesgo medio <<\n", riesgo);
  if(rango_edad<45 && rango_edad2>=22)
        printf("La persona N°%d tiene un >> riesgo medio <<\n", riesgo);
  if(rango_edad>=45 && rango_edad2>=22)
        printf("La persona N°%d tiene un >> riesgo alto <<\n", riesgo);
}

int main(void) {

  //Variables
  int cantidad=0, edad=0;
  float altura=0, peso=0, valor=0, promedio_peso=0, suma=0, peso_min=550, peso_max=0;

  //Ingresar cantidad de personas
  printf("\n *** Calculo de IMC en personas *** \n");
  printf("\nIngrese la cantidad de personas: ");
  scanf("%d", &cantidad);
  for(int identificacion=1;identificacion<=cantidad;identificacion++){

      //Ingresar el peso de la persona
      printf("\nIngrese peso de la persona N°%d (entre 0-543): ", identificacion);
      scanf("%f", &peso);

      //Condicion de peso
      while(peso<0 || peso>543){
        printf("ERROR el peso ingresado de la persona N°%d es invaido, vuelva a ingresarlo (entre 0-543):", identificacion);
        scanf("%f", &peso);
      }

      //Igualar el peso maximo y el peso minimo
      if(peso<=peso_min)
        peso_min=peso;
       if(peso>=peso_max)
        peso_max=peso;

      //Ingresar la estatura de la persona
      printf("Ingrese la estatura de la persona N°%d (entre 0-3 metros): ", identificacion);
      scanf("%f", &altura);

      //Condicion de estatura
      while(altura<0 || altura>3){
        printf("ERROR la estatura ingresara de la persona N°%d es invalida, vuelva a ingresarla (entre 0-3 metros):", identificacion);
        scanf("%f", &altura);
      }

      //Ingresa la edad de la persona
      printf("Ingrese la edad de la persona N°%d (entre 0-122 años): ", identificacion);
      scanf("%d", &edad);

      //Condicion de edad
      while(edad<0 || edad>122){
        printf("ERROR la edad ingresada de la persona N°%d es invalida, vuelva a ingresarla (entre 0-122 años):", identificacion);
        scanf("%d", &edad);
      }

      valor=IMC(peso,altura);

      //Imprimir datos de la persona, IMC y edad
      printf("\n *** La persona N°%d tiene un IMC = %.2f *** \n", identificacion, valor);
      riesgo(identificacion,edad,valor);
      suma=suma+peso;
    }

  //Promedio de peso
  promedio_peso=suma/cantidad;

  //Imprimir estadisticas de los datos
  printf("\n ***** Estadísticas ***** \n");
  printf("\nTamaño de la muestra: %d\n", cantidad);
  printf("\nEl peso promedio es %.2f%\n", promedio_peso);
  printf("El peso mínimo es %.2f \n", peso_min);
  printf("El peso máximo es %.2f \n", peso_max);
  return 0;
}
