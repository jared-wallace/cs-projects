/*
Accepts three arrays as parameters, the first of which is a
10 value array and the subsequent ones which are each 5 values.
The function assigns the first 5 values of the first array to the second
and the final 5 values to the third.
*/
void splitArray (int arg[10], int arg2[5], int arg3[5])
{
	int i(0), g(5);
	while (i<5)
	{
		arg2[i] = arg[i];
		i++;
	}

	i = 0;

	while (i<5)
	{
		arg3[i] = arg[g];
		i++;
		g++;
	}
}

