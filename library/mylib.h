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
namespace scroll
{
    struct node
    {
        node(std::string temp) {content = temp;}
        std::string content = "";
        int pos=0, digit=-1;
        node * next = NULL;
        char Getchar() { elevate(); return content.at(digit);}
        void elevate() { digit++; if(digit>content.size()){digit=-1; next->elevate(); return;}return;}
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
        if(temp->next == NULL)
        {
            node * newnode = new node(newcontent);
            newnode->pos = temp->pos+1;
            temp->next = newnode; return;
        }
        push(newcontent,temp->next);
    }
    node * Get(node * start, int frompos)
    {
        if(start->pos == frompos) {return start;}
        return Get(start->next,frompos);
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
    std::string Getall_nodeChars(node * temp)
    {
        if(temp == NULL) {return "\n";}
        return Getall_nodeChars(temp->next)+temp->Getchar();
    }
}

namespace resolve
{
    std::string simple_string_node_ram(scroll::node * temp)
    { 
        int res = pow(node_size(temp),temp->content.size());
        for(int contatore=0;contatore<res;contatore++)
        {
            std::cout<<"\n"<<scroll::Getall_nodeChars(temp);
        }
        return " ";
    }
    
}
