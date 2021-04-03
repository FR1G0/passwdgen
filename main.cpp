#include<iostream>
#include"library/mylib.h"


int main () 
{
    int input;
    std::cout<<"How many digits do you want? >>>"; std::cin>>input;
    std::string line = " "; line.resize(input);
    std::vector<std::string> instances(input,files::get_characters("sample/numbers.txt")); 
    data::node* newnode = new data::node();
    data::vector_to_node(instances,newnode);
    //data::printall(newnode);
    resolve::simple_string_node_hybrid(newnode,"out/sample.txt",50000);
    

    return 0;
}