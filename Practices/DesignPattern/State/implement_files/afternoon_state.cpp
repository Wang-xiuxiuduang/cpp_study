#include "../header_files/afternoon_state.h"

State* AfternoonState::m_state = nullptr;

void AfternoonState::WriteProgram() {
    std::cout << "I write program !\n";
    SetNextState(EveningState::GetInstance());
}