/*Slip_30_Q2. Read the data from the file “employee.txt” and sort on names in
alphabetical order (use strcmp) using bubble sort and selection sort.*/

#include<stdio.h>
#include<string.h>

#define MAX 100

struct emp
{
	int eid,age;
	char ename[20];
}e[100];

void bubble_sort(int n)
{
	 struct emp temp;
	 
     int i,j;
     
     for(i=1;i<n;i++)
     {
 		for(j=0;j<n-i;j++)
       	{
       		if(strcmp(e[j].ename,e[j+1].ename)>0)
       		{
				temp = e[j];
            	e[j]=e[j+1];
            	e[j+1]=temp;
            }
       	}
     }  
}

void display(int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		printf("\n %d %s %d",e[i].eid,e[i].ename,e[i].age);
	}
}

int main()
{
	FILE *fp;
	int n=0;

	fp = fopen("EMPLOYEE.txt","r");

	while((fscanf(fp,"%d%s%d",&e[n].eid,e[n].ename,&e[n].age))!=EOF)
	{
		n++;
	}

	fclose(fp);

	printf("\n\n Before Sorting : \n");
	display(n);

	bubble_sort(n);
	
	printf("\n\n After Sorting : \n");
	display(n);

	return 0;
}
