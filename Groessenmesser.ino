  #include <LiquidCrystal_I2C.h> // Bibliothek zum initialisieren des LCD Bildschirms
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4); 

  int echo = 10;    // Echo Pin für den Ultraschallsensor
  int trigger = 11; // trigger Pin für den Ultraschallsensor
  float dauer;    // Variable für die Zeit
  float entfernung;  // Variable für die entfernung in cm
  float entfernung_hoehe; // Variable für die Höhe des Menschen

  int taster_hoch = 9;  // wird initialisiert mit dem Wert 9
  int tasterstatus_hoch = 0; // Variable wird mit 0 deklariert

  int taster_start = 4; // wird initialisiert mit dem Wert 4
  int tasterstatus_start = 0; // Variable wird mit 0 deklariert
  
  int taster_bmi = 12; // wird initialisiert mit dem Wert 12
  int tasterstatus_bmi = 0; // Variable wird mit 0 deklariert

  int taster_skala = 2; // wird initialisiert mit dem Wert 2
  int tasterstatus_skala = 0; // Variable wird mit 0 deklariert
  
  int taster_runter = 7; // wird initialisiert mit dem Wert 7
  int tasterstatus_runter = 0; // Variable wird mit 0 deklariert
 
  int buzzer = 3; //wird initialisiert mit dem Wert 3
  float bmi; // Variable für bmi
  float gewicht = 60; // Variable für gewicht deklariert mit Startgewicht 60

  void setup() 
{ 
  pinMode(trigger, OUTPUT); // setzt Pin 11 auf Ausgabe
  pinMode(echo, INPUT);  // setzt Pin 10 auf eingabe
  pinMode(taster_hoch, INPUT); // setzt Pin 9 auf eingabe
  pinMode(taster_skala, INPUT); // setzt Pin 2 auf eingabe
  pinMode(taster_start, INPUT); // setzt Pin 4 auf eingabe
  pinMode(taster_bmi, INPUT); // setzt Pin 12 auf eingabe
  pinMode(taster_runter, INPUT); // setzt Pin 7 auf eingabe
  lcd.init(); // initialisiert das LCD
  lcd.backlight(); // aktiviert das Hintergrundlicht des LCD-Displays
}

  void loop()
{
  tasterstatus_start = digitalRead(taster_start); // lesen des Tasterstatus_start

  if (tasterstatus_start == HIGH) // Wenn Taster gedrückt ...
    {
      lcd.setCursor(0, 0); // erste Zeile 
      lcd.print("Willkommen beim");
      lcd.setCursor(0, 1);  // zweite zeile
      lcd.print("Hoehenmesser und BMI");
      lcd.setCursor(0, 2);  // dritte zeile
      lcd.print("Rechner");

      delay(4500);  // verzögernung um 4,5 sek
      lcd.clear(); // entfernt alle zeichen

      lcd.setCursor(0, 0);  
      lcd.print("Geben sie ihr");
      lcd.setCursor(0, 1);  
      lcd.print("Gewicht mit den");
      lcd.setCursor(0, 2);  
      lcd.print("rechten Knoepfen an");

      delay(4500);
      lcd.clear();

      lcd.setCursor(0, 0);  
      lcd.print("Stellen sie sich");
      lcd.setCursor(0, 1);  
      lcd.print("nach der");
      lcd.setCursor(0, 2);  
      lcd.print("Gewichtseingabe");
      lcd.setCursor(0, 3);  
      lcd.print("unter den Sensor");
    }

  digitalWrite(trigger, LOW);               // Den Trigger auf LOW setzen um ein Signal senden zu können
  delayMicroseconds(2);                    //  2 Millisekunden warten
  digitalWrite(trigger, HIGH);            // Den Trigger auf HIGH setzen um eine Ultraschallwelle zu senden
  delayMicroseconds(10);                 //  10 Millisekunden warten
  digitalWrite(trigger, LOW);           // Trigger auf LOW setzen um das Senden abzuschließen
  dauer = pulseIn(echo, HIGH);         // Die Zeit messen bis die Ultraschallwelle zurückkommt
  delay(1000);                        // Nach 1 Sekunde wiederholen
  entfernung = dauer * 0.034/2;      // Impulsdauer wird mit der Schallgeschwindigkeit in Luft multipliziert und dann halbiert weil Signal hin und zurück geht
  entfernung_hoehe = 217-entfernung;//  gemessene entfernung zwischen Sensor und kopf wird mit der Höhe wo der Sensor aufgestellt ist subtrahiert
  
  if (entfernung_hoehe > 100) // Wenn sich jemand unter den Sensor stellt...
    {
      lcd.clear();  
      tone(buzzer, 210, 200); // Buzzer macht einen Ton frequenz,dauer ton
      lcd.setCursor(0, 1);
      lcd.print("Ihre Groesse");
      lcd.setCursor(0, 2);
      lcd.print("betraegt:");
      lcd.setCursor(10, 3);
      lcd.print(entfernung_hoehe); // gibt die Größe aus 
      lcd.setCursor(17, 3);
      lcd.print("cm");
  
      delay (4500);
      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.print("Alle Werte");
      lcd.setCursor(0, 1);
      lcd.print("zusammengefasst");   
      lcd.setCursor(0,2);
      lcd.print("Groesse:");
      lcd.setCursor(10, 2);
      lcd.print(entfernung_hoehe);
      lcd.setCursor(17,2);
      lcd.print("cm");
      lcd.setCursor(0,3);
      lcd.print("Gewicht:");
      lcd.setCursor(11,3);
      lcd.print(gewicht); // gibt gewicht aus
      lcd.setCursor(17,3);
      lcd.print("kg");
      
      bmi = gewicht / (entfernung_hoehe/100 * entfernung_hoehe/100); // formel zum rechnen des BMIs
    }

  tasterstatus_hoch=digitalRead(taster_hoch); // lesen des Tasterstatus_hoch

  if (tasterstatus_hoch == HIGH) // Wenn Taster gedrückt ...
    {
      gewicht = gewicht + 1;
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print ("Gewichtseingabe");
      lcd.setCursor(0,2);
      lcd.print ("Ihr Gewicht"); 
      lcd.setCursor(0,3);
      lcd.print ("betraegt:");
      lcd.setCursor(10,3);
      lcd.print (gewicht);
      lcd.setCursor(16,3);
      lcd.print ("kg");
    }

  tasterstatus_runter=digitalRead(taster_runter); // lesen des Tasterstatus_runter

  if (tasterstatus_runter == HIGH) // Wenn Taster gedrückt ...
    { 
      gewicht = gewicht - 1;  
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print ("Gewichtseingabe");
      lcd.setCursor(0,2);
      lcd.print ("Ihr Gewicht"); 
      lcd.setCursor(0,3);
      lcd.print ("betraegt:");
      lcd.setCursor(10,3);
      lcd.print (gewicht);
      lcd.setCursor(16,3);
      lcd.print ("kg");     
    }

  tasterstatus_bmi=digitalRead(taster_bmi); // lesen des Tasterstatus_bmi

    if (tasterstatus_bmi == HIGH) // Wenn Taster gedrückt ...
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("Ihr BMI betraegt:");
      lcd.setCursor(7,2);
      lcd.print (bmi); //ausgabe bmi
    }

 tasterstatus_skala=digitalRead(taster_skala); // lesen des Tasterstatus_skala

 if (tasterstatus_skala == HIGH) // Wenn Taster gedrückt ...
  {
      lcd.clear();
      lcd.setCursor(0, 0); 
      lcd.print("BMI Skala");
      lcd.setCursor(0, 1);  
      lcd.print("unter 18,5: wenig");
      lcd.setCursor(0, 2);  
      lcd.print("18,5 bis 24,9: gut");
      lcd.setCursor(0, 3);  
      lcd.print("30 - 34,9: zu viel");
    
  }

}



