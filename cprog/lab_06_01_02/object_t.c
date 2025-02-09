#include <string.h>
#include <ctype.h>
#include "object_t.h"
#include "errcodes.h"

void print_object(struct object_t const *object)
{
    printf("%s\n", object->name_object);
    
    printf("%lf\n", object->mass);

    printf("%lf\n", object->volume);
}

int read_object(FILE *txt, struct object_t *object)
{
    int err = ERR_IO;
    
    char strtmp[MAX_LEN_NAME_OBJ + 1];
    
    char *p;
    size_t len_name;

    if (fgets(strtmp, sizeof(strtmp), txt))
    {   
        p = strrchr(strtmp, '\n');
        if (p)
            *p = '\0';
        
        len_name = strlen(strtmp);

        if (len_name >= MAX_LEN_NAME_OBJ || len_name == 0)
            return ERR_IO;   
        
        strncpy(object->name_object, strtmp, MAX_LEN_NAME_OBJ);
        
        if (fscanf(txt, "%lf", &object->mass) != 1)
            return ERR_IO;
        
        if (fscanf(txt, "%lf", &object->volume) != 1)
            return ERR_IO;

        if (object->mass <= EPS || object->volume <= EPS)
            return ERR_DATA;
        
        fgetc(txt);

        err = ERR_OK;
    }

    if (err == ERR_OK && feof(txt))
        return EOF;
    
    return err;
}

int compare_density(struct object_t const *first, struct object_t const *second)
{  
    double density_f, density_s;

    density_f = first->mass / first->volume;
    density_s = second->mass / second->volume;

    if (density_f > density_s)
        return BIGGER;
    
    if (density_f < density_s)
        return SMALLER;
        
    return EQUAL;  
}
