#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include <iomanip>
#include <limits>

class money
{
private:
    int fullcopecs;


public:
    std::string toString() const;
    money() { fullcopecs = 0; }
    money(unsigned int a) { fullcopecs = a; }
    money(unsigned int r, unsigned int c) { fullcopecs = r * 100 + c; }
    friend std::istream& operator >>(std::istream& in, money& A); 
    friend std::ostream& operator <<(std::ostream& out, money A);  
    friend money operator+(money A, money B);   
    friend money operator-(money A, money B);   
    friend int operator/(money A, money B); 
    friend money operator/(money A, int B); 
    //std::string operator!();  

};


//Вводим данные
std::istream& operator>>(std::istream& in, money& A) {
    unsigned int roubles, copecks;
    in >> roubles >> copecks;
    A.fullcopecs = roubles * 100 + copecks;
    return in;
}
//Выводим
std::ostream& operator<<(std::ostream& out, money A)
{
    unsigned int roubles, copecks;
    roubles = A.fullcopecs / 100;
    copecks = A.fullcopecs % 100;
    out << "Рублей: " << roubles << "; Копеек: " << copecks << std::endl;
    return out;

}
//Складываем
money operator+(money B, money A)
{
    money temp;
    temp.fullcopecs = A.fullcopecs + B.fullcopecs;
    return temp;
}

//Вычитаем
money operator-(money A, money B)
{
    money temp;
    temp.fullcopecs = A.fullcopecs - B.fullcopecs;
    return temp;
}



std::string money::toString() const
{
    std::ostringstream oss;
    unsigned int roubles, copecks;
    roubles = fullcopecs / 100;
    copecks = fullcopecs % 100;
    oss << "Рублей: " << roubles << "; Копеек: " << copecks << std::endl;
    return oss.str();
}



//Делим
int operator/(money A, money B)
{
    unsigned int temp = 0;
    if (B.fullcopecs != 0) temp = A.fullcopecs / B.fullcopecs;
    return temp;
}

money operator/(money A, int B)
{
    money temp;
    if (B != 0) temp.fullcopecs = A.fullcopecs / B;
    return temp;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    money A, B;

    std::cout << "\nВвести первую сумму в формате 'руб','коп':\t";
    std::cin >> A;
    std::cout << "Ввести вторую сумму в формате 'руб','коп':\t";
    std::cin >> B;
    std::cout << "Сумма:\t\t" << (A + B) << std::endl;
    std::cout << "Разность:\t\t" << (A - B) << std::endl;
    std::cout << "Деление на:\t\t" << (A / B) << " части" << std::endl;
    std::cout << "Деление на 4 части:\t\t" << (A / 4) << " части" << std::endl;
    std::cout << " to str: " << A.toString() << std::endl;
    system("pause");
    return 0;
}