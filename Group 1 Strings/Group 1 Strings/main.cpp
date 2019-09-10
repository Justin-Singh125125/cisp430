//
//  main.cpp
//  Group 1 Strings
//
//  Created by Justin Singh on 9/9/19.
//  Copyright © 2019 Justin Singh. All rights reserved.
//

#include <iostream>

void stringCopy(char * a, char * b);

using namespace std;







int main() {

    char a[15]="Hello", b[15]="Hi";
    
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    
    cout << "Calling stringCopy function"<<endl;
    stringCopy(a, b);
}


void stringCopy(char * a, char * b){
    
    
    int i = 0;
    for(; i < strlen(b);i++){
        a[i]=b[i];
    }
    
    //set the null
    a[i]='\0';
    
    cout <<  strlen(a) << endl;
    
    cout << "should be good: " << a << endl;
    cout << endl;
}



