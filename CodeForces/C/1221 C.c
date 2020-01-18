//Created by Rahul Goel
#include <stdio.h>
int min(int a, int b);
int main()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int c, m , x;
        scanf("%d %d %d", &c, &m, &x);
        if(m==min(x, min(m,c)))
            printf("%d\n", m);
        else if(c==min(x, min(m,c)))
            printf("%d\n", c);
        else
        {
            int teams = 0;
            c-=x; m-=x; teams+=x; x=0;
            if(c>=2*min(m,c) || m>= 2*min(m,c))
                printf("%d\n", teams + min(m,c));
            else
            {
                if(m==min(m,c))
                {
                    teams+=(c-m);
                    teams+=(((2*m-c)*2)/3);
                }
                else 
                {
                    teams+=(m-c);
                    teams+=(((2*c-m)*2)/3);
                }
                printf("%d\n", teams);
            }
        }
    }
    return 0;
}

int min(int a, int b)
{
    if(a<=b)
        return a;
    else
        return b;
}