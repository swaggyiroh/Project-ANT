
# Project A.N.T

Ant Terrarium Observer..

Main for 64Bit Bullseye Pi OS
Branch for 64Bit Bookworm Pi OS

Benötigt:
  •	Pi Camera Rev 1.3
  •	Flexkabel (für die Kamera)
  •	DHT22 Sensor
  •	GPIO-Kabel
  •	Raspberry Pi Model 3B+
  •	Stromkabel
  •	Monitor
  •	HDMI-Kabel
  •	Tastatur
  •	Maus
  •	Ethernet oder W-Lan
  •	microSD-Karte (16/32 GB) mit Image
  •	microSD-Karte (16/32 GB) ohne Image
    o	Computer mit microSD-Kartenanschluss
    o	Raspberry Pi Imager 
Vorbereitung:
Falls die microSD-Karte schon ein Image aufgespielt hat, gehe zu Schritt 6
  1.	Schließe die microSD-Karte am Kartenanschluss des Computers an
  2.	Starte den Raspberry Pi Imager
  3.	Wähle als Modell „Raspberry Pi 3“ aus
  4.	Wähle als OS entweder Bookworm 64-bit aus oder unter „Raspberry Pi OS (other)“ Bullseye 64-bit
  5.	Wähle die microSD-Karte aus und erzeuge/schreibe das Image
  6.	Schiebe die microSD-Karte in den dafür vorgesehenen Slot im Pi ein
  7.	Schließe nun den DHT22 Sensor, wie im Foto dargestellt, an (Kabelfarben dienen als Orientierung) ![image](https://github.com/user-attachments/assets/5d4c7e4e-d712-40e5-be6f-fbfed1ec1f9f) ![image](https://github.com/user-attachments/assets/642d7ecc-1b93-45a0-a1ae-dd29a67b7ff3)									
  8.	Schließe nun die Kamera, wie im Foto gezeigt, an (die offenen Stellen des Kabels sollten dabei in die Richtung der Pins zeigen) 
  9.	Schließe nun noch die restlichen Kabel an (Power-Kabel, HDMI, Tastatur und Maus)
  10.	Starte nun den Pi
  11.	Stelle nun eine Verbindung mit dem Internet her (Ethernet oder W-Lan)
  12.	Öffne ein Terminal Fenster
  13.	Führe folgenden Befehl aus: 
    -	„git clone https://github.com/swaggyiroh/Project-ANT“, wenn der Pi auf dem Bullseye OS läuft
    -	„git clone --branch for-bookworm-version https://github.com/swaggyiroh/Project-ANT“, wenn der Pi auf dem Bookworm OS läuft
  14.	Gehe nun in das geklonte Verzeichnis mit „cd Project-ANT/“
  15.	Um alle benötigten Bibliotheken und Updates zu installieren, sowie die Ausführbare Datei zu kompilieren, führe nun die build-Datei aus mit „./build.sh“ (dies kann einige Minuten dauern)
  16.	Starte nun das Programm mit „./ProjectANT“
  17.	Mit der Escape-Taste kann das Programm wieder geschlossen werden
Zu beachten:
  -	Da die Bildverarbeitung den Futterstand anhand der Farben grün, blau und rot bestimmt, darf, für eine korrekte Ermittlung des Futterstands, der Untergrund keine dieser Farben haben. Zu Empfehlen ist ein weißer oder schwarzer Untergrund. 



## By

- [@Kuelpi](https://www.github.com/Kuelpi)
- [@Nilsibus](https://github.com/Nilsibus)
- [@swaggyiroh](https://www.github.com/swaggyiroh)
