/* 
 * i2c.hpp
 * 
 * Created on: Jan 08, 2018 22:45
 * Description: 
 * 
 * Copyright (c) 2018 Ruixiang Du (rdu)
 */

#ifndef I2C_HPP
#define I2C_HPP

#include <errno.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <cstdint>

extern "C" {
#include "i2c-bus/i2c_utils.h"
}

namespace librav
{
class I2CBus
{
  public:
    I2CBus() = default;
    I2CBus(int8_t bus_id);
    ~I2CBus();

    bool Init();
    int8_t ReadRegister(int8_t dev_addr, int8_t reg_addr);
    void WriteRegister(int8_t dev_addr, int8_t reg_addr, int8_t data);

  private:
    bool bus_initialized_ = false;
    int8_t bus_id_ = -1;
    int8_t bus_fd_ = -1;
    char bus_filename_[20];
};
}

#endif /* I2C_HPP */
