/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 09:24:54 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/07/02 16:24:23 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/fdf.h"
#include <fcntl.h>

int					my_key_funct(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int					check_args_open(int argc, char **argv)
{
	int				fd;

	if (argc != 2)
	{
		ft_putstr("usage ./prog file\n");
		exit(0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("Error");
		exit(0);
	}
	return (fd);
}

int					main(int argc, char **argv)
{
	int				fd;
	void			*mlx;
	void			*win;
	t_3d			*lst_head;

	lst_head = NULL;
	if ((fd = check_args_open(argc, argv)) < 0)
		return (EXIT_FAILURE);
	if ((mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((win = mlx_new_window(mlx, 1600, 1200, "mlx window")) == NULL)
		return (EXIT_FAILURE);
	mlx_key_hook(win, my_key_funct, 0);
	lst_head = get_lst(fd, lst_head);
	print_lst_hor(mlx, win, lst_head);
	print_lst_ver(mlx, win, lst_head);
	mlx_loop(mlx);
	return (0);
}
