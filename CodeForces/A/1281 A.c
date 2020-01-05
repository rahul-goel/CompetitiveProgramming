#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char str[1005];
		scanf("%s", str);
		int len = strlen(str);
		if(str[len-2]=='p' && str[len-1]=='o')
			printf("FILIPINO\n");
		else if( ((str[len-4]=='d' && str[len-3]=='e') || (str[len-4]=='m' && str[len-3]=='a'))
					&& str[len-2]=='s' && str[len-1]=='u' )
			printf("JAPANESE\n");
		else
			printf("KOREAN\n");
	}
	return 0;
}