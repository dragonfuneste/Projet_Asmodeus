/*
 * UART.c
 *
 *  Created on: Jan 5, 2025
 *      Author: Loubet Gregory
 */

#include "UART.h"

#include <stdio.h>
#include <string.h>

static UART_HandleTypeDef* huart_;
uint8_t Rx_data[TAILLE_RX_LECTURE];
uint8_t RX_FLAG;
static char Tx_Buffer[100] ;  // Rendre le buffer statique pour éviter des réinitialisations

// Fonction d'initialisation de l'UART
void Initialiser_UART(UART_HandleTypeDef *huart) {
    huart_ = huart;

}

// Fonction générique pour envoyer des données via UART
void UART_envoyer_donnees(void *data, int taille, char type) {
    int len = 0;
    for (int i = 0; i < taille; i++) {
        switch (type) {
            case 'l': // int32_t (long int)
                len += snprintf(&Tx_Buffer[len], sizeof(Tx_Buffer) - len, "%ld,", ((int32_t *)data)[i]);
                break;
            case 's': // int16_t (short int)
                len += snprintf(&Tx_Buffer[len], sizeof(Tx_Buffer) - len, "%d,", ((int16_t *)data)[i]);
                break;
            case 'c': // int8_t (char)
                len += snprintf(&Tx_Buffer[len], sizeof(Tx_Buffer) - len, "%d,", ((int8_t *)data)[i]);
                break;
            case 'i': // int (standard)
                len += snprintf(&Tx_Buffer[len], sizeof(Tx_Buffer) - len, "%d,", ((int *)data)[i]);
                break;
            default:
                // Type inconnu
                return;
        }

        // Empêcher le dépassement du buffer
        if (len >= sizeof(Tx_Buffer)) {
            break;
        }
    }

    // Supprimer la dernière virgule et ajouter les caractères de fin
    if (len > 0) {
        Tx_Buffer[len - 1] = ';';
    }
    len += snprintf(&Tx_Buffer[len], sizeof(Tx_Buffer) - len, "\n\r");

    // Transmission via UART
    HAL_UART_Transmit_IT(huart_, (uint8_t *)Tx_Buffer, len);
}

// Fonction de réception des données
void Recevoir() {
    HAL_UART_Receive(huart_, Rx_data, TAILLE_RX_LECTURE, 1000);
}

/*// Callback d'interruption de réception UART
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart == huart_) {
        RX_FLAG = 1;

        memset(Rx_data, '\0', TAILLE_RX_LECTURE);
        HAL_UART_Receive_IT(huart_, Rx_data, TAILLE_RX_LECTURE);
    }
}*/

