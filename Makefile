LIBUI = libui/libui.a
LIBFT = libft/libft.a
HEADERS = guimp.h 
NAME = guimp

SRCS =  main.c \
        guimp_init.c \
        guimp_mouseclick.c \
        guimp_use_tool.c \
        tool_pencil.c \
        save.c \
        guimp_draw_canvas.c \
        tool_hand.c \
        tool_magnifying_glass.c \
        tool_bucket.c \
        tool_circle.c \
        tool_text.c \
        guimp_undo.c \
        settool_1.c \
        guimp_toggle_filled.c \
        tool_brush.c \
        guimp_mousewheel.c \
        tool_eraser.c \
        tool_line.c \
        tool_rect.c \
        tool_square.c \
        tool_pipette.c \
        stickers.c \
        tool_sticker_brush.c \
        menu_table.c \
        cursor_set.c \
        menu_events.c \
        menu_bar.c \
        text_editing_events.c \
        text_render.c \
        guimp_redo.c \
        settool_2.c \
        settool_3.c \
        convert_rect_to_square.c \
        tool_picture.c \
        menu_bar_23123767.c


OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
INCLUDES_SDL2 = -I ./SDL/SDL2.framework/Headers
INCLUDES_SDL2_IMAGE = -I ./SDL/SDL2_image.framework/Headers
INCLUDES_SDL2_TTF = -I ./SDL/SDL2_ttf.framework/Headers
INCLUDES_LIBFT = -I ./libft/includes
INCLUDES_LIBUI = -I ./libui
FRAMEWORK_SDL2 = -F ./SDL -framework SDL2 \
	-framework SDL2_image \
	-framework SDL2_ttf

all: libs $(NAME)

$(NAME): $(LIBUI) $(OBJS) 
	make -C ./libui
	@echo "\033[0;32mGUImp compiled\033[0;0m"
	gcc -o $(NAME) $(OBJS) $(LIBFT) $(LIBUI) $(INCLUDES_SDL2) $(INCLUDES_SDL2_IMAGE) -rpath @loader_path/sdl $(FRAMEWORK_SDL2)  $(INCLUDES_SDL2_TTF)

# $(FLAGS)

%.o: %.c $(HEADERS)
	@gcc -g -c $< -o $@ -I ./ $(INCLUDES_SDL2) $(INCLUDES_LIBFT) $(INCLUDES_LIBUI) \
$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF)

libs:
	make -C libui/

clean:
	-rm $(OBJS) && make -C libui/ clean

fclean: clean
	-rm $(NAME) && make -C libui/ fclean

re: fclean all
