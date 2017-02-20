#include <iostream>
#include <queue>

using namespace std;

struct Point
{
    bool operator ==(const Point &p)const
    {
        return r == p.r && c == p.c && s == p.s;
    }
    int r;
    int c;
    int s;
};

struct data
{
    Point p;
    int time;
};

const int SIZE = 15;
const int wr[ 6 ] = { -1, 0, 1, 0, 0, 0 };
const int wc[ 6 ] = { 0, 1, 0, -1, 0, 0 };
const int wz[ 6 ] = { 0, 0, 0, 0, 1, -1 };
char sp[ SIZE ][ SIZE ][ SIZE ];
int tlist[ SIZE ][ SIZE ][ SIZE ];
int n;
string str;
Point stp;
Point edp;
queue< data > qu;

int bfs()
{
    while ( !qu.empty() )
    {
        //cout << "123\n";

        for ( int i = 0; i < 6; i++ )
        {
            int tr = qu.front().p.r + wr[ i ];
            int tc = qu.front().p.c + wc[ i ];
            int ts = qu.front().p.s + wz[ i ];

            //cout << tr << " " << tc << endl;

            if ( tr >= 0 && tr < n &&
                    tc >= 0 && tc < n &&
                    ts >= 0 && ts < n && sp[ tr ][ tc ][ ts ] != 'X' )
            {
                //printf( "%d %d %d\n", tr, tc, ts );
                //bool flag = 0;
                int tt = qu.front().time + 1;
                /*
                for ( int i = 0; i < r; i++ )
                {
                    for ( int j = 0; j < c; j++ )
                    {
                        cout << tlist[ i ][ j ] <<" ";
                    }
                    cout << endl;
                }
                */
                if ( tr == edp.r && tc == edp.c && ts == edp.s )
                {
                    while ( !qu.empty() ) qu.pop();
                    return tt;
                }

                if ( tlist[ tr ][ tc ][ ts ] > tt )
                {
                    qu.push( { { tr, tc, ts }, tt } );
                    tlist[ tr ][ tc ][ ts ] = tt;
                }
            }
        }

        qu.pop();
    }
    return -1;
}

int main()
{
    while ( cin >> str >> n )
    {
        for ( int i = 0; i < n; i++ )
        {
            for ( int j = 0; j < n; j++ )
            {
                for( int k = 0; k < n; k++ )
                tlist[ i ][ j ][ k ] = 50000;
            }
        }
        //getchar();
        //printf( "%d\n", n );
        for ( int i = 0; i < n; i++ )
        {
            for ( int j = 0; j < n; j++ )
            {
                for ( int k = 0; k < n; k++ )
                {
                    cin >> sp[ j ][ k ][ i ];
                }
            }
        }

        /*

        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                for( int k = 0; k < n; k++ )
                {
                    printf( "%c ", sp[ i ][ j ][ k ] );
                }
                puts( "" );
            }
        }
        */

       cin >> stp.r >> stp.c >> stp.s >> edp.r >> edp.c >> edp.s >> str;

        if( stp == edp )
        {
            cout << n << " 0\n";
            continue;
        }
        sp[ edp.r ][ edp.c ][ edp.s ] = 'O';
        qu.push( { stp, 0 } );

        int tmp = bfs();

        if ( tmp == -1 ) cout << "NO ROUTE\n";
        else cout << n << " " << tmp << endl;
    }

    //printf( "%d", n );
}
