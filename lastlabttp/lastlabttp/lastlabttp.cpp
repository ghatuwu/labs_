//
//  lastlabttp.cpp
//  lastlabttp
//
//  Created by ehet on 21.05.2022.
//

#include <iostream>
#include "lastlabttp.hpp"
#include "lastlabttpPriv.hpp"

void lastlabttp::HelloWorld(const char * s)
{
    lastlabttpPriv *theObj = new lastlabttpPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void lastlabttpPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

