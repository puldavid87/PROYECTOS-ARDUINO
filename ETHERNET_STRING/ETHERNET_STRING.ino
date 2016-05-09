
#include <SPI.h>
#include <Ethernet.h>
#include <stdlib.h> // libreria usada para conversion de tipo de dato

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network.
// gateway and subnet are optional:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);
IPAddress myDns(192,168,1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 0, 0);
//variables
int valor_cad;
int valor_dig;
int num_sen;
String cadena;
int a;
int i,j;
int b=6;
int c;
int d;
String dato;
String bateria;

//TRAMA
/*
B00112110B130B21B4BB    
B00119110B130B110B110B110B110B110B110B110B91B4B4B4B4B4B4B4B4BB 
*/   

// telnet defaults to port 23
EthernetServer server(23);
boolean alreadyConnected = false; // whether or not the client was connected previously

void setup() {
  // initialize the ethernet device
  Ethernet.begin(mac, ip, myDns, gateway, subnet);
  // start listening for clients
  server.begin();
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  }


  Serial.print("Chat server address:");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // wait for a new client:
  EthernetClient client = server.available();

  // when the client sends the first byte, say hello:
  if (client) {
    if (!alreadyConnected) {
      // clear out the input buffer:
     client.flush();
      alreadyConnected = true;
    }

    if (client.available() > 0) {
      cadena=client.readString();
      
    }
  }
}

