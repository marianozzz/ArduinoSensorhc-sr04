
#include <NewPing.h>


/*Aqui se configuran los pines donde debemos conectar el sensor*/
#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 1000
#define NOTE_E5  659

/*Crear el objeto de la clase NewPing*/
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int sonido = NOTE_E5;
void setup() {
  
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  // Esperar 1 segundo entre mediciones
     delay(1000);
  
  // Obtener medicion de tiempo de viaje del sonido y guardar en variable uS
  int uS = sonar.ping_median();
  // Imprimir la distancia medida a la consola serial
  
  // Calcular la distancia con base en una constante
  if ((uS / US_ROUNDTRIP_CM) <= 10){
  //apaga el led verde
  digitalWrite(10,LOW);
  //enciende el led rojo
  digitalWrite(13,HIGH);
  Serial.print("Distancia: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
  }
  else{
     //hace parpadear el led verde con una espera de medio segundo
     delay(500);
     digitalWrite(10,HIGH);
     delay(500);
     digitalWrite(10,LOW);

     //apaga el led rojo
     digitalWrite(13,LOW);
     Serial.print("Distancia: ");
     Serial.print(uS / US_ROUNDTRIP_CM);
     Serial.println("cm");
    
    }
}
