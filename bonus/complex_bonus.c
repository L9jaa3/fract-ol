
#include "fractol_bonus.h"

t_complex	sum(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = z1.real + z2.real;
	res.imaginary = z1.imaginary + z2.imaginary;
	return (res);
}

t_complex	square(t_complex z)
{
	t_complex	res;

	res.real = (z.real * z.real) - (z.imaginary * z.imaginary);
	res.imaginary = 2 * z.real * z.imaginary;
	return (res);
}

t_complex	absolute(t_complex z)
{
	t_complex	res;

	res.real = z.real;
	res.imaginary = z.imaginary;
	if (res.real < 0)
		res.real = -res.real;
	if (res.imaginary < 0)
		res.imaginary = -res.imaginary;
	return (res);
}

double	magnitude(t_complex z)
{
	return (sqrt((z.real * z.real) + (z.imaginary * z.imaginary)));
}
