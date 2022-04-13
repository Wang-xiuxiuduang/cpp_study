#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <cstring>
#include <iostream>

using std::operator>>;
using std::operator<<;
using std::istream;
using std::ostream;

class String {
private:
    int len;                       // 4B
    char* m_data;                  // 8B
    static const int CINLIM = 80;  // cin input limit  4B

public:
    String();
    String(const char*);
    String(const String&);
    String& operator=(const String&);
    String& operator=(const char*);
    ~String();

    char* GetData() const { return m_data; }
    int GetStringLength() { return len; }

    friend ostream& operator<<(ostream& os, String& str);
    friend istream& operator>>(istream& is, String& str);
};

#endif