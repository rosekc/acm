#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct data
{
    int con;
    int pos;
    char board[ 10 ];
    char res[ 40 ];
};

const int SIZE = 10;
const int wm[ 4 ] = { 3, -1, -3, 1 };
char sp[ SIZE ];
int pos;
queue< data > qu;

int ReNum()//ÄæÐòÊý
{
    char a[ 9 ];
    int con = 0;
    for ( int i = 0, j = 0; i < 9; i++ )
    {
        //cout << sp[ i ];
        if ( sp[ i ] == 'x' )
        {
            pos = i++;
        }
        a[ j++ ] = sp[ i ];
    }
    //cout << endl;
    for ( int i = 0; i < 8; i++ )
    {
        for ( int j = i; j < 8; j++)
        {
            if ( a[ i ] > a[ j ] ) con++;
        }
    }
    return con;
}

int ReNum1( char* p )//ÄæÐòÊý
{
    char a[ 9 ];
    int con = 0;
    for ( int i = 0, j = 0; i < 9; i++ )
    {
        //cout << p[ i ];
        if ( p[ i ] == 'x' )
        {
            i++;
        }
        a[ j++ ] = p[ i ];
    }
    //cout << endl;
    for ( int i = 0; i < 8; i++ )
    {
        //cout << a[ i ];
        for ( int j = i; j < 8; j++)
        {
            if ( a[ i ] > a[ j ] )
            {
                //cout << j << endl;
                //cout << a[ i ] << " " << a[ j ] << endl;
                con++;
            }
        }
    }
    //cout << endl;
    //cout << con << endl;
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
            if ( i == 3 && qu.front().pos % 3 == 2 ) continue;
            if ( i == 1 && qu.front().pos % 3 == 0 ) continue;
            //cout << qu.front().pos << endl;
            int tp = qu.front().pos + wm[ i ];
            //cout << tp << endl;
            if ( tp < 9 && tp >= 0 )
            {
                //cout << i << endl;
                if ( qu.front().con != 0 && qu.front().res[ qu.front().con - 1 ] == char( ( i + 2 ) % 4 + 48 ) )  continue;
                data tmp;

                strncpy( tmp.board, qu.front().board, 9 );
                strncpy( tmp.res, qu.front().res, qu.front().con );
                tmp.res[ qu.front().con ] = char( i + 48 );
                swap( tmp.board[ tp ], tmp.board[ qu.front().pos ] );
                tmp.con = qu.front().con + 1;
                tmp.pos = tp;

                qu.push( tmp );

                //for ( int i = 0; i < qu.back().con; i++ )
                //{
                    //cout << qu.back().res[ i ];
                //}
                //cout << endl;

                if ( ReNum1( tmp.board ) == 0 && tp == 8 )
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
        sp[ 9 ] = '/0';
        //cout << ReNum();
        if (  ReNum() % 2 == 1 )
        {
            cout << "unsolvable\n";
            continue;
        }
        else
        {
            //cout << "ggg\n";
            data tmp;
            strncpy( tmp.board, sp, 9 );

            //for ( int i = 0; i < 9; i++ )
            //{
            //    cout << tmp.board[ i ];
            //}
            //cout << endl;
            tmp.con = 0;
            tmp.pos = pos;
            qu.push( tmp );
            bfs();
        }

        cout << "Con" << qu.back().con << endl;



        for ( int i = 0; i < qu.back().con; i++ )
        {
            switch( qu.back().res[ i ] )
            {
            case '2':
                cout << 'd';
                break;
            case '3':
                cout << 'l';
                break;
            case '0':
                cout << 'u';
                break;
            case '1':
                cout << 'r';
                break;
            }
        }
        cout << endl;

        while ( !qu.empty() ) qu.pop();
    }

    //printf( "%d", n );
}
