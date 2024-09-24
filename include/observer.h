//
// Created by 29789 on 24-9-24.
//

#ifndef EXP2_OBSERVER_H
#define EXP2_OBSERVER_H


#include <iostream>

using namespace std;

class Observer {
public:
    // 更新观察者状态
    virtual void Update(int) = 0;
};


class Subject {
public:
    //注册观察者
    virtual void Attach(Observer *observer) = 0;
    //注销观察者
    virtual void Detach(Observer *observer) = 0;
    //通知观察者
    virtual void Notify() = 0;
};
#endif //EXP2_OBSERVER_H
