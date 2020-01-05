#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char s[105], h[105];
		scanf("%s %s", s, h);
		int len1 = strlen(s), len2 = strlen(h);
		if(len2<len1)
		{
			printf("NO\n");
			continue;
		}
		int freq1[26] = {0}, freq2[26] = {0};
		for(int i=0; i<len1; i++)
			freq1[s[i]-'a']++;
		for(int i=0; i<len1; i++)
			freq2[h[i]-'a']++;

		int flag = 1;
		for(int i=0; i<26; i++)
			if(freq1[i]!=freq2[i])
				flag = 0;
		if(flag)
		{
			printf("YES\n");
			continue;
		}
		int ptr = len1;
		while(ptr<len2)
		{
			freq2[h[ptr]-'a']++, freq2[h[ptr-len1]-'a']--;
			flag = 1;
			for(int i=0; i<26; i++)
				if(freq1[i]!=freq2[i])
					flag = 0;
			if(flag)
				break;
			ptr++;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}