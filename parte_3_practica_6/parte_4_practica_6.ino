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
#define buz A3
#define led0 5
#define led1 6
#define led2 7
#define led3 8
#define led4 9
#define led5 10
#define led6 11
#define led7 12
#define led8 A1
#define led9 A2

int distancia; //Variable de distancia en cm

int medicion();


LiquidCrystal_I2C lcdjj(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcdjj.init();
  lcdjj.backlight();
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); //PIN de Entrada
  digitalWrite(trig, LOW); //Incializamos el TRIGGER en 0

}

void loop() {
  distancia = medicion();
  if (distancia > 45) {
    lcdjj.setCursor(0, 0);
    lcdjj.print("Fuera de        ");
    lcdjj.setCursor(0, 1);
    lcdjj.print("Alcance         ");
    digitalWrite(led0, HIGH); digitalWrite(led1, HIGH); digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);  digitalWrite(led4, LOW);  digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);  digitalWrite(led7, LOW);  digitalWrite(led8, LOW);  digitalWrite(led9, LOW);

  }

  if (distancia >= 30 && distancia < 45) {
    lcdjj.setCursor(0, 0);
    lcdjj.print("Persona  ");
    lcdjj.setCursor(0, 1);
    lcdjj.print("Acercandose     ");
    digitalWrite(led0, HIGH); digitalWrite(led1, HIGH); digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);  digitalWrite(led4, LOW);  digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);  digitalWrite(led7, LOW);  digitalWrite(led8, LOW);  digitalWrite(led9, LOW);
  }

  if (distancia >= 15 && distancia < 30) {
    lcdjj.setCursor(0, 0);
    lcdjj.print("Cuidado      ");
    lcdjj.setCursor(0, 1);
    lcdjj.print("Espacio Privado ");
    digitalWrite(led0, HIGH); digitalWrite(led1, HIGH); digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);  digitalWrite(led4, HIGH);  digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);  digitalWrite(led7, LOW);  digitalWrite(led8, LOW);  digitalWrite(led9, LOW);
    tone(buz, 800, 5000);
    delay(100);
    noTone(buz);
  }

  if (distancia >= 5 && distancia < 15) {
    lcdjj.setCursor(0, 0);
    lcdjj.print("Invadiendo   ");
    lcdjj.setCursor(0, 1);
    lcdjj.print("Espacio Privado ");
    digitalWrite(led0, HIGH); digitalWrite(led1, HIGH); digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);  digitalWrite(led4, HIGH); digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH); digitalWrite(led7, HIGH); digitalWrite(led8, HIGH); digitalWrite(led9, HIGH);
    tone(buz, 200, 10000);
    delay(100);
    noTone(buz);
  }
}
int medicion() {
  long t; //Variable de tiempo en llegar al ECHO
  long d; //Variable de distancia en cm
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); //Pulso de 10us
  digitalWrite(trig, LOW);

  t = pulseIn(echo, HIGH); //obtenemos el ancho del pulso
  d = t / 58; //convertimos el tiempo en una distancia en cm
  Serial.println(d);
  return d;
}
