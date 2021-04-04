#include"includes.h"

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
    struct vector_node
    {
        std::vector<std::string> content;
        int pos=0, digit=0;
        vector_node * next = NULL;

    };
    int node_size(node * temp)
    {
        if(temp->next == NULL) {return temp->pos;}
        return node_size(temp->next);
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