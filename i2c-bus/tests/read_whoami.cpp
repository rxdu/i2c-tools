/* 
 * read_whoami.cpp
 * 
 * Created on: Jan 08, 2018 23:16
 * Description: 
 * 
 * Copyright (c) 2018 Ruixiang Du (rdu)
 */

#include <iostream>
#include "i2c-bus/i2c.hpp"

using namespace librav;

int main()
{
    I2CBus i2cbus(3);

    bool res = i2cbus.Init();
    if (!res)
    {
        std::cerr << "Failed to initialize i2c bus" << std::endl;
        return -1;
    }

    std::cout << i2cbus.ReadRegister(0x1e, 0x0d) << std::endl;

    return 0;
}