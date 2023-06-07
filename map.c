#include <immintrin.h>

long double map(long double number,
                long double lower_bound, long double upper_bound,
                long double new_lower_bound, long double new_upper_bound)
    
{
	return new_lower_bound + number * (new_upper_bound - new_lower_bound) / (upper_bound - lower_bound);
}
