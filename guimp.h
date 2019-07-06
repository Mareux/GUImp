/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:55:25 by ibarabas          #+#    #+#             */
/*   Updated: 2019/06/29 21:10:33 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_EDITOR_H
# define DOOM_NUKEM_EDITOR_H

# include "libft/libft.h"
# include "libui/libui.h"

# define WHITE_SPACES(c) ((c) == ' ' || (c) == '\t')
# define VALID_DIGIT(c) ((c) >= '0' && (c) <= '9')

# define TRUE 1
# define FALSE 0
# define CLICK_BUTTON 0
# define TOGGLE_BUTTON 1
# define WINDOW_W 1920
# define WINDOW_H 1080

# define TWO_TEXTFIELD_WINDOW 0
# define COMBOBOX_WINDOW 1
# define LABEL_WINDOW 2
# define TEXTFIELD_WINDOW 3
# define MAIN_WINDOW 4

# define TEXT 0
# define DIGITS 1


void				loop(t_libui *unicorn);
void				eventloop_keydown(t_libui *data, int *quit);


#endif
