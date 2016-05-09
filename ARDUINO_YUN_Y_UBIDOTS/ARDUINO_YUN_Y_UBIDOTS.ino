#include <Ethernet.h>
#include <SPI.h>
#include <UbidotsEthernet.h>
//id de cada variable creada en ubidots
#define ID_temp  "5707c6ef7625424342d0a674" //
#define ID_hum "5707c75676254247a8d4acf8"
#define ID_co "5707c79f7625424a0ee39e4e"
#define ID_flam"5707d115762542194a6f5d6a"
#define TOKEN  "OmlUQHP2zUdi7YhLzGrDfWSdiAjN1X"  // Put here your Ubidots TOKEN
Ubidots client(TOKEN);
//mac de dispositivo
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xA7, 0xEE, 0xED
};
int hum;
int temp;
int co;
int flam;
int tiempo;
//IP ESTATICA 
IPAddress ip(172, 16,16,133);
IPAddress myDns(172,16,1,254);
IPAddress gateway(172, 16,16,1);
IPAddress subnet(255, 255, 254, 0);
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
Ethernet.begin(mac, ip, myDns,gateway,subnet);
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  hum=random(15,20);
  temp=random(15,18);
  co=random(16,21);
  flam=random(14,18);
  tiempo++;
   client.add(ID_temp, temp);
   client.add(ID_hum, hum);
   client.add(ID_co, co);
   client.add(ID_flam, flam);
    client.sendAll();
    delay(10000);
}
