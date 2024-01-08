#include <stdio.h>
#include <math.h>

int barras;
int agua;
int uranio;
int xenon;

int vapor;
int temperatura;
int potencia;
int presion;

int diagNoBars;
int diagLowBars;
int diagHighBars;
int diagNoXePoison;
int diagLowXePoison;
int diagMidXePoison;
int diagHighXePoison;

int diagNoSpikeTemp;
int diagSpikeTemp;
int diagLowPres;
int diagHighPres;
int diagDangerPres;
int diagNoPower;
int diagMidPower;
int diagHighPower;
int diagDangerPower;

int diagSafeTurbine;
int diagXePoison;

void main()
{
	printf("**********************\n");
	printf("* MONITOR DE CENTRAL *\n");
	printf("**********************\n");
	
	printf("\n");
	printf(">>>> DATOS PARA EL MONITOR DE REACTOR\n");
	printf("\n");

	printf("Cantidad de barras sumergidas?");
	scanf("%d", &barras);
	printf("Cantidad de agua?");
	scanf("%d", &agua);
	printf("Cantidad de uranio?");
	scanf("%d", &uranio);
	printf("Cantidad de xenon?");
	scanf("%d", &xenon);	
	
	diagNoBars = 0;
	diagLowBars = 0;
	diagHighBars = 0;
	diagNoXePoison = 0;
	diagLowXePoison = 0;
	diagMidXePoison = 0;
	diagHighXePoison = 0;
	
	printf("\n");
	printf(">>>> DIAGNOSTICOS DEL MONITOR DE REACTOR\n");
	printf("\n");

	// Diagnostico 1
	
	if(barras == 0)
	{
		printf("NOBARS: No hay barras sumergidas\n");
		
		diagNoBars = 1;
	}
	
	// Diagnostico 2

	if(barras >= 1 && barras <= 5)
	{
		printf("LOWBARS: Hay entre 1 y 5 barras sumergidas\n");

		diagLowBars = 1;
	}
	
	// Diagnostico 3

	if(barras >= 6 && barras <= 10)
	{
		printf("HIGHBARS: Hay entre 6 y 10 barras sumergidas\n");

		diagHighBars = 1;
	}

	// Diagnostico 4

	if(xenon <= uranio)
	{
		printf("NOXEPOISON: La cantidad de xenon es menor o igual a la de uranio\n");

		diagNoXePoison = 1;
	}
	
	// Diagnostico 5
	
	if(xenon >= uranio && abs(xenon - uranio) <= 50)
	{
		printf("LOWXEPOISON: La cantidad de xenon es mayor o igual a la de uranio "
			   "y hay una diferencia entre ambas de 50kg o menos\n");

		diagLowXePoison = 1;
	}
	
	// Diagnostico 6
	
	// En este caso no tenemos que comprobar que la cantidad de xenon supere a la
	// de uranio porque si no fuese asi, la diferencia entre ambas saldria negativa
	// o cero y tampoco superaria 50
	
	if(xenon - uranio > 50)
	{
		printf("MIDXEPOISON: La cantidad de xenon supera a la de uranio por mas de 50kg\n");

		diagMidXePoison = 1;
	}
	
	// Diagnostico 7
	
	if(xenon - uranio > 100 || xenon > 500)
	{
		printf("HIGHXEPOISON: La cantidad de xenon supera a la de uranio por mas de 100kg "
		       "o es mayor que 500kg\n");

		diagHighXePoison = 1;
	}	
	
	printf("\n");
	printf(">>>> DATOS PARA EL MONITOR DE TURBINA\n");
	printf("\n");

	printf("Cantidad de vapor?");
	scanf("%d", &vapor);
	printf("Temperatura?");
	scanf("%d", &temperatura);
	printf("Potencia?");
	scanf("%d", &potencia);
	printf("Presion?");
	scanf("%d", &presion);
	
	printf("\n");
	printf(">>>> DIAGNOSTICOS DEL MONITOR DE TURBINA\n");
	printf("\n");

	diagNoSpikeTemp = 0;
	diagSpikeTemp = 0;
	diagLowPres = 0;
	diagHighPres = 0;
	diagDangerPres = 0;
	diagNoPower = 0;
	diagMidPower = 0;
	diagHighPower = 0;
	diagDangerPower = 0;	

	// Diagnostico 8
	
	if(temperatura <= 100 || vapor <= 5)
	{
		printf("NOSPIKETEMP: La temperatura es de 100 grados o menos "
		       "o la cantidad de vapor no supera los 5kg\n");

		diagNoSpikeTemp = 1;
	}
	// Diagnostico 9

	if(temperatura > 100 && vapor > 5)
	{
		printf("SPIKETEMP: La temperatura es mayor que 100 grados "
		       "y la cantidad de vapor es superior a 5kg\n");
			   
		diagSpikeTemp = 1;
	}
	
	// Diagnostico 10

	if(presion <= 50)
	{
		printf("LOWPRES: La presion no es superior a 50 pascales\n");
		
		diagLowPres = 1;
	}

	// Diagnostico 11

	if(presion > 50)
	{
		printf("HIGHPRES: La presion supera los 50 pascales\n");

		diagHighPres = 1;
	}

	// Diagnostico 12

	if(presion > 100)
	{
		printf("DANGERPRES: La presion excede el limite de seguridad de 100 pascales\n");

		diagDangerPres = 1;
	}

	// Diagnostico 13

	if(potencia == 0)
	{
		printf("NOPOWER: La central no esta produciendo MW\n");

		diagNoPower = 1;
	}

	// Diagnostico 14

	if(potencia >= 1 && potencia <= 200)
	{
		printf("MIDPOWER: La central esta produciendo de 1 a 200 MW\n");

		diagMidPower = 1;
	}

	// Diagnostico 15

	if(potencia > 200)
	{
		printf("HIGHPOWER: La central esta produciendo mas de 200 MW\n");

		diagHighPower = 1;
	}

	// Diagnostico 16

	if(potencia > 200)
	{
		printf("DANGERPOWER: La central excede 1000 MW de potencia\n");

		diagDangerPower = 1;
	}
	
	printf("\n");
	printf(">>>> DIAGNOSTICOS\n");
	printf("\n");

	diagSafeTurbine = 0;
	diagXePoison = 0;
	
	// Diagnostico 17
	
	if(!diagDangerPres && !diagDangerPower)
	{
		printf("SAFETURBINE: No se da el diagnostico DANGERPRES ni DANGERPOWER\n");
		
		diagSafeTurbine = 1;
	}

	// Diagnostico 18
	
	if(diagMidXePoison || diagHighXePoison)
	{
		printf("XEPOISON: Se da el diagnostico MIDXEPOISON o HIGHXEPOISON\n");
		
		diagXePoison = 1;
	}

	// Diagnostico 19
	
	if(diagSafeTurbine && !diagSpikeTemp && (diagNoPower || diagMidPower))
	{
		printf("ADDWATER: Se da el diagnostico SAFETURBINE,no se da SPIKETEMP y  "
		       "se da el diagnostico NOPOWER o MIDPOWER\n");
	}
	
	// Diagnostico 20
	
	if(diagSpikeTemp || diagXePoison || !diagSafeTurbine)
	{
		printf("ADDBARS: Se da el diagnostico SPIKETEMP o XEPOISON o no se da SAFETURBINE\n");
	}	

	// Diagnostico 21
	
	if(	diagSafeTurbine &&
		(
			((diagNoPower || diagMidPower) && !diagSpikeTemp) ||
			((diagNoPower || diagMidPower) && diagXePoison)
		)
	)
	{
		printf("ADDURANIUM: Se da el diagnostico SAFETURBINE y o bien "
		       "NOPOWER o MIDPOWER y no SPIKETEMP o bien "
			   "NOPOWER o MIDPOWER y XEPOISON\n");
	}	
}