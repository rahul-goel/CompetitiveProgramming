//Created by Rahul Goel
#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d", &n);
	char s[105], t[105];
	scanf("%s %s", s, t);
	int len1 = strlen(s), len2 = strlen(t);
	int j=0, k=0;
	for(int i=0; i<len1+len2; i++)
	{
		if(i&1)
			printf("%c", t[k++]);
		else
			printf("%c", s[j++]);
	}
	printf("\n");
	return 0;
}