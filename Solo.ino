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
  delay(250); // aumenta ou diminiui o tempo no terminal

  if (analogRead(pinoSensorUmidade) > 1000)
  { // voce pode usar duas variações < para menor que e o > para maior que

    lcd.print("     Solo");
    delay(1000);
    lcd.setCursor(0, 1);         // é para descer a coluna do visor 1 casa a baixo
    lcd.print("  Desidratado"); // e algo que vai sair no terminal como (pouca undidade) ou solo baixo algo assim
    delay(1000);
    lcd.setCursor(0, 0);
    lcd.clear();
  }
  else if (analogRead(pinoSensorUmidade) < 980)
  {
    lcd.print("     Solo");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("   Hidratado");
    delay(1000);
    lcd.clear();
  }
}
