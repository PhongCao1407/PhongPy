#include "SimpleCompiler.cpp"

int main() {

    vector<tuple<string, string> > instructions = 
    {make_tuple("LOAD_VALUE", "0"),
    make_tuple("STORE_NAME", "0"),
    make_tuple("LOAD_VALUE", "1"),
    make_tuple("STORE_NAME", "1"),
    make_tuple("LOAD_NAME", "0"),
    make_tuple("LOAD_NAME", "1"),
    make_tuple("ADD_TWO_VALUES", ""),
    make_tuple("PRINT_ANSWER", "")
    }; 

    vector<int> numbers = {1, 100};

    vector<string> names = {"a", "b"};

    Interpreter interpreter;
    interpreter.run_code(instructions, numbers, names);

}