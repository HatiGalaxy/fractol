#include "../includes/fractol.h"

static void	malloc_error(void)
{
	putstr_fd("Malloc error\n", 2);
    exit(1);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4.0;
	fractal->iterations_definition = 42;
	fractal->zoom = 1.0;

	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		fractal->shift_x = -0.5;
		fractal->shift_y = 0.0;
	}
	else if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->shift_x = 0.0;
		fractal->shift_y = 0.0;
	}
}


static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 2, 1L << 0, key_handler, fractal);
	mlx_hook(fractal->mlx_window, 4, 1L << 2, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, 17, 0, close_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_window)
		malloc_error();
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
		malloc_error();
	fractal->img.pixels_ptr = mlx_get_data_addr(
			fractal->img.img_ptr,
			&fractal->img.bpp,
			&fractal->img.line_len,
			&fractal->img.endian);
	data_init(fractal);
	events_init(fractal);
}
