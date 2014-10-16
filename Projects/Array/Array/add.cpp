/*
Accpets three arrays as parameters, adds the first two together
and then assigns the resultant values to the third array passed to it.
*/
void addArray (int arg[5], int arg2[5], int arg3[5])
{
	for (int i=0; i<5; i++)
	{
		arg3[i] = (arg[i] + arg2[i]);
	}
}