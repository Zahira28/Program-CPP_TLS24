#include <iostream>
#include <ctime>
using namespace std;
int calculateAge(int birthyear, int birthmonth, int birthday){
    time_t now = time(nullptr);
    tm* timenow = localtime(&now);
    int currentyear = timenow->tm_year + 1900;
    int currentmonth = timenow->tm_mon + 1;
    int currentday = timenow->tm_mday;
    int age = currentyear - birthyear;
    if(currentmonth < birthmonth || (currentmonth == birthmonth && currentday < birthday)){
        age--;
    }
    return age;
}

int main(){
    string name;
    char gender;
    int birthyear, birthmonth, birthday;
    int age = calculateAge(birthyear, birthmonth, birthday);
    time_t now = time(nullptr);
    tm* timenow = localtime(&now);
    int currentHour = timenow->tm_hour;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your gender [M/F]: ";
    cin >> gender;
    cout << "Enter your birth day (DD): ";
    cin >> birthday;
    cout << "Enter your birth month (MM): ";
    cin >> birthmonth;
    cout << "Enter your birth year (YYYY): ";
    cin >> birthyear;
    if(currentHour >= 5 && currentHour < 10){
        cout<< "Good morning!"<< endl;
    } else if(currentHour >= 10 && currentHour <= 17){
        cout<< "Good afternoon!"<< endl;
    } else if(currentHour >= 18 && currentHour <= 24) {
        cout<< "Good evening!"<< endl;
    }
    if(age <= 0 && age >=100){
        cout<< "Invalid";
    }else if(age <= 17){
        cout<< "Welcome, " << name <<". How can I help you today?";
    } else if(age >=18 && age < 25 && (gender == 'F' || gender == 'f')){
        cout<< "Welcome, Ms. " << name <<". How can I help you today?";
    } else if(age >= 25 && (gender == 'F' || gender == 'f')){
        cout<< "Welcome, Mrs. " << name <<". How can I help you today?";
    }else if(age >=18 && age < 25 && (gender == 'M' || gender == 'm')){
        cout<< "Welcome, " << name <<". How can I help you today?";
    }else if(age >= 25 && (gender == 'M' || gender == 'm'))
        cout<< "Welcome, Mr. " << name <<". How can I help you today?";
    return 0;
}