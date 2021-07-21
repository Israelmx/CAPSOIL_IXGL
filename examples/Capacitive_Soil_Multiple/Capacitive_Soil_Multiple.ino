#include <Arduino.h>
#include "CAPSOIL_IXGL.h"

#define AIRVALUE 505    //Calibration value, read the ADC value from the CS Sensor in air
#define WATERVALUE 175  //Calibration value, read the ADC value from the CS Sensor in water

CAPSOIL_IXGL Sensor_Maceta1(A1, AIRVALUE, WATERVALUE);
CAPSOIL_IXGL Sensor_Maceta2(A2, 600,100);
CAPSOIL_IXGL Sensor_Maceta3(A3, 700 , 50);

void setup()
{
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}

void loop()
{
  uint8_t hum_maceta[3];

  hum_maceta[0] = Sensor_Maceta1.Mtd_get_hum();
  Serial.print("Humedad Maceta 1: ");Serial.print(hum_maceta[0]);Serial.println("%");
  delay(500);
  hum_maceta[1] = Sensor_Maceta2.Mtd_get_hum();
  Serial.print("Humedad Maceta 2: ");Serial.print(hum_maceta[1]);Serial.println("%");
  delay(500);
  hum_maceta[2] = Sensor_Maceta3.Mtd_get_hum();
  Serial.print("Humedad Maceta 3: ");Serial.print(hum_maceta[2]);Serial.println("%");
  delay(500);
  Serial.println();
  delay(1000);
}