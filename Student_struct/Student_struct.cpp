/*Задание 1. Описать структуру Student (фамилия, группа, успеваемость
(массив из 5 int)). Создать массив студентов и написать программу,
позволяющую:
● Динамически изменять размер массива
● Выводить список отличников (>75% отличных оценок)
● Выводить список двоечников (>50% оценок 2 и 3)
*/

#include <iostream> 
#include <string> 
using namespace std;

struct student
{
    string name;
    string surname;
    string group;
    int score[5];
    void setStudent()
    {
        cout << "###############################" << endl;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter surname: ";
        cin >> surname;
        cout << "Enter group: ";
        cin >> group;
        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0: cout << "Enter Math score: " << endl; cin >> score[i]; if (score[i] > 100 || score[i] < 0) { cout << "incorrect score"; exit(0); }; break;
            case 1: cout << "Enter ESL score: " << endl; cin >> score[i]; if (score[i] > 100 || score[i] < 0) { cout << "incorrect score"; exit(0); }; break;
            case 2: cout << "Enter Language score: " << endl; cin >> score[i]; if (score[i] > 100 || score[i] < 0) { cout << "incorrect score"; exit(0); }; break;
            case 3: cout << "Enter Chemestry score: " << endl; cin >> score[i]; if (score[i] > 100 || score[i] < 0) { cout << "incorrect score"; exit(0); }; break;
            case 4: cout << "Enter Biology score: " << endl; cin >> score[i]; if (score[i] > 100 || score[i] < 0) { cout << "incorrect score"; exit(0); }; break;
            }
        }
        cout << "###############################" << endl;
    }
    void print()
    {
        cout << "###############################" << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Group: " << group << endl;
        cout << "------------score-------------" << endl;
        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0: cout << "Math score: " << score[i] << endl; break;
            case 1: cout << "ESL score: " << score[i] << endl; break;
            case 2: cout << "Language score: " << score[i] << endl; break;
            case 3: cout << "Chemestry score: " << score[i] << endl; break;
            case 4: cout << "Biology score: " << score[i] << endl; break;
            }
        }
        cout << "###############################" << endl;
    }
};

void printAllStudents(student stArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        stArray[i].print();
    }
}
void  addNewStudent(student** arr, int& size)
{
    student* newArr = new student[size + 1];
    for (int i = 0; i < size; i++)
    {
        newArr[i] = (*arr)[i];
    }

    cout << "-------------Enter new student data:-------------" << endl;
    newArr[size].setStudent();
    delete[] * arr;
    (*arr) = newArr;
    size++;
}
void printFools(student* studentArr, int size)
{
    cout << "----------------------Fools----------------------" << endl;
    int foolCounter = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < sizeof(studentArr[i].score) / sizeof(studentArr[i].score[j]); j++)
        {
            if (studentArr[i].score[j] < 50) { foolCounter++; }
            if (foolCounter >= 2) { studentArr[i].print(); break; }
        }
        foolCounter = 0;
    }

}
void printExcellentStudents(student* studentArr, int size)
{
    cout << "---------------Excellent-students----------------" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < sizeof(studentArr[i].score) / sizeof(studentArr[i].score[j]); j++)
        {
            if (studentArr[i].score[j] > 75) { studentArr[i].print(); break; }
        }
    }
}


int main()
{
    int size = 2;
    student st1, st2;
    st1.setStudent();
    st2.setStudent();
    st1.print();
    st2.print();

    student* studentArray = new student[2];
    studentArray[0] = st1;
    studentArray[1] = st2;

    addNewStudent(&studentArray, size);
    printAllStudents(studentArray, size);

    printFools(studentArray, size);

    delete[] studentArray;

}