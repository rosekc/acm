#include <iostream>
#include <queue>

using namespace std;

struct Point
{
    bool operator ==(const Point &p)const
    {
        return r == p.r && c == p.c;
    }
    int r;
    int c;
};

struct data
{
    Point p;
    int t;
    int face;
    int time;
};

const int SIZE = 1010;
const int wr[ 4 ] = { -1, 0, 1, 0 };
const int wc[ 4 ] = { 0, 1, 0, -1 };
int sp[ SIZE ][ SIZE ];
int tlist[ SIZE ][ SIZE ];
int r, c;
int n;
Point stp;
Point edp;
queue< data > qu;

bool bfs()
{
    while ( !qu.empty() )
    {
        //cout << "123\n";

        for ( int i = 0; i < 4; i++ )
        {
            int tr = qu.front().p.r + wr[ i ];
            int tc = qu.front().p.c + wc[ i ];

            //cout << tr << " " << tc << endl;

            if ( tr >= 1 && tr <= r &&
                    tc >= 1 && tc <= c && ( sp[ tr ][ tc ] == 0 || ( tr == edp.r && tc == edp.c ) ) )
            {
                //cout << tr << " " << tc << qu.front().t<< endl;
                int flag = 0;
                if ( i != qu.front().face ) flag = 1;
                if ( qu.front().t + flag == 3 ) continue;
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
                if ( tr == edp.r && tc == edp.c )
                {
                    while ( !qu.empty() ) qu.pop();
                    return 1;
                }

                if ( tlist[ tr ][ tc ] > tt )
                {
                    qu.push( { { tr, tc }, qu.front().t + flag, i, tt } );
                    tlist[ tr ][ tc ] = tt;
                }
            }
        }

        qu.pop();
    }
    return 0;
}

int main()
{
    while ( cin >> r >> c && r + c )
    {
        for ( int i = 1; i <= r; i++ )
        {
            for ( int j = 1; j <= c; j++ )
            {
                tlist[ i ][ j ] = 50000;
                cin >> sp[ i ][ j ];
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
        cin >> n;

        while ( n-- )
        {
            cin >> stp.r >> stp.c >> edp.r >> edp.c;
            if( sp[ stp.r ][ stp.c ] != sp[ edp.r ][ edp.c ] || sp[ stp.r ][ stp.c ] == 0 || sp[ edp.r ][ edp.c ] == 0 )
            {
                cout << "NO\n";
                continue;
            }
            qu.push( { stp, -1, -1, 0 } );
            if ( bfs() ) cout << "YES\n";
            else cout << "NO\n";
            for ( int i = 1; i < r; i++ )
            {
                for ( int j = 1; j < c; j++ )
                {
                    tlist[ i ][ j ] = 50000;
                }
            }
        }
    }

    //printf( "%d", n );
}
