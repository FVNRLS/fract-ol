/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:54:24 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 14:29:03 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "structs.h"

//COLOR RANGE SHIFTER
# define SHIFT_FACTOR   10

void	increase_red(t_gui *gui);
void	decrease_red(t_gui *gui);
void	increase_green(t_gui *gui);
void	decrease_green(t_gui *gui);
void	increase_blue(t_gui *gui);
void	decrease_blue(t_gui *gui);

//ARROW KEYS HOOKS
void	check_arrow_keys(int keycode, t_gui *gui);
void	check_fractal_hotkeys(int keycode, t_gui *gui);
void	check_color_shift_keys(int keycode, t_gui *gui);
void	check_info_printing_keys(int keycode);
void	move_up(t_gui *gui);
void	move_down(t_gui *gui);
void	move_left(t_gui *gui);
void	move_right(t_gui *gui);

//MOUSE KEY/WHEEL HOOKS
int		check_mouse_hooks(int keycode, int x, int y, t_gui *gui);
int		close_window(t_gui *gui);
void	zoom_in(t_gui *gui, int x, int y);
void	zoom_out(t_gui *gui, int x, int y);

//ADDITIONAL FRACTALS
void	print_burn_ship(t_args *args, t_gui *gui, t_fract *fr, t_color *color);
void	print_std_burn_ship(t_gui *gui, t_fract *fr, t_color *color);

#endif
