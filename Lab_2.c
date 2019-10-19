#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 1024

char** read (char **Mass, int size_mass)
{
Mass = (char **) calloc(size_mass, sizeof(char*)*size_mass);
printf("\nВведите строки: \n");
	for(int i=0;i<size_mass;i++)
	{
	Mass[i]=(char *) calloc(MAX_L, sizeof(char)) ;	
	scanf("%s", Mass[i]);
	}
	for(int i=0;i<size_mass;i++)
	{	
	printf("Mass[%d] = %s, lenght=%lu\n", i, Mass[i], strlen (Mass[i]));
	}
return Mass;
}

char** sort(char** Mass, int size_mass)
{int swap=0;
for(int n=0;n<size_mass/2;n++)
	{
	char* max=Mass[n];
	char* min=Mass[size_mass-n-1];
	char* sw=NULL;
	int ma=n;
	int mi=size_mass-1-n;
	for(int i=n, j=size_mass-1-n; 
		i<size_mass/2+1 & j>size_mass/2-1;
		i++, j--)
		{
		if (strlen(Mass[i])>strlen(max))
			{
			max = Mass[i];
			ma=i;
			swap++;
			}
		if (strlen(Mass[i])<strlen(min))
			{
			min = Mass[i];
			mi=i;
			swap++;
			}
		if (strlen(Mass[j])>strlen(max))
			{
			max = Mass[j];
			ma=j;
			swap++;
			}
		if (strlen(Mass[j])<strlen(min))
			{
			min = Mass[j];
			mi=j;
			swap++;
			}
		}
	sw=Mass[n];
	Mass[n]=max;
	Mass[ma]=sw;
	sw=Mass[size_mass-n-1];
	Mass[size_mass-n-1]=min;
	Mass[mi]=sw;	
	}
printf("\nЧисло перестановок = %d\n\n", swap);

return Mass;	
}

void print(char**Mass, int size)
{
for(int i=0; i<size;i++)
printf("Mass[%d] = %s, lenght=%lu\n", i, Mass[i], strlen (Mass[i]));
printf("\n");
for(int i=0; i<size;i++)
printf("M[%d][1]=%c\n", i,Mass[i][1]);
}	

void freeM(char** Mass)
{
free (Mass);
}

void main()
{
char **M=NULL;
int M_size=0;
printf("Введите количество строк: ");
scanf("%d", &M_size);
M=read(M, M_size);
M=sort(M, M_size);
print(M, M_size);
freeM(M);
}

