#ifndef HPC_DEBUG_H
#define HPC_DEBUG_H

#include "Chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif

