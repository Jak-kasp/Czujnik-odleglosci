#define echoPin 7 // definiowanie pinu Echo
#define trigPin 8 // definiowanie pinu Triger


#include <Wire.h>   // biblioteka niezbędna do obsługi wyświetacza
#include <LiquidCrystal_I2C.h> // biblioteka niezbędna do obsługi wyświetlacza 

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27



const int freq = 1000;  // ustawienie częstotliwości buzzera na 1000 Hz
const int dur = 40;     // ustawienie czasu trwania buzzera
const int buzzer = 3;  // ustawienie pinu buzzera

const int red1 = 2;
const int yellow1 = 4;
const int green1 = 5;



int maximumRange = 200; // ustawienie maksymalnego dystansu
int minimumRange = 0; // ustawienie minimalnego dystansu
long duration, distance; // zmienne potrzebne do obliczenia dystansu


void setup() {


  lcd.begin(16, 2); //Deklaracja typu
  lcd.clear(); // czyszczenie wyświetlacza
  lcd.setCursor(0, 0); //Ustawienie kursora 
  lcd.print("Odleglosc w cm"); // wypisanie tekstu na wyświetlacz
  


  
 pinMode(buzzer, OUTPUT); // ustawienie pinu buzzera na wyjściowy
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT); // ustawienie pinu echa na wejściowy 
 pinMode(green1, OUTPUT);
 pinMode(yellow1, OUTPUT);
 pinMode(red1, OUTPUT);
 
 
 

 
 
 
}

void loop() {

 
 digitalWrite(trigPin, LOW); // Trigger jest wyłączony
 delayMicroseconds(2); 


 digitalWrite(trigPin, HIGH); // Włączamy triggera na 10 ms 
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW); // Wyłączamy triggera 
 duration = pulseIn(echoPin, HIGH);  // czas bo jakim wysłany sygnał odbił się od przeszkody i dotarł do echa
 
 
 distance = duration/58.2;  //Obliczanie odległości (w cm) za pomocą prędkości dźwięku.

   digitalWrite(green1, LOW);
   digitalWrite(yellow1, LOW);
   digitalWrite(red1, LOW);

 
  
 
 if (distance < 10){   // jeśli dystans bbędzie mniejszy od 7 (cm) wywołają się wszystkie poniższe instrukcje
   digitalWrite(green1, HIGH); // pierwsza zielona dioda ustawiona na HIGH - poziom wysoki - włączenie pierwszej zielonej diody 
   digitalWrite(yellow1, HIGH);
   digitalWrite(red1, HIGH);
  
   
   
   
 } else if (distance < 30){
   digitalWrite(green1, HIGH); // pierwsza zielona dioda ustawiona na HIGH - poziom wysoki - włączenie pierwszej zielonej diody 
   digitalWrite(yellow1, HIGH);
   digitalWrite(red1, LOW);  // trzecie czarwona dioda ustawiona na LOW - poziom niski - wyłączenie trzeciej czerwojej diody 
   
   
 } else if (distance < 50){
 digitalWrite(green1, HIGH); // pierwsza zielona dioda ustawiona na HIGH - poziom wysoki - włączenie pierwszej zielonej diody 
   digitalWrite(yellow1, LOW);
   digitalWrite(red1, LOW);
   
   
 } else if (distance < 55){
   digitalWrite(green1, LOW); // pierwsza zielona dioda ustawiona na HIGH - poziom wysoki - włączenie pierwszej zielonej diody 
   digitalWrite(yellow1, LOW);
   digitalWrite(red1, LOW);
   
 } 
 
 if(distance < 10){        // jeśl dystans będzie mnijeszy od 7 (cm) wywołają się wszystkie poniższe instrukcje
   tone(buzzer, freq, dur);  // włączenie buzzera 
   delay(10);                 // opóźnienie (1 ms)
 } else if (distance < 30){
   tone(buzzer, freq, dur);
   delay(100);
 } else if (distance < 50){
   tone(buzzer, freq, dur);
   delay(300);
 }

 lcd.setCursor(0, 1); //Ustawienie kursora 
  lcd.print(distance/1.0); //Wyświetlenie odległości
  delay(100); //Opóźnienie (100 ms)



 delay(50); //Opóźnenie (50ms) przed następnym pomiarem.
}




