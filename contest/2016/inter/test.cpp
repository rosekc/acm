#include <iostream>
#include <cmath>
using namespace std;

const int wr[ 4 ] = { -1, 0, 1, 0 };
const int wc[ 4 ] = { 0, 1, 0, -1 };


int chooseWay();

int main()
{
	int r, c;
	int pace = 5;



	cin >> r >> c;

	int lab[ r ][ c ];
	int f[ r ][ c ] = { 600 };
	int g[ r ][ c ] = { 600 };
	int h[ r ][ c ];
	bool open[ r ][ c ];
	bool close[ r ][ c ];


	for( int i = 0; i < r; i++ )
	{
		for( int j = 0; j < c; j++ )
		{
			cin >> lab[ i ][ j ];

			switch( lab[ i ][ j ] )
			{
			case 2:
				open[ i ][ j ] = 1;
				g[ i ][ j ] = 0;
				break;
			case 3:
				endr = i;
				endc = j;
				break;
			default:
				break;
			}

		}
	}

	do
	{
	    int minf, minr, minc;
	    minf = 600;

		for( int i = 0; i < r; i++ )
		{
			for( int j = 0; j < c; j++ )
			{
				if( open[ i ][ j ] == 1 && f[ i ][ j ] < minf )
                {
                    minf = f[ i ][ j ];
                    minr = i;
                    minc = j;
                }
			}
		}

		open[ minr ][ minc ] = 0;
		close[ minr ][ minc ] = 1;

		for( int i = 0; i <= 3; i++ )
        {
            int tr = minr + wr[ i ];
            int tc = minc + wc[ i ];

            if( ( tr < 0 && tr > r - 1 &&
                 tc < 0 && tc > c && lab[ tr ][ tc ] == 0)
               || close[ tr ][ tc ] == 1 )
            {
                continue;
            }

            if( open[ tr ][ tc ] == 0 )
            {
                open[ tr ][ tc ] = 1;
                g[ tr ][ tc ] = g[ minr ][ minc ]++;
                h[ tr ][ tc ] = abs( tr - endr ) + abs( tc - endc );
                f[ tr ][ tc ] = g[ tr ][ tc ] + h[ tr ][ tc ];
            }

            if( open[ tr ][ tc ] == 1 )
            {
                g[ tr ][ tc ]
            }
        }
	}while( open[ endr ][ endc ] == 1  )

}

int
