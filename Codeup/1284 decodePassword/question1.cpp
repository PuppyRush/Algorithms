
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isPrime(int n)
{
	if (n <= 1)
		return 0; 

	if ((n&1)==0)
		return 0;

	for (int i = 3; i*i <= n; i++)
	{ 
		if (n % i == 0)
		{
			return 0;
		}
	}

	return n; 
}

int main()
{

	int i = 0;
	scanf("%d", &i);

	int div = 2;
	int final = i / 2;
	int count = 0;
	int result[2] = { 0 , 0 };
	while (count < 2 && div <= final)
	{
		if (i%div == 0)
		{
			result[count] = div;
			count++;		
		}
		div++;

		while(isPrime(div)==0)
			div++;

		if (result[0] * result[1] == i)
			break;
	}

	if(result[0] == 0 || result[1] == 0 || ( (result[0] * result[1] != i) ))
		printf("wrong number");
	else
		printf("%d %d", result[0], result[1]);
	return 0;
}