#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>

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
namespace scroll
{
    struct node
    {
        std::string content;
        int pos=0, digit=-1;
        node * next = NULL;
        char Getchar() { elevate(); return content.at(digit);}
        void elevate() { digit++; if(digit>content.size()){digit=-1; return;}}
    };
    void circle(node * temp, node * start)
    {
        if(temp->next == NULL) {temp->next = start; return;}
        circle(temp->next,start);
    }
    void push(std::string newcontent, node * temp)
    {
        if(temp->next == NULL)
        {
            node * newnode = new node();
            newnode->content = newcontent; newnode->pos = temp->pos+1;
            temp->next = newnode; return;
        }
        push(newcontent,temp->next);
    }
    node * Get(node * start, int frompos)
    {
        if(start->pos == frompos) {return start;}
        return Get(start->next,frompos);
    }
}

namespace resolve
{
    std::string simple_string_node_ram(node * temp,)
    

}
