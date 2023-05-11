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
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define trig 2
#define echo 3
int medidas; //Variable de distancia en cm
int i, a;
int medicion();

LiquidCrystal_I2C lcdjj(0x27, 16, 2);

byte customChar[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup() {
  Serial.begin(9600);
  lcdjj.init();
  lcdjj.backlight();
  lcdjj.createChar(0, customChar);
  lcdjj.home();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); //PIN de Entrada
  digitalWrite(trig, LOW); //Incializamos el TRIGGER en 0

}

void loop() {
  medidas = medicion();
  if (medidas >70) {
    lcdjj.clear();
  }
  switch (medidas) {
    case 50:
      lcdjj.setCursor(7, 0);
      lcdjj.print("50    ");
      lcdjj.setCursor(0, 1);
      lcdjj.print("     LIBRES     ");
      i = 0;
      a = 13;
      for (i == 0; i <= 2; i++) {
        lcdjj.setCursor(i, 0);
        lcdjj.write(byte(0));
        lcdjj.setCursor(3, 0);
        lcdjj.print("    ");
      }
      for (a == 13; a <= 15; a++) {
        lcdjj.setCursor(a, 0);
        lcdjj.write(byte(0));
      }
      break;

    case 30:
      lcdjj.setCursor(7, 0);
      lcdjj.print("30  ");
      lcdjj.setCursor(0, 1);
      lcdjj.print("    CUIDADO     ");
      i = 0;
      a = 11;
      for (i == 0; i <= 4; i++) {
        lcdjj.setCursor(i, 0);
        lcdjj.write(byte(0));
        lcdjj.setCursor(5, 0);
        lcdjj.print("  ");
      }
      for (a == 11; a <= 15; a++) {
        lcdjj.setCursor(a, 0);
        lcdjj.write(byte(0));
      }
      break;

    case 10:
      lcdjj.setCursor(7, 0);
      lcdjj.print("10");
      lcdjj.setCursor(0, 1);
      lcdjj.print("     ALTO     ");
      i = 0;
      a = 9;
      for (i == 0; i <= 6; i++) {
        lcdjj.setCursor(i, 0);
        lcdjj.write(byte(0));
      }
      for (a == 9; a <= 15; a++) {
        lcdjj.setCursor(a, 0);
        lcdjj.write(byte(0));
      }
      break;
  }
}

int medicion() {
  long d; 
  long t; 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);

  t = pulseIn(echo, HIGH); 
  d = t / 58; 
  Serial.println(d);
  return d;
}
