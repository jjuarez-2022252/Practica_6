/*
Fundación Kinal
Centro Educativo Técnico Labral Kinal
Electrónica
Grado: Quinto
Sección: A
Curso: Taller de Electrónica Digital y Reparación de Computadoras I
Nombre: Jose Javier Juarez Rivera
Carné: 2022252
*/
#include <LiquidCrystal.h>
#define trig 8
#define echo 9                                                 
#define buz 10
int medicion();
int personas, chavos;
LiquidCrystal lcdjj(2, 3, 4,5,6,7);

byte fantasma[] = {
  B11111,
  B10101,
  B11111,
  B11111,
  B11111,
  B01110,
  B01010,
  B11011
};
byte musica[] = {
  B00001,
  B00011,
  B00101,
  B01001,
  B01001,
  B01011,
  B11011,
  B11000
};

void setup() {
  Serial.begin(9600);
  lcdjj.begin(16,2);
  lcdjj.createChar(0, fantasma);
  lcdjj.createChar(1, musica);
  lcdjj.home();
  pinMode(buz, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trig, LOW);  
}

void loop() {
   personas = medicion();
  if(personas >= 6 && personas <=10){
    chavos = chavos + 1;
    delay(500);
    Serial.println(chavos);
  }
 
  if(chavos <=17){
  lcdjj.setCursor(6,2);
  lcdjj.print("personas");
  lcdjj.setCursor(3,2);
  lcdjj.print(chavos);
  }
 
  if(chavos >= 17){
  lcdjj.clear();
  lcdjj.setCursor(0,2);
  lcdjj.print("lugar");
  lcdjj.setCursor(5,1);
  lcdjj.print("lleno  :))");
  lcdjj.setCursor(0,2);
//personitas
   lcdjj.setCursor(0,0); lcdjj.write(byte(0)); lcdjj.setCursor(15,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(0,0); lcdjj.write(byte(1)); lcdjj.setCursor(15,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(0,0); lcdjj.write(" "); lcdjj.setCursor(15,0); lcdjj.write(" ");
   tone(buz,260);
   delay(500);
   noTone(buz);
//personita1
   lcdjj.setCursor(1,0); lcdjj.write(byte(0)); lcdjj.setCursor(14,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(1,0); lcdjj.write(byte(1)); lcdjj.setCursor(14,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(1,0); lcdjj.write(" "); lcdjj.setCursor(14,0); lcdjj.write(" ");
   tone(buz,260);
   delay(500);
   noTone(buz);
//personitas2
   lcdjj.setCursor(2,0); lcdjj.write(byte(0)); lcdjj.setCursor(13,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(2,0); lcdjj.write(byte(1)); lcdjj.setCursor(13,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(2,0); lcdjj.write(" "); lcdjj.setCursor(13,0); lcdjj.write(" ");
   tone(buz,260);
   delay(500);
   noTone(buz);
//personitas3
   lcdjj.setCursor(3,0); lcdjj.write(byte(0)); lcdjj.setCursor(12,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(3,0); lcdjj.write(byte(1)); lcdjj.setCursor(12,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(3,0); lcdjj.write(" "); lcdjj.setCursor(12,0); lcdjj.write(" ");
   tone(buz,260);
   delay(500);
   noTone(buz);
//personitas4
   lcdjj.setCursor(4,0); lcdjj.write(byte(0)); lcdjj.setCursor(11,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(4,0); lcdjj.write(byte(1)); lcdjj.setCursor(11,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(4,0); lcdjj.write(" "); lcdjj.setCursor(11,0); lcdjj.write(" ");
   tone(buz,260);
   delay(500);
   noTone(buz);
//personitas5
   lcdjj.setCursor(5,0); lcdjj.write(byte(0)); lcdjj.setCursor(10,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(5,0); lcdjj.write(byte(1)); lcdjj.setCursor(10,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(5,0); lcdjj.write(" "); lcdjj.setCursor(10,0); lcdjj.write(" ");
   tone(buz,260);
   delay(500);
   noTone(buz);
//personitas6
   lcdjj.setCursor(6,0); lcdjj.write(byte(0)); lcdjj.setCursor(9,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(6,0); lcdjj.write(byte(1)); lcdjj.setCursor(9,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(6,0); lcdjj.write(" "); lcdjj.setCursor(9,0); lcdjj.write(" ");
   tone(buz,260);
   delay(500);
   noTone(buz);
//personitas7
   lcdjj.setCursor(7,0); lcdjj.write(byte(0)); lcdjj.setCursor(8,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(7,0); lcdjj.write(byte(1)); lcdjj.setCursor(8,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(7,0); lcdjj.write(" "); lcdjj.setCursor(8,0); lcdjj.write(" ");  
   tone(buz,260);
   delay(500);
   noTone(buz);
//personitas6 de regreso
   lcdjj.setCursor(6,0); lcdjj.write(byte(0)); lcdjj.setCursor(9,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(6,0); lcdjj.write(byte(1)); lcdjj.setCursor(9,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(6,0); lcdjj.write(" "); lcdjj.setCursor(9,0); lcdjj.write(" ");
   tone(buz,260);
   delay(500);
   noTone(buz);
//personitas5 de regreso
   lcdjj.setCursor(5,0); lcdjj.write(byte(0)); lcdjj.setCursor(10,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(5,0); lcdjj.write(byte(1)); lcdjj.setCursor(10,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(5,0); lcdjj.write(" "); lcdjj.setCursor(10,0); lcdjj.write(" ");
   tone(buz,260);
   delay(500);
   noTone(buz);
//personitas4 de regreso
   lcdjj.setCursor(4,0); lcdjj.write(byte(0)); lcdjj.setCursor(11,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(4,0); lcdjj.write(byte(1)); lcdjj.setCursor(11,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(4,0); lcdjj.write(" "); lcdjj.setCursor(11,0); lcdjj.write(" ");
   tone(buz,260);
   delay(500);
   noTone(buz);
//personitas3 de regreso
   lcdjj.setCursor(3,0); lcdjj.write(byte(0)); lcdjj.setCursor(12,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(3,0); lcdjj.write(byte(1)); lcdjj.setCursor(12,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(3,0); lcdjj.write(" "); lcdjj.setCursor(12,0); lcdjj.write(" ");  
   tone(buz,260);
   delay(500);
   noTone(buz);
//personitas2 de regreso
   lcdjj.setCursor(2,0); lcdjj.write(byte(0)); lcdjj.setCursor(13,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(2,0); lcdjj.write(byte(1)); lcdjj.setCursor(13,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(2,0); lcdjj.write(" "); lcdjj.setCursor(13,0); lcdjj.write(" ");  
   tone(buz,260);
   delay(500);
   noTone(buz);
//personita1 de regreso
   lcdjj.setCursor(1,0); lcdjj.write(byte(0)); lcdjj.setCursor(14,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(1,0); lcdjj.write(byte(1)); lcdjj.setCursor(14,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(1,0); lcdjj.write(" "); lcdjj.setCursor(14,0); lcdjj.write(" ");
   tone(buz,260);
   delay(500);
   noTone(buz);
//personitas de regreso
   lcdjj.setCursor(0,0); lcdjj.write(byte(0)); lcdjj.setCursor(15,0); lcdjj.write(byte(0));
   delay(500);
   lcdjj.setCursor(0,0); lcdjj.write(byte(1)); lcdjj.setCursor(15,0); lcdjj.write(byte(1));
   delay(500);
   lcdjj.setCursor(0,0); lcdjj.write(" "); lcdjj.setCursor(15,0); lcdjj.write(" ");    
   
   tone(buz,260);
   delay(500);
   noTone(buz);
}
}  
  int medicion(){
  long d;
  long t;
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  t = pulseIn(echo, HIGH);
  d = t/58;
  return d;
    personas = medicion();
} 
