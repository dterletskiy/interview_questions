#include <stdio.h>



#define DBG_MSG( FORMAT, ... ) printf( "%s -> " FORMAT "\n", __PRETTY_FUNCTION__, ##__VA_ARGS__ )
#define DBG_MSG_SIZEOF( TYPE ) DBG_MSG( "sizeof( %s ) = %zu", #TYPE, sizeof( TYPE ) );



class IA
{
   public:
      IA( )                                     { DBG_MSG( ); }
      virtual ~IA( )                            { DBG_MSG( ); }

      virtual void print( )                     { DBG_MSG( ); }
      virtual void print( int )                 { DBG_MSG( ); }
      virtual void print( const char* )         { DBG_MSG( ); }
      virtual void print( float ) = 0           { DBG_MSG( ); }
      virtual void print( double )              { DBG_MSG( ); }

      void dump( )                              { DBG_MSG( ); }
      void info( )                              { DBG_MSG( ); print( ); }
};

class IB
{
   public:
      IB( )                                     { DBG_MSG( ); }
      ~IB( )                                    { DBG_MSG( ); }

      void print( )                             { DBG_MSG( ); }
      virtual void print( int )                 { DBG_MSG( ); }
      virtual void print( int, int )            { DBG_MSG( ); }
      virtual void print( double )              { DBG_MSG( ); }

      template< typename T >
         virtual void print( const T, const T ) { DBG_MSG( ); }
};

class A : public IA , public IB
{
   public:
      A( const int _id ) : id( _id )            { DBG_MSG( ); }
      virtual ~A ( )                            { DBG_MSG( ); }

      void print( )                             { DBG_MSG( ); }
      void print( int )                         { DBG_MSG( ); }
      virtual void print( int, int )            { DBG_MSG( ); }
      void print( const char* ) override        { DBG_MSG( ); }
      void print( char ) override               { DBG_MSG( ); }

      template< typename T >
         void print( const T, const T )         { DBG_MSG( ); }

   private:
      size_t id;
};




int main( int argc, char *argv[ ] )
{
   DBG_MSG_SIZEOF( void* );
   DBG_MSG_SIZEOF( size_t );
   DBG_MSG_SIZEOF( A );

   IA* pA = new A(5);
   pA->print( );
   pA->print( 4 );
   pA->print( 4, 5 );
   pA->print( "a" );
   pA->print( 4.5 );

   IB* pB = dynamic_cast< IB* >( pA );
   pB->print( );
   pB->print( 3 );
   pB->print( 4, 5.0 );
   pB->print( "b" );

   delete pB;
   pA->dump( );
   pA->info( );

   return 0;
}
