#include<stdio.h>
#include<stdlib.h>

// Class for Storing File Pointer
class FilePointer{
        private:
                FILE *data;
        public:
                FilePointer(FILE *p=nullptr)
                {
                    data=p;
                }
                ~FilePointer() { delete data; }
                FILE& GetFilePointer()
                {
                    return *data;
                }
};
