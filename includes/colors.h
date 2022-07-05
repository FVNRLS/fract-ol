/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:51:32 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/05 10:33:46 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_COLORS_H
# define FRACTAL_COLORS_H

# include <limits.h>

typedef struct s_color
{
    int in;
    int out;
}           t_color;

# define WHITE          0x00FFFFFF
# define BLACK          0x00000000
# define RED            0x00FF0000
# define LIME           0x0000FF00
# define BLUE           0x000000FF
# define YELLOW         0x00FFFF00
# define CYAN           0x0000FFFF
# define MAGENTA        0x00FF00FF
# define SILVER         0xC0C0C0
# define GRAY   	    0x808080
# define MAROON	        0x800000
# define OLIVE	        0x808000
# define GREEN  	    0x008000
# define PURPLE 	    0x800080
# define TEAL   	    0x008080
# define NAVY   	    0x000080

/*Hint: the max. RGB color value is: 16581375 (255 power 3)*/
# define NO_COLOR    INT_MAX

#endif