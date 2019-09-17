cmake_minimum_required(VERSION 3.14)
project(amazonia)

set(CMAKE_CXX_STANDARD 11)
set(TEXTURES_PATH "${CMAKE_SOURCE_DIR}/resources/textures")
set(SHADERS_PATH "${CMAKE_SOURCE_DIR}/resources/shaders")
set(TARGET_RESOURCES_PATH "${CMAKE_BINARY_DIR}/resources")
set(TARGET_SHADERS "${TARGET_RESOURCES_PATH}/shaders")
set(TARGET_TEXTURES "${TARGET_RESOURCES_PATH}/textures")

add_executable(amazonia ${CMAKE_SOURCE_DIR}/src/main.cpp src/Game.h src/Game.cpp src/main.cpp src/Shader.cpp src/Shader.h src/Texture2D.cpp src/Texture2D.h src/ResourceManager.cpp src/ResourceManager.h src/SpriteRenderer.cpp src/SpriteRenderer.h src/GameObject.cpp src/GameObject.h)

# Including OS include paths. Idk why this is required, but it is.
include_directories("/usr/local/include")
include_directories("/opt/local/include")
include_directories("/opt/local/include/SOIL")
include_directories("/opt/local/lib")
include_directories("/usr/local/lib")

# Including OS include paths. Idk why this is required, but it is.
include_directories(
        "${CMAKE_SOURCE_DIR}/src"
        "${CMAKE_SOURCE_DIR}/include"
        ${OPENGL_INCLUDE_DIR}
        ${GLFW3_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR}
        ${GLM_INCLUDE_DIR}
)

find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(glfw3 3.3 REQUIRED)

target_link_libraries(amazonia "-framework OpenGL")
target_link_libraries(amazonia "-framework CoreFoundation")
target_link_libraries(amazonia "-framework CoreVideo")
target_link_libraries(amazonia "-framework IOKit")
target_link_libraries(amazonia "-framework Cocoa")
target_link_libraries(amazonia "/opt/local/lib/libSOIL.a")
target_link_libraries(amazonia ${OPENGL_LIBRARIES} ${OPENGL_gl_LIBRARY} ${GLM_LIBRARIES} ${GLEW_LIBRARY} ${GLFW3_LIBRARY} glfw)

target_include_directories(amazonia PUBLIC ${OPENGL_INCLUDE_DIR})

# copy files into build
configure_file(${TEXTURES_PATH}/background.png ${TARGET_TEXTURES}/background.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/elf.png ${TARGET_TEXTURES}/sprites/elf.png COPYONLY)

configure_file(${SHADERS_PATH}/core/core.frag ${TARGET_SHADERS}/core/core.frag COPYONLY)
configure_file(${SHADERS_PATH}/core/core.vert ${TARGET_SHADERS}/core/core.vert COPYONLY)

configure_file(${SHADERS_PATH}/sprite/sprite.frag ${TARGET_SHADERS}/sprite/sprite.frag COPYONLY)
configure_file(${SHADERS_PATH}/sprite/sprite.vert ${TARGET_SHADERS}/sprite/sprite.vert COPYONLY)
