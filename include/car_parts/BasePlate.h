//
// Created by 29789 on 24-9-17.
//

#ifndef BASEPLATE_H
#define BASEPLATE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../nlohmann/json.hpp"
#include "Tire.h" // 确保包含 Tire 类的头文件
#include "observer.h"

using namespace std;
using json = nlohmann::json;

/*
    底盘模块中增加观察者，向雷达模块进行订阅注册，并接收订阅通知。
    这里增加一个决策类,根据传过来的障碍物状态,进行不同的决策
*/
class Decision : public Observer
{
public:
    void Update(int subState);
};

class BasePlate {
private:
    string id;
    string model;
    int wheelBase;
    int wheelTrack;
    int minGroundClearance;
    int minTurningRadius;
    string driveMode;
    int maxTravel;
    vector<Tire> tire;
    Observer *decision = new Decision();
public:
    Observer *getDecision(){
        return decision;
    }
    BasePlate();
    BasePlate(string id, string model, int wheelBase, int wheelTrack, int minGroundClearance,
              int minTurningRadius, string driveMode, int maxTravel, vector<Tire> tire);
    ~BasePlate();

    void setID(string id);
    string getid();
    void setmodel(string model);
    string getmodel();
    void setwheelBase(int wheelBase);
    int getwheelBase();
    void setwheelTrack(int wheelTrack);
    int getwheelTrack();
    void setminGroundClearance(int minGroundClearance);
    int getminGroundClearance();
    void setminTurningRadius(int minTurningRadius);
    int getminTurningRadius();
    void setdriveMode(string driveMode);
    string getdriveMode();
    void setmaxTravel(int maxTravel);
    int getmaxTravel();
    void settire(vector<Tire> tire);
    vector<Tire> gettire();

    void print();
    friend ostream &operator<<(ostream &out, const BasePlate &basePlate);
    friend istream &operator>>(istream &in, BasePlate &basePlate);

    void save();
    json toJson();
    void fromJson(json j);

};

#endif // BASEPLATE_H