#include <Arduino.h> // Obbligatorio per PlatformIO
#include <Adafruit_NeoPixel.h> //contiene i comandi per gestire la striscia led

#define PIN        2    // Usiamo il GPIO 2 per ESP32
#define NUMPIXELS 30  //numero di led nella striscia

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //È come se dessimo un nome alla nostra striscia e le dicessimo come "parlare", quidni crea l'oggewtto pixel

void setup() {
  pixels.begin(); //accende la comunicazione con la striscia
  Serial.begin(115200); // La velocità che serve per comunicare con QT
}

void loop() {
  if (Serial.available() >= 3) {
    int r = Serial.read();
    int g = Serial.read();
    int b = Serial.read();

    //controlla che siano arrivati 3 byte per il concetto RGB e prende i 3 numeri

    //si passa tutti i led (30)  e gli emtte dentor il colore che ha ricevuto
    for(int i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
    }
    pixels.show();
  }
}
