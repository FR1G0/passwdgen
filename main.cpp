#include<iostream>
#include"library/resolver.h"

/*
    using namespace std;
    using namespace data;
*/

int main () 
{
    std::string cont = files.get_content("sample/list.txt");
    data::node* newnode = new data::node(files.get_content("sample/letters.txt"));
    

    return 0;
}