#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define endereco 0x27
#define colunas 16
#define linhas 2
LiquidCrystal_I2C lcd(endereco, colunas, linhas);
const int pinoSensorUmidade = A3;

void setup()
{
  Serial.begin(9600);
  pinMode(pinoSensorUmidade, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop()
{
  Serial.println(analogRead(pinoSensorUmidade));
  delay(150); // aumenta ou diminiui a quantidade de vezes que o arduino manda mensagem

  if (analogRead(pinoSensorUmidade) > 421) // Caso a umidade for maior que 421 vai mostrar que e solo desidratado 
  { 

    lcd.print("     Solo");
    delay(1000);
    lcd.setCursor(0, 1);         // É para descer a coluna do visor 1 casa a baixo
    lcd.print("  Desidratado"); // É algo que vai sair na tela
    delay(1000);
    lcd.setCursor(0, 0);
    lcd.clear();
  }
  else if (analogRead(pinoSensorUmidade) < 420) // Caso a umidade for menor que 420 ele vai mostrar que esta hidratado
  {
    lcd.print("     Solo");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("   Hidratado");
    delay(1000);
    lcd.clear();
  }
}
