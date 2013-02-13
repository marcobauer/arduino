cmake_minimum_required(VERSION 2.8)

# Set a variable for commands below
set( PROJECT_NAME  androino )
set( LIB_STACK     comstack )

# Define your Arduino board (below is for Arduino Uno)
set( ${PROJECT_NAME}_BOARD uno )
set( ${PROJECT_NAME}_PORT  /dev/ttyACM0 )

set( ARDUINO_SDK_PATH "/devel/arduino" )
set( ARDUINO_SDK_VERSION 1.0.3 )

set( CMAKE_SOURCE_DIR /devel/git-repos/arduino-cmake )
set( CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)

project( ${PROJECT_NAME} C CXX)

FILE ( 	GLOB StackSrc 
		${LIB_STACK}/*.cpp 
)

FILE ( 	GLOB StackHdr 
		${LIB_STACK}/*.h 
)

generate_arduino_library( comstack
    SRCS  ${StackSrc}
    HDRS  ${StackHdr} 
    BOARD uno
)

set( ${PROJECT_NAME}_LIBS  comstack )
set( ${PROJECT_NAME}_HDRS  SerialImpl.h )
set( ${PROJECT_NAME}_SRCS  SerialImpl.cpp main.cpp )

generate_arduino_firmware( ${PROJECT_NAME} )
