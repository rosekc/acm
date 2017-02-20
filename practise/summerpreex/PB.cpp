#include <iostream>
using namespace std;

int getcycle( long long n )
{
	int con = 1;

	do
	{
		if( n % 2 == 1 )
		{
			n = ( 3 * n ) + 1;
		}
		else
		{
			n = n / 2;
		}
		con++;
	}while( n != 1 );
	return con;
}


int main()
{
	int i, j;

	while( cin >> i >> j )
	{
	    int ti, tj;
	    if( i > j )
        {
            ti = j;
            tj = i;
        }
        else
        {
            ti = i;
            tj = j;
        }

		int t = 0;
		for( int a = ti; a <= tj; a++ )
        {
            if( t < getcycle( a ) )
            {
                t = getcycle( a );
            }
        }
		cout << i << " " << j << " " << t << endl;
	}

}
