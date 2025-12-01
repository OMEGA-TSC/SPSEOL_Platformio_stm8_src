#include "stm8s.h"
#include "stdio.h"

void SerialInit(uint32_t baudrate){
    UART1_DeInit();
    UART1_Init((uint32_t)baudrate, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
    UART1_SetAddress(0x1);
}
bool SerialAvailable(){
    if(UART1_GetFlagStatus(UART1_FLAG_RXNE) == TRUE) {
        return TRUE;
    }else {
        return FALSE;
    }
}
void print(char string[]){
    char j = 0;
    while (string[j] != 0x00){
        UART1_SendData8(string[j]);
        while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
        j++;
    }
}
void println(char string[]){
    char j = 0;
    while (string[j] != 0x00){
        UART1_SendData8(string[j]);
        while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
        j++;
    }
    UART1_SendData8('\r');
    while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
    UART1_SendData8('\n');
    while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
}
void printInt(uint32_t number){
    char count = 0;
    char digit[5] = "";
    while (number != 0) {
        digit[count] = number%10;
        count++;
        number = number/10;
    }
    while (count !=0){
        UART1_SendData8(digit[count-1] + 0x30);
        while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
        count--;
    }
}
