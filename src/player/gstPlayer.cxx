
#include <cstdlib>
#include "gst_manager.hxx"

using namespace std;

int main(int argc,char ** argv)
{
    if(argc==1) exit(EXIT_FAILURE);
    string element{argv[1]};
    gst_init(&argc, &argv);
    gst_manager lMediaManager;
    lMediaManager(element);
    lMediaManager.play();
}
