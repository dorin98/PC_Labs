#include <stdio.h>
#include <math.h>

void f (double (*fp)(double)){
	double x, y;
	for (x = 1 ; x <= 10 ; x += (1e-1))
	{
		y = (*fp)(x);
		printf ("%lf\n", y);
	}
}



int main ()
{
	double (*tablou[10])(double) = {sqrt, sin, cos, tan, exp, log};
	for (int i = 0 ; tablou[i] ; ++i){
		f(tablou[i]);		
	}
	return 0;
}
