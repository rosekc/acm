#include <iostream>
#include <queue>

using namespace std;

const int wr[ 4 ] = { -1, 0, 1, 0 };
const int wc[ 4 ] = { 0, 1, 0, -1 };

int bfc();

int main()
{
    int i;
    cin >> i;

    for ( int t = 1; t <= i; t++ )
    {
        cout << bfc() << endl;
    }
}


int bfc()
{
    int r, c;

    cin >> r >> c;

    int lab[ r ][ c ];
    int tlist[ r ][ c ];

    for ( int i = 0; i < r; i++ )
    {
        for ( int j = 0; j < c; j++ )
        {
            tlist[ i ][ j ] = 0;
        }
    }


    queue< int > qr;
    queue< int > qc;
    queue< int > qp;
    queue< int > qt;


    for ( int i = 0; i < r; i++ )
    {
        for ( int j = 0; j < c; j++ )
        {
            cin >> lab[ i ][ j ];

            switch ( lab[ i ][ j ] )
            {
            case 2:
                qr.push( i );
                qc.push( j );
                break;
            default:
                break;
            }

        }
    }

    tlist[ qr.front() ][ qc.front() ] = 6;

    qp.push( 0 );
    qt.push( 6 );

    while ( 1 )
    {
        for ( int i = 0; i < 4; i++ )
        {
            int tr = qr.front() + wr[ i ];
            int tc = qc.front() + wc[ i ];

            if ( tr >= 0 && tr < r &&
                    tc >= 0 && tc < c && lab[ tr ][ tc ] != 0 )
            {
                int tt;

                if ( lab[ tr ][ tc ] == 4 && qt.front() != 1 )
                {
                    tt = 6;
                }
                else
                {
                    tt = qt.front() - 1;
                }



                if ( tt == 0 )
                {
                    break;
                }


                if ( tlist[ tr ][ tc ] < tt )
                {
                    qr.push( tr );
                    qc.push( tc );
                    qt.push( tt );
                    qp.push( qp.front() + 1 );
                    tlist[ tr ][ tc ] = tt;
                }

                if ( lab[ qr.back() ][ qc.back() ] == 3 )
                {
                    return qp.back();
                }


            }
        }

        qr.pop();
        qc.pop();
        qp.pop();
        qt.pop();


        if ( qr.empty() == 1 )
        {
            return -1;
        }

    }
}
