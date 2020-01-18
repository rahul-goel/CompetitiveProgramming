//Created by Rahul Goel
#include <stdio.h>
#include <string.h>

int main()
{
	char str[105];
	scanf("%s", str);
	int count = 0, len = strlen(str);
	for(int i=0; i<=len/2; i++)
		if(str[i]!=str[len-i-1])
			count++, str[len-i-1] = str[i];
	printf("%d\n", count);
	return 0;
}