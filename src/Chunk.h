#ifndef HPC_CHUNK_H
#define HPC_CHUNK_H

#include "Common.h"
#include "Value.h"

typedef enum {
	OP_CONST,
	OP_RET,
} OpCode;

typedef struct {
	int count;
	int capacity;
	uint8_t* code;
	int* lines;
	ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif
