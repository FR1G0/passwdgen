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
