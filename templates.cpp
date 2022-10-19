#include <stdio.h>



#define DBG_MSG( FORMAT, ... ) printf( "%s -> " FORMAT "\n", __PRETTY_FUNCTION__, ##__VA_ARGS__ )



template< typename T >
inline void print( const T& a, const T& b )
{
   DBG_MSG( "template" );
}

inline void print( const double& a, const double& b )
{
   DBG_MSG( "double" );
}

template< typename ... TYPES >
inline void print( const TYPES... args )
{
   DBG_MSG( "variadic template" );
}

inline void print( ... )
{
   DBG_MSG( "var args" );
}



int main( int argc, char* argv[ ] )
{
   print( 4, 5 );
   print( 4.0, 5.0 );
   print< >( 4.0, 5.0 );
   print( 4.0, 5 );
   print< >( 4.0, 5 );
   print( 4.0, static_cast< double >( 5 ) );
   print< double >( 4.0, 5 );
   print( 'a', 'b' );
   print( "abc", "def" );
   print( "abc", 1 );
   print( 1, 2, 3 );

   return 0;
}
