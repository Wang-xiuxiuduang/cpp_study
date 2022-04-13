#include "../header_files/context.h"

void Context::Work() {
    pState->WriteProgram();
    pState = pState->GetNextState();
}