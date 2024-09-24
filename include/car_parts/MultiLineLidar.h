//
// Created by 29789 on 24-9-17.
//

#ifndef MULTILINELIDAR_H
#define MULTILINELIDAR_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "../../nlohmann/json.hpp"
#include "observer.h"

using namespace std;
using json = nlohmann::json;

class MultiLineLidar : public Subject {
private:
    string model;
    int channel;
    double testRange;
    double powerConsumption;

// 保存注册的观察者对象
    std::list<Observer *> observers;
    // 目标对象状态.(障碍物状态,1代表前方障碍，2代表左前方障碍，3代表右前方障碍)
    int subjectState;
public:
    MultiLineLidar();

    MultiLineLidar(string model, int channel, int testRange, int powerConsumption);

    ~MultiLineLidar();

    void setmodel(string model);

    string getmodel();

    void setchannel(int channel);

    int getchannel();

    void settestRange(int testRange);

    int gettestRange();

    void setpowerConsumption(int powerConsumption);

    int getpowerConsumption();

    void print();

    friend ostream &operator<<(ostream &out, const MultiLineLidar &multiLineLidar);

    friend istream &operator>>(istream &in, MultiLineLidar &multiLineLidar);

    void save();

    json toJson();

    void fromJson(json j);

    // 注册观察者
    void Attach(Observer *observer);
    // 注销观察者
    void Detach(Observer *observer) ;
    // 通知观察者
    void Notify();
    // 设置状态
    void setSubjectState(int state);
    // 获取状态
    int getSubjectState();
};

#endif // MULTILINELIDAR_H