#include "data.h"

int check_data(int const day, int const mon)
{   
    switch (mon)
    {
    case 1:  
    case 3:  
    case 5: 
    case 7: 
    case 8:  
    case 10:
    case 12: 
        if (day > 31)
            return ERR_DATA;
        break;
    case 4:  
    case 6:  
    case 9:  
    case 11: 
        if (day > 30)
            return ERR_DATA;
        break;
    case 2:  
        if (day > 28)
            return ERR_DATA;
        break;
    default:
        return ERR_DATA;
        break;
    }

    return ERR_OK;
}

node_t *make_tree_alph(node_t *tree, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        char *name = strdup()
    }
}