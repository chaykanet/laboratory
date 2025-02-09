#include "limits.h"
#include "errcodes.h"
#include "object_t.h"
#include "object_t_array.h"

int main(int argc, char **argv)
{   
    int rc = ERR_OK;
    struct object_t list[N];    
    size_t size = 0;

    if (argc == MAX_ARGUMENTS || argc == MAX_ARGUMENTS - 1)
    {   
        rc = read_array(argv[1], list, &size, N);

        if (size == 0)
            rc = ERR_EMPTY;

        if (argc == MAX_ARGUMENTS && rc == ERR_OK)
        {       
            if (strcmp(argv[2], ALL) == 0)
                print_array(list, size);
            else
                rc = print_with_prefix(list, size, argv[2]);
        }
        else if (rc == ERR_OK)
        {           
            sort_array(list, size);
            
            print_array(list, size);
        }
    }
    else
        rc = ERR_ARG;

    return rc;
}
