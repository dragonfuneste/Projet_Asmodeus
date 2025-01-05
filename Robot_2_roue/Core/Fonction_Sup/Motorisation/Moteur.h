/*
 * Moteur.h
 *
 *  Created on: Apr 26, 2024
 *      Author: Loubet Gregory
 */

#ifndef INC_MOTEUR_H_
#define INC_MOTEUR_H_
#include "main.h"
#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim1;


#define NOMBRE_MOTEUR 2

void Initialisation_Moteur( TIM_HandleTypeDef* timer);
void ControleMoteur(uint8_t sens,uint8_t no_moteur);
void ControleVitesse(int16_t Vitesse_Corrige,uint8_t no_moteur);

#define SENS_1 	0
#define SENS_2 	1
#define STOP 	2

#endif /* INC_MOTEUR_H_ */
