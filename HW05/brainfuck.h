#ifndef BRAINFUCK_H_INCLUDED
#define BRAINFUCK_H_INCLUDED
#include <stdio.h>
#include <stdint.h>

void csie_interpreter(const uint8_t code[], size_t size, size_t mem_limit); 

#endif
