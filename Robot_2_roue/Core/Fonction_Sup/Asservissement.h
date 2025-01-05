/*
 * Asservissement.h
 *
 *  Created on: Jan 5, 2025
 *      Author: Loubet Gregory
 */

#ifndef FONCTION_SUP_ASSERVISSEMENT_H_
#define FONCTION_SUP_ASSERVISSEMENT_H_

#include "Communication/UART/UART.h"
#include "Motorisation/Moteur.h"
#include "Motorisation/Capteurs/Codeuse.h"

void Initiation_PID();

void compute_PID(int16_t vitesse_consigne, int no_moteur);
void Reset_PID();



#define NOMBRE_DE_POINT_MESURE 500
void Test_BO_Asserv(int16_t Vitesse_Moteur_0 ,int16_t Vitesse_Moteur_1);
void Test_BF_Asserv(int16_t Vitesse_Moteur_0 ,int16_t Vitesse_Moteur_1);
#endif /* FONCTION_SUP_ASSERVISSEMENT_H_ */
