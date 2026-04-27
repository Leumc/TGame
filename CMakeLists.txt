cmake_minimum_required(VERSION 3.16)
project(tgame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SYSTEM_COMPONENTS 
    src/system/CrossHair.cpp
    src/system/AudioManager.cpp
    src/system/Cursor.cpp
    src/system/Player.cpp
    src/system/BulletManager.cpp
)

set(INTERFACES
    src/interfaces/general_interfaces.cpp
)

set(OTHERS
    src/math.hpp
    src/structs.hpp
)

set(BULLETS
    src/bullets/bullet.cpp
)

add_executable(tgame main.cpp
    ${SYSTEM_COMPONENTS}
    ${INTERFACES}
    ${OTHERS}
    ${BULLETS}
)

target_link_libraries(tgame PRIVATE
    sfml-graphics
    sfml-audio
    sfml-window
    sfml-system
)
