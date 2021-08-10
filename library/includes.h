#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include<math.h>
#include<thread>

#define print(var) std::cout<<var<<std::endl;
#define ask(var) std::cin>>var;
/*OVERLOADERS*/
std::ostream& operator<<(std::ostream& os,std::vector<std::string> sample)
{
    for(auto itr : sample) {os<<itr<<" ";} return os;
}
