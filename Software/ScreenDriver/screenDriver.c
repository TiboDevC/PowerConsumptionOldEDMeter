
/*
 * File:   screenDriver.c
 * Author: TiboDevC
 *
 * Created on May 8, 2018, 12:30 PM
 */


#include <xc.h>
#include "../mcc_generated_files/mcc.h"
#include "screenDriver.h"

void initScreen()
{
    SPI1_Start();
	LATC = 0x20;
	SPI1_Exchange8bit(CLEAR_SCREEN);    
    SPI1_Exchange8bit(END_COM);
    SPI1_Exchange8bit(END_COM);
    LATC = 0x00;
    SPI1_Stop();
}

void drawOneLine(uint8_t lines, uint8_t data)
{
    SPI1_Start();
    SCS_PIN = 1;
    unsigned char lineBis = 0;
    lineBis |= (uint8_t) (lines & 0x01) << 7;
    lineBis |= (uint8_t) (lines & 0x02) << 5;
    lineBis |= (uint8_t) (lines & 0x04) << 3;
    lineBis |= (uint8_t) (lines & 0x08) << 1;
    lineBis |= (uint8_t) (lines & 0x10) >> 1;
    lineBis |= (uint8_t) (lines & 0x20) >> 3;
    lineBis |= (uint8_t) (lines & 0x40) >> 5;
    lineBis |= (uint8_t) (lines & 0x80) >> 7;

    SPI1_Exchange8bit(WRITE_BIT);
    SPI1_Exchange8bit(lineBis);
    SPI1_Exchange8bit(data);
    SPI1_Exchange8bit(END_COM);
    
    SPI1_Exchange8bit(END_COM);
    SCS_PIN = 0;
    SPI1_Stop();
}

void fillAllScreen(unsigned char color)
{
	int lines, lineBis, i;
    SPI1_Start();
    SCS_PIN = 1;

    SPI1_Exchange8bit(WRITE_BIT);

    for(lines = 0; lines < 169; lines ++)
    {
        lineBis = 0;
        lineBis |= (lines & 0x01) << 7;
        lineBis |= (lines & 0x02) << 5;
        lineBis |= (lines & 0x04) << 3;
        lineBis |= (lines & 0x08) << 1;
        lineBis |= (lines & 0x10) >> 1;
        lineBis |= (lines & 0x20) >> 3;
        lineBis |= (lines & 0x40) >> 5;
        lineBis |= (lines & 0x80) >> 7;
        SPI1_Exchange8bit(lineBis);
        for(i = 0; i < 18; i++)
        {
            SPI1_Exchange8bit(color);
        }
        SPI1_Exchange8bit(END_COM);
    }

    SPI1_Exchange8bit(END_COM);

    SPI1_Exchange8bit(END_COM);
    SCS_PIN = 0;
    SPI1_Stop();
}

void drawFont(const uint8_t x, const uint8_t y, const uint8_t toPrint[], const uint8_t toPrintSize)
{
    SPI1_Start();
    SCS_PIN = 1;
    uint8_t colonne = 0;
    uint8_t lineBis = 0;
    uint8_t lines = 0;
    uint8_t data = 0;

    SPI1_Exchange8bit(WRITE_BIT);

    for(lines = y; lines < (y + 0x08); lines++)
    {
        lineBis = 0;
        lineBis |= (uint8_t) (lines & 0x01) << 7;
        lineBis |= (uint8_t) (lines & 0x02) << 5;
        lineBis |= (uint8_t) (lines & 0x04) << 3;
        lineBis |= (uint8_t) (lines & 0x08) << 1;
        lineBis |= (uint8_t) (lines & 0x10) >> 1;
        lineBis |= (uint8_t) (lines & 0x20) >> 3;
        lineBis |= (uint8_t) (lines & 0x40) >> 5;
        lineBis |= (uint8_t) (lines & 0x80) >> 7;
	    SPI1_Exchange8bit(lineBis);
	    for(colonne = 0; colonne < 18; colonne++)
	    {   	
		    if((x <= colonne) && ((colonne - x) < toPrintSize) && ((toPrint[colonne - x] >= ' ') && (toPrint[colonne - x] <= 'z')))
		    {
		    	data = ~font[(toPrint[colonne - x] - ' ') * 0x08 + (lines - y)];
		    }
		    else
		    {
		    	data = WHITE_PIXEL;
		    }
		    SPI1_Exchange8bit(data);
	    }
	    SPI1_Exchange8bit(END_COM);
    }
    
    SPI1_Exchange8bit(END_COM);
    SPI1_Stop();
}

void drawPixel(unsigned char x, unsigned char y, unsigned char color)
{
	if(MAX_WIDTH >= x && MAX_HEIGHT >= y)
	{
		return;
	}
}