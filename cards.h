#pragma once
#ifndef Cards_H
#define Cards_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Cards {
    //private:
    string id;
    string file;
    

public:
    Cards();

    // accessor
    
    string getId();
    void setFile(string newFile);
    string getFile();
    void setId(string Id);
    
    void read_image();

protected:
    
};


#endif // SET_GET_H

