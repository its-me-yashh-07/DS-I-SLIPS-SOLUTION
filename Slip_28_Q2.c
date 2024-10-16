#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
    float salary;
} Employee;

int readEmployees(Employee employees[], int maxCount, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return 0;
    }

    int i = 0;
    while (fscanf(file, "%s %d %f", employees[i].name, &employees[i].age, &employees[i].salary) != EOF && i < maxCount) {
        i++;
    }
    fclose(file);
    return i;
}

void writeEmployees(Employee employees[], int count, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
    fclose(file);
}

void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee* L = (Employee*)malloc(n1 * sizeof(Employee));
    Employee* R = (Employee*)malloc(n2 * sizeof(Employee));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].age <= R[j].age) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(Employee arr[], int low, int high) {
    int pivot = arr[high].age;
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j].age <= pivot) {
            i++;
            Employee temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Employee temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(Employee arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Employee employees[100];
    int count = readEmployees(employees, 100, "employee.txt");
    if (count == 0) {
        return 1;
    }

    Employee mergeSortedEmployees[100];
    memcpy(mergeSortedEmployees, employees, count * sizeof(Employee));
    mergeSort(mergeSortedEmployees, 0, count - 1);
    writeEmployees(mergeSortedEmployees, count, "sortedemponage_mergesort.txt");

    Employee quickSortedEmployees[100];
    memcpy(quickSortedEmployees, employees, count * sizeof(Employee));
    quickSort(quickSortedEmployees, 0, count - 1);
    writeEmployees(quickSortedEmployees, count, "sortedemponage_quicksort.txt");

    return 0;
}
