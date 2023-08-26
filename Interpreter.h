#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <stack>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

class Interpreter {
    public:
        stack<int> stack;
        unordered_map<string, int> environment;

        void run_code(vector<tuple<string, string>> instructions, vector<int> numbers, vector<string> names);

        void *parse_argument(string instruction, int argument, vector<int> &numbers, vector<string> &names);

    private:
        void LOAD_VALUE(int number);
        void STORE_NAME(string name);
        void LOAD_NAME(string name);
        void PRINT_ANSWER();
        void ADD_TWO_VALUES();

};

#endif