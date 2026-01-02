#include "../includes/fractol.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static double	get_fractional_part(char *s)
{
	double	fraction;
	double	divisor;

	fraction = 0;
	divisor = 1;
	while (is_digit(*s))
	{
		fraction = fraction * 10 + (*s - '0');
		divisor *= 10;
		s++;
	}
	return (fraction / divisor);
}

double	atodbl(char *s)
{
	long	integer;
	double	fraction;
	int		sign;

	integer = 0;
	fraction = 0;
	sign = 1;
	if (!s)
		exit(EXIT_FAILURE);
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	if (!is_digit(*s))
		exit(EXIT_FAILURE);
	while (is_digit(*s))
		integer = integer * 10 + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		if (!is_digit(*s))
			exit(EXIT_FAILURE);
		fraction = get_fractional_part(s);
	}
	return ((integer + fraction) * sign);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractal->zoom *= 0.9;
	else if (button == 5)
		fractal->zoom *= 1.1;
	fractal_render(fractal);
	return (0);
}
