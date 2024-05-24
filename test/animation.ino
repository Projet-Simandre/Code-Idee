#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET 0x3C
Adafruit_SSD1306 display(128, 64, &Wire, -1);

const unsigned char perso [] PROGMEM = {
	 
// 'Capture d’écran 2024-02-01 à 10', 128x64px
  0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x1f, 0xf0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0x8f, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xc4, 0x01, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xe0, 0x7d, 0xff, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xfe, 0x7e, 0xff, 0xf8, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0x3f, 0x7f, 0xfc, 0x7e, 0x00, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0x3f, 0xbf, 0xe0, 0x3c, 0xfc, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0x3f, 0xdf, 0x9f, 0x1c, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xff, 0x3f, 0xdf, 0x3f, 0x8c, 0xff, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0x3f, 0xde, 0xff, 0xcc, 0xff, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0x0f, 0xdc, 0xff, 0x80, 0xff, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xc7, 0x9d, 0xff, 0x00, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xf7, 0x3d, 0xc0, 0x3d, 0xfc, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x8f, 0xf1, 0xff, 0xf3, 0x7d, 0x80, 0x7f, 0xfc, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xc7, 0xe0, 0xff, 0xf2, 0xfd, 0x9f, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x06, 0x33, 0xf2, 0xf9, 0x9f, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0x01, 0xe2, 0xf3, 0xcf, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfc, 0x6f, 0xf8, 0x06, 0x67, 0xe0, 0x3e, 0x3f, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfc, 0xef, 0xfc, 0x0f, 0x67, 0xf9, 0x80, 0x3e, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0x27, 0xff, 0xc1, 0x8c, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x07, 0xff, 0xff, 0x27, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf3, 0xf3, 0xff, 0xff, 0x37, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0xf3, 0x87, 0xff, 0x73, 0xf0, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf3, 0xc6, 0x01, 0xfe, 0x7b, 0xc0, 0x37, 0xf3, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x0e, 0x00, 0xfc, 0xf3, 0x80, 0x33, 0xf3, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x6f, 0xf8, 0x79, 0xe7, 0x0f, 0xf8, 0x07, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf9, 0xe7, 0xfe, 0x33, 0xce, 0x3f, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf9, 0xf3, 0xff, 0x37, 0x9e, 0x7f, 0xe7, 0xe7, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf9, 0xf8, 0xff, 0xb7, 0x9f, 0xff, 0xce, 0x07, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x06, 0x7f, 0x77, 0x9f, 0xff, 0xd8, 0x07, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x67, 0x3f, 0xd7, 0x9f, 0xcf, 0x9b, 0xf3, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf9, 0xe7, 0x0f, 0x77, 0xc0, 0x00, 0x39, 0xf9, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf3, 0xef, 0xc7, 0xf7, 0xf0, 0xf8, 0x7c, 0xfd, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0xcf, 0xf7, 0xf7, 0xff, 0xff, 0xfe, 0x39, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0x9f, 0xf3, 0xf0, 0x00, 0xff, 0x07, 0x83, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xf7, 0xc0, 0x00, 0x7e, 0x73, 0x8f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xef, 0x80, 0x00, 0x3e, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xcf, 0x00, 0x00, 0x3c, 0xf0, 0x03, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0x1f, 0x00, 0x00, 0x39, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0x7e, 0x00, 0xc0, 0x33, 0xcf, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0x3e, 0x7e, 0x01, 0xc0, 0x27, 0xcf, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x1e, 0xfe, 0x03, 0xe0, 0x2f, 0xcf, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xfe, 0x03, 0xe0, 0x2f, 0xcf, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x7f, 0x03, 0xe0, 0x6f, 0xc7, 0xfc, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0x7e, 0x7f, 0x83, 0xe0, 0xe7, 0x87, 0xf8, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0x3f, 0xe3, 0xf3, 0xf3, 0x1f, 0xf1, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0x3f, 0xf7, 0xf3, 0xf8, 0x3f, 0xf3, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0x3f, 0xe7, 0xf3, 0xff, 0x3f, 0xf9, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xe0, 0x7c, 0x3f, 0xe7, 0xf9, 0xff, 0x1f, 0xf9, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xc7, 0xf8, 0x1f, 0x87, 0xf9, 0xfe, 0x00, 0xf9, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xcf, 0xf8, 0x84, 0x07, 0xf8, 0x7c, 0x00, 0xf9, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x8f, 0xf9, 0xc0, 0x0f, 0xfc, 0x10, 0xf4, 0x63, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x1f, 0xf9, 0xf1, 0xff, 0xff, 0x83, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfe, 0x3f, 0xf1, 0xf9, 0xff, 0xff, 0xcf, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfe, 0x7f, 0x03, 0xf9, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfe, 0x7e, 0x07, 0xfc, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x3e, 0x7f, 0xfc, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xf9, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xef, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x07, 0xc7, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x23, 0x80, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 28128)
const int epd_bitmap_allArray_LEN = 1;



