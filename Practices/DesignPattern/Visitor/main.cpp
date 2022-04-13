#include "header_files/amativeness.h"
#include "header_files/failing.h"
#include "header_files/man.h"
#include "header_files/success.h"
#include "header_files/woman.h"

int main() {
    Success v1;      // 成功状态
    Failing v2;      // 失败状态
    Amativeness v3;  // 恋爱状态
    Man man;
    man.accept(v1);
    man.accept(v2);
    man.accept(v3);
}