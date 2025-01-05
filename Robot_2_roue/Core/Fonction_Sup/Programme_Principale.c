#include "Programme_Principale.h"





// FLAG
int flag_interrupt = 0 ;
void Initialisation()
{
	Initialisation_Codeuse();
	Initialisation_Moteur(&htim1);

	Initialiser_UART(&huart2);
	HAL_TIM_Base_Start_IT(&htim9);
	flag_interrupt = 0 ;
}



void Programme_Principale()
{
	ControleVitesse(255, 0) ;
	ControleVitesse(-255, 1) ;
	while(1)
	{
		if (flag_interrupt)
		{
			flag_interrupt = 0 ;
			Test_BO_Asserv(255,255);
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
 if(htim->Instance == TIM9)
  {
	 flag_interrupt = 1 ;
	 Update_Codeuse(0, &htim4);
	 Update_Codeuse(1, &htim3);
  }
}
