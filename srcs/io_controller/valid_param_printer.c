/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_param_printer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:20:29 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:57:06 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	print_valid_colors(void)
{
	ft_printf("     ✩░▒▓▆▅▃▂▁COLORS AND PRESETS▁▂▃▅▆▓▒░✩\n");
	ft_printf(".--------------------------------------------.\n"
		"|            COLORS:         PRESETS:        |\n"
		"|                                            |\n"
		"|            WHITE           MATRIX          |\n"
		"|            BLACK           STD_BLUE        |\n"
		"|            RED             STD_RED         |\n"
		"|            LIME            STD_TEAL        |\n"
		"|            BLUE            STD_GREEN       |\n"
		"|            YELLOW          ACID            |\n"
		"|            CYAN            CMYK            |\n"
		"|            MAGENTA         DEPRESSIVE      |\n"
		"|            SILVER          BLOODY          |\n"
		"|            GRAY            UGLY            |\n"
		"|            MAROON                          |\n"
		"|            OLIVE                           |\n"
		"|            GREEN                           |\n"
		"|            PURPLE                          |\n"
		"|            TEAL                            |\n"
		"|            NAVY                            |\n"
		".--------------------------------------------.\n");
}

void	print_valid_julia_consts(void)
{
	ft_printf("✩░▒▓▆▅▃▂▁JULIA CONSTANTS▁▂▃▅▆▓▒░✩\n");
	ft_printf(".-------------------------------.\n"
		"|       −0.4     |   0.6        |\n"
		"|        0.285   |   0          |\n"
		"|        0.285   |   0.01       |\n"
		"|        0.285   |   0.45       |\n"
		"|       -0.70176 |  -0.3842     |\n"
		"|       -0.835   |  -0.2321     |\n"
		"|       -0.8     |   0.156      |\n"
		"|       −0.7269  |   0.1889     |\n"
		"|       -0.8     |   0          |\n"
		".------------------------------.\n");
}

static void	print_main_hotkeys_info(void)
{
	ft_printf(".-----------------------------------------------------.\n"
		"|    MENU KEYS:                                       |\n"
		"|    I       SHOW VERBOSE USAGE INFORMATION           |\n"
		"|    C       SHOW VALID COLORS AND PRESETS            |\n"
		"|    K       SHOW VALID JULIA CONSTANTS               |\n"
		"|    H       SHOW HOTKEYS                             |\n"
		"|    ESC     EXIT THE PROGRAM                         |\n"
		"|                                                     |\n"
		"|    MANDELBROT PRESETS:                              |\n"
		"|    1       MATRIX                                   |\n"
		"|    2       STD_BLUE                                 |\n"
		"|    3       STD_RED                                  |\n"
		"|    4       STD_TEAL                                 |\n"
		"|    5       STD_GREEN                                |\n"
		"|    6       ACID                                     |\n"
		"|    7       CMYK                                     |\n"
		"|    8       DEPRESSIVE                               |\n"
		"|    9       BLOODY                                   |\n"
		"|    0       UGLY                                     |\n"
		"|                                                     |\n"
		"|    OTHER FRACTALS:                                  |\n"
		"|    J       SWITCH TO JULIA                          |\n"
		"|    B       SWITCH TO BURNING SHIP                   |\n");
}

static void	print_add_hotkeys_info(void)
{
	ft_printf("|                                                     |\n"
		"|    MOUSEWHEEL SCROLLING:                            |\n"
		"|    UP      ZOOM IN                                  |\n"
		"|    DOWN    ZOOM OUT                                 |\n"
		"|                                                     |\n"
		"|    ARROW KEYS:                                      |\n"
		"|    UP      MOVE PICTURE UP                          |\n"
		"|    DOWN    MOVE PICTURE DOWN                        |\n"
		"|    LEFT    MOVE PICTURE LEFT                        |\n"
		"|    RIGHT   MOVE PICTURE RIGHT                       |\n"
		"|                                                     |\n"
		"|    PLAY WITH BACKGROUND COLOR:                      |\n"
		"|    Q       INCREASE RED VALUE                       |\n"
		"|    A       DECREASE RED VALUE                       |\n"
		"|    W       INCREASE GREEN VALUE                     |\n"
		"|    S       DECREASE GREEN VALUE                     |\n"
		"|    E       INCREASE BLUE VALUE                      |\n"
		"|    D       DECREASE BLUE VALUE                      |\n"
		".-----------------------------------------------------.\n");
}

void	print_all_hotkeys(void)
{
	ft_printf("                 ✩░▒▓▆▅▃▂▁HOTKEYS▁▂▃▅▆▓▒░✩\n");
	print_main_hotkeys_info();
	print_add_hotkeys_info();
}
