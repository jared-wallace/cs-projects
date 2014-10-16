/*
I will admit the algorithm is shamelessly ripped off from our textbook.  I am still struggling to wrap my head around this, so I will
be studying this section for a week or two.

Accepts an array and the size of said array (not absolutely needed for this program,
but I figure just in case I need the function for a different program, it is ready
to be adapted ;)

While the function doesn't return anything, it does permanently change the
order of the values in the array.
*/
void sort (int x[], int size)
{
	int min, hold;
	for (int i=0; i < size-1; i++)
	{
		min = i;
		for (int j=i+1; j < size; j++)
		{
			if (x[j] < x[min])
			min = j;
		}
		hold = x[min];
		x[min] = x[i];
		x[i] = hold;
	}
}
