#include <IRremote.h>

int RECV_PIN = 4;           // Broche de réception IR sur le blindage du pilote

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();      // Démarrez le récepteur
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();        // Recevez la valeur suivante
  }
}