const unsigned char perso2 [] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x1f, 0xf0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0x8f, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xc4, 0x01, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xe0, 0x7d, 0xff, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xfe, 0x7e, 0xff, 0xf8, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0x3f, 0x7f, 0xfc, 0x7e, 0x00, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0x3f, 0xbf, 0xe0, 0x3c, 0xfc, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0x3f, 0xdf, 0x9f, 0x1c, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xff, 0x3f, 0xdf, 0x3f, 0x8c, 0xff, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x3f, 0xde, 0xff, 0xcc, 0xff, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0x0f, 0xdc, 0xff, 0x80, 0xff, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xc7, 0x9d, 0xff, 0x00, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xf7, 0x3d, 0xc0, 0x3d, 0xfc, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x8f, 0xf1, 0xff, 0xf3, 0x7d, 0x80, 0x7f, 0xfc, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xc7, 0xe0, 0xff, 0xf2, 0xfd, 0x9f, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x06, 0x33, 0xf2, 0xf9, 0x9f, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0x01, 0xe2, 0xf3, 0xcf, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfc, 0x6f, 0xf8, 0x06, 0x77, 0xe0, 0x3e, 0x3f, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfc, 0xef, 0xfc, 0x0f, 0x67, 0xf9, 0x80, 0x3e, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0x27, 0xff, 0xc1, 0x8c, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x07, 0xff, 0xff, 0x27, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf3, 0xf3, 0xff, 0xff, 0x37, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0xf2, 0xff, 0xff, 0x73, 0xff, 0xb0, 0x07, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0xc6, 0x7f, 0xfe, 0x7b, 0xff, 0x37, 0xf3, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x0e, 0x3f, 0xfc, 0xf3, 0xfe, 0x33, 0xf3, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x6f, 0x0e, 0x39, 0xe6, 0x78, 0x78, 0x07, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf9, 0xe7, 0x80, 0x33, 0xce, 0x00, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf9, 0xf3, 0xc0, 0x77, 0x9f, 0x01, 0xe7, 0xe7, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf9, 0xf8, 0xff, 0xf7, 0x9f, 0xff, 0xce, 0x07, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x06, 0x7f, 0xf7, 0x9f, 0xff, 0xd8, 0x07, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x67, 0x3f, 0xf7, 0x9f, 0xcf, 0x99, 0xf3, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf9, 0xe7, 0x0f, 0xf7, 0xc0, 0x00, 0x39, 0xf9, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf3, 0xef, 0xc7, 0xf7, 0xf0, 0xf8, 0x7c, 0xfd, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0xcf, 0xf7, 0xf7, 0xff, 0xff, 0xfe, 0x39, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0x9f, 0xf3, 0xf0, 0x00, 0xff, 0x07, 0x83, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xf7, 0xc0, 0x00, 0x7e, 0x73, 0x8f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xef, 0x80, 0x00, 0x3e, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xcf, 0x00, 0x00, 0x3c, 0xf0, 0x03, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0x1f, 0x00, 0x00, 0x39, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0x7e, 0x00, 0xc0, 0x33, 0xcf, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0x3e, 0x7e, 0x01, 0xc0, 0x27, 0xcf, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x1e, 0xfe, 0x03, 0xe0, 0x2f, 0xcf, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xfe, 0x03, 0xe0, 0x2f, 0xcf, 0xfe, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x7f, 0x03, 0xe0, 0x6f, 0xc7, 0xfc, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0x7e, 0x7f, 0x83, 0xe0, 0xe7, 0x87, 0xf8, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0x3f, 0xe3, 0xf3, 0xf3, 0x1f, 0xf1, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0x3f, 0xf7, 0xf3, 0xf8, 0x3f, 0xf3, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0x3f, 0xe7, 0xf3, 0xff, 0x3f, 0xf9, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xe0, 0x7c, 0x3f, 0xe7, 0xf9, 0xff, 0x1f, 0xf9, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xc7, 0xf8, 0x1f, 0x87, 0xf9, 0xfe, 0x00, 0xf9, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xcf, 0xf8, 0x84, 0x07, 0xf8, 0x7c, 0x00, 0xf9, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x8f, 0xf9, 0xc0, 0x0f, 0xfc, 0x10, 0xf4, 0x63, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x1f, 0xf9, 0xf1, 0xff, 0xff, 0x83, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfe, 0x3f, 0xf1, 0xf9, 0xff, 0xff, 0xcf, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfe, 0x7f, 0x03, 0xf9, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfe, 0x7e, 0x07, 0xfc, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x3e, 0x7f, 0xfc, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xf9, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xef, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x07, 0xc7, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x23, 0x80, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

const unsigned char* epd_bitmap_allArray[2] = {
  perso,
perso2
};


void setup()   {                
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}


void loop() {
 display.clearDisplay();
  display.drawBitmap(0, 0, perso, 128, 64, WHITE);
  display.display();
  delay(100);
  display.clearDisplay();
  display.drawBitmap(0, 0, perso2, 128, 64, WHITE);
  display.display();
  delay(100);
}