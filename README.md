# Menschlicher Größenmesser mit BMI-Rechner

Ein Arduino-basiertes Projekt zur präzisen Messung der Körpergröße einer Person mittels eines Ultraschallsensors für die Berechnung des Body-Mass-Index (BMI). Dieses Projekt wurde als Abschlussprojekt für den Abschluss "staatlich geprüfte/r informationstechnische/r Assistent/in" angefertigt.

## Über das Projekt
Ziel des Projekts war die Entwicklung einer schnelleren, genaueren und bequemeren Alternative zu herkömmlichen Methoden zur Größenmessung, wie beispielsweise dem Maßband. Es ist zudem ein BMI-Rechner integriert, da der BMI ein wichtiger Indikator für den Gesundheitszustand einer Person ist. Das Gerät ist benutzerfreundlich gestaltet und ermöglicht es jedem, seine Größe und seinen BMI in kürzester Zeit zu bestimmen. 


## Hauptmerkmale

* **Körpergrößenmessung:** Verwendet einen HC-SR04 Ultraschallsensor, um den Abstand zum Kopf einer Person zu messen und damit deren Gesamtkörpergröße zu berechnen.
* **BMI-Berechnung:** Nach der Messung der Körpergröße kann der Benutzer sein Gewicht über Tasten eingeben, um seinen BMI zu berechnen. Das Ergebnis wird auf dem Bildschirm angezeigt.
* **LCD-Bildschirm:** Alle Informationen, einschließlich Anweisungen, Körpergröße und BMI, werden auf einem 20x4-Zeichen LCD-Bildschirm angezeigt.
* **Akustisches Feedback:** Ein Piezo Buzzer gibt einen Signalton ab, um zu bestätigen, dass die Messung erfolgreich durchgeführt wurde.
* **Benutzeroberfläche:** Das Gerät wird über fünf Drucktasten bedient, mit denen der Vorgang gestartet, das Gewicht eingestellt und der BMI berechnet werden kann.
* **Maßgeschneidertes Gehäuse:** Die Komponenten sind in zwei maßgeschneiderten Gehäusen aus HPL-Platten untergebracht.

## Hardware-Komponenten

Diese Komponenten wurden für den endgültigen Aufbau benutzt:

* **Microcontroller:** Arduino Nano V3.0
* **Sensor:** HC-SR04 Ultraschallsensor 
* **Bildschirm:** 20x4-LCD-Bildschirm mit einer I2C-Schnittstelle 
* **Tasten:** 4-Pin-Drucktaster
* **Buzzer:** KY-006 Passiver Piezo Buzzer
* **Zusatz:** Breadboard und Jumperkabel
* **Gehäuse:** 15 mm dicke HPL-Platten

## Wie es funktioniert

1. **Einrichtung:** Die Sensorbox wird in einer festen Höhe von 226 cm am Türrahmen angebracht. (Die feste Höhe kann auch geändert werden, wofür aber auch der Code geändert werden muss.) Die Hauptbox mit LCD-Display und Tasten wird in Augenhöhe neben der Tür platziert. (Je nach Bedarf variierbar.)
2. **Messung:** Der Benutzer drückt die „Start”-Taste und wird aufgefordert, sich unter den Ultraschallsensor zu stellen.
3. **Berechnung:** Der Sensor sendet eine Ultraschallwelle aus, misst die Zeit, die das Echo benötigt, um zurückzukehren, und berechnet die Entfernung zum Kopf des Benutzers. Die Körpergröße der Person wird dann durch Subtraktion dieser Entfernung von der festen Höhe des Sensors (226 cm) ermittelt.  
4. **Gewichtsangabe:** Die gemessene Körpergröße wird auf dem LCD-Bildschirm angezeigt. Der Benutzer wird dann aufgefordert, sein Gewicht mit den Tasten „Auf” und „Ab” einzugeben.
5. **BMI-Anzeige:** Nach Bestätigung des Gewichts berechnet das Gerät den BMI anhand der Formel und zeigt das Ergebnis an.

## Projektersteller

* **Loran Demiroglu**
* **Email:** lorandemiroglu04@gmail.com
