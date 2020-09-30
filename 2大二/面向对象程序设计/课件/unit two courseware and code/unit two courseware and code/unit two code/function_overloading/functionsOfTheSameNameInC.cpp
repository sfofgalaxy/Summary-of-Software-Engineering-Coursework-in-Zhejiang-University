//functions Of The Same Name in C£º	
int max1(int x, int y)
{
	return (x>y?x:y);
}

int max2(int x, int y, int z)	
{
	int max = x;
	if( y > max)
		max = y;
	if( z > max)
		max = z;
	return max;
}

float max3(float x, float y)	
{
	return (x>y?x:y);
}	

float max4(float x[], int size)	
{
	float max = x[0];
	for(int i = 0 ; i< size ; i++)
		if(x[i] > max)
			max = x[i];
	return max;
}	

void main()
{
}
