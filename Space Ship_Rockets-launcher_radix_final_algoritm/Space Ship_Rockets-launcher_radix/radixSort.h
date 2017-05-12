#include "Stack.h"
#include "Rocket.h"
#include <string.h>
//--------------------------------------------------------------------------------
// C++ implementation of Radix Sort
#include<iostream>
using namespace std;
//--------------------------------------------------------------------------------
// A utility function to get maximum value in arr[]
int getMax(Stack<Rocket>*s, int n)
{
	int mx = s->at(0).get_acceleration();
	for (int i = 1; i < n; i++)
	if (s->at(i).get_acceleration() > mx)
		mx = s->at(i).get_acceleration();
	return mx;
}
//--------------------------------------------------------------------------------
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(Stack<Rocket>*s, int n, int exp)
{
	Rocket *output = new Rocket[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[((int)s->at(i).get_acceleration() / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual position of
	// this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[((int)s->at(i).get_acceleration() / exp) % 10] - 1] = s->at(i);
		count[((int)s->at(i).get_acceleration() / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to curent digit
	for (i = 0; i < n; i++)
		s->assign(output[i], i);
}
//--------------------------------------------------------------------------------
// The main function to that sorts arr[] of size n using Radix Sort
void radixsort(Stack<Rocket>*s, int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(s, n);

	// Do counting sort for every digit. Note that instead of passing digit
	// number, exp is passed. exp is 10^i where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(s, n, exp);
}
//--------------------------------------------------------------------------------