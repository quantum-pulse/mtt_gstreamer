
#include "gst_manager.hxx"

using namespace std;

string urisegment="playbin uri=file://";

gst_manager::gst_manager():pipeline_(nullptr),bus_(nullptr),msg_(nullptr)
{

}

gst_manager::~gst_manager()
{
    if(msg_) gst_message_unref(msg_);
    if(bus_) gst_object_unref(bus_);
    if(pipeline_){
        gst_element_set_state(pipeline_, GST_STATE_NULL);
        gst_object_unref(pipeline_);
    }
}
    
void gst_manager::operator()(string & _file2watch)
{
    init(_file2watch);
}

void gst_manager::play()
{
    gst_element_set_state(pipeline_,GST_STATE_PLAYING);
    bus_=gst_element_get_bus(pipeline_);
    auto lgst_err= GST_MESSAGE_ERROR | GST_MESSAGE_EOS;
    msg_=gst_bus_timed_pop_filtered(bus_, GST_CLOCK_TIME_NONE,(GstMessageType)lgst_err);//GST_MESSAGE_ANY;
}

void gst_manager::init(string & _file2watch)
{
    string lBuffer=urisegment+_file2watch;
    pipeline_=gst_parse_launch(lBuffer.c_str(),nullptr);
}
