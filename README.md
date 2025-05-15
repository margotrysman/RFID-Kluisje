<p align="center">
<img src="afbeeldingen/2.png" width="30%">
<img src="afbeeldingen/3.png" width="30%">
<img src="afbeeldingen/1.png" width="30%">

## Inleiding
Rfid tags, een interessante technologie waarmee onze studentenkaarten werken. Ook de kluisjes in het A gebouw en verschillende deursloten werken hiermee. Het is een nuttige en ruim toepasbare tool. In dit project proberen we onder andere de volgende vragen te beantwoorden: Hoe werkt deze technologie precies? Is dit een complexe theorie? En kunnen we dit zelf toepassen? Aan de hand van deze technologie (servo, rfid tag en lezer) werken we zelf een kluisje uit.


## Rfid 
<img src="afbeeldingen/schakeling_RFID.png" width="30%">

Hiervoor wordt de schakeling zoals hierboven gebruikt.
Allereest wordt de nfc library gedownload. Binnen de library kan onder "dump info" kan alle informatie gehaald worden die een ingelezen kaart bevat. Vervolgens kan een correcte kaart gedefiniëerd worden. Dit door de unieke code op te slaan. Vervolgens kan een controlemechanisme die de karakters controleerd worden toegevoegd.


## Deel servomotor 
<img src="afbeeldingen/schakeling_servo.png" width="30%">
De servomotor werd aangesloten zoals op bovenstaande afbeelding. Met behulp van de servo library kan eenvoudig de hoek worden ingesteld. Deze moet kunnen veranderen om het kluisje te kunnen ontgrendelen en vergrendelen.

## Samenvoegen
Hiervoor worden bovenstaande schemas's gecombineerd. Het enige verschil is dat nu de digitale pin van de servo op 8 ipv 9 is aangesloten
Het systeem wordt zo geprogrammeerd dat bij een foute kaart de motor niet draait. Bij een correcte kaart draait de motor afwisselend open en dicht.

## Reflectie
In dit proces leerden we:
- Hoe een servo motor werkt en hoe te programmeren
- Hoe een rfid lezer en tag werkt en hoe te programmeren
- Hoe we deze componenten kunnen integreren om tot een werkend geheel en kluisje te komen.

Uit dit proces kwamen we volgende moeilijkheden tegen: 

### Uploaden naar arduino
Het uploaden van de code liep lang niet altijd vlot. Bij het gebruik van de arduino nano gaf deze veel foutmeldingen. Na vervolgens over te schakelen op een arduino uno was dit probleem opgelost. 


### Rfid lezer
Zonder de library als het gebruik van een rfid lezer is vrij complex. Zelfs bij het gebruik van een library is het aanpassen van de code heel gevoelig. Het is niet altijd meteen duidelijk welke lijn welke info bevat.
