cmake_minimum_required(VERSION 2.8)

project(RPi-OpenCV)

SET(COMPILE_DEFINITIONS -Werror)

find_package( OpenCV REQUIRED )

include_directories(/opt/vc/include)
include_directories(/opt/vc/include/interface/vcos/pthreads)
include_directories(/opt/vc/include/interface/vmcs_host)
include_directories(/opt/vc/include/interface/vmcs_host/linux)
include_directories(USERLAND_DIR)
include_directories("${PROJECT_SOURCE_DIR}/include")

link_directories(/opt/vc/lib)

add_executable(test src/test.cpp src/PiCapture.cpp)

target_link_libraries(test mmal_core mmal_util mmal_vc_client bcm_host ${OpenCV_LIBS})
