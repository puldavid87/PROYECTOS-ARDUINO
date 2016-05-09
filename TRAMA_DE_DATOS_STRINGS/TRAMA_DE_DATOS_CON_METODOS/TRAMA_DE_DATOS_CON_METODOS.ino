
/*CADENA DE DATOS PARA REDES DE SENSORES
 * HACIA NODO PRINCIPAL
 * LA TRAMA CUENTA CON LOS SIGUIENTES DATOS
 * _____________________________
 * A|00|00|00|0|000|A|0|0|A|A| |
 * ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 *A| IDENTIFICADOR DE CLIENTE
 *00|PRIORIDAD DE ENVIO DE PAQUETES
 *        La Prioridad viene de cambios altos en 
 *        los sensores del cliente y es necesario 
 *        conocer de mas cerca su estado y comprobar 
 *        que no es un error.*se puede ampliar el campo*
 * 00| INDICADOR DE BATERIA
 *        Mediante 4 niveles se indica el valor de la
 *        bateria del cliente para determinar su tiempo 
 *        de envio de datos
 * 00| INDICADOR DE ESTADO       
 *        Presenta la forma de estados de sleep que pueden tener
 *        o si tiene problemas de lectura
 * 0| INDICADOR DE NUMERO DE SENSORES ANALOGOS
 *        Indica el numero de sensores utilizados en el 
 *        cliente para realizar las diferentes lecturas 
 * 000| VALOR ANALOGO DE SENSOR 
 *        Depende del numero del indicador de numero de 
 *        sensores, pueden ser 3 digitos, se recomienda 
 *        hasta 5 sensores con un total de 15 digitos. 
 * A| INDICADOR DE FIN DE VALOR ANALOGO
 *        Es el fin de lectura de numero por cada valor
 *        analogo traido,  se usa el mismo identificador 
 *        de cliente. si se tiene mas sensores, por 
 *        cada sensor se tiene un indicador de fin.Ej:
 *        2 sensores: 000A000A
 *        3 sensores: 000A000A000A
 * 0| INDICADOR DE NUMERO DE SENSORES DIGITALES
 *        Indicar el numero de sensores digitales o 
 *        estados boleanos de comprobacion que necesitan
 *        es un campo multiuso.
 * 0| VALOR DE SENSOR DIGITAL O INDICADOR DE COMPROBACION       
 *        El valor del sensor digital puede ser 1 o 0 para
 *        su lectura, si es de comprobacion se puede usar 
 *        otros caracteres de llenado para ser comparados
 *        en el nodo central
 *  A| INDICADOR DE FIN DE VALOR DIGITAL O COMPROBACION       
 *        Fin de lectura del valor digital o comprobacion,
 *        se usa el mismo identificador de cliente.
 *        si se tiene mas sensores o comprobadores se usa:
 *        2 sensores: 1A0A
 *        1 sensores, 1 indicador : 1A8A
 * A| FIN DE ENVIO 
 *        Comprueba el fin de trama de datos y si el usurio,
 *        en caso de no recibir este dato, el sistema entiende
 *        como error de cx y pedira el reenvio de la trama.
 *  | CAMPO DE FIN DE ENVIO
 *        Para un correcto fin de trama se envia un caracter
 *        que permite reconocer que el buffer esta ya bacio
 */
#include <stdlib.h> // libreria usada para conversion de tipo de dato

int valor_cad;
int valor_dig;
int num_sen;
String cadena;
int a;
int i,j;
int b=8;
int c;
int d;
String dato;
String bateria;
//TRAMA
/*
B00112110B130B21B4BB    
B0011009110B130B110B110B110B110B110B110B110B91B4B4B4B4B4B4B4B4BB  
*/    
void setup() {
Serial.begin(9600);
}

void loop() {
 

}

void serialEvent (){
  while(Serial.available()) {
     // es necesario enviar un espacio en blanco al terminar la trama
     cadena= Serial.readString();// lectura de string
     a=cadena.length();// determinar tamano de trama
     char buf [a]; //definicion de vector con tamano de trama
     cadena.toCharArray(buf,a);//conversion de un string a un vector
    //evaluacion de clinetes segun identificador
      switch(buf[0]){
        case 'A':
          Serial.println("usuario 1");
          usuario(buf[0],buf[a-2]);
         break;
         case 'B':
         Serial.println("usuario 2");
          usuario(buf[0],buf[a-2]);
          break;
        default:
          Serial.println("APRENDER");
           usuario(buf[0],buf[a-2]);
         break;
      }
      //evaluacion de bateria
    bateria= String(buf[3])+String(buf[4]);// union de caracteres a string
    if(bateria.equals("00"))
       {
         Serial.println("BAT. MAL");
         //instruccion de trama para reenvio
        }
    if(bateria.equals("01"))
       {
        Serial.println("BAT. SOSO");
      }
    if(bateria.equals("11"))
      {
       Serial.println("BAT. BIEN");
      }
      //conversion de datos de sensores tipo string a int
    dato +=(char)buf[7];//conversion de char a string
    num_sen=dato.toInt();// conversion de string a int de # de sensores
    Serial.print("Sensores:");
    Serial.println(num_sen);
    //ciclo de lectura de datos analogos
    for(i=0;i<num_sen;i++){
        valor_cad=atoi(&buf[b]);// conversio de 3 caracteres a int 
        Serial.print("Sensor_analog ");
        Serial.print(i+1);
        Serial.print(":");
        Serial.println(valor_cad);
        b=b+4;//conteo para seleccion de posicion de vector
       
        //insertar en vector y almacenar en microsd
      }
      //reseteo de variables
      c=b;//para deteccion de valores digitales
     b=6;i=0;
     dato="";
     dato+= (char)buf[c];//conversion de string a int de # de sensores
     num_sen=dato.toInt();// # de sensores digitales
     Serial.print("Sensores_dig:");
     Serial.println(num_sen);
     //ciclo de lectura de valores digitales
     d=c+1;
     for(;i<num_sen;i++){
          valor_dig=atoi(&buf[d]);
          Serial.print("Sensor ");
          Serial.print(i+1);
           Serial.print(":");
           Serial.println(valor_dig);
          d=d+2;//conteo para seleccion de posicion de vector
      }
      i=0;
      dato="";
    Serial.flush();
  } 
 }

 void usuario (char dato_1, char dato_2){
    if(dato_1==dato_2){
      Serial.println("Usuario correcto");
      }
     else
     Serial.println("aprendizaje"); 
  }
  void conteosensores (){
    
    }
