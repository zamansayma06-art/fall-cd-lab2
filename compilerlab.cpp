#include <iostream>
using namespace std;


bool matchRE1(string s){
    for(char c : s){
        if(c != 'a') return false;
    }
    return true;
}

bool matchRE2(string s){
    return (s == "a" || s == "b");
}


bool matchRE3(string s){
    return (s == "ab");
}


bool matchRE4(string s){
    int n = s.size();
    if(n < 3) return false;

    // 1st char = a or b
    if(s[0] != 'a' && s[0] != 'b') return false;

    // 2nd char = b
    if(s[1] != 'b') return false;

    // 3rd char = a or b
    if(s[2] != 'a' && s[2] != 'b') return false;

    // remaining characters: only b*
    for(int i = 3; i < n; i++){
        if(s[i] != 'b') return false;
    }
    return true;
}


bool matchRE5(string s){
    int n = s.size();
    if(n < 2) return false;
    int i = 0;


    while(i < n && (s[i]=='a' || s[i]=='b')){
        i++;
    }


    if(i >= n || s[i] != 'a') return false;
    i++;


    while(i < n){
        if(s[i] != 'b') return false;
        i++;
    }
    return true;
}

int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "RE1 (a*): " << (matchRE1(s)? "valid"   : "invalid") << endl;
    cout << "RE2 (a+b): " << (matchRE2(s)? "valid"   : "invalid")  << endl;
    cout << "RE3 (a.b): " << (matchRE3(s)? "valid"   : "invalid")  << endl;
    cout << "RE4 ((a+b).b(a+b).b*): " << (matchRE4(s)? "valid"   : "invalid")  << endl;
    cout << "RE5 ((a+b)^+ a b*): " << (matchRE5(s)? "valid"   : "valid")  << endl;

    return 0;
}
