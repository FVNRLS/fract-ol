/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:56:54 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 16:27:13 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "structs.h"

/* *****************MAC_OS KEY HOOKS ***************** */

//EVENTS (BUILD IN INTERFACE ELEMENTS (e.g: red cross to close a window))
# define ON_DESTROY 17

// MOUSE HOOKS
# define ZOOM_IN	5
# define ZOOM_OUT	4

//KEYBOARD HOOKS
# define ESC 		53

//PRESETS KEYS
# define ONE 		18
# define TWO 		19
# define THREE		20
# define FOUR 		21
# define FIVE 		23
# define SIX 		22
# define SEVEN		26
# define EIGHT		28
# define NINE 		25
# define ZERO 		29

//ARROW KEYS HOOKS
# define UP 		126
# define DOWN 		125
# define LEFT 		123
# define RIGHT		124

//FRACTAL HOTKEYS
# define J 			38
# define B 			11

//COLOR RANGE INCREASE/DECREASE KEY HOOKS
# define Q 			12
# define W 			13
# define E 			14
# define A 			0
# define S 			1
# define D 			2

//INFO PRINTERS
# define C 			8
# define K 			40
# define I 			34
# define H 			4

/* HOOKS FUNCTIONS */
void	check_win_hooks(t_gui *gui);

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
