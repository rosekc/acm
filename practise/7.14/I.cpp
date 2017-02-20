#include <cstdio>

using namespace std;

int main()
{
	long long in;
	while ( scanf( "%I64d", &in ) != EOF )
	{
		long long tmp = 0;
		int i = 1;
		while( 1 )
		{
			if( tmp + i > in ) break;
			tmp += i++;
			//printf( "%d\n", i );
		}

		printf( "%I64d\n", in % tmp == 0 ? i - 1 : in % tmp );
	}
}
