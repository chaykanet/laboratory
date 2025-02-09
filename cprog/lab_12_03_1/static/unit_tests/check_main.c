#include "check_func_array.h"
#include "check_mysort.h"

int main(void)
{
    int rc = 0;

    rc += mysort_result();
    
    rc += key_result();

    rc += arrscan_toarray_result();

    return rc;
}
