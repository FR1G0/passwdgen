#include<iostream>
#include"library/all.h"

/*
    using namespace std;
    using namespace data;
*/

int main () 
{
    std::string cont = files.get_content("assets/list.txt");
    node* newnode = new node(files.get_content("sample/letters.txt"));
    

    return 0;
}