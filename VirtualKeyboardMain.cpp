#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Terminal.h"
#include "VirtualKeyboard.h"
#include "SessionManager.h"
using namespace std;
//Execution starts from here
int main (void ) {

        FILE *fp = stdin; // File pointer
        // Smart Pointer
        FilePointer file_object= FilePointer(fp);
        Terminal terminal_object; // object of class terminal
        VirtualKeyBoard virtual_keyboard_object; // object of class VirtualKeyboard
        SessionManager session_object; // object of class session manager

                        // Start the session for user
                        session_object.StartSession();
                                // Infinite loop that will only stop when user presses CTRL+q
                        cout<<"$Virtual Keyboard session start"<<endl;
                                while(1)
                                {
                                        // Check if we are able to get the terminal parameters
                                        if(terminal_object.GetTerminalParameters(&(file_object.GetFilePointer()))==1)
                                        {
                                                // Turn of echoing on screen
                                                terminal_object.TrunOffEchoOnScreen();
                                                // Check if we are able to set terminal parameters
                                                if(terminal_object.SetNewTerminalParameters(&(file_object.GetFilePointer()))==1)
                                                {
                                                        virtual_keyboard_object.TakeInput();
                                                        terminal_object.ResetTerminalParameters(&(file_object.GetFilePointer()));
                                                        virtual_keyboard_object.PrintOutput();
                                                }
                                                else
                                                {
                                                        cout<<"Sorry Virtual Keyboard cannot be started on your PC";
                                                        break;
                                                }

                                        }
                                        else
                                        {
                                                cout<<"Sorry Virtual Keyboard cannot be started on your PC";
                                                break;
                                        }

                                }
                        // End the session for user
                        session_object.EndSession();

        return 0;
}
