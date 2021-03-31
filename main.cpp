#include<iostream>
#include<vector>
#include"library/mylib.h"

struct scroll
{
    std::string digit;
    int pos=0;  
};

int main () 
{
    int input;
    std::cout<<"How many digits do you want? >>>"; std::cin>>input;
    std::string line = " "; line.resize(input);
    std::vector<std::string> instances(input,files::get_characters("sample/numbers.txt")); 
    for(size_t digit=0;digit<input;digit++)
    {
        
    }
    

    return 0;
}