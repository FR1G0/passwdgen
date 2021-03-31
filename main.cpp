#include<iostream>
#include"library/mylib.h"


int main () 
{
    int input;
    std::cout<<"How many digits do you want? >>>"; std::cin>>input;
    std::string line = " "; line.resize(input);
    std::vector<std::string> instances(input,files::get_characters("sample/numbers.txt")); 
    scroll::node* newnode = new scroll::node();
    scroll::vector_to_node(instances,newnode);
    
    std::cout<<resolve::simple_string_node_ram(newnode);
    

    return 0;
}