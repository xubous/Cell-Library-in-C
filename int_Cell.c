/* Bibliotecas Auxiliares */
#include <stdio.h>
#include <stdlib.h>
/* Fim Bibliotecas Auxiliares */


/* Definições Globais */
#define null NULL
#define optional_int 0
int global_tests = 0;
/* Fim Definições Globais */


/* Definição Das Structs E Referências */
typedef
struct s_int_Cell
{
    int value;
    struct s_int_Cell * link;
} int_Cell;

typedef
int_Cell *
ref_int_Cell;
/* Fim Definição Das Structs */


/* Métodos E Funções */
// Método Para Criar Nova Célula
ref_int_Cell int_new_Cell ( int value )
{
    ref_int_Cell this = null; // ponteiro começa apontando para null
    this = ( ref_int_Cell ) malloc ( 1 * sizeof ( int_Cell ) ); // memoria pra celula
    if ( this != null ) // caso a alocação funcione
    {  
        this -> value = value; // atribui o valor
        this -> link = null; // indica que nao esta conectado a outro
    }

    return ( this ); // retorna o ponteiro
} // Fim Método Para Criar Nova Célula

// Método Para Setar Valor Da Célula
ref_int_Cell int_Cell_set ( ref_int_Cell this, int value )
{
    if ( this != null ) // se o this tiver espaço na memória
    {
        this -> value = value; // atribui o valor
    }

    return ( this ); // retorna o ponteiro com o valor atribuido
} // Fim Método Para Setar Valor Da Célula

// Método Para Pegar Valores Da Célula
int int_Cell_get ( ref_int_Cell this )
{
    int value = optional_int; // variavel pra receber o valor da célula

    if ( this != null ) // se o this tiver espaços na memória
    {  
        value = this -> value; // pega o valor da célula
    }

    return ( value ); // retorna o valor da célula
} // Fim Método Para Pegar Valores Da Célula

// Método Para Printar 
void int_Cell_print ( ref_int_Cell this )
{
    ref_int_Cell pointerAssistant = this; // um ponteiro para this

    if ( this == null ) // se a lista for vazia
    {
        printf ( "[]" ); // retorna lista vazia
    } else
        {
            while ( pointerAssistant != null ) // enquando o ponteiro for diferente de nulo
            {
                printf ( "%d\t", pointerAssistant -> value ); // mostra o valor
                pointerAssistant = pointerAssistant -> link; // passa para o próximo nó
            }
        }
        printf ( "\n" ); // quebra de linha 

} // Fim Método Para Printar 

// Método Para Conectar Células
ref_int_Cell int_Cell_connect ( ref_int_Cell this, ref_int_Cell other )
{
    if ( this != null && other != null )
    {
        this -> link = other;
    }

    return this;
}
// Fim Método Para Conectar Células

// Método Para Desconectar Células
ref_int_Cell int_Cell_disconnect ( ref_int_Cell this, ref_int_Cell other )
{
    if ( this != null && other != null )
    {
        this -> link = null;
    }

    return this;
}

// Método Para Receber Referência Para A Próxima Célula
ref_int_Cell int_Cell_get_back ( ref_int_Cell this )
{
 // definir dado local
    ref_int_Cell back = this;
 // se exitir
    if ( this != null )
    {
        global_tests = 0;
     // procurar a ultima celula
        while ( back->link != null )
        {
          back = back -> link;
          global_tests++;
        }
    }
 // retornar a referencia
    return back;
}
// Fim Método Para Receber Referência Para A Próxima Célula

// Método Para Receber Referência Para A Célula Anterior
ref_int_Cell int_Cell_get_before_back ( ref_int_Cell this )
{
 // definir dado local
    ref_int_Cell back = this;
 // repetir enquanto houver pelo menos duas celulas
    if ( this != null && this -> link != null )
    {
     // procurar ela penultima celula
        while ( back -> link -> link != null )
        {
           back = back -> link;
        }
    }
 // retornar referencia
    return back;
}
// Fim Método Para Receber Referência Para A Célula Anterior

// Método Para Conectar Células Ao Final
ref_int_Cell int_Cell_push_back ( ref_int_Cell this, ref_int_Cell other )
{
 // definir dado local
    ref_int_Cell back = this;
 // se existir
    if ( this != null )
    {
     // conectar a ultima na celula nova
       back = int_Cell_connect ( int_Cell_get_back ( back ), other );
    }
 // retornar a referencia
    return back;
}
// Fim Método Para Conectar Células Ao Final

// Método Para Desconectar Células Ao Final
ref_int_Cell int_Cell_pop_back 
(  ref_int_Cell this  )
{
 // definir dado local
    ref_int_Cell back = this;
 // se existir
    if ( this != null )
    {
     // desconectar a penultima da ultima celula
       back = int_Cell_get_before_back ( this );
       back = int_Cell_disconnect ( back, back->link );
     // OBS.: A celula desconectada pode ser dispensada.
     // caso nao houver mais celulas, voltar NULL
       if ( this->link == null ) back = null;
    }
 // retornar referencia
    return back;
}
// Fim Método Para Desconectar Células Ao Final

