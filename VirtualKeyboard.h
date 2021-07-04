#include<vector>
#include <stdlib.h>
#include<iostream>
using namespace std;
class VirtualKeyBoard
{
        private:
                char input_character; // variable to get the character entered by user
                vector<char> complete_string; // vector to store complete string given by user
        public:
                // This function take input from user
                void TakeInput()
                {
                        while((input_character=getchar())!='\n')
                        {
                                complete_string.push_back(input_character);
                        }
                }
                // This function prints the output on screen
                void PrintOutput()
                {
                        for(int i=0; i < complete_string.size(); i++)
                        {
                                cout << complete_string.at(i);
                        }
                        complete_string.clear();
                        cout<<endl;
                }
};
                  