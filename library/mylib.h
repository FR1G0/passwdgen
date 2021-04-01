#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include<math.h>

#define print(var) std::cout<<var<<std::endl;

namespace files
{
    std::string get_characters(std::string path)
    {
        std::string toreturn;
        std::ifstream readthis; readthis.open(path.c_str());
        if(readthis.is_open())
        {
            std::string line;
            while(getline(readthis,line)){toreturn +=line;}
            readthis.close(); return toreturn;
        }
        else {print("[ERRORE] Failed to read file"); return NULL;}
    }

    void append_write(std::string path,std::string content)
    {
        std::ofstream towrite(path.c_str(), std::ofstream::app);
        if(towrite.is_open())
        {
            towrite<<content;
            towrite.close(); return;
        }
        else {print("[ERRORE] Failed to write on file "); return;}
    }
}
namespace data
{
    struct node
    {
        std::string content = "";
        int pos=0, digit=0;
        node * next = NULL;
        /*fucked*/
        void elevate() 
        {
            digit++;
            if(digit==content.size())
            {
                digit=0; if(next != NULL){next->elevate();} 
            }
        }
    };
    int node_size(node * temp)
    {
        if(temp->next == NULL) {return temp->pos;}
        return node_size(temp->next);
    }
    void circle(node * temp, node * start)
    {
        if(temp->next == NULL) {temp->next = start; return;}
        circle(temp->next,start);
    }
    void push(std::string newcontent, node * temp)
    {
        if(temp->content=="")
        {
            temp->content = newcontent;
            node* newnode = new node; newnode->pos = temp->pos+1;
            temp->next = newnode; return; 
        }
        push(newcontent,temp->next);
    }
    node * Get(node * start, int frompos)
    {
        if(start->pos == frompos) {return start;}
        return Get(start->next,frompos);
    }
    node * Getlast(node * start)
    {
        if(start->next->next==NULL) {return start;}
        return Getlast(start->next);
    }
    void vector_to_node(std::vector<std::string> temp, node* nodes)
    {
        int size_vec = temp.size();
        for(size_t x=0;x<size_vec;x++) { push(temp[x],nodes);}
        return;
    }
    void printall(node * temp)
    {
        if(temp==NULL) {return;}
        std::cout<<temp->content<<std::endl;
        printall(temp->next);
    }
    std::string assemble(node * temp)
    {
        if(temp->next==NULL) {return "\n";}
        return temp->content.at(temp->digit)+assemble(temp->next);
    }
}

namespace resolve
{
    std::string simple_string_node_ram(data::node * temp)
    { 
        std::string result=" ";
        data::node * last = data::Getlast(temp); int lastsize=last->content.size()-1;
        while(last->digit!=lastsize)
        {
            result+=data::assemble(temp);
            temp->elevate();
        }
        return result;
    }
    
}
