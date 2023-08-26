#include "Interpreter.h"

#include <iostream>

void Interpreter::run_code(vector<tuple<string, string>> instructions, vector<int> numbers, vector<string> names)
{

    for (tuple<string, string> each_step : instructions)
    {
        string instruction = get<0>(each_step);
        string argument = get<1>(each_step);

        void *parsed_argument = NULL;

        if (argument != "")
        {
            parsed_argument = parse_argument(instruction, stoi(argument), numbers, names);
        }

        if (instruction == "LOAD_VALUE")
        {
            int number = *((int *)parsed_argument);

            LOAD_VALUE(number);
        }
        else if (instruction == "STORE_NAME")
        {
            string name = *((string *)parsed_argument);
            STORE_NAME(name);
        }
        else if (instruction == "LOAD_NAME")
        {
            string name = *((string *)parsed_argument);
            LOAD_NAME(name);
        }
        else if (instruction == "ADD_TWO_VALUES")
        {
            ADD_TWO_VALUES();
        }
        else if (instruction == "PRINT_ANSWER")
        {
            PRINT_ANSWER();
        }
    }
}

void *Interpreter::parse_argument(string instruction, int argument, vector<int> &numbers, vector<string> &names)
{
    void *parsed_argument;
    if (instruction == "LOAD_VALUE")
    {
        parsed_argument = &numbers[argument];
    }
    else if (instruction == "LOAD_NAME" || instruction == "STORE_NAME")
    {

        parsed_argument = &names[argument];
    }

    return parsed_argument;
}

void Interpreter::LOAD_VALUE(int number)
{
    stack.push(number);
}

void Interpreter::STORE_NAME(string name)
{
    int val = Interpreter::stack.top();
    stack.pop();

    environment[name] = val;
}

void Interpreter::LOAD_NAME(string name)
{
    int val = environment[name];

    stack.push(val);
}

void Interpreter::PRINT_ANSWER()
{
    int answer = stack.top();
    stack.pop();

    cout << answer << endl;
}

void Interpreter::ADD_TWO_VALUES()
{
    int firstNum = stack.top();
    stack.pop();

    int secondNum = stack.top();
    stack.pop();

    // cout << firstNum << endl;
    // cout << secondNum << endl;

    int total = firstNum + secondNum;
    stack.push(total);
}
