#include<iostream>



int main () 
{
    int input;
    std::cout<<"How many digits do you want? >>>"; std::cin>>input;
    std::string line = " "; line.resize(input);
    std::vector<std::string> instances(input,files::get_characters("sample/numbers.txt")); 
    
    
    

    return 0;
}