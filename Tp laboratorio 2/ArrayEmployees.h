#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    char sector[51];
    int isEmpty;

} eEmployee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

int searchFree(eEmployee vec[], int len);
void listEmployee(eEmployee* vec);
void listEmployees(eEmployee* vec, int len);

int initEmployees(eEmployee* vec,int len);
int addEmployee(int idx,eEmployee* vec, int len);
int findEmployeeById(int id,eEmployee* vec,int len);
void removeEmployee(eEmployee* vec, int len);
void sortEmployees(eEmployee* vec,int len,int order);

void reportEmployees(eEmployee* vec,int len);
void modifyEmployee(eEmployee* vec, int len);
void reportSalaryTotalAverage(eEmployee* vec,int len);
char menuReports();


