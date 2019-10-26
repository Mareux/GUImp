cmake_minimum_required(VERSION 3.14)
project(GUImp C)

set(CMAKE_C_STANDARD 11)

# Linux

#find_package(SDL2 REQUIRED)
#find_package(SDL_ttf REQUIRED)
#find_package(SDL_image REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS})
#link_directories(${SDL2_LIBRARY})

# Unit Factory

set(SDL2_INCLUDE_DIR ~/.brew/include/SDL2/)
set(SDL2_LIBRARY ~/.brew/lib/)
include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARY})

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
        guimp_mouseclick.c
        guimp_use_tool.c
        tool_pencil.c
        libui/put_pixel.c
        libui/get_pixel.c
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
        libui/draw_line.c
        libui/keyhooks_init.c
        libui/draw_rect.c
        libui/keyhooks_mousebuttons.c
        save.c
        guimp_draw_canvas.c
        tool_hand.c
        tool_magnifying_glass.c
        libui/scaled_surfaces.c
        tool_bucket.c
        libui/flood_fill.c
        libui/draw_circle.c
        tool_circle.c
        checker.c
        widgets_draw.c
        libui/menu/menu_add.c
        libui/menu/calculate_menu.c
        libui/draw_thick_line.c
        libui/keyhooks_bind_key.c
        tool_text.c
        libui/draw_text.c
        guimp_undo.c
        libui/free_surface.c
        libui/duplicate_surface.c
        libui/menu/menu.c
        settool_1.c guimp_toggle_filled.c tool_brush.c guimp_mousewheel.c tool_eraser.c tool_line.c tool_rect.c
        tool_square.c tool_pipette.c libui/stickers.c tool_sticker_brush.c libui/menu/menu_table.c cursor_load.c cursor_set.c libui/generic_window/generic_windows.c libui/color_picker/convert_colors.c
        libui/color_picker/color_picker_window.c libui/color_picker/draw_gradients.c libui/color_picker/color_utils.c libui/color_picker/draw_info.c libui/color_picker/color_events.c
        libui/menu/menu_events.c libui/menu/menu_bar.c
        libui/generic_window/multiple_window_delete.c
        libui/generic_window/multiple_windows_utils.c libui/generic_window/generic_window_events.c
        text_editing_events.c
        text_render.c)

target_link_libraries(GUImp -lSDL2 -lm -lSDL2_image -lSDL2_ttf)