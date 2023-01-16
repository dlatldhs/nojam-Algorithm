#include <stdio.h>
#include <string.h>
int n,r;
char st[21];
int main()
{
    scanf("%d", &n);
    
    while (n--)
    {
        scanf("%d %s", &r,st);
        
        for (int i=0; i < strlen(st); i++ )
        {
            for ( int k=0; k<r; k++ )
            {
                printf("%c", st[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
