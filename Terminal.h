#include <stdio.h>
#include <termios.h>

// This class handles all the functionality related to Termainal
class Terminal
{

        private:
                struct termios old_settings; // for getting current terminal Settings
                struct termios new_settings; // for storing new terminal settings

        public:
                // The tcgetattr() function shall get the parameters associated with the terminal referred to by fildes and store them in the termios structure referenced
                int GetTerminalParameters(FILE *stream)
                {
                        if (tcgetattr (fileno (stream), &old_settings) != 0)
                        {
                                return -1;
                        }
                        else
                        {
                                new_settings=old_settings;
                                return 1;
                        }
                }
                // Function to Turn of the echo on screen
                void TrunOffEchoOnScreen()
                {
                        new_settings.c_lflag &= ~ECHO;
                }

                // Set new terminal settings after turning of the echo on screen
                int SetNewTerminalParameters(FILE *stream)
                {
                        // tcsetattr() function shall set the parameters associated with the terminal 
                        if (tcsetattr (fileno (stream), TCSAFLUSH, &new_settings) != 0)
                        {
                             return -1;
                        }
                        else
                        {
                                return 1;
                        }
                }

                // Restore Terminal
                void ResetTerminalParameters(FILE *stream)
                {
                        // tcsetattr() function shall set the parameters associated with the terminal 
                        tcsetattr (fileno (stream), TCSAFLUSH, &old_settings);

                }

};