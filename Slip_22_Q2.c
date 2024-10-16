/*Slip_22_Q2. Read the data from file 'cities.txt' containing names of cities and their STD 
codes. Accept a name of the city from user and use sentinel linear search 
algorithm to check whether the name is present in the file and output the STD 
code, otherwise output “city not in the list”. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100
#define NAME_LENGTH 30

struct City {
    char name[NAME_LENGTH];
    int std_code;
};

void readCitiesFromFile(const char *filename, struct City cities[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%s %d", cities[*count].name, &cities[*count].std_code) == 2) {
        (*count)++;
        if (*count >= MAX_CITIES) {
            printf("Maximum number of cities reached.\n");
            break;
        }
    }

    fclose(file);
}

int sentinelLinearSearch(struct City cities[], int count, const char *target, int *std_code) {
    if (count == 0) {
        return 0;
    }

    strcpy(cities[count].name, target);
    int i = 0;

    while (strcmp(cities[i].name, target) != 0) {
        i++;
    }

    if (i < count) {
        *std_code = cities[i].std_code;
        return 1;
    }

    return 0;
}

int main() {
    struct City cities[MAX_CITIES];
    int count = 0;
    char cityName[NAME_LENGTH];
    int std_code;

    readCitiesFromFile("cities.txt", cities, &count);

    printf("Enter the name of the city: ");
    scanf("%s", cityName);

    if (sentinelLinearSearch(cities, count, cityName, &std_code)) {
        printf("STD code for %s is: %d\n", cityName, std_code);
    } else {
        printf("City not in the list.\n");
    }

    return 0;
}
