/*
  Fundacion Kinal
  Centro Educativo Tecnico Laborla Kinal
  Electronica
  Grado: Quinto
  Seccion: A
  Curso: Taller de eleectronica digital y reparacion de computadoras I
  Nombre: Juan Manuel Sebastian Ixen Coy
  Carne: 2019519
  Fecha: 05/05
*/

#include <Wire.h>   
#include <LiquidCrystal_I2C.h>  


#define Direccion_LCD 0x27
#define filas A3
#define columnas A4
#define trig A0
#define echo A1
#define Buzzer 13
#define D1 3
#define D2 4
#define D3 5
#define D4 6
#define D5 7
#define D6 8
#define D7 9
#define D8 10
#define D9 11
#define D10 12
int distancia ;
int i;

 
LiquidCrystal_I2C LCD_Jixen(Direccion_LCD, columnas , filas);


void setup()
{
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D9, OUTPUT);
  pinMode(D10, OUTPUT);
  for(i=2; i<=11;i++){
  }
  pinMode(Buzzer ,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  LCD_Jixen.init();
  LCD_Jixen.backlight();
}


void loop()
{
  Medida();
  Alarma();
}
int Medida(){
  long T; 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  T = pulseIn(echo, HIGH);
  distancia  = T/59;
  delay(50);
  return distancia ;
}
int Alarma(){

     if( distancia  < 10 && distancia  > 00){
    LCD_Jixen.setCursor(0,0);
    LCD_Jixen.print("   Invadiendo  ");
    LCD_Jixen.setCursor(0,1);
    LCD_Jixen.print("Propiedad PRIV ");
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
    tone(Buzzer, 523);
    delay(1000);
    noTone(Buzzer);
 }

  if( distancia  < 15 && distancia  > 10)
  {
    LCD_Jixen.setCursor(0,0);
    LCD_Jixen.print("   Cuidado   ");
    LCD_Jixen.setCursor(0,1);
    LCD_Jixen.print("Propiedad PRIV ");
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
    tone(Buzzer, 523);
    delay(1000);
    noTone(Buzzer);
  }

   if( distancia  < 20 && distancia  > 15)
  {
    LCD_Jixen.setCursor(0,0);
    LCD_Jixen.print("   Cuidado   ");
    LCD_Jixen.setCursor(0,1);
    LCD_Jixen.print("Propiedad PRIV ");
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
    tone(Buzzer, 523);
    delay(1000);
    noTone(Buzzer);
  }

  if( distancia  < 25 && distancia  > 20){
    LCD_Jixen.setCursor(0,0);
    LCD_Jixen.print(" Cerca de ");
    LCD_Jixen.setCursor(0,1);
    LCD_Jixen.print("Propiedad PRIV ");
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
  }
  
  if( distancia  < 30 && distancia  > 25){
    LCD_Jixen.setCursor(0,0);
    LCD_Jixen.print(" Cerca de ");
    LCD_Jixen.setCursor(0,1);
    LCD_Jixen.print("Propiedad PRIV ");
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
  }
 
  if( distancia  > 30)
  {
    LCD_Jixen.setCursor(0,0);
    LCD_Jixen.print("Fuera de rango");
    LCD_Jixen.setCursor(0,1);
    LCD_Jixen.print("Espacio Publico ");
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
  }
  
    else {
    noTone(Buzzer);
 }
    return 0;
 }
 
