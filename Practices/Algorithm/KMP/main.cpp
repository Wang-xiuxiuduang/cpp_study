#include <iostream>
#include <string>

int getIndex(std::string&, std::string&);

int main() {
    std::string txt = "aabaabaaf";
    std::string mode = "aabaaf";
    // 暴力解法
    std::cout << getIndex(txt, mode) << std::endl;
    return 0;
}

// 暴力求解
int getIndex(std::string& txt_string, std::string& mode_string) {
    int txt_string_length = txt_string.size();
    int mode_string_length = mode_string.size();
    int length = 0;
    for (int i = 0; i <= txt_string_length - mode_string_length; ++i) {
        int j = 0;
        for (j = 0; j < mode_string_length; ++j) {
            if (mode_string[j] != txt_string[i + j]) {
                break;
            }
        }
        if (j == mode_string_length) {
            return i;
        }
    }
    return -1;
}

// KMP 解法
int kmp(std::string& txt_string, std::string& mode_string) {
    
}