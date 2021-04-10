#include"includes.h"
#include"files.h"
#include"data.h"

namespace resolve
{   
    void simple_string_node_hybrid(data::node * temp, std::string path, int perwrite)
    {
        std::string result=""; data::node *last = data::Getlast(temp); int lastsize=last->content.size()-1, counter=0;
        while(last->digit!=lastsize)
        {
            result+=data::assemble(temp);
            temp->elevate(); counter++;
            if(counter==perwrite) {files::append_write(path,result); result=""; counter=0;}
        }
        if(counter<=perwrite) {files::append_write(path,result);}
    }
    

}

namespace todata
{
    void list_to_vector(std::string list, std::vector<std::string> &temp)
    {
        int start=0,end=0;
        for(size_t counter=0;list.at(counter)!=']'||counter!=list.size();counter++)
        {
            if(list.at(counter)=='\"')
            {
                start=counter+1;
                for(size_t finder=0;finder<(list.size()-counter);counter++)
                {
                    if(list.at(counter+finder)=='\"'){end=counter+finder-1; break;}
                }
            }
        }
    }
}