/*
 * Asservissement.cpp
 *
 *  Created on: Jan 5, 2025
 *      Author: Loubet Gregory
 */

#include "Asservissement.h"


// VALEUR INTERNE
extern int codeuse_position [NOMBRE_CODEUSE] ;
int16_t Vitesse_Mesurer [NOMBRE_CODEUSE] = {0};

int16_t Vitesse_Corrige [NOMBRE_CODEUSE] = {0};


/** RELATIF A L'ASSERVISSEMENT */
// Constantes PID pour chaque moteur (les mêmes ici, mais pourraient être différentes)
float Kp[NOMBRE_MOTEUR];
float Kd[NOMBRE_MOTEUR];
float Ki[NOMBRE_MOTEUR];

// Erreurs PID pour chaque moteur
int16_t Erreur_Proportionnel[NOMBRE_MOTEUR] = {0};
int16_t Erreur_Derive[NOMBRE_MOTEUR] = {0};
int16_t Erreur_Integrale[NOMBRE_MOTEUR] = {0};
int16_t Erreur_Precedente[NOMBRE_MOTEUR] = {0};


void Initiation_PID()
{
    // Initialisation des gains PID (Kp, Kd, Ki) pour chaque moteur
    Kp[0] = 0.3;
    Kp[1] = 0.3;



    Kd[0] = 0.1846;
    Kd[1] = 0.1846;

    Ki[0] = 0.3788;
    Ki[1] = 0.3788;
}

/** GERE LES CALCUL DE PID */
void compute_PID(int16_t vitesse_consigne, int no_moteur)
{

}


void Reset_PID()
{
	for (int i = 0 ; i<NOMBRE_CODEUSE; i++)
	{
		Erreur_Proportionnel[NOMBRE_CODEUSE] = 0 ;
		Erreur_Derive		[NOMBRE_CODEUSE] = 0 ;
		Erreur_Integrale	[NOMBRE_CODEUSE] = 0 ;
		Erreur_Precedente	[NOMBRE_CODEUSE] = 0 ;
	}

}


/*** TEST DU SYSTEME EN BOUCLE OUVERTE POUR UN ECHELLON UNITAIRE */
int16_t Valeur_Mesurer [NOMBRE_CODEUSE * 2] = {0};
int n = 0 ;
void Test_BO_Asserv(int16_t Vitesse_Moteur_0 ,int16_t Vitesse_Moteur_1)
{
	if ((n < NOMBRE_DE_POINT_MESURE*0.1) || (n >= NOMBRE_DE_POINT_MESURE))
	{
		ControleVitesse(0, 0) ;
		ControleVitesse(0, 1) ;
	}
	else
	{
		ControleVitesse(Vitesse_Moteur_0, 0) ;
		ControleVitesse(Vitesse_Moteur_1, 1) ;
	}
	if (n < NOMBRE_DE_POINT_MESURE)
	{
		// On envoie simplement la position souhaité
		n++ ;


		Valeur_Mesurer [0] = Vitesse_Moteur_0 ;
		Valeur_Mesurer [1] = Vitesse_Moteur_1 ;
		Valeur_Mesurer [2] = codeuse_position[0] ;
		Valeur_Mesurer [3] = codeuse_position[1] ;

		UART_envoyer_donnees(Valeur_Mesurer, NOMBRE_CODEUSE*2 , 's');
	}
}


/*** TEST DU SYSTEME EN BOUCLE FERMER POUR UN ECHELLON UNITAIRE */
void Test_BF_Asserv(int16_t Vitesse_Moteur_0 ,int16_t Vitesse_Moteur_1)
{
	if ((n < NOMBRE_DE_POINT_MESURE*0.1) || (n >= NOMBRE_DE_POINT_MESURE))
	{
		compute_PID(0,0);
		compute_PID(0,1);
	}
	else
	{
		compute_PID(Vitesse_Moteur_0,0);
		compute_PID(Vitesse_Moteur_0,1);
	}
	if (n < NOMBRE_DE_POINT_MESURE)
	{
		// On envoie simplement la position souhaité
		n++ ;

		Valeur_Mesurer [0] = Vitesse_Moteur_0 ;
		Valeur_Mesurer [1] = Vitesse_Moteur_1 ;
		Valeur_Mesurer [2] = Vitesse_Corrige[0] ;
		Valeur_Mesurer [3] = Vitesse_Corrige[1] ;

		UART_envoyer_donnees(Valeur_Mesurer, NOMBRE_CODEUSE*2, 's');
	}
}
