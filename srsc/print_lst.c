/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 14:16:39 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/07/02 15:59:36 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/fdf.h"

int					convert_x(int x, int y)
{
	x = (x - y) + 300;
	return (x);
}

int					convert_y(int x, int y, int z)
{
	y = x + (y - (z * G_S / 2)) / 2;
	return (y);
}

void				print_line(void *mlx, void *win, t_pli pli)
{
	t_dda			dda;
	int				ctr;

	ctr = 0;
	dda.x1 = convert_x(pli.start_x, pli.start_y);
	dda.y1 = convert_y(pli.start_x, pli.start_y, pli.start_z);
	dda.x2 = convert_x(pli.end_x, pli.end_y);
	dda.y2 = convert_y(pli.end_x, pli.end_y, pli.end_z);
	dda.dx = dda.x2 - dda.x1;
	dda.dy = dda.y2 - dda.y1;
	if (dda.dx >= dda.dy)
		dda.step = dda.dx;
	else
		dda.step = dda.dy;
	dda.dx /= dda.step;
	dda.dy /= dda.step;
	while (ctr < dda.step)
	{
		dda.x1 += dda.dx;
		dda.y1 += dda.dy;
		mlx_pixel_put(mlx, win, (S_C + dda.x1), (S_C + dda.y1), 0x0FFFFFF);
		ctr++;
	}
}

void				print_lst_ver(void *mlx, void *win, t_3d *head_lst)
{
	t_3d			*start;
	t_3d			*end;
	t_pli			pli;

	start = head_lst;
	end = start;
	while (end && end->next)
	{
		pli.start_x = start->x;
		pli.start_y = start->y;
		pli.start_z = start->z;
		end = end->next;
		if (end == start && end->next != NULL)
			end = end->next;
		while (end->x != start->x && end->next != NULL)
			end = end->next;
		start = start->next;
		pli.end_x = end->x;
		pli.end_y = end->y;
		pli.end_z = end->z;
		print_line(mlx, win, pli);
	}
}

void				print_lst_hor(void *mlx, void *win, t_3d *head_lst)
{
	t_pli			pli;
	t_3d			*ptr;
	t_3d			*temp;

	ptr = head_lst;
	temp = head_lst;
	while (temp && temp->next)
	{
		pli.start_x = temp->x;
		pli.start_y = temp->y;
		pli.start_z = temp->z;
		temp = temp->next;
		pli.end_x = temp->x;
		pli.end_y = temp->y;
		pli.end_z = temp->z;
		print_line(mlx, win, pli);
	}
}
