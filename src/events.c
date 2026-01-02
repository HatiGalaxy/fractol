#include "../includes/fractol.h"

#define K_ESC   65307
#define K_UP    65362
#define K_DOWN  65364
#define K_LEFT  65361
#define K_RIGHT 65363
#define K_PLUS  61
#define K_MINUS 45

int	close_handler(t_fractal *fractal)
{
	if (fractal->img.img_ptr)
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);

	if (fractal->mlx_window)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);

	if (fractal->mlx_connection)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
	exit(0);
}


int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == K_ESC)
		close_handler(fractal);
	else if (keysym == K_LEFT)
		fractal->shift_x -= 0.3 * fractal->zoom;
	else if (keysym == K_RIGHT)
		fractal->shift_x += 0.3 * fractal->zoom;
	else if (keysym == K_UP)
		fractal->shift_y += 0.3 * fractal->zoom;
	else if (keysym == K_DOWN)
		fractal->shift_y -= 0.3 * fractal->zoom;
	else if (keysym == K_PLUS)
		fractal->iterations_definition += 10;
	else if (keysym == K_MINUS && fractal->iterations_definition > 10)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}
