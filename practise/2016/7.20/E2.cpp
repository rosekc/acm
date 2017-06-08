#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct data
{
    data( int _con, int _pos, char* _board, char* _res )
    {
        con = _con;
        pos = _pos;
        strncpy( board, _board, 9 );
        strncpy( res, _res, 35 );
    }
    int con;
    int pos;
    char board[ 9 ];
    char res[ 35 ];
};

const int SIZE = 9;
const int wm[ 4 ] = { -3, 3, 1, -1  };
const char nore[ 4 ] = { '1', '0', '3', '2' };
char sp[ SIZE ];
int pos;
queue< data > qu;

int ReNum()//ÄæÐòÊý
{
    int con = 0;

    for ( int i = 0; i < 9; i++ )
    {
        for ( int j = i; j < 9; j++)
        {
            if ( sp[ i ] == 'x' )
            {
                pos = i++;
            }
            if( sp[ j ] == 'x' ) j++;
            if( i >= 9 || j >= 9 ) continue;
            if ( sp[ i ] > sp[ j ] ) con++;
        }
    }
    return con;
}

int ReNum1( char* p )//ÄæÐòÊý
{
    int con = 0;
    for ( int i = 0; i < 9; i++ )
    {
        for ( int j = i; j < 9; j++)
        {
            if ( p[ i ] == 'x' )
            {
                i++;
            }
            if( p[ j ] == 'x' ) j++;
            if( i >= 9 || j >= 9 ) continue;
            if ( p[ i ] > p[ j ] ) con++;
        }
    }
    return con;
}

bool bfs()
{
    while ( !qu.empty() )
    {
        //cout << "123\n";
        //cout << "345\n";

        for ( int i = 0; i < 4; i++ )
        {
            //cout << i << endl;
            if ( i == 2 && qu.front().pos % 3 == 2 ) continue;
            if ( i == 3 && qu.front().pos % 3 == 0 ) continue;
            //cout << qu.front().pos << endl;
            int tp = qu.front().pos + wm[ i ];
            //cout << tp << endl;
            if ( tp < 9 && tp >= 0 )
            {
                //cout << i << endl;
                if ( qu.front().con != 0 && qu.front().res[ qu.front().con - 1 ] == nore[ i ] )  continue;

                qu.push( data( qu.front().con + 1, tp, qu.front().board, qu.front().res ) );

                //cout << char( i + 48 ) << endl;

                qu.back().res[ qu.front().con ] = char( i + 48 );
                swap( qu.back().board[ tp ], qu.back().board[ qu.front().pos ] );
                /*
                for ( int i = 0; i < qu.back().con; i++ )
                {
                    cout << qu.back().res[ i ];
                }
                cout << endl << endl;

                for ( int i = 0; i < 9; i++ )
                {
                    cout << qu.back().board[ i ];
                }
                cout << endl;

                cout <<"       "<< ReNum1( qu.back().board ) <<endl;;
*/
                if ( ReNum1( qu.back().board ) == 0 && tp == 8 )
                {
                    return 1;
                }
            }
        }
        qu.pop();
    }
    return 0;
}

int main()
{
    while ( cin >> sp[ 0 ] >> sp[ 1 ] >> sp[ 2 ]
            >> sp[ 3 ] >> sp[ 4 ] >> sp[ 5 ]
            >> sp[ 6 ] >> sp[ 7 ] >> sp[ 8 ] )
    {
        //cout << ReNum();
        if (  ReNum() % 2 == 1 )
        {
            cout << "unsolvable\n";
            continue;
        }
        else
        {
            //cout << "ggg\n";

            //for ( int i = 0; i < 9; i++ )
            //{
            //    cout << tmp.board[ i ];
            //}
            //cout << endl;
            char a[ 35 ];

            qu.push( data( 0, pos, sp, a ) );
            bfs();
        }

        //cout << "Con" << qu.back().con << endl;



        for ( int i = 0; i < qu.back().con; i++ )
        {
            switch ( qu.back().res[ i ] )
            {
            case '0':
                cout << 'u';
                break;
            case '1':
                cout << 'd';
                break;
            case '2':
                cout << 'r';
                break;
            case '3':
                cout << 'l';
                break;
            }
        }
        cout << endl;

        while ( !qu.empty() ) qu.pop();
    }
    //printf( "%d", n );
}
