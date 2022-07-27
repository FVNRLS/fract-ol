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

#endif
