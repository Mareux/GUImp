LIB = ../libft/libft.a
HEADERS = ../doom_nukem.h editor.h ../serialization/serialization.h
NAME = editor


SRCS = ../serialization/serialization.c \
		../serialization/deserialization_sector.c \
		../serialization/converter_to_bytes.c \
		../serialization/utilities_for_serialization.c\
        ../serialization/file.c \
        ../serialization/serialize_sector.c \
        ../serialization/serialize_sector_2.c \
        ../serialization/serialize_texture.c \
        ../serialization/serialize_soundtrack.c \
        ../serialization/serialize_player.c \
        ../serialization/push_back.c \
        ../serialization/for_deserialization_sector.c \
        widgets_draw.c \
        draw.c init.c \
        text_render.c \
        text_editing_events.c \
        checker.c \
        form_create.c \
        widgets_create.c \
        form_draw.c \
        utils.c \
        events/button_points_events.c \
        events/button_points_events_2.c \
        events/button_points_events_3.c \
        events/button_points_events_4.c \
        draw_in_drawbox.c \
        widgets_add_to_lists.c \
        events_combobox.c \
        widgets_combobox_scrolling_data.c \
        widgets_combobox_utils.c \
        events/button_create_lvl_clicked.c \
        events/button_save_file_clicked.c \
        multiple_windows_utils.c \
        multiple_windows_forms.c \
        multiple_windows_create.c \
        events.c \
        events/button_combobox_window_event.c \
        widget_textfield_utils.c \
        ft_atof.c \
        events/button_sectors_event.c \
        events/button_sectors_event_2.c \
        delete_data_at_selected_point.c \
        delete_data.c \
        sprites_data.c \
        check_null.c \
        ../collisions_main.c \
        ../collisions_init.c \
        ../collisions_check_sector.c \
        ../collisions_collide_with_wall.c \
        ../collisions_slide.c \
        ../light_control.c \
        ../draw_floor_and_ceiling.c \
        ../draw_floor_and_ceiling_2.c \
        ../draw_wall.c \
        ../draw_wall_2.c \
        ../draw_bullet_holes.c \
        ../draw_bullet_holes_2.c \
        ../init.c \
        ../put_pixel.c \
        ../get_pixel.c \
        ../vectors.c \
        ../vectors_2.c \
        ../vectors_3.c \
        ../color.c \
        ../process_input.c \
        ../process_game_input.c \
        ../utilities.c \
        ../map_sectors.c \
        ../map_sectors_2.c \
        ../connect_sectors.c \
        ../connect_sectors_2.c \
        ../player_move.c \
        ../update_vertical_pos.c \
        ../update_vertical_pos_2.c \
        ../update_player_height.c \
        ../update_player_pos.c \
        ../update_enemies.c \
        ../render.c \
        ../cast_ray.c \
        ../cast_ray_2.c \
        ../find_closest_wall.c \
        ../floor_and_ceiling.c \
        ../floor_and_ceiling_2.c \
        ../images.c \
        ../images_check.c \
        ../update.c \
        ../sprites.c \
        ../sprites_add.c \
        ../sprites_prepare_sprites.c \
        ../sprites_prepare_bullets.c \
        ../sprites_sort_sprites.c \
        ../sprites_prepare_to_draw.c \
        ../sprites_crate.c \
        ../check_sprites.c \
        ../bullets.c \
        ../player_shoot.c \
        ../player_take_damage.c \
        ../update_bullets.c \
        ../update_bullets_2.c \
        ../bullets_sprite_collision.c \
        ../bullet_holes.c \
        ../draw_decoration.c \
        ../change_floor_and_ceiling.c \
        ../elevator.c \
        ../decorations_interact.c \
        ../update_elevator.c \
        ../update_light.c \
        ../update_doors.c \
        ../doors.c \
        ../hud.c \
        ../init_hud.c \
        ../ft_strjoinfree.c \
        ../is_inside_sector.c \
        ../audio_add.c \
        ../audio_init.c \
        ../audio_play.c \
        ../audio_utils.c \
        scrolling_list_data.c \
        scrolling_list_combobox_render.c \
        events/button_add_sprite_action.c \
        widgets_delete.c \
        multiple_window_delete.c \
        button_handler.c \
        events/button_add_light.c \
        events/button_add_elevator.c \
        textures.c \
        events/button_point_add_portal.c \
        events/button_point_color.c \
        events/button_add_player.c \
        ui_bg.c ui_draw_line.c \
        ui_draw_sector.c \
        ui_draw_map.c \
        ui_update_labels.c \
        valid_sector.c \
        valid_portal.c \
        widget_textfield_validator.c \
        events/button_add_texture_clicked.c \
        ../soundtraks.c \
        ../audio_callback_function.c events_2.c \
        main.c \
        form_create_cat.c \
        form_create_cactus.c \
        form_create_otter.c \
        form_create_oikakslozhno.c \
        events/button_delete_map.c \
        ui_draw_map_2.c \
        ui_update_labels_2.c \
        ui_update_labels_3.c

OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
INCLUDES_SDL2 = -I ../SDL/SDL2.framework/Headers
INCLUDES_SDL2_IMAGE = -I ../SDL/SDL2_image.framework/Headers
INCLUDES_SDL2_TTF = -I ../SDL/SDL2_ttf.framework/Headers
INCLUDES_LIBFT = -I ../libft/includes
FRAMEWORK_SDL2 = -F ../SDL -framework SDL2 \
	-framework SDL2_image \
	-framework SDL2_ttf

all: libs $(NAME)

$(NAME): $(LIB) $(OBJS) 
	make -C ../libft
	@echo "\033[0;32mEditor compiled\033[0;0m"
	@gcc -o $(NAME) $(FLAGS) $(LIB) $(INCLUDES_SDL2) $(INCLUDES_SDL2_IMAGE) -rpath @loader_path/../sdl $(FRAMEWORK_SDL2) $(OBJS) $(INCLUDES_SDL2_TTF)

%.o: %.c $(HEADERS)
	@gcc -g $(FLAGS) -o $@ -c $< -I ./ $(INCLUDES_SDL2) $(INCLUDES_LIBFT) \
$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF)

libs:
	make -C ../libft/

clean:
	-rm $(OBJS) && make -C ../libft/ clean

fclean: clean
	-rm $(NAME) && make -C ../libft/ fclean

re: fclean all
