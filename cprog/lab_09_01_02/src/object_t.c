#include <string.h>
#include <ctype.h>
#include "object_t.h"
#include "errcodes.h"

void free_object(object_t *object)
{   
    if (object)
    {
        if (object->name_object == NULL)
            return;

        free(object->name_object);

        object->name_object = NULL;
    }
}

int init_object(object_t *object, char *name, double mass, double volume)
{   
    char *p;

    p = strdup(name);

    if (!p)
        return ERR_ALLOC;

    object->name_object = p;

    object->mass = mass;

    object->volume = volume;
    
    return ERR_OK;
}

void print_object(object_t const *object)
{
    printf("%s\n", object->name_object);
    
    printf("%lf\n", object->mass);

    printf("%lf\n", object->volume);
}

int read_object(FILE *file, object_t *object)
{
    int rc = ERR_OK;
    
    char *strtmp = NULL;
    
    char *p;

    size_t n;
    ssize_t read;
    
    read = getline(&strtmp, &n, file);
    
    if (read != -1)
    {   
        p = strrchr(strtmp, '\n');
        
        if (p == strtmp)
            rc = ERR_IO;
    }
    else
        rc = ERR_IO;

    if (rc == ERR_OK)
    {   
        if (p)
            *p = '\0';

        double mass;
        double volume;

        if (fscanf(file, "%lf %lf\n", &mass, &volume) != 2)
            rc = ERR_IO;
        
        if (rc == ERR_OK && (mass <= EPS || volume <= EPS))
            rc = ERR_DATA;

        if (rc == ERR_OK)
            rc = init_object(object, strtmp, mass, volume);
    }

    if (strtmp)
        free(strtmp);

    if (rc == ERR_OK && feof(file))
        return EOF;
    
    return rc;
}

int compare_density(void const *first, void const *second)
{  
    double density_f, density_s;

    object_t *f = (object_t *) first;
    object_t *s = (object_t *) second; 

    density_f = f->mass / f->volume;
    density_s = s->mass / s->volume;

    if (density_f > density_s)
        return BIGGER;
    
    if (density_f < density_s)
        return SMALLER;
        
    return EQUAL;  
}
