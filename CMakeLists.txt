cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
include_directories(include)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

if(EXISTS "/proc/device-tree/model")
    file(READ "/proc/device-tree/model" DEVICE_MODEL)
    if(DEVICE_MODEL MATCHES "Raspberry Pi")
        set(IS_RPI TRUE)
    endif()
endif()

# 2. Если это Pi, ищем и подключаем библиотеки
if(IS_RPI)
    message(STATUS "Configuring for Raspberry Pi...")

    # Ищем pigpio (она должна быть установлена в системе: sudo apt install pigpio)
    find_library(PIGPIO_LIB pigpio)

    if(PIGPIO_LIB)
        target_link_libraries(${PROJECT_NAME} PRIVATE ${PIGPIO_LIB})
        # Добавляем макрос для кода, чтобы можно было использовать #ifdef RPI_BUILD
        target_compile_definitions(${PROJECT_NAME} PRIVATE RPI_BUILD)
    else()
        message(WARNING "pigpio not found! GPIO features might not work.")
    endif()
endif()

add_executable(main src/main.cpp
        src/gpio/Pin.h
        src/SinglePinActor.cpp
        src/SinglePinActor.h
        src/preferences/PreferencesLoader.cpp
        src/preferences/PreferencesLoader.h
        src/VehicleConstants.h
        src/VehicleController.cpp
        src/VehicleController.h
        src/MovementController.cpp
        src/MovementController.h
        src/MovementController.h
        src/GlobalCommand.cpp
        src/GlobalCommand.h
        src/gamepad/GamepadController.cpp
        src/gamepad/GamepadController.h
        src/gamepad/GamepadController.h
        src/IUpdateable.h
        src/Constants.h
        src/Logger.h
        src/DebugLauncherBuzzerTest.cpp
        src/DebugLauncherBuzzerTest.h
        src/WheelActor.cpp
        src/WheelActor.h
        src/GlobalCommandPrefix.h
        src/gpio/SoftwarePin.cpp
        src/gpio/SoftwarePin.h
        src/gpio/SoftwarePin.cpp
        src/gpio/HardwarePin.cpp
        src/gpio/HardwarePin.h
        src/gpio/HardwarePin.h
        src/main.cpp
        src/main.cpp
        src/gamepad/GamepadDataStruct.cpp
        src/gamepad/GamepadDataStruct.h
        src/gamepad/GamepadDataStruct.h
        src/gpio/PinsInitializer.cpp
        src/gpio/PinsInitializer.h
        src/gpio/PinActionName.h
        src/GlobalCommandsListenersObserverSingleton.cpp
        src/GlobalCommandsListenersObserverSingleton.h
        src/GlobalCommandsListener.cpp
        src/GlobalCommandsListener.h
        src/BuzzerController.cpp
        src/BuzzerController.h
        src/BuzzerController.cpp
        src/gpio/desktop/PinDesktop.cpp
        src/gpio/PinAbstract.h
        src/gpio/pi/PinPi.cpp
        src/gpio/desktop/PinDesktop.cpp
        src/gpio/HardwarePin.h
        src/gpio/GpioManager.cpp
        src/gpio/GpioManager.h
        src/gpio/PinCommon.cpp
        src/gpio/PinCommon.h
        src/gpio/PinCommon.h
        src/gamepad/GamepadConfigLoader.cpp
        src/gamepad/GamepadConfigLoader.h
        src/gamepad/InputKeys.h
        src/gamepad/GamepadMappingDataStruct.cpp
        src/gamepad/GamepadMappingDataStruct.h
)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/data"
        "$<TARGET_FILE_DIR:main>/data"
        COMMENT "Data copy in the output dir..."
)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)