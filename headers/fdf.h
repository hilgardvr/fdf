/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 08:21:46 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/07/02 16:25:00 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdio.h>

# define G_S 15
# define S_C 100

typedef struct	s_3d
{
	int			x;
	int			y;
	int			z;
	struct s_3d	*next;
}				t_3d;

typedef struct	s_pli
{
	int			start_x;
	int			start_y;
	int			start_z;
	int			end_x;
	int			end_y;
	int			end_z;
}				t_pli;

typedef struct	s_ctrs
{
	int			x;
	int			y;
}				t_ctr;

typedef struct	s_dda
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	float		dx;
	float		dy;
	float		step;
	float		xin;
	float		yin;
}				t_dda;

int				my_key_funct(int keycode);
int				check_args_open(int argc, char **argv);
int				convert_x(int x, int y);
int				convert_y(int x, int y, int z);
void			assign_new_lst(t_3d **temp_ptr, t_3d **lst_ptr, t_3d **new);
t_3d			*nn(t_3d *new, int x, int y, int z);
t_3d			*get_lst(const int fd, t_3d *lst_ptr);
void			print_line(void *mlx, void *win, t_pli pli);
void			print_lst_ver(void *mlx, void *win, t_3d *head_lst);
void			print_lst_hor(void *mlx, void *win, t_3d *head_lst);

#endif
