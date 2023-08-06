#include "Common.h"
#include "Chunk.h"
#include "Debug.h"
#include "Vm.h"

int main(int argc, const char* argv[]) {
	initVM();

	Chunk chunk;
	initChunk(&chunk);

	int constant = addConstant(&chunk, 1.2);
	writeChunk(&chunk, OP_CONST, 123);
	writeChunk(&chunk, constant, 123);

	writeChunk(&chunk, OP_RET, 123);

	disassembleChunk(&chunk, "test chunk");

	interpret(&chunk);

	freeVM();
	freeChunk(&chunk);
	return 0;
}