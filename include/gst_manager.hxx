
#ifndef GST_MANAGER_HXX
#define GST_MANAGER_HXX

#include <gst/gst.h>
#include <string>

class gst_manager
{
public:
    gst_manager();
    ~gst_manager();

    void operator()(std::string & _file2watch);
    void play();

private:

    void init(std::string & _file2watch);
 
    GstElement *pipeline_;
    GstBus *bus_;
    GstMessage *msg_;
};

#endif
