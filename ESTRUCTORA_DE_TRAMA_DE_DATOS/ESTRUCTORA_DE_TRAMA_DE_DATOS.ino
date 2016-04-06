/* Envio de tramas de datos para redes de sensores
de conversores analogicos tipo integer  */
int cad0;// variable para conversor 0
int i; //variable de envio de vector
int vector [6];
int cad0mil;//miles de cad0
int cad0cen;//cententa de cad0
int cad0dec;//decena de cad0
int cad0uni;//unidad de cad0
void setup() {
  // Configuraciones
Serial.begin(9600); //inicio de cx serial
}

void loop() {
cad0=analogRead(0); // lectura de conversor de 0 a 1023 datos
//se descompone el valor cad para ser enviado
//se evalua si el conversor tiene 4 o 3 digitos
  
  if(cad0>999){
    cad0mil=1;// si es mayor a 999 el cad el se pone en 1 los miles
    cad0cen=(cad0-1000)/100; //se encuentra las centenas 
    cad0dec=(cad0-(1000+cad0cen*100))/10;// se encuentra las decenas
    cad0uni=cad0-(1000+(cad0cen/100)+(cad0dec*10));//se encuentra unidades
  }
  else{
    cad0mil=0;// si es menor miles en cero
    cad0cen=cad0/100; // en encuentra las centenas
    cad0dec=(cad0-(cad0cen*100))/10;// se encuentra las decenas
    cad0uni=cad0-((cad0cen*100)+(cad0dec*10));// se encuentra las unidades
  }
  // se almacena en el vector declarado por las posiciones
  vector[0]=0;
  vector[1]=cad0mil;
  vector[2]=cad0cen;
  vector[3]=cad0dec;
  vector[4]=cad0uni;
  vector[5]=0;
  /*ciclo de envio de integeres, sizeof(vector)/sizeof(int)-1 
  solo es usado cuando se envia tipo integer, caso contrario solo es 
  sizeof(vector) para caracteres.
  */
  for(i=0;i<=sizeof(vector)/sizeof(int)-1;i++){
    Serial.print(vector[i]);
    delay(100);
  }
  delay(1000);
  i=0;
  
  
}
