#ifndef PERFORMANCE_H_
#define PERFORMANCE_H_
#include <iostream>
#include <cstdlib>
#include "cycle.h"

using namespace std;

/**
 * Function that returns true if a sequence of numbers
 * corresponds to a constant function
 * @param y_el[] the array of ints to be considered
 * @param size the number of elements in the array
 * @param var a varia��o (+/-) aceit�vel
 * @return true if corresponds to a constant function
 */
bool isConstant(const unsigned int y_el[], const int size, const int var) {

	// Esta abordagem verifica as diferen�as entre cada elemento
	// bastando uma das diferen�as ser superior ao intervalo
	// para n�o considerar constante
	int primDif = 0; // para ser constante o valor de referencia da diferen�a entre elementos dever� ser zero
	//cout << "primDif = " << primDif << endl;
	int dif = 0;
	for (int i = 1; i < size; i++) {
		dif = (y_el[i] - y_el[i-1]);
		//cout << "dif = " << dif << endl;
		//cout << "primdif-var = " << primDif-var << "primdif+var = " << primDif+var << endl;
		if (dif<(primDif-var) || dif>primDif+var) return false;
	}
	return true;

/*
	// Esta abordagem usa o valor m�dio da leitura
	// e considera constante se estiver dentro do intervalo definido
	int primDif = 0; // para ser constante o valor de referencia da diferen�a entre elementos dever� ser zero
	cout << "primDif = " << primDif << endl;
	int soma = 0;
	int dif = 0;
	for (int i = 1; i < size; i++) {
		dif = (y_el[i] - y_el[i-1]);
		soma = soma + dif;
		cout << "dif = " << dif << endl;
		cout << "soma = " << soma << endl;
	}
	int media = soma/(size-1);
	cout << "media = " << soma/(size-1) << " primdif-var = " << primDif-var << " primdif+var = " << primDif+var << endl;
	return (media >= primDif-var && media <= primDif+var);
*/
}

/**
 * Function that returns true if a sequence of numbers
 * corresponds to a linear function
 * @param y_el[] the array of ints to be considered
 * @param size the number of elements in the array
 * @param var a varia��o (+/-) aceit�vel
 * @return true if corresponds to a linear function
 */
bool isLinear(const unsigned int y_el[], const int size, const int var) {

	// Esta abordagem usa os valores m�dios

	// Para saber se � linear, basta calcular as primeiras diferen�as
	// entre elementos consecutivos, somar essas diferen�as e dividir pelo n�mero
	// de elementos -1.
	// O resultado ter� de estar dentro do intervalo pretendido

	// Primeiro, verificar se � n�o � constante
	if (isConstant(y_el, size, var)) return false;
	// Agora que sabemos que n�o � constante
	int soma = 0;
	int primDif = y_el[1]-y_el[0];
	//cout << "primDif = " << primDif << endl;
	for (int i = 1; i < size; i++) {
		soma = soma + (y_el[i] - y_el[i-1]);
		//cout << "soma = " << soma << endl;
	}

	//
	int media = soma/(size-1);
	//cout << "media = " << soma/(size-1) << " primdif-var = " << primDif-var << " primdif+var = " << primDif+var << endl;
	return (media >= primDif-var && media <= primDif+var);
}

/**
 * Function that returns true if a sequence of numbers
 * corresponds to a quadratic function
 * @param y_el[] the array of ints to be considered
 * @param size the number of elements in the array
 * @param var a varia��o (+/-) aceit�vel
 * @return true if corresponds to a quadratic function
 */
