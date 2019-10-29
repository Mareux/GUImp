LIB = libft/libft.a
HEADERS = doom_nukem.h serialization/serialization.h
NAME = doom-nukem

SRCS = main.c \
        collisions_main.c \
        collisions_init.c \
        collisions_check_sector.c \
        collisions_collide_with_wall.c \
        collisions_slide.c \
        light_control.c \
        draw_floor_and_ceiling.c \
        draw_floor_and_ceiling_2.c \
        draw_wall.c \
        draw_wall_2.c \
        draw_bullet_holes.c \
        draw_bullet_holes_2.c \
        init.c \
        put_pixel.c \
        get_pixel.c \
        vectors.c \
        vectors_2.c \
        vectors_3.c \
        color.c \
        process_input.c \
        process_game_input.c \
        utilities.c \
        map_sectors.c \
        map_sectors_2.c \
        connect_sectors.c \
        connect_sectors_2.c \
        player_move.c \
        update_vertical_pos.c \
        update_vertical_pos_2.c \
        update_player_height.c \
        update_player_pos.c \
        update_enemies.c \
        render.c \
        cast_ray.c \
        cast_ray_2.c \
        find_closest_wall.c \
        floor_and_ceiling.c \
        floor_and_ceiling_2.c \
        images.c \
        images_check.c \
        update.c \
        sprites.c \
        sprites_add.c \
        sprites_prepare_sprites.c \
        sprites_prepare_bullets.c \
        sprites_sort_sprites.c \
        sprites_prepare_to_draw.c \
        sprites_crate.c \
        check_sprites.c \
        bullets.c \
        player_shoot.c \
        player_take_damage.c \
        update_bullets.c \
        update_bullets_2.c \
        bullets_sprite_collision.c \
        bullet_holes.c \
        draw_decoration.c \
        change_floor_and_ceiling.c \
        elevator.c \
        decorations_interact.c \
        update_elevator.c \
        update_light.c \
        update_doors.c \
        doors.c \
        hud.c \
        init_hud.c \
        ft_strjoinfree.c \
        is_inside_sector.c \
        audio_callback_function.c \
        serialization/serialization.c \
        serialization/deserialization_sector.c \
        serialization/converter_to_bytes.c \
        serialization/utilities_for_serialization.c \
        serialization/file.c serialization/serialize_sector.c \
        serialization/serialize_sector_2.c \
        serialization/for_deserialization_sector.c \
        serialization/serialize_texture.c \
        serialization/serialize_soundtrack.c \
        soundtraks.c \
        serialization/serialize_player.c \
        serialization/push_back.c \
        sounds_play.c \
        audio_init.c \
        audio_utils.c \
        audio_add.c \
        audio_play.c


OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
INCLUDES_SDL2 = -I ./SDL/SDL2.framework/Headers
INCLUDES_SDL2_IMAGE = -I ./SDL/SDL2_image.framework/Headers
INCLUDES_SDL2_TTF = -I ./SDL/SDL2_ttf.framework/Headers
INCLUDES_LIBFT = -I ./libft/includes
FRAMEWORK_SDL2 = -F ./SDL -framework SDL2 \
	-framework SDL2_image \
	-framework SDL2_ttf

all: libs $(NAME) level_editor

$(NAME): $(LIB) $(OBJS) 
	make -C ./libft
	@echo "\033[0;32mDoom-nukem compiled\033[0;0m"
	@gcc -o $(NAME) $(FLAGS) $(LIB) $(INCLUDES_SDL2) $(INCLUDES_SDL2_IMAGE) -rpath @loader_path/sdl $(FRAMEWORK_SDL2) $(OBJS) $(INCLUDES_SDL2_TTF)

%.o: %.c $(HEADERS)
	@gcc -g $(FLAGS) -o $@ -c $< -I ./ $(INCLUDES_SDL2) $(INCLUDES_LIBFT) \
$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF)

level_editor:
	make -C editor/

libs:
	make -C libft/

clean:
	-rm $(OBJS) && make -C libft/ clean && make -C editor/ clean

fclean: clean
	-rm $(NAME) && rm editor/editor && make -C libft/ fclean && make -C editor/ fclean

re: fclean all
