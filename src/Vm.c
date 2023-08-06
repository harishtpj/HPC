#include <stdio.h>

#include "Common.h"
#include "Vm.h"

VM vm;

void initVM() {

}

void freeVM() {

}

static InterpretResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONST() (vm.chunk->constants.values[READ_BYTE()])

    while (true) {
        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
        case OP_CONST: {
            Value constant = READ_CONST();
            printValue(constant);
            printf("\n");
            break;
        }

        case OP_RET: {
            return INTERPRET_OK;
        }
        }
    }

#undef READ_BYTE
#undef READ_CONSTANT
}

InterpretResult interpret(Chunk* chunk) {
	vm.chunk = chunk;
	vm.ip = vm.chunk->code;
	return run();
}
