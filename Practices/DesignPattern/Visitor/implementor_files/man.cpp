#include "../header_files/man.h"

void Man::accept(Action& visitor) { visitor.getConclusion(*this); }