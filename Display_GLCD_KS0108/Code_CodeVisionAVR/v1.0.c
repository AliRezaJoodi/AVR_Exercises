/****************************************************************
    Title               :   Samsung KS0108 128x64 Graphic LCD controller demo
    Last Updated        :   2016/07/02
    Micro Contoroler    :   ATMega32A
    Clock frequency     :   8.000000 MHz
    Compiler            :   Code Vision AVR V3.12
    Author              : 
    Mobile              : 
    Email               :   
    Websit              :   http://www.hpinfotech.com
    Connections(LCD-AVR):
                            DB0     - PORTB.0
                            DB1     - PORTB.1
                            DB2     - PORTB.2
                            DB3     - PORTB.3
                            DB4     - PORTB.4
                            DB5     - PORTB.5
                            DB6     - PORTB.6
                            DB7     - PORTB.7

                            E       - PORTD.5
                            R/W     - PORTD.6
                            RS      - PORTD.2
                            RESET   - PORTD.3
                            CS1     - PORTD.4
                            CS2     - PORTD.3
**********************************************************/
// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <glcd.h>
#include <delay.h>

/* Include some fonts needed by the demo */
#include <font5x7.h>
#include "Attachment\Fonts\arial14.h"
#include "Attachment\Fonts\arial_bold14.h"
#include "Attachment\Fonts\courier7x14.h"
#include "Attachment\Fonts\courier_bold14.h"
#include "Attachment\Fonts\script19.h"
#include "Attachment\Pictures\Picture1.h"

/* Small dots filling pattern */
flash unsigned char small_dots[]={0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55};

/* EEPROM buffer used for image storage */
eeprom unsigned char buffer[1000];

/* Hexagon point coordinates
   The last point's coordinates must match
   the first point coordinates,
   so that the polygon will be closed */
flash GLCDPOINT_t hexagon[7]={
{40,0},
{57,10},
{57,30},
{40,40},
{23,30},
{23,10},
{40,0}
};


