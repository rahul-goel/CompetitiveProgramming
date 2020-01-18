//Created by Rahul Goel
#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char str[105];
		scanf("%s", str);
		int len = strlen(str);
		int even_flag = 0, c0=0, sum = 0, flag0=0;
		for(int i=0; i<len; i++)
		{
			if((flag0 || (str[i]!='0')) && (str[i]-'0')%2==0)
				even_flag=1;
			if(str[i] == '0')
				c0++, flag0=1;
			else
				sum += str[i] - '0';
		}
		if(c0==len)
			printf("red\n");
		else if(c0 && sum%3==0 && even_flag)
			printf("red\n");
		else
			printf("cyan\n");
	}
	return 0;
}