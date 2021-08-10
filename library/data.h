#include"includes.h"


namespace data
{
    /*DATA TYPES*/
    class node 
    {
        protected:
            int anchor;
        public:
            node(std::string sample) : content(sample), anchor(sample.size()) {};

            /*DATA*/
            std::string content;
            node* next = NULL;

            /*methods*/
            void roll() {P_roll(this,this);}
            virtual void push(std::string sample) {content+=sample; anchor=content.size();}
            

            /*GETTERS*/
            node* getlast() {P_getlast(this);}
            node* getfirst() {return this;}
            int getanchor() {return anchor;}


        private:
        void P_roll(node* start,node* current)
        {
            if(current->next == NULL) {current->next = start; return;}
            P_roll(start,current->next);
        }
        node* P_getlast(node * subject) {return subject->next == NULL ? subject : P_getlast(subject->next);}
    };

    /*METHODS FOR DATA*/
    class
    {

    }methods;

    
}