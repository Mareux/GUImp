cmake_minimum_required(VERSION 3.14)
project(GUImp C)

set(CMAKE_C_STANDARD 11)

# Linux

find_package(SDL2 REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(SDL_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY})

# Unit Factory

#set(SDL2_INCLUDE_DIR ~/.brew/include/SDL2/)
#set(SDL2_LIBRARY ~/.brew/lib/)
#include_directories(${SDL2_INCLUDE_DIR})
#link_directories(${SDL2_LIBRARY})

# Mac OS VM

#set(SDL2_INCLUDE_DIR /usr/local/Cellar/sdl2/2.0.9_1/include/SDL2)
#set(SDL2_LIBRARY /usr/local/Cellar/sdl2/2.0.9_1/lib)
#include_directories(${SDL2_INCLUDE_DIR}
#        /usr/local/Cellar/sdl2_image/2.0.4/include/SDL2
#        /usr/local/Cellar/sdl2_ttf/2.0.15/include/SDL2)
#link_directories(${SDL2_LIBRARY}
#        /usr/local/Cellar/sdl2_image/2.0.4/lib
#        /usr/local/Cellar/sdl2_ttf/2.0.15/lib)

file(GLOB libft
        "libft/*.c")

add_executable(GUImp
        ${libft}
        libft/libft.h
        guimp.h
        main.c
        guimp_init.c
        guimp_mouse1_down.c
        guimp_use_tool.c
        tool_pencil.c
        libui/put_pixel.c
        libui/color.c
        libui/libui.h
        libui/new_window.c
        libui/events.c
        libui/events_2.c
        libui/init.c
        libui/utils.c
        libui/vectors.c
        libui/window_options.c
        libui/widgets_create.c
        libui/widgets_add_to_lists.c
        libui/widgets_delete.c
        libui/cursor.c
        libui/menu.c
        draw.c
        libui/draw_line.c
        libui/keyhooks_init.c
        libui/keyhooks_mousebuttons.c save.c guimp_draw_canvas.c tool_hand.c tool_magnifying_glass.c libui/scaled_surfaces.c libui/menu_add.c load_cursors.c libui/calculate_menu.c)

target_link_libraries(GUImp -lSDL2 -lm -lSDL2_image -lSDL2_ttf)