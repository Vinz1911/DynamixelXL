//
//  main.cpp
//  Dynamixel
//
//  Created by Vinzenz Weist on 27.04.20.
//  Copyright © 2020 Vinzenz Weist. All rights reserved.
//

#include <unistd.h>
#include "../src/dynamixel.h"

#define DXL_ID 1

int main(int argc, const char * argv[]) {
    Dynamixel dynamixel = Dynamixel();
    if(!dynamixel.set_open()) {
        printf("failed: could not open port, please check connection!");
        return 1;
    }
    dynamixel.set_operating_mode(DXL_ID, ADDR_CONTROL_MODE_VELOCITY);
    dynamixel.set_torque(DXL_ID, true);
    dynamixel.set_goal_velocity(DXL_ID, 265);

    sleep(2.0);

    dynamixel.set_goal_velocity(DXL_ID, 0);
    dynamixel.set_torque(DXL_ID, false);
    dynamixel.set_close();
    return 0;
}