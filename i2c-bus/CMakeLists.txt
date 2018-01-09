# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Dependency libraries
#find_package(LIBRARY_NAME REQUIRED)

# Add libraries
set(I2CBUS_LIB_SRC
	src/i2c.cpp
	src/i2c_utils.c
)
add_library(i2cbus STATIC ${I2CBUS_LIB_SRC})
# target_link_libraries(i2cbus -lpthread)
target_include_directories(i2cbus PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
	$<INSTALL_INTERFACE:include>)

add_subdirectory(tests)

