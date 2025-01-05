/*
 * Codeuse.h
 *
 *  Created on: Jan 4, 2025
 *      Author: Loubet Gregory
 */

#ifndef FONCTION_SUP_CAPTEURS_CODEUSE_H_
#define FONCTION_SUP_CAPTEURS_CODEUSE_H_

#include "main.h"
#include "stm32f4xx_hal.h"


/** LES DEFINE RELATIF AU CODEUSE */
#define GAIN_CODEUSE 275
#define NOMBRE_CODEUSE 2


extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

/** LES FONCTIONS  */
void Initialisation_Codeuse();
void Update_Codeuse(int i, TIM_HandleTypeDef *htim);



#endif /* FONCTION_SUP_CAPTEURS_CODEUSE_H_ */
