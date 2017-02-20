#include <cstdio>
//#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
	char in[ 110005 ];

	while ( scanf( "%s", &in ) )
	{
		int insize;


		insize = strlen( in );

		//printf( "%d\n", insize );

		int maxn = 0;
		for ( int i = 0; i < insize; i++ )
		{
			if ( maxn / 2 > insize - i )
			{
				//cout << "aaa" << endl;
				break;
			}

			for ( int j = 1; j + i - 1 < insize && i - j >= 0; j++ )
			{
				if( in[ i + ( maxn - 1 ) / 2 ] != in[ i - ( maxn - 1 ) / 2 ]
				        && in[ i + maxn / 2 - 1 ] != in[ i - maxn / 2 ] )
				{
				    //cout << "aaa" << endl;
					break;
				}
				int flag1 = 0;
				int flag2 = 0;
				//cout << "a" << endl;
				if ( j + i < insize )
				{
					if ( in[ i + j ] != in[ i - j ] )
					{
						flag1 = 1;
					}
				}
				else
				{
					flag1 = 1;
				}
				if ( in[ i + j - 1 ] != in[ i - j ] )
				{
					flag2 = 1;
				}
				//cout << flag2 << endl;
				//cout << i;// << endl;
				//cout << j << endl;
				if ( flag1 == 1 && flag2 == 1 )
				{
					break;
				}
				else if ( flag1 == 0 && maxn < 2 * j + 1)
				{
					maxn = 2 * j + 1;
				}
				else if ( flag2 == 0 && maxn < 2 * j )
				{
					maxn = 2 * j;
				}
			}
			/*for ( int j = 1; i + j - 1 < in.size() && i - j >= 0; j++ )
			{
			    //cout << "a" << endl;
			    if ( in.at( i + j - 1 ) != in.at( i - j ) )
			    {
			        break;
			    }
			    //cout << i;// << endl;
			    //cout << j << endl;

			    int tmp = 2 * j;
			    if ( tmp > maxn )
			    {
			        maxn = tmp;
			    }
			}*/

		}
		printf( "%d\n", maxn );
	}
}
