/* Envio de tramas de datos para redes de sensores
de conversores analogicos tipo integer  */
#include <TimerOne.h>
int cad0;// variable para conversor 0
int est_bateria;// mide el voltaje de la bateria
int aleatorio; // valor a contar en timer
int limite_aleatorio;// valor maximo de aleatorio
int cont_backoff=10;// contador de timer
String ind_bateria;
String strcad0;
String tramatx;
boolean verf=false;
void setup() {
  // Configuraciones
Serial.begin(9600); //inicio de cx serial
Timer1.initialize(1000000);// inicio de timer a 1 seg
Timer1.attachInterrupt(backoff);// subrutina de backoff
aleatorio=random(1,limite_aleatorio);// numero aleatorio
}

void loop() {

}

void backoff(){
cont_backoff++;// conteo de segundos
  if(cont_backoff==aleatorio){//comparacion con aleatorio
    cad0=analogRead(0)/4; // lectura de conversor de 0 a 1023 datos
      if(cad0<99){
      verf=true;
      }
      else
      verf=false;
      //lectura de estado de bateria
   est_bateria=analogRead(1)/4;
    if(est_bateria<100){
      ind_bateria="00";
      cont_backoff=10;
    }
   if(est_bateria>100&&est_bateria<200){
    ind_bateria="01";
    cont_backoff=20;
    }
  if(est_bateria>200){
    ind_bateria="10";
    cont_backoff=30;
  }
//se descompone el valor cad para ser enviado
//se evalua si el conversor tiene 4 o 3 digitos
 strcad0=String(cad0);
  if(verf)
    tramatx=String("A"+ind_bateria+"0"+strcad0+"A ");
  else
    tramatx=String("A"+ind_bateria+strcad0+"A ");

   Serial.println(tramatx);
}
aleatorio=random(1,cont_backoff);
cont_backoff=0;
}
