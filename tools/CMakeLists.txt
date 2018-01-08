# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Dependency libraries
#find_package(LIBRARY_NAME REQUIRED)

# Add libraries
set(TOOLS_LIB_SRC
	src/librav_math.cpp
    src/poly_curve.cpp
    src/quad_flattraj.cpp
)
add_library(tools STATIC ${TOOLS_LIB_SRC})
# target_link_libraries(tools -lpthread)
target_include_directories(tools PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
	$<INSTALL_INTERFACE:include>
	PRIVATE src)

