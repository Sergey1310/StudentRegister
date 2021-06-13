//
// Created by Sergey on 6/13/2021.
//

#ifndef STUDENTREGISTER_STUDENTREGISTER_H
#define STUDENTREGISTER_STUDENTREGISTER_H


#include <iostream>
#include <string>
#include <vector>
using namespace std;
//---------------------------------------------------------------------------------------------------------------------
/*
1. написать класс Студенческий журнал. в нем нужно хранить студентов,
о каждом известны фио, номер группы, пол, средний балл зачетки.
класс создается пустым, без студентов. можно добавлять студентов,
выводить инфо о конкретном студенте, удалять студентов, очищать список.
при этом, выводить инфо и удалять надо принимая фио. если такого студента нет,
писать об этом в консоль. при добавлении если студент с таким фио уже есть -
нужно не добавлять нового, а изменить параметры уже записанного. использовать stl
 */


class StudentRegister
{
private:
    class Student
    {
    public:
        string firstName;
        string surname;
        string patronymic;
        bool gender;
        int averageScore;
        int groupNumber;

        void SetName(){
            cout << "----------------------------------------------------------------------------------" << endl;
            cout << "| Pleas enter Name of student: ";
            cin >> firstName;

            cout << "| Pleas enter Surname of student: ";
            cin >> surname;

            cout << "| Pleas enter Patronymic of student: ";
            cin >> patronymic;
        } /*Задаём отдельно ФИО, оно используется не только для создания объекта но и дл других
                             операций, поэтому отдельно*/
        void SetParam()
        {
            cout << "| Pleas enter gender of student: ";
            cin >> gender;

            cout << "| Pleas enter number group where study student: ";
            cin >> groupNumber;

            cout << "| Pleas enter a middle ball of student: ";
            cin >> averageScore;
            cout << "----------------------------------------------------------------------------------" << endl;
        } // Здесь остальные параметры, гендер тоже тут, свободная стпана всё же)
        void Show() const{
            cout << "----------------------------------------------------------------------------------" << endl;
            cout << "| Student:" << endl;
            cout << "| Name: " << firstName
                 << "\t Surname: " << surname
                 << "\t\t Patronymic: " << patronymic << endl;
            cout << "|" << endl;
            cout << "| Gender: " << gender
                 << "\t Group number: " << groupNumber
                 << "\t The middle ball: " << averageScore << endl;
            cout << "----------------------------------------------------------------------------------" << endl;
        } // Выводим на экран Инфо
        Student(){
            this -> averageScore = 0;
            this -> groupNumber = 0;
            this -> firstName = "none";
            this -> surname = "none";
            this -> patronymic = "none";
            this -> gender = false;
        }; // Конструктор, не знаю для чего он нужен, но висело предупреждение что нужен.
    };// Тут всё в принципе понятно, объектом студенческого журнала должны быть студенты
    vector<Student> Register; // Вектор под студентов
    vector<string> AnswerType{"Yes","yes","Y","y","No","no","n"}; // Вектор под варианты ответов в функции "AddStudent"
    string answer; // Перемнная под ответ пользователя в функции "AddStudent" 122 строка.
    int identifier; //Вспомогательная переменная, определяется в функции "CheckName", хранит индекс определяемого объекта.
    Student NewStudent;

    void EnterFIO()
    {
        NewStudent.SetName();
    }; //Заводим новый объект Студент с ФИО, кладём в вектор "Check"
    int CheckName(){
        identifier = 0;
        int size = Register.size(); // Тут какое то предупреждение о конвертации, но всё работает
        for (int i = 0; i < size; ++i) {
            if (NewStudent.firstName == Register[i].firstName
                && NewStudent.firstName == Register[i].surname
                && NewStudent.firstName == Register[i].patronymic){
                identifier = i; // Тут, в случае если ФИО есть в векторе, сохранчю его индекс в массиве.
                return 1; // Эту функцию я использую в if-ах, поэтому удобно было поставить возврат 1, если есть дубль
            }
        }
        return 0;// и 0, если нету.
    }; // Проверка на наличие студента из "EnterNewStudent" в основном векторе "Register"

public: //Тут уже готовые методы класса, непосредственно для использования.
    void AddStudent()
    {
        EnterFIO();
        int point = 0; // Вспомогалельная переменная, Если введённого студента ещё нет в векторе или есть, и  пользователь
        if (CheckName()){ // Ответил что хочет внести изменения, то остаётся изменений и данные вносятся.
            cout << "@------------------------------------@" << endl;// А если нет, то выходим из программы не с чем.
            cout << "|                                    |" << endl;
            cout << "| Such a student is already existent |" << endl;
            cout << "| Do you want to change his details? |" << endl;
            cout << "| Please answer yes or no : ";
            cin >> answer;
            cout << "|                                    |" << endl;
            cout << "@------------------------------------@" << endl;
            if (AnswerType[0] == answer
                || AnswerType[1] == answer
                || AnswerType[2] == answer
                ||AnswerType[3] == answer){
                NewStudent.SetParam();
            }else if (AnswerType[4] == answer
                      || AnswerType[5] == answer
                      || AnswerType[6] == answer){
                point = 1;
            } else{
                cout << "@-----------------------------------@" << endl;
                cout << "|                                   |" << endl;
                cout << "|   You entered an invalid value!   |" << endl;
                cout << "|   Input canceled.                 |" << endl;
                cout << "|                                   |" << endl;
                cout << "@-----------------------------------@" << endl;
                point = 1;
            }
        }
        if (!point){
            NewStudent.SetParam(); // Добавляем или меняем инфу у студента
            Register.push_back(NewStudent); // И передаём на постоянное хранение в главный вектор
        } else{
            cout << "@------------------------------------@" << endl;
            cout << "|                                    |" << endl;
            cout << "|   No changes have been made.       |" << endl;
            cout << "|                                    |" << endl;
            cout << "@------------------------------------@" << endl;
        }
    };
    void DelStudent()
    {
        EnterFIO(); // Вводи Имя,
        if (!CheckName()) {
            cout << "@-----------------------------------@" << endl;
            cout << "|                                   |" << endl;
            cout << "|   Such a student does not exist!  |" << endl;
            cout << "|                                   |" << endl;
            cout << "@-----------------------------------@" << endl;
        } else Register.erase(Register.begin()+identifier);
    };
    void ShowStudent()
    {
        EnterFIO();
        if (!CheckName()){
            cout << "@------------------------------------@" << endl;
            cout << "|                                    |" << endl;
            cout << "|   Such a student does not exist!   |" << endl;
            cout << "|                                    |" << endl;
            cout << "@------------------------------------@" << endl;
        } else Register[identifier].Show();
    };
    void ShowAllStudent()
    {
        int sise = Register.size();
        for (int i = 0; i < sise; ++i) {
            Register[i].Show();
        }
    };
    void ClearList ()
    {
        Register.clear();
    };
};


#endif //STUDENTREGISTER_STUDENTREGISTER_H
