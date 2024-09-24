//
// Created by 29789 on 24-9-17.
//

#ifndef SONGLINGCAR_H
#define SONGLINGCAR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../nlohmann/json.hpp"
#include "car_parts/BasePlate.h"
#include "car_parts/AGXKit.h"
#include "car_parts/BinocularCamera.h"
#include "car_parts/MultiLineLidar.h"
#include "car_parts/NineAxisGyroscope.h"
#include "car_parts/LCD.h"
#include "car_parts/BatteryModule.h"

using namespace std;
using json = nlohmann::json;

class SongLingCar {
public:
    string id;
    BasePlate basePlate;
    vector<AGXKit> agxKit;
    vector<BinocularCamera> binocularCamera;
    vector<MultiLineLidar> multiLineLidar;
    vector<NineAxisGyroscope> nineAxisGyroscope;
    vector<LCD> lcd;
    vector<BatteryModule> batteryModule;

    SongLingCar();
    SongLingCar(string id, BasePlate basePlate, vector<AGXKit> agxKit, vector<BinocularCamera> binocularCamera,
                vector<MultiLineLidar> multiLineLidar, vector<NineAxisGyroscope> nineAxisGyroscope, vector<LCD> lcd,
                vector<BatteryModule> batteryModule);
    ~SongLingCar();

    void setid(string id);
    string getid();
    void setBasePlateid(string id);
    string getBasePlateid();
    void setBasePlate(BasePlate basePlate);
    BasePlate getBasePlate();
    void setagxKit(vector<AGXKit> agxKit);
    vector<AGXKit> getagxKit();
    void setbinocularCamera(vector<BinocularCamera> binocularCamera);
    vector<BinocularCamera> getbinocularCamera();
    void setmultiLineLidar(vector<MultiLineLidar> multiLineLidar);
    vector<MultiLineLidar> getmultiLineLidar();
    void setnineAxisGyroscope(vector<NineAxisGyroscope> nineAxisGyroscope);
    vector<NineAxisGyroscope> getnineAxisGyroscope();
    void setlcd(vector<LCD> lcd);
    vector<LCD> getlcd();
    void setbatteryModule(vector<BatteryModule> batteryModule);
    vector<BatteryModule> getbatteryModule();

    void print();
    friend ostream &operator<<(ostream &out, const SongLingCar &songLingCar);
    friend istream &operator>>(istream &in, SongLingCar &songLingCar);
    void save();
    json toJson();
    void fromJson(json j);
    void test(int order);
};

#endif // SONGLINGCAR_H