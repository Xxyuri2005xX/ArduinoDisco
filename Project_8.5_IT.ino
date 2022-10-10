//led rgb 1
int red1 = 9; //pin rosso led RGB 1
int blue1 = 10; //pin blu led RGB 1
int green1 = 11; //pin verde led RGB 1

//led rgb 2
int red2 = 3; //pin rosso led RGB 2
int blue2 = 5; //pin blu led RGB 2
int green2 = 6; //pin verde led RGB 2

//altre variabili
int button1 = 8; //conto ingressi persone
int button2 = 7; //conto uscite persone
int persone=0, ritardo; //conto persone e delay dei led
int debug=0; //variabile per abilitare il debug (0 -> no, 1 -> si)
unsigned long time0, timeA;

void setup() {
  //codice di setup
  pinMode(red1, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600);
}

void loop() {
  //codice di loop
  timeA = millis(); //avvio del millis
  ritardo=analogRead(A0); //lettura valore velocità cambio colore LED
  ritardo=map(ritardo, 0, 1023, 200, 1200); //adattamento del valore
  //lettura contatore ingressi
  if(digitalRead(button1)==LOW) {
    delay(200);
    persone++; //incremento persone
  }
  //lettura contatore uscite
  if(digitalRead(button2)==LOW) {
    delay(200);
    persone--; //decremento persone
  }
  //controllo differenza tempo col tempo della velocità
  if((timeA - time0) >= ritardo) {
    time0=timeA;
    //funzione led RGB
    rgbLedDisplay(red1, blue1, green1, 
                  random(256), random(256), random(256));
    //check del numero di persone e accensione Led RGB 2
    if(persone>=15) {
      rgbLedDisplay(red2, blue2, green2, 
                  random(256), random(256), random(256));
    }
  }
    /*
     * abilitazione sistema debug nel monitor seriale
     * se la variabile è 1
     */
    if(debug==1) {
    Serial.print("\nNumero di persone: ");
    Serial.print(persone);
    Serial.print(" Velocita led: ");
    Serial.print(ritardo);
  }
}

/*
 * funzione led RGB per il colore
 * Struttura variabili:
 * pin led rosso, pin led blu, pin led verde, valore led rosso, valore red blu, valore led verde
*/
void rgbLedDisplay(int redPin, int bluePin, int greenPin, 
                   int red, int green, int blue) {
//Imposta i led di output ad un duty cycle
analogWrite(redPin, constrain(red, 0, 255));
analogWrite(greenPin, constrain(green, 0, 255));
analogWrite(bluePin, constrain(blue, 0, 255));
}
