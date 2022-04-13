#include "header_files/afternoon_state.h"
#include "header_files/context.h"
#include "header_files/evening_state.h"
#include "header_files/morning_state.h"
#include "header_files/state.h"

int main() {
    Context *context = new Context(MorningState::GetInstance());
    context->Work();
    context->Work();
    context->Work();
    return 0;
}