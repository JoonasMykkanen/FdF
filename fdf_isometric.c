
#include "fdf.h"

int	isometric_pos(pixel p, int n, char dir, char type)
{
	int pos;
	int	x_start;
	int	y_start;

	x_start = 480;
	y_start = 250;
	if (type == 'x')
	{
		if (dir == 'r')
		{
			if (n == 1)
			{
				pos = (p.count * p.x_offset) - (p.y * p.y_offset) + x_start;
			}
			else if (n == 2)
			{
				pos = ((p.count + 1) * p.x_offset) - (p.y * p.y_offset) + x_start;
			}
		}
		else if (dir == 'd')
		{
			if (n == 1)
			{
				pos = (p.count * p.x_offset) - (p.y * p.y_offset) + x_start;
			}
			else if (n == 2)
			{
				pos = (p.count * p.x_offset) - (p.y * p.y_offset) + x_start;
			}
		}
	}
	else if (type == 'y')
	{
		if (dir == 'r')
		{
			if (n == 1)
			{
				pos =  ((p.count * p.x_offset) + (p.y * p.y_offset)) / 2 + y_start;
			}
			else if (n == 2)
			{
				pos = (((p.count + 1) * p.x_offset) + (p.y * p.y_offset)) / 2 + y_start;
			}
		}
		else if (dir == 'd')
		{
			if (n == 1)
			{
				pos =  ((p.count * p.x_offset) + (p.y * p.y_offset)) / 2 + y_start;
			}
			else if (n == 2)
			{
				pos = ((p.count * p.x_offset) + (p.y * p.y_offset)) / 2 + y_start;
			}
		}
	}
	return (pos);
}