#include <immintrin.h>

long double map(long double number,
                long double lower_bound, long double upper_bound,
                long double new_lower_bound, long double new_upper_bound)
    
{
    long double percent = number / (upper_bound - lower_bound);
    long double new_range = new_upper_bound - new_lower_bound;
    long double scaled_number = new_range * percent;

    return new_lower_bound + scaled_number;
}
