#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isCommonPassword(string password) 
{
    ifstream file("common.txt");
    string line;

    while(getline(file,line)) 
    {
        if(line==password) 
        {
            return true;
        }
    }
    return false;
}

int main() 
{
    string password;
    cout<<"enter password: ";
    cin>>password;

    bool hasUpper=false;
    bool hasLower=false;
    bool hasDigit=false;
    bool hasSpecial=false;

    for (char c:password) 
    {
        if(isupper(c)) hasUpper=true;
        else if(islower(c)) hasLower=true;
        else if(isdigit(c)) hasDigit=true;
        else hasSpecial=true;
    }

    int score=0;

    if(password.length()>=8) score++;
    if(hasUpper) score++;
    if(hasLower) score++;
    if(hasDigit) score++;
    if(hasSpecial) score++;

    cout<<"\npassword analysis:\n";

    if(score<=2) cout<<"strength: weak >:(\n";
    else if(score<=4) cout<<"strength: medium :|\n";
    else cout<<"strength: strong :)\n";

    if(isCommonPassword(password)) 
    {
        cout<<"⚠ warning: this is a common password!!!!!!!\n";
    }

    return 0;
}