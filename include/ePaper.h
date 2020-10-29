#ifndef EPAPER_H_
#define EPAPER_H_

#define UP 1
#define DOWN 0
#define NONE 2

//122x250 
#define DISPLAY_MAX_HEIGHT 122 //display.height()
#define DISPLAY_MIN_HEIGHT 0
#define DISPLAY_MAX_WIDTH 250 //display.width()
#define DISPLAY_MIN_WIDTH 0
#define CORONA_IMG_HEIGHT 50
#define CORONA_IMG_WIDTH 50
#define ARROW_IMG_HEIGHT 22
#define ARROW_IMG_WIDTH 22



class E_PAPER
{
private:
    void displayTextNew(const String &str, int16_t x, int16_t y);
    void updateDisplayData();

public:
    E_PAPER();
    void displayInit();
    void layoutInit();
    void updateDisplay(String lastUpdateDate, int newCasesIS, int newCasesRO);
    void drawArrows(int countyArrow, int countryArrow);
};

#endif