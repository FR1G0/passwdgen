#include<iostream>
#include<vector>     // std::cout, std::dec, std::hex, std::oct
#include"library/mylib.h"

int main () 
{
    int input; std::string line=" ";
    std::cout<<"How many digits do you want? >>>"; std::cin>>input;
    std::string instances = files::get_characters("sample/numbers.txt");
    for(size_t digits=0; digits<input;digits++)
    {
        for(size_t stringchars=0;stringchars<instances.size();stringchars++)
        {
            line.at(digits) = instances.at(stringchars);
            files::append_write("out/sample.txt",line+"\n");
        }
        line+=" ";
    }
    return 0;
}