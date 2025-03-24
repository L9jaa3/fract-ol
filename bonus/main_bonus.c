
#include "fractol_bonus.h"

static void	ft_error(void *value)
{
	if (!value)
		exit(EXIT_FAILURE);
}

static void	data_init(t_data *data)
{
	if (!ft_strcmp(data->name, "julia"))
		data->color = 0xF0FF0000;
	else
		data->color = 0x00050709;
	data->iterations = 100;
	data->zoom = 1.0;
	data->lock_mouse = 1;
	data->x_offset = 0.0;
	data->y_offset = 0.0;
	data->mlx = mlx_init();
	ft_error(data->mlx);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	ft_error(data->win);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	ft_error(data->img);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel,
			&data->size_line,
			&data->endian);
	ft_error(data->addr);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 6, 0, mouse_move, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, CLOSE_BUTTON, 0, close_window, data);
}

static void	display_usage(void)
{
	ft_write("Usage:\n");
	ft_write("./fractol mandelbrot\n");
	ft_write("./fractol julia 0.45 0.2\n");
	ft_write("./fractol burningship\n");
	ft_write("Controls:\n");
	ft_write("arrow keys move\n");
	ft_write("mouse wheel zoom\n");
	ft_write("left click change color\n");
	ft_write("right click lock/unlock julia\n");
	ft_write("+/- add/reduce detail\n");
	ft_write("r key reset\n");
}

static void	handle_args(int argc, char **argv, t_data *data)
{
	if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
	{
		data->name = "mandelbrot";
		return ;
	}
	else if (argc == 4 && !ft_strcmp(argv[1], "julia")
		&& valid_value(argv[2])
		&& valid_value(argv[3]))
	{
		data->name = "julia";
		data->c.real = ft_atodouble(argv[2]);
		data->c.imaginary = -ft_atodouble(argv[3]);
		return ;
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "burningship"))
	{
		data->name = "burningship";
		return ;
	}
	display_usage();
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	handle_args(argc, argv, &data);
	data_init(&data);
	render(data);
	mlx_loop(data.mlx);
}
