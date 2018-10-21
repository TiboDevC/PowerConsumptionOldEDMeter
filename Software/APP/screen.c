/*
 * File:   screen.c
 * Author: TiboDevC
 *
 * Created on May 9, 2018, 10:06 AM
 */


#include <xc.h>
#include <stdio.h>

#include "../ScreenDriver/screenDriver.h"
#include "screen.h"

unsigned char flagInterrupt;

void updateScreen()
{
	flagInterrupt = 0x01;
}

void displayScreen()
{
	if(flagInterrupt == 0x01)
	{
		flagInterrupt = 0x00;
		unsigned char str[10];
	    static unsigned char compteur = 0;
	    
	    sprintf(str, "%d", compteur);

	    drawFont(3, 70, str, 3);
	    compteur++;
	    compteur %=999;
	}
}
