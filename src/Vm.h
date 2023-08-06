#ifndef HPC_VM_H
#define HPC_VM_H

#include "Chunk.h"

typedef struct {
	Chunk* chunk;
	uint8_t* ip;
} VM;

typedef enum {
	INTERPRET_OK,
	INTERPRET_COMPILE_ERROR,
	INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(Chunk* chunk);

#endif