bool isQuadratic(const unsigned int y_el[], const int size, const int var) {

	// Esta abordagem usa os valores m�dios

	// Para saber se � quadratica, primeiro garantir que n�o � constante nem linear.
	// Depois, Calcular as segundas diferen�as entre elementos consecutivos, somar essas diferen�as e dividir pelo n�mero
	// de elementos -2.
	// O resultado ter� de ser igual � diferen�a da primeira segunda-diferen�a
	//
	//
	// Primeiro, verificar se � n�o � constante (de notar que n�o � suficiente comparar com Linear, pois n�o ser linear
	// pode significar que � constante)
	if (isConstant(y_el, size, var)) return false;
	// Segundo, verificar se � n�o � linear
	if (isLinear(y_el, size, var)) return false;
	// Criar um array para guardar os valores das primeiras diferen�as
	int y_el_prim_dif[size-1];
	// Calcular as primeiras diferen�as e guard�-las no array
	for (int i = 1; i < size; i++ ) {
		y_el_prim_dif[i-1] = (y_el[i] - y_el[i-1]);
	}
	// Agora calcular as segundas-diferen�as
	int soma = 0;
	int primDif = y_el_prim_dif[1]-y_el_prim_dif[0];

	for (int i = 1; i < size-1; i++) {
		soma = soma + (y_el_prim_dif[i] - y_el_prim_dif[i-1]);
	}
	//
	int media = soma/(size-2);
	return (media >= primDif-var && media <= primDif+var);

}

/**
 * Function that returns true if a sequence of numbers
 * corresponds to a cubic function
 * @param y_el[] the array of ints to be considered
 * @param size the number of elements in the array
 * @param var a varia��o (+/-) aceit�vel
 * @return true if corresponds to a cubic function
 */
bool isCubic(const unsigned int y_el[], const int size, const int var) {

	// Esta abordagem usa os valores m�dios

	// Para saber se � cubica, primeiro garantir que n�o � constante nem linear nem quadratica.
	// Depois, Calcular as terceiras diferen�as entre elementos consecutivos, somar essas diferen�as e dividir pelo n�mero
	// de elementos -3.
	// O resultado ter� de ser igual � diferen�a da primeira segunda-diferen�a
	//
	//
	// Primeiro, verificar se � n�o � constante (de notar que n�o � suficiente comparar com Linear, pois n�o ser linear
	// pode significar que � constante)
	if (isConstant(y_el, size, var)) return false;
	// Segundo, verificar se � n�o � linear
	if (isLinear(y_el, size, var)) return false;
	// Terceiro, verificar se � n�o � quadratica
	if (isQuadratic(y_el, size, var)) return false;
	// Criar um array para guardar os valores das primeiras diferen�as
	int y_el_prim_dif[size-1];
	// Calcular as primeiras diferen�as e guard�-las no array
	for (int i = 1; i < size; i++ ) {
		y_el_prim_dif[i-1] = (y_el[i] - y_el[i-1]);
	}
	// Criar um array para guardar os valores das segundas diferen�as
	int y_el_sec_dif[size-2];
	// Calcular as segundas diferen�as e guard�-las no array
	for (int y = 1; y < size-1; y++ ) {
		y_el_sec_dif[y-1] = (y_el_prim_dif[y] - y_el_prim_dif[y-1]);
	}
	// Agora calcular as terceiras-diferen�as
	int soma = 0;
	int primDif = y_el_sec_dif[1]-y_el_sec_dif[0];

	for (int z = 1; z < size-2; z++) {
		soma = soma + (y_el_sec_dif[z] - y_el_sec_dif[z-1]);
	}
	//
	int media = soma/(size-3);
	return (media >= primDif-var && media <= primDif+var);

}

/**
 * Function that returns true if a sequence of numbers
 * corresponds to an exponential function
 * @param y_el[] the array of ints to be considered
 * @param size the number of elements in the array
 * @param var a varia��o (+/-) aceit�vel
 * @return true if corresponds to an exponential function
 */
bool isExponential(const unsigned int y_el[], const int size, const int var) {

	// Esta abordagem usa os valores m�dios

	// Para saber se � exponencial, basta calcular as primeiras divisoes
	// entre elementos consecutivos, somar essas diferen�as e dividir pelo n�mero
	// de elementos -1.
	// O resultado ter� de ser igual ao valor da primeira divis�o

	int soma = 0;
	int primDiv = y_el[1]/y_el[0];
	for (int i = 1; i < size; i++) {
		soma = soma + (y_el[i] / y_el[i-1]);
	}
	//
	int media = soma/(size-1);
	return (media >= primDiv-var && media <= primDiv+var);
}

/**
 * Fun��o para devolver a diferen�a entre dois ticks
 * @param te  tick de fim
 * @param ts  tick de inicio
 * @return a diferen�a
 */
unsigned int getElapsed(ticks te, ticks ts) {
	return ( (int)te - (int)ts )/1000;
}


#endif /* PERFORMANCE_H_ */
