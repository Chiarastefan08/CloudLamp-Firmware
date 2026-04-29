# CloudLamp-Firmware
Questo repository contiene il firmware per il microcontrollore (Arduino/ESP32) dedicato al controllo della Cloud Lamp. Il sistema riceve dati tramite comunicazione seriale e pilota una striscia LED indirizzabile.

# Descrizione 
Il firmware è progettato per interfacciarsi con un'applicazione PC sviluppata in Qt. Analizza i flussi di dati in arrivo sulla porta seriale e aggiorna in tempo reale il colore e l'intensità della striscia LED WS2812B, creando un effetto dinamico a ritmo di musica.

# Componente 
WS2812B data(DIN) pin 6 , collegato tramite una resistenza da 330Ω
Alimentazione (+) 5V esterni, condensatore da 1000µF in parallelo
GND (-) GND Comune , è importante che arduino e aliementatore siano uniti 

# Librerie necessarie 
FastLED per la gestione dei led WS2812B

# Protocollo di comunicazione 
Per garantire bassa latenza e sincronizzazione perfetta con l'audio, il firmware utilizza un protocollo seriale binario semplificato:
- Baud Rate: 115200
- Formato Pacchetto: Il firmware legge i dati in gruppi di 3 byte
   -byte 0: intensità rosso (R) [0-255]
   -byte 1: intensità verde (G) [0-255]
   -byte 2: intensità blu (B) [0-255]
  
