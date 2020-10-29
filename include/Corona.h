
#ifndef CORONA_H_
#define CORONA_H_

#define ROMANIA_CASES_WEBSITE "https://covid19.geo-spatial.org/api/dashboard/getDailyCaseReport"
#define COUNTY_CASES_WEBSITE "https://covid19.geo-spatial.org/api/dashboard/v2/getCasesByCounty"

#include "Arduino.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "EEPROM.h"

class County
{
public:
  String countyCode;
  String countyName;
  int activeCasesCounty;
  int newCasesCounty;

  County();
  County(String countyCode, String countyName, int activeCasesCounty, int newCasesCounty);
};

class Country
{
public:
  String dateOfData;
  int newCasesCountry;

  Country();
  Country(String dateOfData, int newCasesCountry);
};

class Corona : public County, public Country
{
public:
  Corona(County countyObject, Country countryObject);
  Corona();
  void printCoronaData(String s);
  void writeInEEPROM();
};

County getIasiData();
Country getRomaniaData();
Corona getObjectFromEEPROM();

//EEPROM functions used in the methods above
void initEEPROM();
String getStringFromEEPROM();
void writeStringInEEPROM(int address, String string, int lenght);
#endif /* CORONA_H_ */
