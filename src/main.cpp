#include <GxEPD.h>
#include <Adafruit_I2CDevice.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include <Wire.h>
#include "SPI.h"
#include "WiFi.h"
#include "Corona.h"
#include "ePaper.h"
#include "Credentials.h"
#include <Arduino.h>

int getArrowDirection(int oldCasesCounty,int newCasesCountry);
void checkIfTheDataIsDifferent(String oldData , String newData);

void setup()
{
  Serial.begin(115200);
  int arrow1, arrow2;

  Corona coronaDataYesterday;
  coronaDataYesterday = getObjectFromEEPROM();
  coronaDataYesterday.printCoronaData("In EEPROM:");

  //connect to Wifi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  Corona coronaDataToday(getIasiData(), getRomaniaData());

  Serial.println("Turning off wifi and bluetooth");

  WiFi.mode(WIFI_OFF);
  btStop();

  checkIfTheDataIsDifferent(coronaDataYesterday.dateOfData,coronaDataToday.dateOfData);
 
  coronaDataToday.printCoronaData("New data: ");

  E_PAPER ePaper;

  ePaper.displayInit();
  ePaper.layoutInit();
  Serial.println("Before updateDisplay");
  ePaper.updateDisplay(coronaDataToday.dateOfData, coronaDataToday.newCasesCounty, coronaDataToday.newCasesCountry);
  arrow1 = getArrowDirection(coronaDataToday.newCasesCounty,coronaDataYesterday.newCasesCounty);
  arrow2 = getArrowDirection(coronaDataToday.newCasesCountry,coronaDataYesterday.newCasesCountry);
  ePaper.drawArrows(arrow1, arrow2);

  coronaDataToday.writeInEEPROM();

  Serial.println("Enter deep sleep");

  esp_deep_sleep_start();

  Serial.println("This will never be printed");
}

void loop()
{
}

int getArrowDirection(int oldCasesCounty,int newCasesCountry)
{
  if (oldCasesCounty > newCasesCountry)
    return UP;
  else if (oldCasesCounty < newCasesCountry)
    return DOWN;
  else
    return NONE;
}

void checkIfTheDataIsDifferent(String oldData , String newData)
{
  //if the date is the same go to sleep
  if (oldData == newData)
  {
    Serial.println("There is no new data to be displayed");
    Serial.println("Enter deep sleep");
    esp_deep_sleep_start();
    Serial.println("This will never be printed");
  }
}