/*WAP to create a SET A and determine the cardinality of SET for an input array of elements (repetititon allowed)
 and perform the following operations on the SET
 i. isMember(a,A): check whether an element belongs to set or not and return value as a true/false
 ii. powerset(A) : list all the elements of power set of  A
*/
#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <algorithm>
class Set
{
public:
    vector<int> setArr;
    void getElements();
    void disp();
    friend bool ismember(int a, Set A);
    void powerset();
};

// using bit masking
void Set::powerset()
{
    unsigned int subCnt = pow(2, setArr.size());
    vector<vector<int>> powerSet;

    for (int counter = 0; counter < subCnt; counter++)
    {
        vector<int> subSet;
        for (int j = 0; j < setArr.size(); j++)
        {
            if (counter & (1 << j)) // checking if the jth bit is set or not
                subSet.push_back(setArr[j]);
        }
        powerSet.push_back(subSet);
    }

    for (int i = 0; i < powerSet.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < powerSet[i].size(); j++)
        {
            cout << powerSet[i][j] << ",";
        }
        cout << "}"
             << "  ";
    }
}

bool ismember(int a, Set A)
{

    for (int i = 0; i < A.setArr.size(); i++)
    {
        if (a == A.setArr.at(i))
            return true;
    }
    return false;
}

void Set::getElements()
{
    cout << "Please enter the elements in the set.\n Repetititon is allowed." << endl;
    cout << "Press y to exit." << endl;
    int ele = 0;
    char ans;
    bool run = true;
    do
    {
        cout << "Enter the element :";
        cin >> ele;
        setArr.push_back(ele);
        cout << "Do you wish to exit? y/n" << endl;
        cin >> ans;
        if (ans == 'y')
            run = false;

    } while (run != false);
}

void Set::disp()
{
    cout << "Elements of the set are :";
    cout << "{ ";
    for (int i = 0; i < setArr.size(); i++)
        cout << setArr[i] << " ";
    cout << " }" << endl;
}

int main()
{
    Set A;
    A.getElements();
    A.disp();
    cout << "\nCardinality of the set = " << A.setArr.size() << endl;
    A.powerset();
    int ele;
    bool res;
    cout << "\nEnter the element that is to be checked :";
    cin >> ele;
    res = ismember(ele, A);
    cout << ele << " is a memeber of the set." << endl;
    return 0;
}