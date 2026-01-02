#include "../includes/fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	putstr_fd(char *s, int fd)
{
	while (s && *s)
		write(fd, s++, 1);
}

double	ft_map(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled / old_max + new_min);
}
