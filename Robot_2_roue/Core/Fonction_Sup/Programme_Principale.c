#include "Programme_Principale.h"



void Initialisation()
{
	Initialisation_Codeuse();
	Initialisation_Moteur(&htim1);
}



void Programme_Principale()
{
	ControleVitesse(255, 0) ;
	ControleVitesse(255, 1) ;
	while(1)
	{
		Update_Codeuse(0, &htim4);
		Update_Codeuse(1, &htim3);
	}
}
