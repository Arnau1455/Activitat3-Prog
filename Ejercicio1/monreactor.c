#include <stdio.h>
#include <math.h>


int barras;
int agua;
int uranio;
int xenon;

void main()
{
	printf("**********************\n");
	printf("* MONITOR DE REACTOR *\n");
	printf("**********************\n");
	
	printf("Cantidad de barras sumergidas?");
	scanf("%d", &barras);
	printf("Cantidad de agua?");
	scanf("%d", &agua);
	printf("Cantidad de uranio?");
	scanf("%d", &uranio);
	printf("Cantidad de xenon?");
	scanf("%d", &xenon);
	
	// Diagnostico 1
	
	if(barras == 0)
	{
		printf("NOBARS: No hay barras sumergidas\n");
	}
	
	// Diagnostico 2

	if(barras >= 1 && barras <= 5)
	{
		printf("LOWBARS: Hay entre 1 y 5 barras sumergidas\n");
	}
	
	// Diagnostico 3

	if(barras >= 6 && barras <= 10)
	{
		printf("HIGHBARS: Hay entre 6 y 10 barras sumergidas\n");
	}

	// Diagnostico 4

	if(xenon <= uranio)
	{
		printf("NOXEPOISON: La cantidad de xenon es menor o igual a la de uranio\n");
	}
	
	// Diagnostico 5
	
	if(xenon >= uranio && abs(xenon - uranio) <= 50)
	{
		printf("LOWXEPOISON: La cantidad de xenon es mayor o igual a la de uranio "
			   "y hay una diferencia entre ambas de 50kg o menos\n");
	}
	
	// Diagnostico 6
	
	// En este caso no tenemos que comprobar que la cantidad de xenon supere a la
	// de uranio porque si no fuese asi, la diferencia entre ambas saldria negativa
	// o cero y tampoco superaria 50
	
	if(xenon - uranio > 50)
	{
		printf("MIDXEPOISON: La cantidad de xenon supera a la de uranio por mas de 50kg\n");
	}
	
	// Diagnostico 7
	
	if(xenon - uranio > 100 || xenon > 500)
	{
		printf("HIGHXEPOISON: La cantidad de xenon supera a la de uranio por mas de 100kg "
		       "o es mayor que 500kg\n");
	}

}