String inString="";
int num1;
int num2;
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
            Serial.println(num1);
            i++;
            Serial.println(i);
        break;
        case 1:
          if(inString=="+"){
              Serial.println("SUMAR");
              oper=1;
           }
            i++;
        break;
        }
    }  
  
}


  
  


