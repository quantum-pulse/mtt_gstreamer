
#ifndef FILESYS_MGR_HXX
#define FILESYS_MGR_HXX

#include <filesystem>

class filesys_mgr
{
public:
    filesys_mgr();
    ~filesys_mgr();

    bool isRelative(const std::string & _filename);
    bool hasFile(const std::string & _filename);
    std::string operator()();

private:
    std::string getcwd();
};

#endif
