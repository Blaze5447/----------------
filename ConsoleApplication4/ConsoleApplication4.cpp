/*  Жуков Валерий */
/*  Форма регистрации пользователя */

#include<iostream>
#include<fstream>
using namespace std;

struct mail
{
    char un[50];
    char pd[50];
    void reg(int);
} obj[5];

void mail::reg(int k)
{
    int i = k;
    cout << "\nВведите имя пользователя :: ";
    cin >> un;
    cout << "\nВведите пароль :: ";
    cin >> pd;

    ofstream filout;
    filout.open("C:\\Desktop\\registration.txt", ios::app | ios::binary);
    if (!filout)
    {
    
    }
    else
    {
        cout << "\n";
        filout.write((char*)&obj[i], sizeof(mail));
        filout.close();
    }

    cout << "\n...........Вы зарегистрированны.......... \n\n";

}

int main()
{
    setlocale(LC_ALL, "ru");
    int t;
    cout << "\nВведите регистрационные данные для пользователя 1 :: \n";
    obj[0].reg(0);
    cout << "\nВведите регистрационные данные для пользователя 2 :: \n";
    obj[1].reg(1);
    cout << "\nВведите регистрационные данные для пользователя 3 :: \n";
    obj[2].reg(2);

    mail obj2;

    ifstream filein;
    filein.open("C:\\Desktop\\registration.txt", ios::in | ios::binary);
    if (!filein)
    {
        cout << "\nНевозможно открыть файл\n";
    }
    else
    {
        cout << "\nРегистрационные данные пользователей :: \n";
        filein.read((char*)&obj2, sizeof(obj2));
        while (filein)
        {
            cout << "\nИмя :: " << obj2.un << "\nПароль :: " << obj2.pd << "\n";
            filein.read((char*)&obj2, sizeof(obj2));
        }

    }
    return 0;
}
