#include <cassert>
#include <wh/whio/whio_streams.h>
#include <wh/whio/whio_stream_stl.hpp>
#include <sstream>

#define MARKER if(1) printf("MARKER: %s:%d:%s():\n",__FILE__,__LINE__,__func__); if(1) printf

int main( int argc, char const ** argv )
{

    whio_stream * wout = whio_stream_for_filename( "/dev/stdout", "w+" );
    assert( wout );

    {
        std::ostringstream dummy;
        whio::ostreambuf_whio os( dummy, wout, false );
        dummy << "Hi, world!\n";
    }
    wout->api->flush(wout);

    whio_stream * win = whio_stream_for_filename( "/dev/stdin", "r" );
    assert( win );
    {
        std::istringstream din;
        whio::istreambuf_whio os( din, win, false );
        MARKER("Enter an INTEGER and tap ENTER, then CTRL-D: ");
        fflush(stdout);
        int x = -1;
        din >> x;
        MARKER("read int=%d\n",x);
    }
    win->api->finalize(win);
    wout->api->finalize(wout);

    return 0;
}
