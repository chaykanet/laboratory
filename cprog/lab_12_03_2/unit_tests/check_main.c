#include "check_arr.h"

int main(void)
{
    int rc = 0;

    rc += calc_even_result();

    rc += add_num_after_even_result();

    rc += fill_prime_result();

    return rc;
}
