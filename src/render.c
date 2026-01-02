#include "../includes/fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

/*
	Mandelbrot:
		z = 0
		c = pixel

	Julia:
		z = pixel
		c = sabit
*/
static void	handle_type(int x, int y, t_fractal *f, t_complex *z, t_complex *c)
{
	double	scale;

	scale = 3.0 / WIDTH;

	if (!ft_strncmp(f->name, "mandelbrot", 10))
	{
		z->x = 0.0;
		z->y = 0.0;
		c->x = (x - WIDTH / 2.0) * scale * f->zoom + f->shift_x;
		c->y = (HEIGHT / 2.0 - y) * scale * f->zoom + f->shift_y;
	}
	else if (!ft_strncmp(f->name, "julia", 5))
	{
		z->x = (x - WIDTH / 2.0) * scale * f->zoom + f->shift_x;
		z->y = (HEIGHT / 2.0 - y) * scale * f->zoom + f->shift_y;
		c->x = f->julia_x;
		c->y = f->julia_y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	handle_type(x, y, fractal, &z, &c);
	while (i < fractal->iterations_definition)
	{
		double	tmp_x = z.x * z.x - z.y * z.y + c.x;

		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp_x;
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = ft_map(i, BLACK, WHITE,
					fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
