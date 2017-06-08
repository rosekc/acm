#include <stdio.h>
#include <string.h>

char p[ 10005 ], t[ 1000005 ];

void kmp_pre(char x[],int m,int next[])
{
	int i,j;
	j=next[0]=-1;
	i=0;
	while(i<m)
	{
		while(-1!=j && x[i]!=x[j])j=next[j];
		next[++i]=++j;
	}
}
void preKMP(char x[],int m,int kmpNext[])
{
	int i,j;
	j=kmpNext[0]=-1;
	i=0;
	while(i<m)
	{
		while(-1!=j && x[i]!=x[j])j=kmpNext[j];
		if(x[++i]==x[++j])kmpNext[i]=kmpNext[j];
		else kmpNext[i]=j;
	}
}

int next[10010];
int KMP_Count(char x[],int m,char y[],int n)
{

	int i,j;
	int ans=0;

	kmp_pre(x,m,next);
	i=j=0;
	while(i<n)
	{
		while(-1!=j && y[i]!=x[j])j=next[j];
		i++;
		j++;
		if(j>=m)
		{
			ans++;
			j=next[j];
		}
	}
	return ans;
}

int main()
{
	int n;

	scanf( "%d", &n );

	for( int i = 1; i <= n; i++ )
	{
		scanf( "%s%s", &p, &t );
		printf( "%d\n", KMP_Count( p, strlen( p ), t, strlen( t ) ) );
	}
}
