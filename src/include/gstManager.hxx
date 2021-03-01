
#ifndef GSTMANAGER_HXX
#define GSTMANAGER_HXX

#include <gst/gst.h>
#include <string>
#include <tools>

std::string urisegment="playbin uri=file://";

class gstManager
{
public:
    gstManager(std::string & _dataFile):dataFile_(_dataFile),pipeline_(nullptr),bus_(nullptr),msg_(nullptr){}
    ~gstManager(){
        if(msg_) gst_message_unref(msg_);
        if(bus_) gst_object_unref(bus_);
        if(pipeline_){
            gst_element_set_state(pipeline_, GST_STATE_NULL);
            gst_object_unref(pipeline_);
        }
    }
    
    void init(){
        std::string lBuffer=urisegment+dataFile_;
        rlog_wn(lBuffer);
        pipeline_=gst_parse_launch(lBuffer.c_str(),nullptr);
    }

    void play(){
        gst_element_set_state(pipeline_,GST_STATE_PLAYING);
        bus_=gst_element_get_bus(pipeline_);
        auto lgst_err= GST_MESSAGE_ERROR | GST_MESSAGE_EOS;
        msg_=gst_bus_timed_pop_filtered(bus_, GST_CLOCK_TIME_NONE,(GstMessageType)lgst_err);//GST_MESSAGE_ANY;
    }

private:
    
    std::string & dataFile_;
    GstElement *pipeline_;
    GstBus *bus_;
    GstMessage *msg_;
};

#endif
