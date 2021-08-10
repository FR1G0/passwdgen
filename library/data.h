#include"includes.h"

/*OVERLOADERS*/
std::ostream& operator<<(std::ostream& os,std::vector<std::string> sample)
{
    for(auto itr : sample) {os<<itr<<" ";} return os;
}



namespace data
{
    /*DATA TYPES*/
    class node
    {
        protected:
            int anchor;
        public:
            node(std::string sample) : content(sample),anchor(sample.size()) {};

            /*DATA*/
            std::string content;
            node* next = NULL;

            /*methods*/
            void roll() {P_roll(this,this);}


            /*GETTERS*/
            node* getlast(node * subject) {return subject->next == NULL ? subject : getlast(subject->next);}
            node* getfirst(node * subject) {return this;}
            int getanchor() {return anchor;}

        private:
        void P_roll(node* start,node* current)
        {
            if(current->next == NULL) {current->next = start; return;}
            P_roll(start,current->next);
        }
    };

    /*METHODS FOR DATA*/
    class
    {

    }methods;
}