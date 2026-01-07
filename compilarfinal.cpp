#include <iostream>
#include <string>
using namespace std;

enum State {
    q0, q1, q2, q3, q4, q5, DEAD
};

State transition(State s, char c) {
    switch (s) {
    case q0:
        if (c == 'b') return q1;
        return DEAD;

    case q1:
        if (c == 'a') return q0;
        return DEAD;

    case q2:
        if (c == 'b') return q2;
        if (c == 'a') return q3;
        return DEAD;

    case q3: // accepting
        if (c == 'a') return q3;
        if (c == 'b') return q4;
        return DEAD;

    case q4:
        if (c == 'a') return q5;
        return DEAD;

    case q5:
        if (c == 'a' || c == 'b') return q3;
        return DEAD;

    default:
        return DEAD;
    }
}

bool accepts(const string& input) {
    State state = q0;

    // handle (ba)* first
    int i = 0;
    while (i + 1 < input.size() && input[i] == 'b' && input[i + 1] == 'a') {
        i += 2;
    }

    // then b*
    while (i < input.size() && input[i] == 'b') {
        i++;
    }

    if (i >= input.size() || input[i] != 'a')
        return false;

    state = q3;
    i++;

    for (; i < input.size(); i++) {
        state = transition(state, input[i]);
        if (state == DEAD)
            return false;
    }

    return state == q3;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if (accepts(s))
        cout << "Accepted\n";
    else
        cout << "Rejected\n";

    return 0;
}
