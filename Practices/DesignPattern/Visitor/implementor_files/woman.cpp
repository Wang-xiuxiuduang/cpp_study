#include "../header_files/woman.h"

void Woman::accept(Action& visitor) { visitor.getConclusion(*this); }