void main(){
GLCDINIT_t init;

/* Set current font */
init.font=font5x7;
/* No need for reading data from external memory */
init.readxmem=NULL;

/* No need for reading data from external memory */ 
init.writexmem=NULL;

/* Initialize the LCD controller and graphics */
glcd_init(&init); 

glcd_putimagef(0,0,Picture1,GLCD_PUTCOPY);
delay_ms(1000); glcd_clear();
 
glcd_outtextf("KS0108 Graphics Demo\nFont samples:"); // Display literal char string located in FLASH
glcd_outtextxyf(0,20,"Standard 5x7");
glcd_setfont(arial14); glcd_outtextxyf(0,30,"Arial 14\n");
glcd_setfont(arial_bold14); glcd_outtextf("Arial Bold 14");
delay_ms(1000); glcd_clear(); // Clear display

glcd_setfont(courier7x14); glcd_outtextf("Courier 7x14\n");
glcd_setfont(courier_bold14); glcd_outtextf("Courier Bold 14");
glcd_setfont(script19); glcd_outtextxyf(0,30,"Script 19");
delay_ms(1000); glcd_clear();

glcd_setfont(font5x7); glcd_outtextf("Var. text spacing:\n");
glcd_setfont(courier_bold14); glcd_outtextf("KS0108 Demo\n");
/* Set horizontal justification: 2 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(2,1); glcd_outtextf("KS0108 Demo\n");
/* Set horizontal justification: 3 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(3,1); glcd_outtextf("KS0108 Demo");
delay_ms(1000); glcd_clear();

/* Set horizontal justification: 1 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(1,1); glcd_setfont(font5x7); glcd_outtextf("Some line styles:");
/* Draw various styles of lines */
glcd_line(0,10,127,10);
/* Line thickness: 1 pixel */
glcd_setlinestyle(1,GLCD_LINE_DOT_SMALL); glcd_line(0,15,127,15);
glcd_setlinestyle(1,GLCD_LINE_DOT_LARGE); glcd_line(0,20,127,20);
/* Line thickness: 2 pixels */
glcd_setlinestyle(2,GLCD_LINE_SOLID); glcd_line(0,25,127,25);
glcd_setlinestyle(2,GLCD_LINE_DOT_SMALL); glcd_line(0,30,127,30);
glcd_setlinestyle(2,GLCD_LINE_DOT_LARGE); glcd_line(0,35,127,35);
/* Line thickness: 4 pixels */
glcd_setlinestyle(4,GLCD_LINE_SOLID); glcd_line(0,40,127,40);
glcd_setlinestyle(4,GLCD_LINE_DOT_SMALL); glcd_line(0,45,127,45);
glcd_setlinestyle(4,GLCD_LINE_DOT_LARGE); glcd_line(0,50,127,50);
delay_ms(1000); glcd_clear();

/* Draw a hexagon with line thickness: 1 pixel */
glcd_setlinestyle(1,GLCD_LINE_SOLID); glcd_drawpoly(7,hexagon);
delay_ms(1000);
/* Fill the hexagon with solid fill */
glcd_floodfill(48,24,1);

/* Write a text inside the filled hexagon in
   reversed colors */
glcd_setcolor(0);
glcd_setbkcolor(1);
glcd_outtextxyf(30,17,"Fill");

/* Save hexagon image in EEPROM */
glcd_getimagee(22,0,37,41,buffer);
/* Restore the default foreground
   and background colors */
glcd_setcolor(1);
glcd_setbkcolor(0);
glcd_outtextxyf(0,47,"Image was saved to\nEEPROM");

delay_ms(1000); glcd_clear();

/* Draw a circle with line thickness: 1 pixel */
glcd_circle(21,23,20);

/* Draw an arc of a circle with line thickness: 1 pixel */
glcd_arc(21,23,0,120,15);

/* Draw a circle with line thickness: 3 pixels */
glcd_setlinestyle(3,GLCD_LINE_SOLID);
glcd_circle(63,23,20);

/* Draw an arc of a circle with line thickness: 3 pixels */
glcd_arc(63,23,0,210,15);

glcd_outtextxyf(0,47,"Circles & arcs");

delay_ms(1000); glcd_clear();

/* Draw a rectangle with line thickness: 1 pixel 
   and solid line */
glcd_setlinestyle(1,GLCD_LINE_SOLID);
glcd_rectrel(0,0,40,25);

/* Draw a rectangle with line thickness: 3 pixel
   and dotted line */
glcd_setlinestyle(3,GLCD_LINE_DOT_LARGE);
glcd_rectrel(42,0,40,25);

/* Draw a bar filled with a pattern */
glcd_setfillf(small_dots,1);
glcd_bar(14,29,70,44);

glcd_outtextxyf(0,47,"Rectangles &\nfilled bar");

delay_ms(1000); glcd_clear();

/* Draw rounded rectangle */
glcd_rectround(5,5,74,38,8);
glcd_outtextxyf(16,16,"Rounded");
glcd_outtextxyf(16,24,"rectangle");

delay_ms(1000); glcd_clear();

/* Set line thickness: 1 pixel */
glcd_setlinestyle(1,GLCD_LINE_SOLID);

/* Draw filled pie slice */
glcd_outtextf("Pie\nslice:");
glcd_pieslice(60,23,30,300,20);

delay_ms(1000); glcd_clear();

glcd_outtextf("Put\nimage\nfrom\nEEPROM:");
/* Display image saved in EEPROM */
glcd_putimagee(56,0,buffer,GLCD_PUTCOPY);

delay_ms(1000); glcd_clear();

glcd_outtextf("Put\ninverted\nimage\nfrom\nEEPROM:");
/* Display image saved in EEPROM,
   using bitwise negation */
glcd_putimagee(56,0,buffer,GLCD_PUTNOT);
}
