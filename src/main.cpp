#include <iostream>
#include "Color.h"

#include "Matrix.h"
#include "Terminal.h"

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

#include <thread>

using namespace std;

char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

int main() {
    
    for (;;) {
        char c = getch();
    
        cout << c << endl;
    }
    
    return 0;
}
