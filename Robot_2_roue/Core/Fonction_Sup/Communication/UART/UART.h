/*
 * UART.h
 *
 *  Created on: Jan 5, 2025
 *      Author: Loubet Gregory
 */

#ifndef FONCTION_SUP_COMMUNICATION_UART_UART_H_
#define FONCTION_SUP_COMMUNICATION_UART_UART_H_

#include "main.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#define TAILLE_RX_LECTURE 8
extern UART_HandleTypeDef huart2;


void Initialiser_UART(UART_HandleTypeDef *huart);
void UART_envoyer_donnees(void *data, int taille, char type);
void Recevoir();

#endif /* FONCTION_SUP_COMMUNICATION_UART_UART_H_ */
