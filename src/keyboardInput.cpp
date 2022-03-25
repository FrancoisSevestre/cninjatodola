#include "keyboardInput.hpp"
/*
 * Je ne comprends pas encore cette partie!
 * Je sais juste qu'elle focntionne
 *
 *
 *
 */

char keyboardInput()
{
    char c;
    char z;

    struct termios oldSettings, newSettings;

    tcgetattr( fileno( stdin ), &oldSettings );
    newSettings = oldSettings;
    newSettings.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr( fileno( stdin ), TCSANOW, &newSettings );

    fd_set set;
    struct timeval tv;

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    FD_ZERO( &set );
    FD_SET( fileno( stdin ), &set );

    int res = select( fileno( stdin )+1, &set, NULL, NULL, &tv );

    if( res > 0 )
    {
        char c;
        // printf( "Input available\n" );
        read( fileno( stdin ), &c, 1 );
        z = c;
    }
    else if( res < 0 )
    {
        perror( "select error" );
    }
    else
    {
        printf( "Select timeout\n" );
    }

    tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );

    return z;
}
