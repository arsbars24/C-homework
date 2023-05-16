#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
using namespace std;
#define MAXN 100+10                     // n, m, k max 
#define MAXEXPRELEN 250+10

struct Point {                           // point 
    int x;
    int y;
    int dir;                            // Mark the direction of the current point
};
Point fork_point[MAXN];                 // Founding point 
Point cur_poi;                          // Current point 

struct Invert {                          // Define the conversion point
    int a;
    int b;
    char c[5];
};
Invert inv[MAXN];                       // Conversion point                        
char sent[MAXEXPRELEN];                 // expression 
int reg_arr[26 + 5];                      // Register array 
int N,                                  //field
M,                                  //fork 
K;                                  //register-invert-point

int get_val(const char* formu);         // Calculate the value of the expression
int get_pri(string str);                // Get priority 
bool is_fork();                         // Judgment whether the current point is bifurcated 
void next_posi(int res, Point& poi);    // Calculate the next location according to the current point
bool is_out(Point poi);                 // Check if the new point is out of bound
bool is_invert(int& reg);               // Check if the current point is converted, if it is available register number
int main()
{
    memset(reg_arr, 0, sizeof(reg_arr));
    cin.getline(sent, 260);
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
        cin >> fork_point[i].x >> fork_point[i].y;
        
    for (int j = 0; j < K; j++)
        cin >> inv[j].a >> inv[j].b >> inv[j].c;
        
    cur_poi.x = 1;
    cur_poi.y = 0;
    cur_poi.dir = 1;                        // (0, 0) -> (1, 0): Right
    cout << 0 << ' ' << 0 << '\n';
    cout << 1 << ' ' << 0 << '\n';
    Point new_poi;
    int inv_reg;                            // Convert register number 
    for (;;) {
        int res = -1;                       // Directly from the default 
        if (is_fork())                       // If standing on the fork point 
            res = get_val(sent);            //about? 

        if (is_invert(inv_reg))              // If standing in the conversion point 
            reg_arr[inv_reg] = 1 - reg_arr[inv_reg];

        next_posi(res, new_poi);            // Calculate the next point
            bool ch = is_out(new_poi);          // Check if the new point is out of bound
            if (!ch) {
                cout << new_poi.x << ' ' << new_poi.y << '\n';
                cur_poi.x = new_poi.x;
                cur_poi.y = new_poi.y;
                cur_poi.dir = new_poi.dir;
            }
            else
                break;
    }

    return 0;
}

int get_val(const char* formu)
{
    string expre = formu;
    expre += "#";
    int len = expre.length();
    stack<string> sym;
    stack<string> oper;
    string str = "";              // Temporary string 
    string top_str = "";          // Top operator
        string top_oper = "";         // Stack top operation 
    int str_len = 0;
    sym.push("#");
    for (int i = 0; i < len; i++) {
        str += expre[i];
        str_len++;
        if (str == " ") {                             // If it is a space 
            str = "";
            str_len = 0;
            continue;
        }
        if (isalpha(str[0])) {
            int j;
            for (j = i + 1; j < len; j++)
                if (isalpha(expre[j])) {
                    str += expre[j];
                    str_len++;
                }
                else
                    break;
            i = j - 1;                                // Other characters, i moved to the last valid character 
        }

        if (str == "TRUE" || str == "FALSE" ||
            (isalpha(str[0]) && str_len == 1))      // Register or true value 
            oper.push(str);
        else {                                       // Operator or parentheses 
            if (get_pri(str) > get_pri(sym.top()) ||
                (sym.top() == "(" && str != ")") || str == "NOT")//> Top priority or stack top is the left bracket or "not" (Not is the right binding) 
                sym.push(str);
            else if (sym.top() == "(" && str == ")")
                sym.pop();
            else {                                   // <Stack top priority or right bracket or "#" 
                while (sym.top() != "#" && get_pri(str) <= get_pri(sym.top()) && sym.top() != "(") {
                    bool res = 0;                   // Temporary results
                    string res_str = "";            // Temporary result of string form (True, False) 
                    top_str = sym.top();            // Pop out of the top operator 
                    sym.pop();
                    top_oper = oper.top();          // Pop up the first operand 
                    oper.pop();
                    if (top_str == "NOT") {           // single operating number (only NOT) 
                        if (top_oper == "TRUE")
                            res = 0;
                        else if (top_oper == "FALSE")
                            res = 1;
                        else
                            res = 1 - reg_arr[top_oper[0] - 'A'];
                    }
                    else {                           // Double operand 
                        string sec_oper = oper.top();       // Second operand 
                        oper.pop();
                        if (top_str == "AND") {               //AND
                            if (top_oper == "TRUE") {
                                if (sec_oper == "TRUE")
                                    res = 1;
                                else if (sec_oper == "FALSE")
                                    res = 0;
                                else
                                    res = reg_arr[sec_oper[0] - 'A'];
                            }
                            else if (top_oper == "FALSE")
                                res = 0;
                            else {                           // The first operand is the register 
                                if (!reg_arr[top_oper[0] - 'A'])
                                    res = 0;
                                else {
                                    if (sec_oper == "TRUE")
                                        res = 1;
                                    else if (sec_oper == "FALSE")
                                        res = 0;
                                    else
                                        res = reg_arr[sec_oper[0] - 'A'];
                                }
                            }
                        }
                        else {                               //OR
                            if (top_oper == "TRUE")
                                res = 1;
                            else if (top_oper == "FALSE") {
                                if (sec_oper == "TRUE")
                                    res = 1;
                                else if (sec_oper == "FALSE")
                                    res = 0;
                                else
                                    res = reg_arr[sec_oper[0] - 'A'];
                            }
                            else {                           // The first operand is the register 
                                if (reg_arr[top_oper[0] - 'A'])
                                    res = 1;
                                else {                       // The first operand is 0 
                                    if (sec_oper == "TRUE")
                                        res = 1;
                                    else if (sec_oper == "FALSE")
                                        res = 0;
                                    else
                                        res = reg_arr[sec_oper[0] - 'A'];
                                }
                            }
                        }
                    }

                    if (res == 1)
                        res_str = "TRUE";           // Computing result Convert to a string stack 
                    else
                        res_str = "FALSE";
                    oper.push(res_str);
                    if (str == ")" && sym.top() == "(") {
                        // Encounter a left bracket to exit cycle
                            sym.pop();
                        break;
                    }
                }

                if (str != ")")
                    sym.push(str);                  // STR into the stack 
            }
        }
        str = "";
        str_len = 0;
    }
    if (!oper.empty()) {
        string lst = oper.top();
        if (lst == "TRUE")
            return 1;
        else if (lst == "FALSE")
            return 0;
        else
            return reg_arr[lst[0] - 'A'];
    }
    else {
        cout << "oper stack is empty!";
        return false;
    }
}

