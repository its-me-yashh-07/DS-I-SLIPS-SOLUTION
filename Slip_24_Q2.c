 /*Slip_24_Q2. Read the data from the file “employee.txt” and sort on names in
 alphabetical order (use strcmp) using bubble sort and selection sort.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50
void insertionSort(char names[][NAME_LENGTH], int count) 
{
    for (int i = 1; i < count; i++) 
	{
        char key[NAME_LENGTH];
        strcpy(key, names[i]);
        int j = i - 1;
        while (j >= 0 && strcmp(names[j], key) > 0) 
		{
            strcpy(names[j + 1], names[j]);
            j--;
        }
        strcpy(names[j + 1], key);
    }
}
void selectionSort(char names[][NAME_LENGTH], int count) 
{
    for (int i = 0; i < count - 1; i++) 
	{
        int minIdx = i;
        for (int j = i + 1; j < count; j++) 
            if (strcmp(names[j], names[minIdx]) < 0) 
                minIdx = j;
        char temp[NAME_LENGTH];
        strcpy(temp, names[minIdx]);
        strcpy(names[minIdx], names[i]);
        strcpy(names[i], temp);
    }
}
int main() 
{
    FILE *file = fopen("employee.txt", "r");
    char names[MAX_EMPLOYEES][NAME_LENGTH];
    int count = 0;
    while (fgets(names[count], sizeof(names[count]), file)) 
	{
        names[count][strcspn(names[count], "\n")] = 0;
        count++;
    }
    fclose(file);
    insertionSort(names, count);
    printf("Sorted using Insertion Sort:\n");
    for (int i = 0; i < count; i++) 
        printf("%s\n", names[i]);
    file = fopen("employee.txt", "r");
    count = 0;
    while (fgets(names[count], sizeof(names[count]), file)) 
	{
        names[count][strcspn(names[count], "\n")] = 0;
        count++;
    }
    fclose(file);
    selectionSort(names, count);
    printf("Sorted using Selection Sort:\n");
    for (int i = 0; i < count; i++) 
        printf("%s\n", names[i]);
}

