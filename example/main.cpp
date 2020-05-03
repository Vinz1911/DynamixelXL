//
//  main.cpp
//  Dynamixel_XL430
//
//  Created by Vinzenz Weist on 27.04.20.
//  Copyright © 2020 Vinzenz Weist. All rights reserved.
//

#include "../src/dynamixel_xl.cpp"

int main(int argc, const char * argv[]) {
    DynamixelXL dynamixel = DynamixelXL();
    if(!dynamixel.set_open()) {
        printf("failed: could not open port, check connection!");
        return 1;
    }
    dynamixel.set_close();
    return 0;
}