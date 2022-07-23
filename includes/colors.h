/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:51:32 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/05 11:35:32 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_COLORS_H
# define FRACTAL_COLORS_H

# include <limits.h>

# define WHITE          0x00FFFFFF
# define BLACK          0x00000000
# define RED            0x00FF0000
# define LIME           0x0000FF00
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

/*Hint: the max. RGB color value is: 16581375 (255 power 3)*/
# define NO_COLOR    INT_MAX

#endif