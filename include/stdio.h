#ifndef STDIO_H
#define STDIO_H
#include "stm8s.h"

void SerialInit(uint32_t baudrate);
bool SerialAvailable();
void print(char string[]);
void println(char string[]);
void printInt(uint32_t number);
#endif //STDIO_H