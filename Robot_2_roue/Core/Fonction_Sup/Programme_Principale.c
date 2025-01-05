#include "Programme_Principale.h"

extern TIM_HandleTypeDef htim9;

void Initialisation()
{
	Initialisation_Codeuse();
	Initialisation_Moteur(&htim1);

	HAL_TIM_Base_Start_IT(&htim9);

}



void Programme_Principale()
{
	ControleVitesse(255, 0) ;
	ControleVitesse(-255, 1) ;
	while(1)
	{

	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
 if(htim->Instance == TIM9)
  {
	 Update_Codeuse(0, &htim4);
	 Update_Codeuse(1, &htim3);
  }
}
