/*
 * File:   optoCoupleur.c
 * Author: tmazery
 *
 * Created on May 9, 2018, 11:00 AM
 */


#include <xc.h>
#include <stdio.h>

#include "optoCoupleur.h"
#include "../ScreenDriver/screenDriver.h"
#include "../mcc_generated_files/mcc.h"

unsigned char flagStartADC = 0;
unsigned char flagButtonPressed = 0;

uint8_t compteurPulseMinute[60]; // contains 60 sec
uint8_t compteurPulseHeure[60];  // contains 60 min
uint8_t compteurPulseJour[24];   // contains 24 hours

optoCoupleurState_t optoCoupleurState;

void flagConvertion()
{
    flagStartADC = 0x01;
}

void flagButton()
{
	flagButtonPressed = 0x01;
}

void initSeuils()
{
	static uint8_t initStarted = 0;
	static uint16_t min = 0xFFFFF;
	static uint16_t max = 0;
	uint8_t str[18];
	uint8_t temp;

	if(initStarted == 0x00)
	{
		TMR1_RegisterTimer(TIMER1_ADC);
		initStarted = 0x01;
		min = 0xFFFFF;
		max = 0x00;
		for(temp = 0; temp < 60; temp++)
		{
			compteurPulseMinute[temp] = 0;
			compteurPulseHeure[temp] = 0;			
		}
		for(temp = 0; temp < 24; temp++)
		{
			compteurPulseJour[temp] = 0;
		}

		drawFont(0, 5, "Releve compteur", 15);
	    drawFont(0, 20, "Initialisation ...", 18);
	    drawFont(0, 70, "Appuyer sur start", 17);
	    drawFont(0, 80, "pour lancer le log", 18);
	}
	else
	{
		if(flagStartADC == 0x01)
		{
			flagStartADC = 0x00;
			uint16_t result = ADCC_GetSingleConversion(OPTO_INPUT);

			if(min > result)
			{
				min = result;
				sprintf(str, "min : %d   ", result);
				drawFont(3, 120, str, 9);
			}
			if(max < result)
			{
				max = result;
				sprintf(str, "max : %d   ", result);
				drawFont(3, 130, str, 10);
			}

			sprintf(str, "direct : %d   ", result);
			drawFont(3, 140, str, 14);

			if(flagButtonPressed == 0x01)
			{
				flagButtonPressed = 0x00;
				optoCoupleurState = MEASURING;
				initStarted = 0x00;
				fillAllScreen(WHITE_PIXEL);
                sprintf(str, "Dern 1/4h- 1h - 6h");
				drawFont(0, 100, str, 18);
			}
		}
	}
}

void updateTime(Time_t *time)
{
	uint8_t str[18];

	if(time->milliseconde == TIMER1_1SEC)
	{
		time->milliseconde = 0;
		time->seconds++;
		if(time->seconds == 60)
		{
			time->seconds = 0;
			time->minutes++;
			if(time->minutes == 60)
			{
				time->minutes = 0;
				time->hours++;
				if(time->hours == 24)
				{
					time->hours++;
					time->days++;
					if(time->days == 31)
					{
						time->days = 0;
					}
				}
			}
		}
		sprintf(str, "%d:%d:%d:%d     ", time->days, time->hours, time->minutes, time->seconds);
		drawFont(0, 10, str, 10);
	} 
}

void measuring()
{
	static uint16_t history[MAX_HISTORY_BUFFER];
	static uint8_t indexHistory = 0;
	static uint8_t justUpdated = 0;

	static Time_t time;

	uint8_t compteurPulse15min;
	uint8_t compteurPulse60min;

	uint8_t str[25];

	uint8_t indexBuffer;
	uint32_t average = 0;
	uint8_t i = 0;
	uint16_t index = 0;
	uint8_t temp = 0;

	if(flagStartADC == 0x01)
	{
		flagStartADC = 0x00;
		time.milliseconde++;
		
		updateTime(&time);

		history[indexHistory] = ADCC_GetSingleConversion(OPTO_INPUT);

		for(indexBuffer = 0; indexBuffer < MAX_HISTORY_BUFFER; indexBuffer++)
		{
			average += history[indexBuffer];
		}
		average /= MAX_HISTORY_BUFFER;

		//drawFont(3, 120, "Measuring", 9);
		//sprintf(str, "avg : %d", average);
		//drawFont(3, 130, str, 10);

		if((history[indexHistory] > average) && ((history[indexHistory] - average) > SEUIL_DETECTION))
		{
			if(justUpdated == 0x00)
			{
				compteurPulseMinute[time.minutes]++;
				compteurPulseHeure[time.hours]++;
				compteurPulseJour[time.days]++;

				compteurPulse15min = 0;
				for(index = 0; index < 15; index++)
				{
					temp = time.minutes - index;
					if(time.minutes < index)
					{
						temp = time.minutes + 60 - index;
					}
					compteurPulse15min += compteurPulseMinute[temp];
				}
				compteurPulse60min = 0;
				for(index = 0; index < 24; index++)
				{
					temp = time.hours - index;
					if(time.minutes < index)
					{
						temp = time.hours + 24 - index;
					}
					compteurPulse60min += compteurPulseHeure[index];
				}

				sprintf(str, "    %d   %d   %d  ", compteurPulse15min, compteurPulseHeure[time.hours], compteurPulse60min);
				drawFont(0, 110, str, 18);
			}
			justUpdated = 1;
		}
		else
		{
			justUpdated = 0;
		}

		indexHistory = (indexHistory + 1) % MAX_HISTORY_BUFFER;

		if(flagButtonPressed == 0x01)
		{
			flagButtonPressed = 0x00;
			optoCoupleurState = INITIALISATION;
			fillAllScreen(WHITE_PIXEL);
		}
	}
}

void manageOptoCoupleur()
{
	switch(optoCoupleurState)
	{
		case NO_STATE:
			optoCoupleurState = INITIALISATION;
			break;
		case INITIALISATION:
    		initSeuils();
			break;
		case MEASURING:
			measuring();
			break;
		default:
			optoCoupleurState = INITIALISATION;
		break;
	}
}