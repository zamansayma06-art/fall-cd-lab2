#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int state = 0;

    for(int i=0; i<s.size(); i++){

        if(state == 0)
            {

            if(s[i] == 'b')
                state = 1;

                else if (s[i]== 'a')
                    state =2;


            else{
                cout << "Rejected";

    return 0;
            }
        }

        else if(state == 1)
            {

            if(s[i] == 'a')
                state = 0;

            else{
                cout << "Rejected";
            return 0;
            }
        }

        else if(state == 2)
            {

            if(s[i] == 'a')
                state = 2;

            else if(s[i] == 'b')
                state = 4;

            else{
                cout << "Rejected";


                return 0;
            }
        }

        else if(state == 3)
            {

            if(s[i] == 'a')
                state = 2;

            else if(s[i] == 'b')
                state = 2;

            else{
                cout << "Rejected";

            return 0;
            }
        }

       if(state == 4)

         {

            if(s[i] == 'a')
                state = 3;



            else{
                cout << "Rejected";

            return 0;
            }
        }
    }
    return 0;
}
