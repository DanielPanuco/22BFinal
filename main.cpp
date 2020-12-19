#include <iostream>
#include "BoolVariable.h"
#include "VarNameException.h"
#include "IntVariable.h"
#include <vector>
#include <sstream>
using namespace std;

vector<BoolVariable *> containsIgnoreCase(vector<BoolVariable *> list, const string& search, int &count);
BoolVariable* createVariable();
void testQuestionFour();
void testClasses();
void testException();



BoolVariable* createVariable()
{
    BoolVariable* temp; // need to initialize this outside of the try-catch block so that we can access the object after the block
    string variable;
    string name;

    bool check = false;
    while(!check){
        cout << "Enter variable name: ";
        cin.clear(); // need to clear before getLine
        getline(cin, name); // need getline so that (name) can be an empty string, which gets thrown in the constructor
        cout << "Enter variable value: ";
        cin.clear(); // need to clear before getline
        getline(cin, variable);
        try {
            if (variable == "true" || variable == "false") {
                bool bVariable;
                istringstream(variable) >> boolalpha >> bVariable; // converting variable string into boolean

                temp = new BoolVariable(name, bVariable);

                check = true;
            }
            else if (isdigit(variable[0])) {
                int iTemp;

                stringstream ss;
                ss << variable;
                ss >> iTemp;

                temp = new IntVariable(name, iTemp);
                check = true;
            }
        }
        catch (VarNameException &errObj) { // throwing exception and catching by reference rather than throwing "new" exception and catching by pointer
            cout << endl;
            cout << "Error: " << errObj.what() << endl;
            cout << "Invalid Name: " << errObj.getBadName() << endl;
            cout << endl;
        }
    }
    return temp;
}

vector<BoolVariable *> containsIgnoreCase(vector<BoolVariable *> list, const string& search, int &count)
//search is a const reference so that no new variable is created when the function is called (more efficient). This works since search isn't altered in the function.
{
    for(int i = 0; i < list.size();) // don't need i to go up one value if something is removed
    {
        if(!list[i]->containsIgnoreCase(search)) {
            list.erase(list.begin() + i);
        }
        else if(search == list[i]->getName()) // we need this to get count of EXACT string matches, whereas the previous if statement was for substring search
        {
            count++;
            i++;
        }
        else // if nothing is erased then it is moved to the next element
            i++;
    }
    return list;
}

void testQuestionFour()
{
    vector<BoolVariable*> temp;
    temp.push_back(new BoolVariable("Same one", true)); // both BoolVariable and IntVariable work because the vector is points of BookVariable
    temp.push_back(new BoolVariable("saMe", false));
    temp.push_back(new BoolVariable("same", false));
    temp.push_back(new IntVariable("same", 5));
    temp.push_back(new IntVariable("Different", 6));
    temp.push_back(new BoolVariable("Also Different", true));
    int matchCount;
    temp = containsIgnoreCase(temp, "same", matchCount);

    cout << "Searching for string 'same': \n";

    for (auto &i: temp) {
        cout << '\t' << i->toString() << endl;
    }
    cout << "Count of exact string matches: " << matchCount << endl;
}

void testClasses()
{
    BoolVariable test("test", true);
    cout << test.toString() << endl;
    cout << "Does " << test.toString() << " contain 'Test'?: " << boolalpha << test.containsIgnoreCase("Test") << endl;

    IntVariable count("count", 8);
    IntVariable speed("speed", 4);
    cout << "Does " << speed.toString() << " contain 'speed'?: " << boolalpha << speed.containsIgnoreCase("speed") << endl;
    cout << "Does " << count.toString() << " contain 'speed'?: " << boolalpha << count.containsIgnoreCase("speed") << endl;
    cout << "Is " << count.toString() << " greater than " << speed.toString() << "?: "<< boolalpha << count.isGreater(speed) << endl;
    cout << "Is " << speed.toString() << " greater than " << count.toString() << "?: "<< boolalpha << speed.isGreater(count) << endl;

}
void testException()
{
    BoolVariable* temp = createVariable();
    cout << temp->toString(); // test that the object pointer was returned properly from function
}
int main()
{
    cout << "_____________________________\n";
    cout << "Testing classes \n";

    testClasses();

    cout << "\n_____________________________\n";

    cout << "Test question four function:  \n";

    testQuestionFour();

    cout << "\n_____________________________\n";
    cout << "Test question five function:  \n";

    testException();

    cout << "\n_____________________________\n";

    return 0;
}
