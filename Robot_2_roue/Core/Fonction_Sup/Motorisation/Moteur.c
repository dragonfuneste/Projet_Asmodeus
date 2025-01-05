/*
 * Moteur.h
 *
 *  Created on: Apr 26, 2024
 *      Author: Loubet Gregory
 */

#include "Moteur.h"

// Fonction d'initialisation des moteurs avec le timer
void Initialisation_Moteur(TIM_HandleTypeDef* timer) {
    HAL_TIM_PWM_Start(timer, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(timer, TIM_CHANNEL_2);
}

// Fonction pour contrôler la direction du moteur
void ControleMoteur(uint8_t sens, uint8_t no_moteur) {
    GPIO_PinState moteurState[2];

    if (sens == SENS_1) {
        moteurState[0] = GPIO_PIN_SET;
        moteurState[1] = GPIO_PIN_RESET;
    } else if (sens == SENS_2) {
        moteurState[0] = GPIO_PIN_RESET;
        moteurState[1] = GPIO_PIN_SET;
    } else {
        moteurState[0] = GPIO_PIN_SET;
        moteurState[1] = GPIO_PIN_SET;
    }

    switch (no_moteur) {
        case 0:
            HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, moteurState[0]);
            HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, moteurState[1]);
            break;
        case 1:
            HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, moteurState[0]);
            HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, moteurState[1]);
            break;
        default:
            break;
    }
}

// Fonction pour contrôler la vitesse du moteur
void ControleVitesse(int16_t Vitesse_Corrigee, uint8_t no_moteur) {
    if (Vitesse_Corrigee > 0) {
        ControleMoteur(SENS_1, no_moteur);
    }
    else if (Vitesse_Corrigee < 0) {
        ControleMoteur(SENS_2, no_moteur);
    }
    else {
        ControleMoteur(STOP, no_moteur);
    }
    // Appliquer la vitesse corrigée avec le bon timer
	switch(no_moteur)
	{
	case 1 : // Moteur n°1
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,abs(Vitesse_Corrigee));
		break ;
	case 0 : // Moteur n°2
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,abs(Vitesse_Corrigee));
		break ;
	}
}




