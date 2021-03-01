
#include <gst/gst.h>
#include <string>

#include "gstManager.hxx"

using namespace std;

string gBuffer="playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm";

int main(int argc,char ** argv)
{
    /*
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;
    */

    //Initialize GStreamer 
    gst_init (&argc, &argv);
    gstManager lManager(gBuffer);
    lManager.init();
    lManager.play();
   
    /* 
    //Build the pipeline 
    pipeline = gst_parse_launch(gBuffer.c_str(),nullptr);

    // Start playing 
    gst_element_set_state (pipeline, GST_STATE_PLAYING);

    // Wait until error or EOS 
    bus = gst_element_get_bus (pipeline);
    auto lgst_err = GST_MESSAGE_ERROR | GST_MESSAGE_EOS;
    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,(GstMessageType)lgst_err) ;//GST_MESSAGE_ANY;
    
    // Free resources 
    if (msg != nullptr)
        gst_message_unref (msg);
    gst_object_unref (bus);
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);
    */ 
    return 0;
}
