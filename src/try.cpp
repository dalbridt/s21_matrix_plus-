#include <iostream>
#include <string>
#include <exception>
#include "s21_matrix_oop.h"
using namespace std; 

int main(){
   
    try{
        S21Matrix matrix(1, 3);
        cout << "matrix created" << endl ;
    } catch(exception & er) {
        cout << er.what() << endl;
    }
    return 0; 
}
