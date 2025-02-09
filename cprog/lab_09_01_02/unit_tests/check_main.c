#include "check_sort.h"
#include "check_read_array.h"
#include "check_compare_density.h"

int main(void)
{   
    int rc = 0;

    rc += read_array_result();

    rc += sort_array_result();

    rc +=  compare_density_result();

    return rc;
}
