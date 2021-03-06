#ifndef IMAGE_H_
#define IMAGE_H_

#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif
//https://javl.github.io/image2cpp/
//64x64
const unsigned char corona[] PROGMEM = {0xff, 0xfe, 0x3f, 0xff, 0x0f, 0xff, 0xc0, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xc0, 0xff, 0xf8, 
  0x3f, 0xff, 0x07, 0xff, 0xc0, 0xff, 0xf8, 0x7f, 0xff, 0x87, 0xff, 0xc0, 0xff, 0xfe, 0x7f, 0xff, 
  0x9f, 0xff, 0xc0, 0xff, 0xff, 0x3f, 0x1f, 0x3f, 0xff, 0xc0, 0xff, 0xff, 0x3e, 0x1f, 0x3f, 0xff, 
  0xc0, 0xff, 0xff, 0x9f, 0x3e, 0x7f, 0xff, 0xc0, 0xff, 0xff, 0x9f, 0x3e, 0x7f, 0xff, 0xc0, 0xff, 
  0xff, 0x80, 0x00, 0x7f, 0xff, 0xc0, 0xff, 0xe7, 0x80, 0x00, 0x79, 0xff, 0xc0, 0xff, 0xc6, 0x00, 
  0x00, 0x30, 0xff, 0xc0, 0xff, 0xc4, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x8f, 0xc0, 0x00, 0x00, 0x03, 
  0xfc, 0x40, 0x8f, 0xf0, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x03, 0xf8, 0x00, 
  0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0xfe, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0xc0, 0xff, 0x80, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0xff, 0x80, 0x00, 0x00, 
  0x00, 0x7f, 0xc0, 0xff, 0x80, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0xff, 0x80, 0x00, 0x00, 0x00, 0x7f, 
  0xc0, 0xf9, 0x00, 0x00, 0x00, 0x00, 0x6f, 0xc0, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x47, 0xc0, 0xf8, 
  0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0xf9, 0x00, 0x00, 0x00, 0x00, 0x47, 0xc0, 0xff, 0x00, 0x00, 
  0x00, 0x00, 0x7f, 0xc0, 0xff, 0x80, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0xff, 0x80, 0x00, 0x00, 0x00, 
  0x7f, 0xc0, 0xff, 0x80, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc0, 
  0x18, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x07, 0xe0, 
  0x00, 0x00, 0x01, 0xf8, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x03, 0xfc, 0x40, 0x8f, 0xf0, 0x00, 0x00, 
  0x03, 0xfc, 0x40, 0xff, 0xc0, 0x00, 0x00, 0x00, 0xff, 0xc0, 0xff, 0xc2, 0x00, 0x00, 0x10, 0xff, 
  0xc0, 0xff, 0xe7, 0x80, 0x00, 0x79, 0xff, 0xc0, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xc0, 0xff, 
  0xff, 0x9c, 0x1e, 0x7f, 0xff, 0xc0, 0xff, 0xff, 0x9f, 0x3e, 0x7f, 0xff, 0xc0, 0xff, 0xff, 0x3e, 
  0x1f, 0x3f, 0xff, 0xc0, 0xff, 0xff, 0x3e, 0x1f, 0x3f, 0xff, 0xc0, 0xff, 0xfe, 0x7f, 0xff, 0x9f, 
  0xff, 0xc0, 0xff, 0xf8, 0x7f, 0xff, 0x87, 0xff, 0xc0, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xc0, 
  0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xc0, 0xff, 0xfe, 0x3f, 0xff, 0x1f, 0xff, 0xc0}
;


//22x22
const unsigned char arrowDown[] PROGMEM = 
{
0xff, 0x87, 0xfc, 0xff, 0x87, 0xfc, 0xff, 0x87, 0xfc, 0xff, 0x87, 0xfc, 0xff, 0x87, 0xfc, 0xff, 
  0x87, 0xfc, 0xff, 0x87, 0xfc, 0xdf, 0x87, 0xec, 0xcf, 0x87, 0xcc, 0xc7, 0x87, 0x8c, 0xc3, 0x87, 
  0x0c, 0xc1, 0x86, 0x0c, 0xc0, 0x84, 0x0c, 0xc0, 0x00, 0x0c, 0xe0, 0x00, 0x1c, 0xf0, 0x00, 0x3c, 
  0xf8, 0x00, 0x7c, 0xfc, 0x01, 0xfc, 0xfe, 0x03, 0xfc, 0xff, 0x07, 0xfc, 0xff, 0x8f, 0xfc, 0xff, 
  0xdf, 0xfc
  };

//22x22
 const unsigned char arrowUp[] PROGMEM = 
{
0xff, 0xef, 0xfc, 0xff, 0xc7, 0xfc, 0xff, 0x83, 0xfc, 0xff, 0x01, 0xfc, 0xfe, 0x00, 0xfc, 0xf8, 
0x00, 0x7c, 0xf0, 0x00, 0x3c, 0xe0, 0x00, 0x1c, 0xc0, 0x00, 0x0c, 0xc0, 0x84, 0x0c, 0xc1, 0x86, 
0x0c, 0xc3, 0x87, 0x0c, 0xc7, 0x87, 0x8c, 0xcf, 0x87, 0xcc, 0xdf, 0x87, 0xec, 0xff, 0x87, 0xfc, 
0xff, 0x87, 0xfc, 0xff, 0x87, 0xfc, 0xff, 0x87, 0xfc, 0xff, 0x87, 0xfc, 0xff, 0x87, 0xfc, 0xff, 
0x87, 0xfc
  };
  
//22x22
const unsigned char noArrow[] PROGMEM = 
{
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff
  };
  


#endif