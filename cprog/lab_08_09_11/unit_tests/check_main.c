#include "check_solve_sle.h"
#include "check_sum_matrix.h"
#include "check_multy_matrix.h"

int main(void)
{
    int rc = 0;

    rc += sum_matrix_result();

    rc += sub_rows_result();

    rc += sle_result();

    rc += multy_matrix_result();

    rc += find_vector_result();

    return rc;
}
