#include<iostream>
#include<vector>     // std::cout, std::dec, std::hex, std::oct
#include"library/mylib.h"

int main () 
{
    int input;
    std::cout<<"How many digits do you want? >>>"; std::cin>>input;
    std::vector<std::string> instances(input,files::get_characters("sample/numbers.txt"));



    return 0;
}