#include "map.h"

long double map(long double number,
                long double lower_bound, long double upper_bound,
                long double new_lower_bound, long double new_upper_bound)
    
{
	return new_lower_bound + number * (new_upper_bound - new_lower_bound) / (upper_bound - lower_bound);
}

void fractal_map(int number, const FractalData *f, FractalData *output)
{
	output->a = f->nlb + number * (f->nub - f->nlb) / (f->ub - f->lb);
	output->b = f->nlb + number * (f->nub - f->nlb) / (f->ub - f->lb);
}




