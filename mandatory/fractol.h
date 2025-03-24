
#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define TITLE "Fractol"
# define HEIGHT 600
# define WIDTH 600

# define ESC 53

# define LEFT_MOUSE 1
# define RIGHT_MOUSE 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define R_KEY 15
# define PLUS_KEY 69
# define MINUS_KEY 78

# define CLOSE_BUTTON 17

typedef struct s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

t_complex		sum(t_complex z1, t_complex z2);
t_complex		square(t_complex z);
double			magnitude(t_complex z);

typedef struct s_data
{
	char			*name;
	unsigned int	color;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				iterations;
	double			zoom;
	t_complex		c;
	t_complex		z;

}				t_data;

int				close_window(t_data *data);
int				key_hook(int keycode, t_data *data);
int				mouse_hook(int button, int x, int y, t_data *data);

void			render(t_data data);
double			scale(double value, double min, double max, double dimension);

void			ft_write(char *str);
int				ft_strcmp(const char *s1, const char *s2);
double			ft_atodouble(char *str);
int				valid_value(char *str);
#endif