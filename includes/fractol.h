

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h" 


# define WIDTH	800
# define HEIGHT	800


# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF


typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;


typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;


typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;




void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
double	atodbl(char *s);
double	ft_map(double unscaled_num, double new_min, double new_max, double old_max);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	putstr_fd(char *s, int fd);
int		key_handler(int keysym, t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);
int		close_handler(t_fractal *fractal);

#endif
