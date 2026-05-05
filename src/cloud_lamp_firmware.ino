//usa la libreria indicata precedentemente installata per controllare le strisce led
#include <FastLED.h> 

//imposta i parametri principali 
#define LED_PIN     6          // Pin dati
#define NUM_LEDS    30         // simuliamo I 30 led che ho nella striscia
#define BRIGHTNESS  100        // Luminosità (0-255)
#define LED_TYPE    WS2812B //tipo di led
#define COLOR_ORDER GRB //ordine dei colori(verde-rosso-blu)

//fa una lista di led, ogni led è un’oggetto con rosso-verde-blu
CRGB leds[NUM_LEDS];

void setup() {
  // Inizializzazione seriale a 115200 (veloce per la musica)
  Serial.begin(115200);
  
  // Inizializzazione LED
//dice alla libreria che tipo di led ci sono, su quale Pine. Quanti led sono
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

//imposta la luminosità globale
  FastLED.setBrightness(BRIGHTNESS);
  
  // Test accensione: la nuvola lampeggia di bianco all'avvio
  fill_solid(leds, NUM_LEDS, CRGB::White); //accende I led di bianco
  FastLED.show();
  delay(500); //aspetta mezzo secondo
  fill_solid(leds, NUM_LEDS, CRGB::Black); //spegne tutto
  FastLED.show();
}

void loop() {
  // Controlla se sono arrivati almeno 3 byte (Rosso, Giallo, Blu)
  if (Serial.available() >= 3) { 
    byte r = Serial.read();
    byte g = Serial.read();
    byte b = Serial.read();

    // colora tutta la striscia di quel colore
    fill_solid(leds, NUM_LEDS, CRGB(r, g, b));
    FastLED.show(); // mostra il colore, senza questo i led non si aggiornano
  }
}
