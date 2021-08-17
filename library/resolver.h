#include"includes.h"
//resolvers are methods that allow the processing of the information in the nodes

namespace resolve
{   
    /*this resolver collects a section of data and writes it to data*/
    

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