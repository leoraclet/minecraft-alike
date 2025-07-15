cmake_minimum_required(VERSION 3.31)
project(minecraft)

# C++ compile flags
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
endif()

# Directories
set(IMGUI_SRC_DIR libs/imgui)
set(LIB_SFML_PATH libs/sfml)
set(LIB_DIR libs)
set(INCLUDE_DIR includes)
set(SRC_DIR src)

# Load OpenGL
set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)

# Load SFML
find_package(
        SFML 2.5.1 COMPONENTS REQUIRED
        system
        window
        graphics
        PATHS ${LIB_SFML_PATH}
)

# Load source and header files
set(SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/camera.cpp
        ${SRC_DIR}/ebo.cpp
        ${SRC_DIR}/fbo.cpp
        ${SRC_DIR}/mesh.cpp
        ${SRC_DIR}/rbo.cpp
        ${SRC_DIR}/shader.cpp
        ${SRC_DIR}/texture.cpp
        ${SRC_DIR}/vao.cpp
        ${SRC_DIR}/vbo.cpp
        ${SRC_DIR}/window.cpp
)

set(HEADERS
        ${INCLUDE_DIR}/camera.h
        ${INCLUDE_DIR}/ebo.h
        ${INCLUDE_DIR}/fbo.h
        ${INCLUDE_DIR}/mesh.h
        ${INCLUDE_DIR}/rbo.h
        ${INCLUDE_DIR}/shader.h
        ${INCLUDE_DIR}/texture.h
        ${INCLUDE_DIR}/vao.h
        ${INCLUDE_DIR}/vbo.h
        ${INCLUDE_DIR}/window.h
)

# Load ImGUI src files
set(
        IMGUI_LIB_SRC
        ${IMGUI_SRC_DIR}/imgui.cpp
        ${IMGUI_SRC_DIR}/imgui_draw.cpp
        ${IMGUI_SRC_DIR}/imgui_tables.cpp
        ${IMGUI_SRC_DIR}/imgui_widgets.cpp
        ${IMGUI_SRC_DIR}/imgui-SFML.cpp
)

# Load GLAD and STB src files
set(
        LIBS_SRC
        ${LIB_DIR}/stb/stb_image.cpp
        ${LIB_DIR}/glad/src/glad.c
)

# Include directories
include_directories(
        ${LIB_DIR}
        ${INCLUDE_DIR}
        ${LIB_DIR}/glad/include
)

# Executable
add_executable(
        ${CMAKE_PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
        ${LIBS_SRC}
        ${IMGUI_LIB_SRC}
)

# Include directory to target
target_include_directories(
        ${CMAKE_PROJECT_NAME} PRIVATE
        ${IMGUI_SRC_DIR}
        ${LIBS_DIR}
)

# Link libraries to target
target_link_libraries(
        ${CMAKE_PROJECT_NAME} PRIVATE
        sfml-system
        sfml-window
        sfml-graphics
        dl
        ${OPENGL_LIBRARY}
)