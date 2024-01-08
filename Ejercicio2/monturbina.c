#include <stdio.h>
#include <math.h>


int vapor;
int temperatura;
int potencia;
int presion;

void main()
{
	printf("**********************\n");
	printf("* MONITOR DE TURBINA *\n");
	printf("**********************\n");
	
	printf("Cantidad de vapor?");
	scanf("%d", &vapor);
	printf("Temperatura?");
	scanf("%d", &temperatura);
	printf("Potencia?");
	scanf("%d", &potencia);
	printf("Presion?");
	scanf("%d", &presion);
	
	// Diagnostico 8
	
	if(temperatura <= 100 || vapor <= 5)
	{
		printf("NOSPIKETEMP: La temperatura es de 100 grados o menos "
		       "o la cantidad de vapor no supera los 5kg\n");
	}
	
	// Diagnostico 9

	if(temperatura > 100 && vapor > 5)
	{
		printf("SPIKETEMP: La temperatura es mayor que 100 grados "
		       "y la cantidad de vapor es superior a 5kg\n");
	}
	
	// Diagnostico 10

	if(presion <= 50)
	{
		printf("LOWPRES: La presion no es superior a 50 pascales\n");
	}

	// Diagnostico 11

	if(presion > 50)
	{
		printf("HIGHPRES: La presion supera los 50 pascales\n");
	}

	// Diagnostico 12

	if(presion > 100)
	{
		printf("DANGERPRES: La presion excede el limite de seguridad de 100 pascales\n");
	}

	// Diagnostico 13

	if(potencia == 0)
	{
		printf("NOPOWER: La central no esta produciendo MW\n");
	}

	// Diagnostico 14

	if(potencia >= 1 && potencia <= 200)
	{
		printf("MIDPOWER: La central esta produciendo de 1 a 200 MW\n");
	}

	// Diagnostico 15

	if(potencia > 200)
	{
		printf("HIGHPOWER: La central esta produciendo mas de 200 MW\n");
	}

	// Diagnostico 16

	if(potencia > 200)
	{
		printf("DANGERPOWER: La central excede 1000 MW de potencia\n");
	}
}