/*
 * Programme_Principale.h
 *
 *  Created on: Jan 4, 2025
 *      Author: Loubet Gregory
 */

#ifndef FONCTION_SUP_PROGRAMMEPRINCIPALE_H_
#define FONCTION_SUP_PROGRAMMEPRINCIPALE_H_


#include "Motorisation/Capteurs/Codeuse.h"
#include "Motorisation/Moteur.h"
#include "Communication/UART/UART.h"

extern TIM_HandleTypeDef htim9;


void Initialisation();
void Programme_Principale();


#endif /* FONCTION_SUP_PROGRAMMEPRINCIPALE_H_ */
