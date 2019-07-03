cmake_minimum_required(VERSION 3.14)
project(GUImp C)

set(CMAKE_C_STANDARD 11)

#find_package(SDL2 REQUIRED)
#find_package(SDL_ttf REQUIRED)
#find_package(SDL_image REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS})
#link_directories(${SDL2_LIBRARY})

set(SDL2_INCLUDE_DIR ~/.brew/include/SDL2/)
set(SDL2_LIBRARY ~/.brew/lib/)
include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARY})


file(GLOB libft
        "libft/*.c")

add_executable(GUImp
        ${libft}
        libft/libft.h
        button_handler.c
        check_null.c
        checker.c
        draw.c
        draw_in_drawbox.c
        guimp.h
        events.c
        events_2.c
        events_combobox.c
        form_draw.c
        ft_atof.c
        init.c
        main.c
        multiple_window_delete.c
        multiple_windows_create.c
        multiple_windows_forms.c
        multiple_windows_utils.c
        scrolling_list_combobox_render.c
        scrolling_list_data.c
        text_editing_events.c
        text_render.c
        ui_bg.c
        ui_draw_line.c
        utils.c
        widget_textfield_utils.c
        widget_textfield_validator.c
        widgets_add_to_lists.c
        widgets_combobox_utils.c
        widgets_create.c
        widgets_delete.c
        widgets_draw.c
        get_pixel.c
        put_pixel.c
        color.c libui/libui.h)

target_link_libraries(GUImp -lSDL2 -lm -lSDL2_image -lSDL2_ttf)