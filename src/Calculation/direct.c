//#include "direct.h"
#include "../main.h"

static Direct _direct;
Direct* direct_calc = &_direct;

int load(const char* fileName, enum FileType fileType)
{
    char *c;
    int m = sizeof(int);
   
    FILE * fp = fopen(fileName, "r");
    if (!fp)
    {
        printf("Error occured while opening file\n");
        return -1;
    }
    
    int *ptr_count = malloc(m);
    
    c = (char *)ptr_count;
    
    while (m > 0 && (*c = getc(fp)) != EOF)
    {
        c++;
        m--;
    }
    
    Cell * ptr1;
    Receiver * ptr2;

    if(fileType == CELLS)
    {
        direct_calc->K = *ptr_count;
        free(ptr_count);    // освобождаем память
        ptr1 = malloc(direct_calc->K * sizeof(Cell));
        c = (char *)ptr1;
    }
    else if(fileType == RECEIVERS)
    {
        direct_calc->N = *ptr_count;
        free(ptr_count);    // освобождаем память
        ptr2 = malloc(direct_calc->N * sizeof(Receiver));
        c = (char *)ptr2;
    }
   
    
   
    while ((*c= getc(fp))!=EOF)
    {
        c++;
    }
   
    if(fileType == CELLS)
    {
        for(int i = 0; i < direct_calc->K; i++)
        {
            direct_calc->cellObjects[i] = ptr1[i];
        }
        free(ptr1);
    }
    else if(fileType == RECEIVERS)
    {
        for(int i = 0; i < direct_calc->N; i++)
        {
            direct_calc->receivers[i] = ptr2[i];
        }
        free(ptr2);
    }
   
    
    fclose(fp);
    return 0;
}

int save(const char* fileName, enum FileType fileType)
{
    char *c;
    int size;
    FILE* fp = fopen(fileName, "wb");
    if (!fp)
    {
        printf("Error occured while opening file\n");
        return -1;
    }

    if(fileType == CELLS)
    {
        c = (char *)&direct_calc->K;
    }
    else if(fileType == RECEIVERS)
    {
        c = (char *)&direct_calc->N;
    }
    for (int i = 0; i < (int)sizeof(int); i++)
    {
        putc(*c++, fp);
    }

    if(fileType == CELLS)
    {
        c = (char *)direct_calc->cellObjects;
        size = direct_calc->K * sizeof(direct_calc->cellObjects);
    }
    else if(fileType == RECEIVERS)
    {
        c = (char *)direct_calc->receivers;
        size = direct_calc->N * sizeof(direct_calc->receivers);
    }
    
    for (int i = 0; i < size; i++)
    {
        putc(*c, fp);
        c++;
    }
    fclose(fp);
    return 0;

}

double get_r(Cell cell, Receiver receiver)
{
    return sqrt(pow(cell.Center->x - receiver.Point->x, 2) + 
    pow(cell.Center->y - receiver.Point->y, 2));
}

double get_cell_area(Cell cell)
{
    return (cell.nodes[1]->x - cell.nodes[0]->x) * (cell.nodes[1]->y - cell.nodes[0]->y);
}

int calculate()
{
    double r, square, x, y, coef;

    if(direct_calc->cellObjects == NULL || direct_calc->receivers == NULL)
    {
        return -1;
    }

    for(int i = 0; i < direct_calc->N; i++)
    {
        for(int j = 0; j < direct_calc->K; j++)
        {
            r = get_r(direct_calc->cellObjects[j], direct_calc->receivers[i]);
            square = get_cell_area(direct_calc->cellObjects[j]);
            x = direct_calc->receivers[i].Point->x - direct_calc->cellObjects[j].Center->x;
            y = direct_calc->receivers[i].Point->y - direct_calc->cellObjects[j].Center->y;
            coef = square * direct_calc->cellObjects[j].I / (4 * M_PI * pow(r, 3));

            direct_calc->receivers[i].B->x = coef * direct_calc->cellObjects[j].P->x * (3 * pow(x, 2) / pow(r,2)) 
             + direct_calc->cellObjects[j].P->y * 3 * x * y / pow(r, 2);
            
            direct_calc->receivers[i].B->y = coef * direct_calc->cellObjects[j].P->x * 3 * x * y / pow(r,2) 
             + direct_calc->cellObjects[j].P->y * (3 * pow(y, 2) / pow(r, 2) - 1);            
        }
    }
    return 0;
}