/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:57:07 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 14:42:40 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>

typedef struct s_fract
{
	double	c_re;
	double	c_im;
	double	j_re;
	double	j_im;
	double	z;
	double	z_re;
	double	z_im;
	double	sum_re;
	double	sum_im;
	int		x_cor;
	int		y_cor;
	double	x_scal;
	double	y_scal;
	int		iter;
	int		max_iter;
	bool	left_padded;
	double	x_offset;
	double	y_offset;
	double	vert_mod;
	double	horiz_mod;
	int		type;
	double	view_scope;
	double	new_x_offset;
	double	new_y_offset;
	bool	zoom_activated;
}			t_fract;

typedef struct s_color
{
	int		in;
	int		out;
	int		outln;
	bool	preset_found;
}			t_color;

typedef struct s_args
{
	char	**argv;
	int		argc;
}			t_args;

typedef struct s_gui
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	mouse_x_pos;
	double	mouse_y_pos;
	t_fract	*fract;
	t_color	*color;
	t_args	*args;
}			t_gui;

#endif
