#include "car_t_io.h"
#include "errcodes.h"

int read_carfrmfile(FILE *file, car_t *car)
{   
    char str[BUFFER_LEN];
    char elemnts[N][MAX_LEN_STR];
    int tmp;
    short int tmp_h;

    fgets(str, BUFFER_LEN, file);

    char *p = strtok(str, " ");
    
    size_t i = 0;
    strncpy(elemnts[i], p, MAX_LEN_STR);

    i++;

    while ((p = strtok(NULL, " ")) != NULL && i < N)
    {   
        if (strlen(p) >= MAX_LEN_STR)
            return ERR_IO;
        strncpy(elemnts[i], p, MAX_LEN_STR);
        i++;
    }
    // printf("%s, %s, %s, %s, %s, %s, %s, %s\n", elemnts[0], elemnts[1], elemnts[2], elemnts[3],elemnts[6], elemnts[7], elemnts[8], elemnts[9]);
    // if (i - 1 != ELEM_NEW || i - 1 != ELEM_OLD)
    //     return ERR_IO;

    strncpy(car->mark, elemnts[0], MAX_LEN_STR);

    strncpy(car->country, elemnts[1], MAX_LEN_STR);

    if (strcmp(elemnts[2], "no") == 0 || strcmp(elemnts[2], "No") == 0)
        car->garanty = 0;
    else if (strcmp(elemnts[2], "yes") == 0 || strcmp(elemnts[2], "Yes") == 0)
        car->garanty = 1;
    else
        return ERR_IO;
    
    if (sscanf(elemnts[3], "%u", &tmp) != 1 || tmp < 0)
        return ERR_IO;

    car->price = tmp;

    strncpy(car->color, elemnts[4], MAX_LEN_STR);

    if (strcmp(elemnts[5], "new") == 0 || strcmp(elemnts[5], "New"))
    {   
        newstate_t state;
        car->state_new = true;
        if (sscanf(elemnts[6], "%hd", &tmp_h) != 1 || tmp_h < 0)
            return ERR_IO;

        state.serlife = tmp_h; 
        car->state.newstate = state;
    }
    else if (strcmp(elemnts[5], "old") == 0 || strcmp(elemnts[5], "Old") == 0)
    {   
        // struct state_car *p = &car->state_new;
        oldstate_t state;
        car->state_new = false;  
        if (sscanf(elemnts[6], "%hd",  &tmp_h) != 1 || tmp_h < 0)
            return ERR_IO;
        
        state.yearof = tmp_h;
        
        if (sscanf(elemnts[7], "%d", &tmp) != 1 || tmp < 0)
            return ERR_IO;
        state.mileage = tmp;
        
        if (sscanf(elemnts[8], "%hd", &tmp_h) != 1 || tmp_h < 0)
            return ERR_IO;
        state.owners = tmp_h;
        if (sscanf(elemnts[9], "%hd", &tmp_h) != 1 || tmp_h < 0)
            return ERR_IO;
        state.repairs = tmp_h;
        car->state.oldstate = state;
    }
    else 
        return ERR_IO;

    return ERR_OK;
}

void print_header(int const key)
{   
    if (key == 1)
    {
        print_centered(stdout, "N", 5);
        print_centered(stdout, "Price", 15);
        fprintf(stdout, "\n");
        return;
    }

    print_centered(stdout, "N", 5);
    print_centered(stdout, "Mark", 15);
    print_centered(stdout, "Country", 15);
    print_centered(stdout, "Mach. support", 15);
    print_centered(stdout, "Price", 15);
    print_centered(stdout, "Color", 15);
    print_centered(stdout, "Novelty", 15);
    print_centered(stdout, "Garanty", 15);
    print_centered(stdout, "Age of product", 15);
    print_centered(stdout, "Mileage", 15);
    print_centered(stdout, "Num owners", 15);
    print_centered(stdout, "Num repairs", 15);
    fprintf(stdout, "\n");
}

