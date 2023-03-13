/**
  Author: Yuri
  Date: 09/10/2022
  Version: v1
  Copyright © 2022-2023 Xx_yuri2005_xX
*/

//led rgb 1
int red1 = 9; //red pin RGB led 1
int blue1 = 10; //blue pin RGB led 1
int green1 = 11; //green pin RGB led 1

//led rgb 2
int red2 = 3; //red pin RGB led 2
int blue2 = 5; //blue pin RGB led 2
int green2 = 6; //green pin RGB led 2

//other variables
int button1 = 8; //people join count
int button2 = 7; //people leave count
int people=0, late; //people counter and led delay
int debug=0; //variable to enable debugging (0 -> no, 1 -> yes)
unsigned long time0, timeA; //time count variables

void setup() {
  //setup code
  pinMode(red1, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600); //serial monitor initialization
}

void loop() {
  //loop code
  timeA = millis(); //millis startup
  late=analogRead(A0); //read value speed color change LED
  late=map(late, 0, 1023, 200, 1200); //value adapting
  //reading join counter
  if(digitalRead(button1)==LOW) {
    delay(200);
    people++; //people increase
  }
  //reading leave counter
  if(digitalRead(button2)==LOW) {
    delay(200);
    people--; //people decrease
    if(people<0) { //negativity check (if people is less than 0 set value to 0)
      people=0;
    }
  }
  //check time difference with speed time
  if((timeA - time0) >= late) {
    time0=timeA;
    //RGB led function
    rgbLedDisplay(red1, blue1, green1, 
                  random(256), random(256), random(256));
    //Checking the number of people and lighting RGB Led 2
    if(people>=15) {
      rgbLedDisplay(red2, blue2, green2, 
                  random(256), random(256), random(256));
    }
  }
    /*
     * enable debug system in the serial monitor 
     * if the variable is 1
     */
    if(debug==1) {
    Serial.print("\nPeople number: ");
    Serial.print(people);
    Serial.print(" Led Speed: ");
    Serial.print(late);
  }
}

/*
 * RGB led function for color
 * Variables structure:
 * @param redPin red led pin
 * @param bluePin blue led pin
 * @param greenPin green led pin
 * @param red red led intensity value
 * @param green green led intensity value
 * @param blue blue led intensity value
*/
void rgbLedDisplay(int redPin, int bluePin, int greenPin, 
                   int red, int green, int blue) {
//Sets the output LED to a duty cycle
analogWrite(redPin, constrain(red, 0, 255));
analogWrite(greenPin, constrain(green, 0, 255));
analogWrite(bluePin, constrain(blue, 0, 255));
}
