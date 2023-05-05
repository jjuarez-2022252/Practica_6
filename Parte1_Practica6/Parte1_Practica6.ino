/*
Fundación Kinal
Centro Educativo Técnico Labral Kinal
Electrónica
Grado: Quinto
Curso: Taller de Electrónica Digital y Reparación de Computadoras I
Nombre: Jose Javier Juarez Rivera
Carné: 2022252
*/
#include <LiquidCrystal.h>

LiquidCrystal lcdjj(2, 3,4,5,6,7);

void setup() {
  lcdjj.begin(16,2);
}

void loop() {
  delay(1000);
  lcdjj.setCursor(2,0);
  lcdjj.print("Javier Rivera");
  lcdjj.setCursor(4,2);
  lcdjj.print("2022252");
  delay(1000);
}
