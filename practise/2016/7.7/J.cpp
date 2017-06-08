#include <stdio.h>

int main()
{
	int s1, s2, s3, s4, s5, s6;
	int con;

	while ( scanf( "%d%d%d%d%d%d", &s1, &s2, &s3, &s4, &s5, &s6 ) != EOF
	        && s1 + s2 + s3 + s4 + s5 + s6 != 0 )
	{
		con = s6 + s5 + s4;

		s1 -= s5 * 11;

		if ( s4 > 0 )
		{
			if ( s4 * 5 < s2 )
			{
				s2 -= s4 * 5;
			}
			else
			{
				s1 -= 4 * ( s4 * 5 - s2 );
				s2 = 0;
			}
		}

		con += ( s3 + 3 ) / 4;
		s3 %= 4;

		if ( s3 == 1 )
		{
			if ( s2 >= 5 )
			{
				s2 -= 5;
				s1 -= 7;
			}
			else
			{
				s1 -= 7 + 4 * ( 5 - s2 );
				s2 = 0;
			}
		}
		else if ( s3 == 2 )
		{
			if ( s2 >= 3 )
			{
				s2 -= 3;
				s1 -= 6;
			}
			else
			{
				s1 -= 6 + 4 * ( 3 - s2 );
				s2 = 0;
			}
		}
		else if ( s3 == 3 )
		{
			if ( s2 >= 1 )
			{
				s2 -= 1;
				s1 -= 5;
			}
			else
			{
				s1 -= 9;
				s2 = 0;
			}
		}

		if ( s2 > 0 )
		{
			con += ( s2 + 8 ) / 9;
			s2 %= 9;
			s1 -= 4 * ( 9 - s2 );
		}

		if ( s1 > 0 )
		{
			con += ( s1 + 35 ) / 36;
		}

		printf( "%d\n", con );
	}
}
