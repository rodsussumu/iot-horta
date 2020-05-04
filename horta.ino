#include <DHT.h>

#define DHTPIN A0
#define DHTTYPE DHT11
#define Higrometro A1
#define LDR A2
#define LED_VERDE 12
#define LED_VERMELHO 13

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(Higrometro, INPUT);
  pinMode(LDR, INPUT);
  dht.begin();
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
}

void loop() {
  int umidade = dht.readHumidity();
  int temperatura = dht.readTemperature();
  int umidadeSolo = analogRead(Higrometro);
  int luminosidade = analogRead(LDR);
  int botaoAperta = digitalRead(Botao);
  

    Serial.print(umidade);
    Serial.print(temperatura);
    Serial.print(umidadeSolo);
    Serial.print(luminosidade);

    if(umidadeSolo > 511.5 && luminosidade > 450) {
        digitalWrite(LED_VERDE, HIGH);
        digitalWrite(LED_VERMELHO, LOW);    
        Serial.print("Irriga horta";)
    } else {
         digitalWrite(LED_VERMELHO, HIGH); 
         digitalWrite(LED_VERDE, LOW);
         Serial.print("Condiçoes invalidas, sem irrigação");
    }

}
