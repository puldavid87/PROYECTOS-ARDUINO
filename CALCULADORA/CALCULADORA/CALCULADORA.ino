String inString="";
int num1;
int num2;
int total;
int i=0;
int oper;
void setup() {
pinMode(8,OUTPUT);
pinMode(9,INPUT);
Serial.begin(9600);
}

void loop() {
 if(Serial.available()>0){
     inString=Serial.readString();
      switch(i){
        case 0:
            num1=inString.toInt();
            Serial.println("INGRESE OPERANDO");
            i++;
        break;
        case 1:
          if(inString=="+"){
              oper=1;
              Serial.println("INGRESE 2 NUM");
           }
            i++;
        break;
        case 2:
        num2=inString.toInt();
        if(oper==1){
          total=num1+num2;
          Serial.print("Resultado:");
          Serial.println(total);
        }
        i=0;
        break;
        
        }
    }  
  
}


  
  


