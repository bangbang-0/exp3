#include <iostream>
#include <fstream>
#include <vector>

#include "Student.h"
#include "car_parts/AGXKit.h"
#include "car_parts/BatteryModule.h"
#include "car_parts/BasePlate.h"
#include "car_parts/BinocularCamera.h"
#include "car_parts/LCD.h"
#include "car_parts/MultiLineLidar.h"
#include "car_parts/NineAxisGyroscope.h"
#include "SongLingCar.h"

using namespace std;
using namespace nlohmann;


int main() {

    SongLingCar songLingCar("cqusn0000000000000",
                            BasePlate("dp00000000", "SCOUT MINI", 451, 490, 115, 0, "四轮四驱", 10,
                                      vector<Tire>(4, Tire("公路轮、麦克纳姆轮", 175))),
                            vector<AGXKit>(1, AGXKit("AGX Xavier", 32, 512, 64, 32, 32)),
                            vector<BinocularCamera>(1,
                                                    BinocularCamera("RealSense D435i", "D430", "1920 1080", 30,
                                                                    8758, 90)),
                            vector<MultiLineLidar>(1, MultiLineLidar("RS-Helios-16p", 16, 100, 8)),
                            vector<NineAxisGyroscope>(1, NineAxisGyroscope("CH110", "NXP")),
                            vector<LCD>(1, LCD("11.6", "super")),
                            vector<BatteryModule>(1, BatteryModule("24V/15Ah", "24V", 2)));

    std::cout << "-------------------------------------------------------------------\n";
    std::cout << "开始进行障碍物测试，1代表前方障碍，2代表左前方障碍，3代表右前方障碍\n";
    while (true) {
        int order;
        std::cout << "请输入命令：";
        std::cin >> order;
        if (order == 0) {
            std::cout << "测试结束\n-------------------------------------------------------------------\n";
            return 0;
        }
        songLingCar.test(order);
    }
}