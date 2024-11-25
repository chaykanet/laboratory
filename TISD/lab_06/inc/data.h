#ifndef __DATA_H__
#define __DATA_H__

#include "tree.h"
#include "tree_io.h"
#include "errcodes.h"

int make_n_times(FILE *data, const size_t n);

int check_data(int const day, int const mon);

#endif
