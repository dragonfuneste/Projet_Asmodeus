/*
 * Codeuse.c
 *
 *  Created on: Jan 4, 2025
 *      Author: Loubet Gregory
 */

#include "Codeuse.h"

int valeur_precedent [NOMBRE_CODEUSE]  = {0} ;
int valeur_actuelle  [NOMBRE_CODEUSE]  = {0} ;
int delta_position   [NOMBRE_CODEUSE]  = {0} ;


void Initialisation_Codeuse()
{
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
}



void Update_Codeuse(int i, TIM_HandleTypeDef *htim)
{
	valeur_actuelle[i] = __HAL_TIM_GET_COUNTER(htim);
	delta_position[i] =  valeur_actuelle[i] - valeur_precedent[i];
    valeur_precedent[i]= valeur_actuelle[i];
}


