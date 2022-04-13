#ifndef BT_H_
#define BT_H_

struct Bt {
    int val;
    Bt *left;
    Bt *right;
    Bt(int val) : val(val), left(nullptr), right(nullptr) {}
};

#endif