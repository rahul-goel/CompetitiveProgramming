#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void* a, const void* b)
{
	return *((char* )a) - *((char* )b);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char s[5005], c[5005];
		scanf("%s %s", s, c);
		int len_s = strlen(s), len_c = strlen(c);
		char sort_s[5005];
		strcpy(sort_s, s);
		qsort(sort_s, len_s, sizeof(char), comp);

		int ptr = 0, flag = -1;
		if(strcmp(s, c) < 0)
		{
			printf("%s\n", s);
			continue;
		}
		
		while(ptr<len_s)
		{
			if(s[ptr] != sort_s[ptr])
			{
				int j = len_s-1;
				while(sort_s[ptr]!=s[j])
					j--;
				s[j] = s[ptr], s[ptr] = sort_s[ptr];
				flag = 1;
				break; 
			}

			ptr++;
		}

		if(strcmp(s, c) < 0)
			printf("%s\n", s);
		else
			printf("---\n");
	}
	return 0;
}