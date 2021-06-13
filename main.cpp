#include <iostream>
#include <vector>
#include <string>
#include "StudentRegister.h"





using namespace std;

int main() {
    StudentRegister reg;
    reg.AddStudent();
    reg.AddStudent();
    reg.ShowAllStudent();
    reg.ShowStudent();
    reg.DelStudent();
    reg.ShowAllStudent();

}
