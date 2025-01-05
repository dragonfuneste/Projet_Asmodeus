/*
 * Codeuse.c
 *
 *  Created on: Jan 4, 2025
 *      Author: Loubet Gregory
 */

#include "Codeuse.h"

int valeur_precedent [NOMBRE_CODEUSE]  = {0} ;
int valeur_actuelle  [NOMBRE_CODEUSE]  = {0} ;
int codeuse_position   [NOMBRE_CODEUSE]  = {0} ;


void Initialisation_Codeuse()
{
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
}

#define OVERFLOW 65535+1

void Update_Codeuse(int i, TIM_HandleTypeDef *htim)
{
	valeur_actuelle[i] = __HAL_TIM_GET_COUNTER(htim);

    if (__HAL_TIM_IS_TIM_COUNTING_DOWN(htim) && (valeur_actuelle[i] > valeur_precedent[i]))
    {
    	// Overflow en décomptage
    	codeuse_position[i] =  (valeur_actuelle[i]-OVERFLOW) - valeur_precedent[i];
    }
    else
    {
    	if (!__HAL_TIM_IS_TIM_COUNTING_DOWN(htim) &&(valeur_actuelle[i] < valeur_precedent[i]))
    	{
    		//Overflow comptage
    		codeuse_position[i] =  valeur_actuelle[i] - (valeur_precedent[i]-OVERFLOW);
    	}
    	else
    	{
    		codeuse_position[i] =  valeur_actuelle[i] - valeur_precedent[i];
    	}
    }
    valeur_precedent[i]= valeur_actuelle[i];

}


