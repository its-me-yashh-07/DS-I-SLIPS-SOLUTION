/*Slip_27_Q2. Read the data from the file and sort on names in alphabetical order (use 
strcmp) using Counting sort, Merge sort and write the sorted data to another 
file 'sortedemponname.txt' */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(char arr[][100], int left, int mid, int right) 
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    char L[n1][100], R[n2][100];
    for (i = 0; i < n1; i++)
        strcpy(L[i], arr[left + i]);
    for (j = 0; j < n2; j++)
        strcpy(R[j], arr[mid + 1 + j]);
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) 
	{
        if (strcmp(L[i], R[j]) <= 0) 
		{
            strcpy(arr[k], L[i]);
            i++;
        } 
		else 
		{
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }
    while (i < n1) 
	{
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }
    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}
void mergeSort(char arr[][100], int left, int right) 
{
    if (left < right) 
	{
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main() 
{
    FILE *inputFile = fopen("emponname.txt", "r");
    FILE *outputFile = fopen("sortedemponname.txt", "w");
    char names[100][100];
    int count = 0;
    while (fgets(names[count], sizeof(names[count]), inputFile) && count < 100) 
	{
        names[count][strcspn(names[count], "\n")] = 0;
        count++;
    }
    mergeSort(names, 0, count - 1);
    for (int i = 0; i < count; i++) 
        fprintf(outputFile, "%s\n", names[i]);
    fclose(inputFile);
    fclose(outputFile);
  return 0;
}
