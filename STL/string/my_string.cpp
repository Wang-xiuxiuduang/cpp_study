#include "my_string.h"

String::String() {  // default constructor
    len = 4;
    m_data = new char[1];
    m_data[0] = '\0';
}

// constructor String from C string
String::String(const char* cstr) {
    len = strlen(cstr);
    m_data = new char[len + 1];
    strcpy(m_data, cstr);
}

String::~String() {  // necessary destuctor
    std::cout << "destructor\n";
    delete[] m_data;
}

String::String(const String& other) {  // assign string to string
    len = strlen(other.m_data);
    m_data = new char[len + 1];
    strcpy(m_data, other.m_data);
}

// assign a string to a string
String& String::operator=(const String& other) {
    if (this == &other)  // object assigned to self
        return *this;    // all done

    len = strlen(other.m_data);
    delete[] m_data;               // 1.杀掉原来的位置
    m_data = new char[len + 1];    // 2.分配新的位置
    strcpy(m_data, other.m_data);  // 3.放置指定内容
    return *this;
}

String& String::operator=(const char* other) {
    len = strlen(other);
    delete[] m_data;
    m_data = new char[len + 1];
    strcpy(m_data, other);
    return *this;
}

ostream& operator<<(ostream& os, String& str) {
    os << str.GetData();
    return os;
}

istream& operator>>(istream& is, String& str) {
    std::cout << "Please cin: ";
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is) {
        str = temp;
    }
    while (is && is.get() != '\n') continue;
    return is;
}
