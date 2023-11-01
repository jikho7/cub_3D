int sgn(float n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
	return (0);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// float	remainder(float a, float b)
// {
// 	int div;
// 	float res;

// 	div = a/b;
// 	res = a - (float)div * a/b;
// 	printf("%f / %f = %d r %f\n", a, b, div, res);
// 	return(a - (float)div * a/b);
// }
