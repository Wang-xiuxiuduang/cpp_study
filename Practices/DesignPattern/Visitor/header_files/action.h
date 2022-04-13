#ifndef ACTION_H_
#define ACTION_H_

class Man;
class Woman;

class Action {
public:
    // 第二次分派
    virtual void getConclusion(Man& man) = 0;
    virtual void getConclusion(Woman& woman) = 0;
};

#endif