void print_centered(FILE *f, const char *str, int const width) 
{
    int len = strlen(str);
    int padding = width - len;
    
    fprintf(f, "|%s%*s", str, padding, "");
}
void write_car_tofile(FILE *file, car_t const car)
{   
    char strtmp[20];
    print_centered(file, car.mark, 15);
    print_centered(file, car.country, 15); 
    // fprintf(file, "%-15s%-15s", car.mark, car.country);

    if (car.garanty)
        // fprintf(file, "%-15s", "yes");
        print_centered(file, "yes", 15);
    else
        // fprintf(file, "%-15s", "no");
        print_centered(file, "no", 15);
    
    snprintf(strtmp, sizeof(strtmp), "%u", car.price);
    print_centered(file, strtmp, 15);
    memset(strtmp, 0, 20);
    print_centered(file, car.color, 15);

    if (!car.state_new)
    {   
        memset(strtmp, 0, 20);
        print_centered(file, "old", 15);
        print_centered(file, "-", 15);
        snprintf(strtmp, sizeof(strtmp), "%hu", car.state.oldstate.yearof);
        print_centered(file, strtmp, 15);
        memset(strtmp, 0, 20);
        snprintf(strtmp, sizeof(strtmp), "%u", car.state.oldstate.mileage);
        print_centered(file, strtmp, 15);
        memset(strtmp, 0, 20);
        snprintf(strtmp, sizeof(strtmp), "%hu", car.state.oldstate.owners);
        print_centered(file, strtmp, 15);
        memset(strtmp, 0, 20);
        snprintf(strtmp, sizeof(strtmp), "%hu", car.state.oldstate.repairs);
        print_centered(file, strtmp, 15);
        // fprintf(file, "%-15s%-20hu%-15u%-20hu%-20hu", new, car.state.yearof, car.state.mileage, car.state.owners, car.state.repairs);
    }
    else
    {
        print_centered(file, "new", 15);
        memset(strtmp, 0, 20);
        snprintf(strtmp, sizeof(strtmp), "%hu", car.state.newstate.serlife);
        print_centered(file, strtmp, 15);
        print_centered(file, "-", 15);
        print_centered(file, "-", 15);
        print_centered(file, "-", 15);
        print_centered(file, "-", 15);
    //     fprintf(file, "%-15s%-20hu", old, car.state.serlife);
    }
    fprintf(file, "\n");
}

int get_car(car_t *car)
{   
    memset(car, 0, sizeof(car_t));
    char *p = NULL;
    char str[MAX_LEN_STR + 2];
    char strtmp[MAX_LEN_STR];
    printf("Ввод данных о машине...\n");

    printf("Введите марку машины: \n");
    while (getchar() != '\n');

    if (!fgets(str, MAX_LEN_STR + 1, stdin))
        return ERR_IO;
    p = strchr(str, '\n');

    if (!p)
        return ERR_IO;
    *p = '\0';

    if (!p || strlen(p) >= MAX_LEN_STR)
        return ERR_IO;

    strcpy(car->mark, str);

    printf("Введите страну машины: \n");
    

    if (!fgets(str, MAX_LEN_STR + 1, stdin))
        return ERR_IO;
    
    p = strchr(str, '\n');

    if (!p)
        return ERR_IO;

    *p = '\0';

    if (!p || strlen(p) >= MAX_LEN_STR)
        return ERR_IO;

    strcpy(car->country, str);
    if (strcmp(car->country, "Russia") != 0 && strcmp(car->country, "russia") != 0)
    {
        printf("Гарантия машины (Yes/No): \n");
        if (scanf("%s", strtmp) == 1)
        {
            if (strcmp("Yes", strtmp) == 0 || strcmp("yes", strtmp) == 0)
                car->garanty = true;

            else if (strcmp("No", strtmp) == 0 || strcmp("no", strtmp) == 0)
                car->garanty = false;
            else
                return ERR_IO;
        }
        else
            return ERR_IO;
    }
    printf("Введите стоимость машины в руб.: \n");

    int tmp;
    
    if (scanf("%d", &tmp) != 1 || tmp <= 0)
        return ERR_IO;
    car->price = tmp;

    printf("Цвет машины: \n");
    while (getchar() != '\n');
    if (!fgets(str, MAX_LEN_STR + 1, stdin))
        return ERR_IO;
    
    p = strchr(str, '\n');

    if (!p)
        return ERR_IO;
    *p = '\0';

    if (!p || strlen(p) >= MAX_LEN_STR)
        return ERR_IO;
    
    strcpy(car->color, str);
    printf("Состояние машины (New/Old): \n");
    if (scanf("%s", strtmp) == 1 && (strcmp(strtmp, "New") == 0 || strcmp(strtmp, "new") == 0))
        car->state_new = true;
    else if ((strcmp(strtmp, "Old") == 0 || strcmp(strtmp, "old") == 0))
        car->state_new = false;
    else
        return ERR_IO;
    
    if (!car->state_new)
    {   
        oldstate_t stat;
        
        printf("Год выпуска: \n");
        if (scanf("%d", &tmp) != 1 || tmp < 0)
            return ERR_IO;
        stat.yearof = tmp;

        printf("Введите пробег машины в км: \n");
        if (scanf("%d", &tmp) != 1 || tmp < 0)
            return ERR_IO;
        stat.mileage = tmp;

        printf("Введите кол-во владельцев: \n");
        if (scanf("%d", &tmp) != 1 || tmp < 0)
            return ERR_IO;
        stat.owners = tmp;

        printf("Введите кол-во произведенных ремонтов: \n");
        if (scanf("%d", &tmp) != 1 || tmp < 0)
            return ERR_IO;
        stat.repairs = tmp;

        car->state.oldstate = stat;
    }
    else
    {   
        newstate_t stat;
        printf("Гарантия лет: \n");
        if (scanf("%d", &tmp) != 1 || tmp < 0)
            return ERR_IO;
        
        stat.serlife = tmp;
        car->state.newstate = stat;
    }
    return ERR_OK;    
}

