/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:30:43 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:02:50 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "structs.h"

# define WINSIZE  500
# define ZOOM     0.75

//ADDITIONAL MLX FUNCTIONS
void	my_mlx_pixel_put(t_gui *data, int x, int y, int color);

//IMAGE UPDATERS
void	update_image_to_3d(t_gui *gui, t_fract *fr, t_color *color);
void	update_image_to_standard(t_gui *gui, t_fract *fr, t_color *color);
void	update_image_to_psychedelic(t_gui *gui, t_fract *fr, t_color *color);
void	update_image_to_julia(t_gui *gui, t_fract *fr, t_color *color);
void	update_image_to_burningship(t_gui *gui, t_fract *fr, t_color *color);

#endif
