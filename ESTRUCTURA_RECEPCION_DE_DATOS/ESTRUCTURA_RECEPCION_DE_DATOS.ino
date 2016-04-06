/* Recepcion de tramas de datos para redes de sensores
de conversores analogicos tipo Integer */
int cad0;// variable para conversor 0
int i=0;; //variable de recepcion de vector
char vector [6];
int cad0mil;//miles de cad0
int cad0cen;//cententa de cad0
int cad0dec;//decena de cad0
int cad0uni;//unidad de cad0

void setup() {
  // Configuraciones
Serial.begin(9600); //inicio de cx serial
Serial1.begin(9600);
}

void loop() {
   
}

void serialEvent(){
  if (Serial.available()>0) {
    switch(i){
    case 0:
    vector[i]=(char)Serial.read();
    i++;
    break;
    }
    case 1:
    vector[i]=(char)Serial.read();
    i++;
    break;
    case 2:
    vector[i]=(char)Serial.read();
    i++;
    break;
    case 3:
    vector[i]=(char)Serial.read();
    i++;
    break;
    case 4:
    vector[i]=(char)Serial.read();
    i++;
    break;
    case 5:
    vector[i]=(char)Serial.read();
    i=0;
    break;
   }
}