int get_pri(string str)
{
    const int num = 6;
    string prim[num] = { "#", ")", "OR", "AND", "NOT", "(" };
    for (int i = 0; i < num; i++)
        if (prim[i] == str)
            return i;

    return -1;
}

bool is_fork()                  // Judgment whether the current point is bifurcated 
{
    for (int i = 0; i < M; i++)
        if (cur_poi.x == fork_point[i].x && cur_poi.y == fork_point[i].y)
            return true;

    return false;
}

void next_posi(int res, Point & poi)         // Calculate the next location
{
    int dir = cur_poi.dir;                  // To the direction of the current point
    if (res == 1) {                           // Right turn 
        if (dir == 0) {                       // Country left 
            poi.x = cur_poi.x;
            poi.y = cur_poi.y + 1;
            poi.dir = 2;
        }
        else if (dir == 1) {                  // Original right 
            poi.x = cur_poi.x;
            poi.y = cur_poi.y - 1;
            poi.dir = 3;
        }
        else if (dir == 2) {                  // 
            poi.x = cur_poi.x + 1;
            poi.y = cur_poi.y;
            poi.dir = 1;
        }
        else {                               // 
            poi.x = cur_poi.x - 1;
            poi.y = cur_poi.y;
            poi.dir = 0;
        }
    }
    else if (res == 0) {                      // turn left 
        if (dir == 0) {
            poi.x = cur_poi.x;
            poi.y = cur_poi.y - 1;
            poi.dir = 3;
        }
        else if (dir == 1) {
            poi.x = cur_poi.x;
            poi.y = cur_poi.y + 1;
            poi.dir = 2;
        }
        else if (dir == 2) {
            poi.x = cur_poi.x - 1;
            poi.y = cur_poi.y;
            poi.dir = 0;
        }
        else {
            poi.x = cur_poi.x + 1;
            poi.y = cur_poi.y;
            poi.dir = 1;
        }
    }
    else {                                   // go straight 
        if (dir == 0) {
            poi.x = cur_poi.x - 1;
            poi.y = cur_poi.y;
        }
        else if (dir == 1) {
            poi.x = cur_poi.x + 1;
            poi.y = cur_poi.y;
        }
        else if (dir == 2) {
            poi.x = cur_poi.x;
            poi.y = cur_poi.y + 1;
        }
        else {
            poi.x = cur_poi.x;
            poi.y = cur_poi.y - 1;
        }
        poi.dir = dir;
    }
}

bool is_out(Point poi)                  // Check if (x, y) is out of bound 
{
    if (poi.x<-N || poi.x>N || poi.y<-N || poi.y>N)
        return true;
    else
        return false;
}

bool is_invert(int& reg)                // Check if the current point is converted, if yes, reference to the back register number
{
    for (int i = 0; i < K; i++)
        if (cur_poi.x == inv[i].a && cur_poi.y == inv[i].b) {
            reg = inv[i].c[0] - 'A';
            return true;
        }

    return false;
}