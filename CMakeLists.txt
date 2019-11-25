cmake_minimum_required(VERSION 3.14)
project(amazonia)

set(CMAKE_CXX_STANDARD 11)
set(TEXTURES_PATH "${CMAKE_SOURCE_DIR}/resources/textures")
set(SHADERS_PATH "${CMAKE_SOURCE_DIR}/resources/shaders")
set(TARGET_RESOURCES_PATH "${CMAKE_BINARY_DIR}/resources")
set(TARGET_SHADERS "${TARGET_RESOURCES_PATH}/shaders")
set(TARGET_TEXTURES "${TARGET_RESOURCES_PATH}/textures")

add_executable(amazonia ${CMAKE_SOURCE_DIR}/src/main.cpp src/Game.h src/Game.cpp src/main.cpp src/Shader.cpp src/Shader.h src/Texture2D.cpp src/Texture2D.h src/ResourceManager.cpp src/ResourceManager.h src/SpriteRenderer.cpp src/SpriteRenderer.h src/GameObject.cpp src/GameObject.h src/GameConfig.cpp src/GameConfig.cpp src/TextRenderer.cpp src/TextRenderer.h src/TileMapView.cpp src/TileMap.cpp src/TileSet.cpp)

# Including OS include paths. Idk why this is required, but it is.
include_directories("/usr/local/include")
include_directories("/opt/local/include")
include_directories("/opt/local/include/SOIL")
include_directories("/opt/local/lib")
include_directories("/usr/local/lib")
include_directories ("/usr/local/opt/freetype/include/freetype2")


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
find_package(freetype REQUIRED)

target_link_libraries(amazonia "-framework OpenGL")
target_link_libraries(amazonia "-framework CoreFoundation")
target_link_libraries(amazonia "-framework CoreVideo")
target_link_libraries(amazonia "-framework IOKit")
target_link_libraries(amazonia "-framework Cocoa")
target_link_libraries(amazonia "/opt/local/lib/libSOIL.a")
target_link_libraries(amazonia "/usr/local/opt/freetype/include/freetype2")
target_link_libraries(amazonia ${OPENGL_LIBRARIES} ${OPENGL_gl_LIBRARY} ${GLM_LIBRARIES} ${FREETYPE_LIBRARIES} ${GLEW_LIBRARY} ${GLFW3_LIBRARY} glfw)

target_include_directories(amazonia PUBLIC ${OPENGL_INCLUDE_DIR})


# copy files into build
configure_file(${TEXTURES_PATH}/background.png ${TARGET_TEXTURES}/background.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/elf.png ${TARGET_TEXTURES}/sprites/elf.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/indiana.png ${TARGET_TEXTURES}/sprites/indiana.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/banner.png ${TARGET_TEXTURES}/sprites/banner.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/wizard.png ${TARGET_TEXTURES}/sprites/wizard.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/tree.png ${TARGET_TEXTURES}/sprites/tree.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/beartrap.png ${TARGET_TEXTURES}/sprites/beartrap.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/guard.png ${TARGET_TEXTURES}/sprites/guard.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/pharao.png ${TARGET_TEXTURES}/sprites/pharao.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/urn.png ${TARGET_TEXTURES}/sprites/urn.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/pyramid.png ${TARGET_TEXTURES}/sprites/pyramid.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/dog.png ${TARGET_TEXTURES}/sprites/dog.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/boulder.png ${TARGET_TEXTURES}/sprites/boulder.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/cactus.png ${TARGET_TEXTURES}/sprites/cactus.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/coins.png ${TARGET_TEXTURES}/sprites/coins.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/bridge.png ${TARGET_TEXTURES}/sprites/bridge.png COPYONLY)


configure_file(${TEXTURES_PATH}/sprites/shovel.png ${TARGET_TEXTURES}/sprites/shovel.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/alicate.png ${TARGET_TEXTURES}/sprites/alicate.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/bp.png ${TARGET_TEXTURES}/sprites/bp.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/axe.png ${TARGET_TEXTURES}/sprites/axe.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/pick.png ${TARGET_TEXTURES}/sprites/pick.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/glasses.png ${TARGET_TEXTURES}/sprites/glasses.png COPYONLY)


configure_file(${TEXTURES_PATH}/sprites/orc.png ${TARGET_TEXTURES}/sprites/orc.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/chest.png ${TARGET_TEXTURES}/sprites/chest.png COPYONLY)

configure_file(${TEXTURES_PATH}/sprites/run.png ${TARGET_TEXTURES}/sprites/run.png COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/resources/textures/tilemap/terrain.png ${TARGET_RESOURCES_PATH}/textures/tilemap/terrain.png COPYONLY)

configure_file(${TEXTURES_PATH}/sprites/orc/running.png ${TARGET_TEXTURES}/sprites/orc/running.png COPYONLY)
configure_file(${TEXTURES_PATH}/sprites/portal.png ${TARGET_TEXTURES}/sprites/portal.png COPYONLY)


configure_file(${TEXTURES_PATH}/mushroom.png ${TARGET_TEXTURES}/mushroom.png COPYONLY)

configure_file(${SHADERS_PATH}/text/text.vert ${TARGET_SHADERS}/text/text.vert COPYONLY)
configure_file(${SHADERS_PATH}/text/text.frag ${TARGET_SHADERS}/text/text.frag COPYONLY)


configure_file(${CMAKE_SOURCE_DIR}/resources/fonts/OCRAEXT.TTF ${TARGET_RESOURCES_PATH}/fonts/OCRAEXT.TTF COPYONLY)


configure_file(${SHADERS_PATH}/sprite/sprite.frag ${TARGET_SHADERS}/sprite/sprite.frag COPYONLY)
configure_file(${SHADERS_PATH}/sprite/sprite.vert ${TARGET_SHADERS}/sprite/sprite.vert COPYONLY)
