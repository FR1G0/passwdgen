#include"includes.h"



/*DATA TYPES*/
class node 
{
    protected:
        int anchor;
    public:
        node() {};
        node(std::string sample) : content(sample), anchor(0) {};
        node(long digits,std::string sample) {for(long x=0;x<digits;x++){push(sample);}}


        /*DATA*/
        node* next = NULL;

        /*METHODS*/
        void roll() {P_roll(this,this);}
        virtual void push(std::string sample) {content+=sample; anchor=content.size();}
        virtual void update_anchor() {if(anchor++==content.size()){anchor=0; return;}anchor++;}
            

        /*GETTERS*/
        node* getlast() {P_getlast(this);}
        node* getfirst() {return this;}
        int getanchor() {return anchor;}
        


    private:
    std::string content;
    void P_roll(node* start,node* current)
    {
        if(current->next == NULL) {current->next = start; return;}
        P_roll(start,current->next);
    }
    node* P_getlast(node * subject) {return subject->next == NULL ? subject : P_getlast(subject->next);}
};
class node_vectorstring : public node
{
    protected:
    public:
        node_vectorstring(std::vector<std::string> sample) : content(sample) {};

        /*methods*/
        void push(std::string sample) {content.push_back(sample);}
        

    private:
    std::vector<std::string> content;
};
    

/*METHODS FOR DATA*/
class
{

}methods;
