
#include "filesys_mgr.hxx"
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

string filesys_mgr::operator()()
{
    return getcwd();
}

bool filesys_mgr::isRelative(const string & _filename)
{
    return (fs::path(_filename).parent_path().compare("")==0);
}

bool filesys_mgr::hasFile(const string & _filename)
{
    return fs::exists(_filename);
}

string filesys_mgr::getcwd()
{
   return fs::current_path(); 
}
