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
    struct vector_node : public node
    {
        std::vector<std::string> content;
        int pos=0, digit=0;
        vector_node * next = NULL;
    };
    struct list
    {
        std::vector<std::string> content;
        void showall()
        {
            std::cout<<"[";
            for(size_t counter=0;counter<content.size();counter++)
            {
                std::cout<<content.at(counter)<<",";
            }
            std::cout<<"]";
        }
    };



/*--------------------------METHODS--------------------------*/
    /*Returns the side of the node*/
    int node_size(node * temp)
    {
        if(temp->next == NULL) {return temp->pos;}
        return node_size(temp->next);
    }
//methods for simple node with string as content
    /*adds a new node*/
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
    /*returns the pointer to the last node*/
    node * Getlast(node * start)
    {
        if(start->next->next==NULL) {return start;}
        return Getlast(start->next);
    }
    /*inserts the strings inside the vector into the node*/
    void vector_to_node(std::vector<std::string> temp, node* nodes)
    {
        int size_vec = temp.size();
        for(size_t x=0;x<size_vec;x++) { push(temp[x],nodes);}
        return;
    }
    /*prints all content of */
    void printall(node * temp)
    {
        if(temp==NULL) {return;}
        std::cout<<temp->content<<std::endl;
        printall(temp->next);
    }
    /*assembles the elements of the nodes*/
    std::string assemble(node * temp)
    {
        if(temp->next==NULL) {return "\n";}
        return temp->content.at(temp->digit)+assemble(temp->next);
    }

//methods for vector strings
    void vpush(std::vector<std::string> content, vector_node * temp)
    {
        if(temp->next == NULL)
        {
            vector_node* newnode = new vector_node;
            newnode->content = content; newnode->pos = temp->pos+1;
            temp->next = newnode; return;
        }
        vpush(content,temp->next);
    }
    std::string assemble(vector_node * temp)
    {
        if(temp->next==NULL) {return "\n";}
        return temp->content.at(temp->digit)+assemble(temp->next);
    }
    
}