// Método Para Testar
void int_Cell_test ( )
{   
 // definir dado
    ref_int_Cell a = null;
 // identificar
    printf ( "\nTest int_Cell library (C)\n" );
 // criar armazenador sem valor inicial
    a = int_new_Cell ( 5 );
 // mostrar dado
    printf ( "\n01. Testar criacao e armazenamento\n" );
    int_Cell_print ( a );
 // alterar dado
    a = int_Cell_set ( a, 10 );
 // mostrar dado
    printf ( "\n02. Testar alteracao e recuperacao\n" );
    printf ( "a->%d\n", int_Cell_get ( a ) );
    printf ( "\n" );
 // criar armazenador e inicializar
    printf ( "\n03. Testar criacao e armazenamento\n" );
    ref_int_Cell b = int_new_Cell ( 15 );
 // mostrar dado
    printf ( "b->%d\n", int_Cell_get ( b ) );
    printf ( "\n" );
 // conectar celulas
    printf ( "\n04. Testar conexao de celulas\n" );
    a = int_Cell_connect ( a, b );
 // mostrar dados
    int_Cell_print ( a );
    printf ( "\n" );
 // conectar mais uma celula 'a ultima conectada
    printf ( "\n05. Testar conexao de celulas\n" );
    ref_int_Cell c = int_new_Cell ( 30 );
    b = int_Cell_connect ( b, c );
 // mostrar dados
    int_Cell_print ( a );
    printf ( "\n" );
 // conectar mais outra celula
    printf ( "\n06. Testar conexao de celulas\n" );
    c = int_Cell_connect ( c, int_new_Cell ( 40 ) );
 // mostrar dados
    int_Cell_print ( a );
    printf ( "\n" );
 // conectar outras celulas
    ref_int_Cell back = null; 
    printf ( "\n07. Testar conexao de celulas\n" );
    for ( int x = 50; x<=70; x=x+10 )
    {
     // encontrar o ultimo
        back = int_Cell_get_back ( a );
     // conectar mais outra celula
        back = int_Cell_connect ( back, int_new_Cell ( x ) );
     // mostrar dados
        int_Cell_print ( a );
     // mostrar a quantidade de testes
        printf ( "global_tests = %d\n", global_tests );
    }
    printf ( "\n" );
    printf ( "\n08. Testar conexao de celulas\n" );
    for ( int x = 80; x<=100; x=x+10 )
    {
     // conectar mais outra celula
        back = int_Cell_connect ( int_Cell_get_back ( a ), 
                                  int_new_Cell ( x ) );
     // mostrar dados
        int_Cell_print ( a );
     // mostrar a quantidade de testes
        printf ( "global_tests = %d\n", global_tests );
    }
    printf ( "\n" );
    printf ( "\n09. Testar conexao de celulas\n" );
    for ( int x = 110; x<=130; x=x+10 )
    {
     // conectar mais outra celula
        back = int_Cell_connect ( int_Cell_get_back ( a ), 
                                  int_new_Cell ( x ) );
     // mostrar dados
        int_Cell_print ( a );
     // mostrar a quantidade de testes
        printf ( "global_tests = %d\n", global_tests );
    }
    printf ( "\n" );
    printf ( "\n10. Testar conexao de celulas\n" );
    for ( int x = 140; x<=160; x=x+10 )
    {
     // conectar mais outra celula
        back = int_Cell_connect ( int_Cell_get_back ( back ), 
                                  int_new_Cell ( x ) );
     // mostrar dados
        int_Cell_print ( a );
     // mostrar a quantidade de testes
        printf ( "global_tests = %d\n", global_tests );
    }
    printf ( "\n" );
    printf ( "\n11. Testar conexao de celulas\n" );
    for ( int x = 170; x<=200; x=x+10 )
    {
     // conectar mais outra celula
        back = int_Cell_push_back 
             ( back, int_new_Cell ( x ) );
     // mostrar dados
        int_Cell_print ( a );
     // mostrar a quantidade de testes
        printf ( "global_tests = %d\n", global_tests );
    }
    printf ( "\n" );
 // desconectar ultima celula
    printf ( "\n12. Testar desconexao de celula\n" );
    back = int_Cell_disconnect 
         ( back, int_Cell_get_back ( back ) );
 // mostrar dados
    int_Cell_print ( a );
    printf ( "\n" );
 // desconectar outra celula
    printf ( "\n13. Testar desconexao de celula\n" );
    back = int_Cell_disconnect 
         ( int_Cell_get_before_back ( a ),
           int_Cell_get_back ( back )   );
 // mostrar dados
    int_Cell_print ( a );
    printf ( "\n" );
 // desconectar outras celulas
    printf ( "\n14. Testar desconexao de celula\n" );
    for ( int x=1; x<=3; x=x+1 )
    {
        back = int_Cell_disconnect 
             ( int_Cell_get_before_back ( a ),
               int_Cell_get_back ( back )   );
     // mostrar dados
        int_Cell_print ( a );
    }
    printf ( "\n" );
 // desconectar outras celulas
    printf ( "\n15. Testar desconexao de celula\n" );
    while ( back != null )
    {
        back = int_Cell_pop_back ( a) ;
     // mostrar dados
        int_Cell_print ( a );
        getchar( );
    }
 // remover o apontador o estrutural
    printf ( "\n16. Testar remocao de celula\n" );
    free ( a );
    a = null;
 // mostrar dado
    int_Cell_print ( a );
} // Fim Método Para Testar

/* Fim Métodos E Funções */


/* Função Principal */
int main ( )
{
    int_Cell_test ( );
    return 0;
}
/* Fim Função Principal */