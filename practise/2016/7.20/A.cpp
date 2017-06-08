#include <iostream>
#include <queue>

using namespace std;

const int SIZE = 205;

struct data
{
    int r;
    int c;
    int time;
    bool isgu;
};

char map1[ SIZE ][ SIZE ];
int tlist[ SIZE ][ SIZE ];
const int wr[ 4 ] = { -1, 0, 1, 0 };
const int wc[ 4 ] = { 0, 1, 0, -1 };
int r, c;
queue< data >qu;

int dfs()
{
    while ( !qu.empty() )
    {
        //cout << "123\n";
        if ( qu.front().isgu )
        {
            qu.push( { qu.front().r, qu.front().c, qu.front().time + 1, 0 } );
            qu.pop();
            continue;
        }

        for ( int i = 0; i < 4; i++ )
        {
            int tr = qu.front().r + wr[ i ];
            int tc = qu.front().c + wc[ i ];

            //cout << tr << " " << tc << endl;

            if ( tr >= 0 && tr < r &&
                    tc >= 0 && tc < c && map1[ tr ][ tc ] != '#' )
            {
                //cout << tr << " " << tc << endl;
                bool flag = 0;
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
                if ( map1[ tr ][ tc ] == 'a' )
                {
                    while ( !qu.empty() ) qu.pop();
                    return tt;
                }

                if ( map1[ tr ][ tc ] == 'x' )
                {
                    flag = 1;
                }

                if ( tlist[ tr ][ tc ] > tt )
                {
                    qu.push( { tr, tc, tt, flag } );
                    tlist[ tr ][ tc ] = tt;
                }
            }
        }

        qu.pop();
    }
    return -1;
}

int main()
{
    while ( cin >> r >> c )
    {
        for ( int i = 0; i < r; i++ )
        {
            for ( int j = 0; j < c; j++ )
            {
                tlist[ i ][ j ] = 50000;
            }
        }
        for ( int i = 0; i < r; i++ )
        {
            for ( int j = 0; j < c; j++ )
            {
                cin >> map1[ i ][ j ];
                if ( map1[ i ][ j ] == 'r' )
                {
                    //cout << i << " " << j << endl;
                    qu.push( { i, j, 0, 0 } );
                    tlist[ i ] [ j ] = 0;
                }
            }
        }

        int tmp = dfs();
        if( tmp == -1 )
            cout << "Poor ANGEL has to stay in the prison all his life.\n";
        else cout << tmp << endl;
    }
}
