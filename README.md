<div align="center">
    <h1>
        <br>
            Dynamixel
        <br>
    </h1>
</div>

`Dynamixel` is a simple and easy way to deal with the Dynamixel XL430 Servo. It's fast and based on the `DynamixelSDK`. 

## Features:
- [X] fast and easy to understand
- [X] support for group writes
- [X] most of the common features implemented (WIP)
- [X] `NOTE: DynamixelSDK is required!` get it from here and install it to `/usr/local/include`: [DynamixelSDK](https://github.com/ROBOTIS-GIT/DynamixelSDK) 

## License:
[![License](https://img.shields.io/badge/license-GPLv3-blue.svg?longCache=true&style=flat)](https://github.com/Vinz1911/Dynamixel/blob/master/LICENSE)

## C++ Version:
[![C++17](https://img.shields.io/badge/C++-17-blue.svg?logo=c%2B%2B&style=flat)](https://isocpp.org)

## Install:
```shell
# create cmake file
cmake CMakeLists.txt
# install to /usr/local/include
sudo make install

```

## Import:
```cpp
// include the .cpp files from the project
#include "dynamixel_xl.cpp"

// create instance of the dynamixel 
Dynamixel dynamixel = Dynamixel();
if(!dynamixel.set_open()) {
    printf("failed: could not open port, please check connection!");
}
```

## Usage:
### Examples:
```cpp
#define DXL_ID 1

// enable LED
dynamixel.set_led(DXL_ID, true);

// set the operating mode to velocity
dynamixel.set_operating_mode(DXL_ID, ADDR_CONTROL_MODE_VELOCITY);
// enable torque for the dynamixel
dynamixel.set_torque(DXL_ID, true);
// set maximum speed
dynamixel.set_goal_velocity(DXL_ID, 265);
// let it rotate for two seconds
sleep(2.0);
// disable rotation
dynamixel.set_goal_velocity(DXL_ID, 0);
// disable torque
dynamixel.set_torque(DXL_ID, false);
// close connection
dynamixel.set_close();

```

## Author:
👨🏼‍💻 [Vinzenz Weist](https://github.com/Vinz1911)