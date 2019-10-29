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
        libui/events_keydown.c
        libui/init.c
        libui/utils.c
        libui/vectors.c
        libui/window_options.c
        libui/widgets/widgets_create.c
        libui/widgets_add_to_lists.c
        libui/widgets/widgets_delete.c
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
        libui/checker.c
        libui/widgets/widgets_draw.c
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
        tool_square.c tool_pipette.c stickers.c tool_sticker_brush.c menu_table.c libui/cursor_load.c cursor_set.c libui/generic_window/generic_windows.c libui/color_picker/convert_colors.c
        libui/color_picker/color_picker_window.c libui/color_picker/draw_gradients.c libui/color_picker/color_utils.c libui/color_picker/draw_info.c libui/color_events.c
        menu_events.c menu_bar.c
        libui/generic_window/multiple_window_delete.c
        libui/generic_window/multiple_windows_utils.c libui/generic_window/generic_window_events.c
        text_editing_events.c
        text_render.c libui/blit_surface.c guimp_redo.c libui/save_jpg.c libui/create_surface.c settool_2.c settool_3.c convert_rect_to_square.c libui/draw_circle_2.c libui/flood_fill_2.c libui/events_mouse.c libui/find_window_by_id.c
        libui/update_window_surface.c tool_picture.c libui/generic_window/return_data.c libui/menu/menu_2.c libui/menu/resize_menu.c libui/set_system_cursor.c libui/events_2.c libui/menu_bar_2.c menu_bar_23123767.c)

target_link_libraries(GUImp -lSDL2 -lm -lSDL2_image -lSDL2_ttf)