#include <cstdio>

using namespace std;

int main()
{
	int in;

	while ( scanf( "%d", &in ) != EOF )
	{
		if( in % 3 == 0 )
        {
            printf( "%d\n", in / 3 * 2 );
        }
		else
		{
		    printf( "%d\n", 1 + in / 3 * 2 );
		}
	}
}
