/* 
 * File:   optoCoupleur.h
 * Author: tmazery
 *
 * Created on May 9, 2018, 11:01 AM
 */

#ifndef OPTOCOUPLEUR_H
#define	OPTOCOUPLEUR_H

#define MAX_HISTORY_BUFFER	100
#define SEUIL_DETECTION		40

#define LED_ON_OFF			LATAbits.LATA7

typedef enum
{
    NO_STATE =  0x0,
    INITIALISATION =  0x01,
    MEASURING =  0x02,
} optoCoupleurState_t;

void manageOptoCoupleur();

void flagConvertion();
void flagButton();

void initSeuils();

#endif	/* OPTOCOUPLEUR_H */

