/* 
 * i2c.cpp
 * 
 * Created on: Jan 08, 2018 22:51
 * Description: 
 * 
 * Copyright (c) 2018 Ruixiang Du (rdu)
 */

#include "i2c-bus/i2c.hpp"

using namespace librav;

I2CBus::I2CBus(int8_t bus_id) : bus_id_(bus_id)
{
}

I2CBus::~I2CBus()
{
    if(bus_initialized_)
        close(bus_fd_);
}

bool I2CBus::Init()
{
    bus_fd_ = open_i2c_dev(bus_id_, bus_filename_, sizeof(bus_filename_), 0);

    if (bus_fd_ < 0)
        return false;

    bus_initialized_ = true;

    return true;
}

int8_t I2CBus::ReadRegister(int8_t dev_addr, int8_t reg_addr)
{
    int res = set_slave_addr(bus_fd_, dev_addr, 1);
    if (reg_addr >= 0)
    {
        res = i2c_smbus_write_byte(bus_fd_, dev_addr);
        if (res < 0)
            fprintf(stderr, "Warning - write failed\n");
    }
    res = i2c_smbus_read_byte(bus_fd_);

    return res;
}

void I2CBus::WriteRegister(int8_t dev_addr, int8_t reg_addr, int8_t data)
{
}