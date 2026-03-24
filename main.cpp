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

//basic suggestion gen 
string generateSuggestion(string password)
{
    string suggestion=password;

    if(suggestion.length()<8) suggestion+="123!";

    bool hasUpper=false, hasDigit=false, hasSpecial=false;

    for(char c:suggestion)
    {
        if(isupper(c)) hasUpper=true;
        if(isdigit(c)) hasDigit=true;
        if(ispunct(c)) hasSpecial=true;
    }

    if(!hasUpper) suggestion[0]=toupper(suggestion[0]);
    if(!hasDigit) suggestion+="9";
    if(!hasSpecial) suggestion+="!";

    return suggestion;
}

//crack time estimate
string crackTime(int score)
{
    if(score<=2) return "instantly (very weak)";
    else if(score==3) return "a few minutes";
    else if(score==4) return "a few hours";
    else return "years (strong)";
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

    for(char c:password) 
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

    //feedback
    cout<<"\nissues:\n";

    if(password.length()<8) cout<<"-> too short (min 8 characters)\n";
    if(!hasUpper) cout<<"-> missing uppercase letter\n";
    if(!hasLower) cout<<"-> missing lowercase letter\n";
    if(!hasDigit) cout<<"-> missing number\n";
    if(!hasSpecial) cout<<"-> missing special character\n";

    if(score==5) cout<<"- no major issues detected\n";

    //common password warning
    if(isCommonPassword(password)) 
    {
        cout<<"⚠ warning: this is a common password!!!!!!!\n";
    }

    //suggestion
    cout<<"\nsuggested password:\n";
    cout<<generateSuggestion(password)<<endl;

    //crack time
    cout<<"\nestimated crack time: ";
    cout<<crackTime(score)<<endl;

    return 0;
}
