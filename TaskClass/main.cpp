/*Задача #6: Классы
 
 Для получения места в общежитии формируется список студентов, который включает ФИО студента, номер группы, список из четырех оценок за сессию и средний балл (вычисляется). Создать класс Student по заданному условию, в котором определены поля и методы класса:

 - именованные свойства (get и set) для атрибутов класса;

 - конструктор без параметров;

 - конструктор с параметрами;

 - ввод данных с консоли - InputStudent();

 - вывод данных - OutputStudent();

 - переопределенный оператор > для сравнения двух объектов класса по среднему баллу.

 Реализовать статические функции: MinMark для определения минимального среднего балла, Sort для сортировки списка студентов по среднему баллу.

 Формат ввода

 На первой строке вводится натуральное число N - количество студентов в списке. Далее на последующих N строках вводятся элементы этого списка - данные о студентах - каждое значение на отдельной строке.

 Формат вывода

 Исходный список студентов (значения ФИО студента, номер группы и средний балл выводятся на одной строке через пробел, но каждый элемент списка выводятся на отдельной строке) Число - размер минимального среднего балла Отсортированный список студентов (значения ФИО студента, номер группы и средний балл выводятся на одной строке через пробел, но каждый элемент списка выводятся на отдельной строке)*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Student {
public:
    string Name;
    string Soname;
    string FatherName;
    string Marks;
    double Srmark;
    
    Student() {
        Name = "";
        Soname = "";
        FatherName = "";
        Marks = "";
        Srmark = 0;
    };
    Student(const string& name, const string& soname, const string& fatherName, const string& marks){
       // Student student;
        Name = name;
        Soname = soname;
        FatherName = fatherName;
        Marks = marks;
        Srmark = AverageMark();
//        Print();
    };
    double AverageMark() {
        double sum = 0;
            for (int i = 0; i < Marks.size() ; i++)
            {
                sum += Marks[i] - '0';
            }
            sum = sum / Marks.size();
        return sum;
    };
    void Print()
    {
        cout << Name << " ";
        cout << Soname << " ";
        cout << FatherName << " ";
        cout << Srmark << endl;
    };

     ~Student()
    {
        if (Name != "")
            Name = "";
        if (Soname != "")
            Soname = "";
        if (FatherName != "")
            FatherName = "";
        if (Marks != "0000")
            Marks = "";
    }
 
};

vector<Student> SortM(vector<Student> v) {
    Student b = Student() ;
         for(int i = 0; i < v.size()-1 ; i++) {
             if( v[i].Srmark > v[i+1].Srmark)
             {
                 b = v[i+1];
                 v[i+1] = v[i];
                 v[i] = b;
             }
         }
    return v;
};

void Output(vector<Student> v) {
    vector<Student> sortV = {};
    sortV = SortM(v);
    cout << endl<< endl;
    cout << "Минимальный средний балл = " << sortV[0].Srmark << endl;
    cout << endl<< endl;
    for(int i = 0; i < v.size() ; i++) {
        sortV[i].Print();
    }
};
void Input () {
    int N; //a s m 4444
    string Name, Soname, FatherName, Marks;
    cout << "Количество студентов = ";
    cin >> N;
    vector<Student> v = {};
    for (int i = 0; i < N ; i++) {
        cout<<"Введите имя, фамилию, отчество и оценки студента: ";
        cin >> Name >> Soname >> FatherName >> Marks;
        v.push_back(Student(Name, Soname, FatherName, Marks));
    }
    Output(v);
};

int main() {
    Input();
    return 0;
}
