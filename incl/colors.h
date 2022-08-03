/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:51:32 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/03 18:20:11 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <limits.h>
# include "structs.h"

/*Hint: the max. RGB color value is: 16581375 (255 power 3)*/
# define NO_COLOR		INT_MAX
# define WHITE			0x00FFFFFF
# define BLACK			0x00000000
# define RED			0x00FF0000
# define LIME			0x0000FF00
# define BLUE           0x000000FF
# define YELLOW         0x00FFFF00
# define CYAN           0x0000FFFF
# define MAGENTA        0x00FF00FF
# define SILVER         0x00C0C0C0
# define GRAY   	    0x00808080
# define MAROON	        0x00800000
# define OLIVE	        0x00808000
# define GREEN  	    0x00008000
# define PURPLE 	    0x00800080
# define TEAL   	    0x00008080
# define NAVY   	    0x00000080

//COLORIZER
int		get_transparency(int trgb);
int		get_red(int trgb);
int		get_green(int trgb);
int		get_blue(int trgb);
int		convert_rgb_to_hex(int t, int r, int g, int b);
int		new_bgr_gradient(int trgb, double mod);
int		new_outln_gradient(int trgb, double mod);
int		new_aura(int trgb, t_fract *fr);
int		invert_colors(int trgb, t_fract *fr);
void	colorize_img_to_black(t_gui *gui);
void	colorize_with_gradient(t_gui *img, t_fract *fr, t_color *color);
void	colorize_with_inverted_colors(t_gui *img, t_fract *fr, t_color *color);
void	colorize_with_basic_colors(t_gui *img, t_fract *fr, t_color *color);
void	colorize_with_aura(t_gui *img, t_fract *fr, t_color *color);
void	colorize_julia_with_gradient(t_gui *img, t_fract *fr, t_color *color);
void	colorize_burning_ship(t_gui *img, t_fract *fr, t_color *color);

//COLOR RANGE SHIFTER
# define SHIFT_FACTOR   10

void	increase_red(t_gui *gui);
void	decrease_red(t_gui *gui);
void	increase_green(t_gui *gui);
void	decrease_green(t_gui *gui);
void	increase_blue(t_gui *gui);
void	decrease_blue(t_gui *gui);

#endif