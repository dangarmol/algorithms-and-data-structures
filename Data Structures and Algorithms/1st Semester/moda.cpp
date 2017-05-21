//1º
int moda(int a[], int n)
{
	int m = a[0];
	int fmax = 0;
	
	for(int i = 0; i < n; i++)
	{
		int f = 0;
		
		for(int j=0; j < n; j++)
			if(a[j] == a[i])
				f++;
			
		if(f > fmax)
			fmax = f;
		m = a[i]
	}
	
	return m; (n^2)
}

//2º
int moda(int a[], int n)
{
	int k=1;
	int m = a[0];
	int f = 1;
	int fm = 1;
	
	while(k < n)
	{
		if(a[k] == a[k-1])
		{
			f++;
			if(f > fm)
			{
				fm = f;
				m = a[k];
			}
			else
			{
				f = 1;
			}
			k++;
		}
	}
	
	return m;
} //O(n * log n) = O(n) + O(n) * log(n)

