#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int SIZE = 205;

struct data
{
    int r;
    int c;
    int time;
    int isgu;
    string res;
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
        if ( qu.front().isgu != 0 )
        {
            qu.push( { qu.front().r, qu.front().c, qu.front().time + 1, qu.front().isgu - 1, qu.front().res + '5' } );
            qu.pop();
            continue;
        }

        for ( int i = 0; i < 4; i++ )
        {
            int tr = qu.front().r + wr[ i ];
            int tc = qu.front().c + wc[ i ];

            //cout << tr << " " << tc << endl;

            if ( tr >= 0 && tr < r &&
                    tc >= 0 && tc < c && map1[ tr ][ tc ] != 'X' )
            {
                //cout << tr << " " << tc << endl;
                int flag = 0;
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
                if ( map1[ tr ][ tc ] > '0' && map1[ tr ][ tc ] <= '9' )
                {
                    flag = int( map1[ tr ][ tc ] - 48 );
                }

                if ( tlist[ tr ][ tc ] > tt )
                {
                    qu.push( { tr, tc, tt, flag, qu.front().res + char( 48 + i ) } );
                    tlist[ tr ][ tc ] = tt;
                }

                if ( tr == r - 1 && tc == c - 1 )
                {
                    //while ( !qu.empty() ) qu.pop();
                    //cout << flag << endl;
                    while( flag != 0 )
                    {
                        qu.back().res += '5';
                        flag--;
                        tt++;
                    }
                    return tt;
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
                cin >> map1[ i ][ j ];
                tlist[ i ][ j ] = 50000;
            }
        }

        qu.push( { 0, 0, 0, 0 } );


        int tmp = dfs();
        //cout << qu.back().res << endl;
        if( tmp == -1 )
            cout << "God please help our poor hero.\n";
        else
        {
            cout << "It takes " << tmp << " seconds to reach the target position, let me show you the way.\n";
            int sr = 0;
            int sc = 0;
            int con = 1;
            for( int i = 0; i < qu.back().res.size(); i++ )
            {
                if( qu.back().res.at( i ) != '5' )
                {
                    //cout << int( qu.back().res.at( i ) - 48 ) << endl;
                    cout << con++ << "s:(" << sr << ',' << sc
                    << ")->(" << sr + wr[ int( qu.back().res.at( i ) - 48 ) ]
                    << ',' << sc + wc[ int( qu.back().res.at( i ) - 48 ) ] << ")\n";
                    sr += wr[ int( qu.back().res.at( i ) - 48 ) ];
                    sc += wc[ int( qu.back().res.at( i ) - 48 ) ];
                }
                else
                    cout << con++ << "s:FIGHT AT (" << sr << ',' << sc << ")\n";
            }
        }
        cout << "FINISH\n";
        while ( !qu.empty() ) qu.pop();
    }
}
