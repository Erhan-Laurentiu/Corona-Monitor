#include "ePaper.h"
#include <GxEPD.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include"board_def.h"
#include <Wire.h>
#include "SPI.h"
#include "board_def.h"
#include"image.h"
#include"Fonts.h"

String casesIs = "9876";
String casesRo = "09876";
GxIO_Class io(SPI, ELINK_SS, ELINK_DC, ELINK_RESET);
GxEPD_Class display(io, ELINK_RESET, ELINK_BUSY);


E_PAPER::E_PAPER()
{
    //default constructor

}



void E_PAPER::drawArrows(int countyArrow, int countryArrow)
{
  if (countyArrow==UP) display.drawExampleBitmap(arrowUp, 229, DISPLAY_MAX_HEIGHT / 4 - 15, ARROW_IMG_WIDTH, ARROW_IMG_HEIGHT, GxEPD_BLACK);
  else if(countyArrow==DOWN)   display.drawExampleBitmap(arrowDown, 229, DISPLAY_MAX_HEIGHT / 4 - 15, ARROW_IMG_WIDTH, ARROW_IMG_HEIGHT, GxEPD_BLACK);
  else display.drawExampleBitmap(noArrow, 229, 3 * DISPLAY_MAX_HEIGHT / 4 - 11, ARROW_IMG_WIDTH, ARROW_IMG_HEIGHT, GxEPD_BLACK);
  
  if (countryArrow==UP)   display.drawExampleBitmap(arrowUp, 229, 3 * DISPLAY_MAX_HEIGHT / 4 - 11, ARROW_IMG_WIDTH, ARROW_IMG_HEIGHT, GxEPD_BLACK);
  else if(countryArrow==DOWN)  display.drawExampleBitmap(arrowDown, 229, 3 * DISPLAY_MAX_HEIGHT / 4 - 11, ARROW_IMG_WIDTH, ARROW_IMG_HEIGHT, GxEPD_BLACK);
  else display.drawExampleBitmap(noArrow, 229,  DISPLAY_MAX_HEIGHT / 4 - 15, ARROW_IMG_WIDTH, ARROW_IMG_HEIGHT, GxEPD_BLACK);
  display.update();


}



void E_PAPER::updateDisplay(String date, int newCasesIS , int newCasesRO)
{

  Serial.println("updateDisplay1");
  display.setFont(&BIGGER_FONT);
  displayTextNew(String(newCasesIS), 127, display.height() / 4 + 6);      //IS
  Serial.println("updateDisplay2");
  displayTextNew(String(newCasesRO), 120, 3 * display.height() / 4 + 10); //RO
  Serial.println("updateDisplay3");
  String dateString;
  dateString += date[8];
  dateString += date[9];
  dateString += '.';
  dateString += date[5];
  dateString += date[6];
  dateString += '.';
  dateString += date[0];
  dateString += date[1];
  dateString += date[2];
  dateString += date[3];
  Serial.println(dateString);
  //  date[8]+date[9]+"."+date[5]+date[6]+"."+date[0]+date[1]+date[2]+date[3];
  display.setFont(&SMALLER_FONT);
  displayTextNew("Updated:", 5, 110);
  //  displayTextNew("23:25", 10, 110);
  displayTextNew(dateString, 0, 120);
  Serial.println("updateDisplay4");
//  display.update();
}


void E_PAPER::displayTextNew(const String &str, int16_t x, int16_t y)
{
  //    int16_t x = 0;
  int16_t x1, y1;
  uint16_t w, h;
  display.setCursor(x, y);
  display.getTextBounds(str, x, y, &x1, &y1, &w, &h);
  display.println(str);
}


//After partial update i can still see the old number in a grey-ish color
//void showPartialUpdateIasi()
//{
//  Serial.println("Updating display ...");
//
//  uint16_t box_x = 57;
//  uint16_t box_y = 0;
//  uint16_t box_w = 193;
//  uint16_t box_h = 100;
//  uint16_t cursor_y = box_y + 16;
//
//  display.setFont(&BIGGER_FONT);
//  display.setTextColor(GxEPD_BLACK);
//
////  display.fillRect(box_x, box_y, box_w, box_h, GxEPD_BLACK);
//
//  display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
//  delay(100);
//  display.setCursor(box_x, cursor_y+38);
//  display.print("9876");
//  display.updateWindow(box_x, box_y, box_w, box_h, true);
//}
void E_PAPER::displayInit()
{
  display.init();
  display.setRotation(1);
  display.eraseDisplay();
  display.setTextColor(GxEPD_BLACK);
  display.setFont(&BIGGER_FONT);
  display.setTextSize(0);
}

void E_PAPER::layoutInit()
{
  uint16_t x = 0;
  uint16_t y = (DISPLAY_MAX_HEIGHT - CORONA_IMG_WIDTH) / 2;

  display.fillScreen(GxEPD_WHITE);

  //draw corona logo
  display.drawExampleBitmap(corona, x, y, CORONA_IMG_WIDTH, CORONA_IMG_HEIGHT, GxEPD_BLACK);


  //Vertical Line
  display.drawLine(CORONA_IMG_WIDTH + 3, DISPLAY_MIN_HEIGHT, CORONA_IMG_WIDTH + 3, DISPLAY_MAX_HEIGHT, GxEPD_BLACK);
  display.drawLine(CORONA_IMG_WIDTH + 4, DISPLAY_MIN_HEIGHT, CORONA_IMG_WIDTH + 4, DISPLAY_MAX_HEIGHT, GxEPD_BLACK);
  display.drawLine(CORONA_IMG_WIDTH + 5, DISPLAY_MIN_HEIGHT, CORONA_IMG_WIDTH + 5, DISPLAY_MAX_HEIGHT, GxEPD_BLACK);

  //Horizontal line
  display.drawLine(CORONA_IMG_WIDTH + 5, DISPLAY_MAX_HEIGHT / 2 - 1, DISPLAY_MAX_WIDTH, DISPLAY_MAX_HEIGHT / 2 - 1, GxEPD_BLACK);
  display.drawLine(CORONA_IMG_WIDTH + 5, DISPLAY_MAX_HEIGHT / 2, DISPLAY_MAX_WIDTH, DISPLAY_MAX_HEIGHT / 2, GxEPD_BLACK);
  display.drawLine(CORONA_IMG_WIDTH + 5, DISPLAY_MAX_HEIGHT / 2 + 1, DISPLAY_MAX_WIDTH, DISPLAY_MAX_HEIGHT / 2 + 1, GxEPD_BLACK);

  display.setFont(&BIGGER_FONT);
  displayTextNew("IS: ", CORONA_IMG_WIDTH + 7, DISPLAY_MAX_HEIGHT / 4 + 6);
  displayTextNew("RO:", CORONA_IMG_WIDTH + 7, 3 * display.height() / 4 + 10);
  //
  //     display.setFont(&MASSIVE_FONT);
  //     displayTextNew(casesIs , 127 , display.height() / 4 + 6 ); //IS
  //     displayTextNew(casesRo , 120 , 3 * display.height() / 4 + 10 ); //RO

//  display.update();
//  delay(500);
}

void E_PAPER::updateDisplayData()
{
  display.setFont(&BIGGER_FONT);
  displayTextNew(casesIs, 127, display.height() / 4 + 6);      //IS
  displayTextNew(casesRo, 120, 3 * display.height() / 4 + 10); //RO

  display.setFont(&SMALLER_FONT);
  displayTextNew("Updated:", 5, 100);
  displayTextNew("23:25", 10, 110);
  displayTextNew("15.02.2020", 0, 120);
}

