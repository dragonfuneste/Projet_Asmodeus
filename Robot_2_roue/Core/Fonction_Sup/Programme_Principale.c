#include "Programme_Principale.h"

void Initialisation()
{
	Initialisation_Codeuse();
}



void Programme_Principale()
{
	while(1)
	{
		Update_Codeuse(0, &htim4);
		Update_Codeuse(1, &htim3);
	}
}
