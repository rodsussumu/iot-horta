#include <DHT.h>

#define DHTPIN A0
#define DHTTYPE DHT11
#define Higrometro A1
#define LDR A2
#define LED_VERDE 12
#define LED_VERMELHO 13
#define Botao 8
#define Rele 7

DHT dht(DHTPIN, DHTTYPE);

void leitura() {
  int umidade = dht.readHumidity();
  int temperatura = dht.readTemperature();
  int umidadeSolo = analogRead(Higrometro);
  int luminosidade = analogRead(LDR);
  int botaoAperta = digitalRead(Botao);
}

void resposta() {
  Serial.print(umidade);
  Serial.print(temperatura);
  Serial.print(umidadeSolo);
  Serial.print(luminosidade);
}

boolean irriga() {
  return (umidadeSolo > 511.5 && luminosidade > 450) || botaoAperta == HIGH;
}

boolean naoIrriga() {
  return umidadeSolo < 511.5 && luminosidade < 450
}

void setup() {
  Serial.begin(9600);
  pinMode(Higrometro, INPUT);
  pinMode(LDR, INPUT);
  dht.begin();
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(Botao, INPUT);
  pinMode(Rele, INPUT);
  digitalWrite(Rele, LOW);
  }


void loop() {
  leitura();

    if(irriga() == true) {
        digitalWrite(LED_VERDE, HIGH);
        digitalWrite(LED_VERMELHO, LOW);
        digitalWrite(Rele, HIGH);  
        Serial.print("Irriga horta";)
    } if(naoIrriga() == true) {
         digitalWrite(LED_VERMELHO, HIGH); 
         digitalWrite(LED_VERDE, LOW);
         digitalWrite(Rele, LOW);  
         Serial.print("Condiçoes invalidas, sem irrigação");
    } else {
      digitalWrite(Rele, LOW);
    }
    
  respostas();
  delay(1500);

}
