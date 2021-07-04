#include <stdlib.h>
class SessionManager
{
        public:
        // This function will start the session for user
        void StartSession()
        {
                system("sh start_session_change_stty.sh");
        }
        // This function will end the session for user
        void EndSession()
        {
                system("sh end_session_change_stty.sh");
        }
};
