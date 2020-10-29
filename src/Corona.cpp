#include "Corona.h"

County::County()
{
    //default constructor
    this->countyCode = "AAAAAAAAA";
    this->countyName = "AA";
    this->activeCasesCounty = -1;
    this->newCasesCounty = -1;
}

County::County(String countyCode, String countyName, int activeCasesCounty, int newCasesCounty)
{
    this->countyCode = countyCode;
    this->countyName = countyName;
    this->activeCasesCounty = activeCasesCounty;
    this->newCasesCounty = newCasesCounty;
}

Country::Country()
{
    //default constructor
    this->dateOfData = "0000-00-00";
    this->newCasesCountry = -1;
}

Country::Country(String dateOfData, int newCasesCountry)
{
    this->dateOfData = dateOfData;
    this->newCasesCountry = newCasesCountry;
}

Corona::Corona()
{
    //default constructor
    this->countyCode = "BBBBBBBBB";
    this->countyName = "BB";
    this->activeCasesCounty = -2;
    this->newCasesCounty = -2;

    this->dateOfData = "9999-99-99";
    this->newCasesCountry = -2;
}

Corona::Corona(County countyObject, Country countryObject)
{
    //default constructor
    this->countyCode = countyObject.countyCode;
    this->countyName = countyObject.countyName;
    this->activeCasesCounty = countyObject.activeCasesCounty;
    this->newCasesCounty = countyObject.newCasesCounty;

    this->dateOfData = countryObject.dateOfData;
    this->newCasesCountry = countryObject.newCasesCountry;
}

County getIasiData()
{
    int i;
    //try 3 times to get the data
    for (i = 0; i < 3; i++)
    {
        HTTPClient http;
        Serial.print("[HTTP] Iasi:");
        Serial.print("[HTTP] begin...\n");

        // configure server and url
        http.begin(COUNTY_CASES_WEBSITE);

        Serial.print("[HTTP] GET...\n");

        // start connection and send HTTP header
        int httpCode = http.GET();

        if (httpCode > 0)
        {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if (httpCode == HTTP_CODE_OK)
            {

                // get lenght of document (is -1 when Server sends no Content-Length header)
                // int len = http.getSize();
                // Serial.println(len);

                WiFiClient *stream = http.getStreamPtr();
                stream->find("{\"county_code\":\"IS\"");
                char json[300] = "{\"county_code\":\"IS\"";
                char *p = &json[19];
                p += stream->readBytesUntil('}', p, 300 - 20);
                //      p++;
                *p = '}';

                http.end();
                Serial.print("[HTTP] connection closed or file end.\n");
                StaticJsonDocument<400> doc;
                deserializeJson(doc, json);
                County iasi(doc["county_code"], doc["county"], doc["total_active"], doc["new_case"]);
                //   Serial.println(iasi.);
                return iasi;
            }
        }
        else
        {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
            //    *newCases = -1; //http fault;
        }
    }
    //No wifi or website down
    Serial.println("Failed to get iasi data");
    County iasi;
    return iasi;
}

Country getRomaniaData()

{
    int i;
    //try 3 times to get the data
    for (i = 0; i < 3; i++)
    {
        HTTPClient http;
        Serial.print("[HTTP] Romania:");
        Serial.print("[HTTP] begin...\n");

        // configure server and url
        http.begin(ROMANIA_CASES_WEBSITE);

        Serial.print("[HTTP] GET...\n");

        // start connection and send HTTP header
        int httpCode = http.GET();

        if (httpCode > 0)
        {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if (httpCode == HTTP_CODE_OK)
            {

                // get lenght of document (is -1 when Server sends no Content-Length header)
                int len = http.getSize();
                // Serial.println(len);
                // create buffer for read
                uint8_t buff[200] = {0};
                uint8_t buff2 = 0;
                int i;
                // get tcp stream
                WiFiClient *stream = http.getStreamPtr();

                for (i = 0; i < len - 200; i++)
                {
                    stream->readBytes(&buff2, 1);
                }

                stream->readBytes(buff, 200);
                http.end();
                Serial.print("[HTTP] connection closed or file end.\n");
                buff[199] = 0;
                buff[198] = 0;
                buff[197] = 0;
                for (i = 199; i > 0; i--)
                {
                    if (buff[i] == '{')
                        break;
                }

                uint8_t *p = &buff[i];
                StaticJsonDocument<200> doc;
                deserializeJson(doc, p);

                Country romania(doc["day_case"], doc["new_case_no"]);
                return romania;
            }
        }
        else
        {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
    }
    //No wifi or website down
    Serial.println("Failed to get romania data");
    Country romania;
    return romania;
}

Corona getObjectFromEEPROM()
{
    initEEPROM();
    String dateInEEPROM = getStringFromEEPROM();
    Corona eepromData;
    eepromData.dateOfData = dateInEEPROM;
    eepromData.newCasesCounty = (int)EEPROM.readInt(10);
    eepromData.newCasesCountry = (int)EEPROM.readInt(14);
    return eepromData;
}

void Corona::printCoronaData(String s)
{
    //Example of strings : "EEPROM" , "Today"
    Serial.println();
    Serial.println(s);
    Serial.print("Date: ");
    Serial.println(dateOfData);
    Serial.print("Cases IASI: ");
    Serial.println(newCasesCounty);
    Serial.print("Cases ROMANIA: ");
    Serial.println(newCasesCountry);
    Serial.println();
}

void Corona::writeInEEPROM()
{
    writeStringInEEPROM(0, dateOfData, 10); //date will always be 10 bits so 0-9 -> date
    EEPROM.writeInt(10, newCasesCounty);    // 10-14 -> new cases in county
    EEPROM.writeInt(14, newCasesCountry);   // 14-18 -> new cases in country

    EEPROM.commit();
}













void initEEPROM()
{
    if (!EEPROM.begin(1000))
    {
        Serial.println("Failed to initialise EEPROM");
        Serial.println("Restarting...");
        delay(1000);
        ESP.restart();
    }
}

String getStringFromEEPROM()
{
    String date;
    date += (char)EEPROM.read(0);
    date += (char)EEPROM.read(1);
    date += (char)EEPROM.read(2);
    date += (char)EEPROM.read(3);
    date += (char)EEPROM.read(4);
    date += (char)EEPROM.read(5);
    date += (char)EEPROM.read(6);
    date += (char)EEPROM.read(7);
    date += (char)EEPROM.read(8);
    date += (char)EEPROM.read(9);
    return date;
}

void writeStringInEEPROM(int address, String string, int lenght)
{
    int i = 0;
    char buff[lenght + 1];
    string.toCharArray(buff, lenght + 1);
    for (i = 0; i < lenght; i++)
    {
        EEPROM.write(i, buff[i]);
    }
}

