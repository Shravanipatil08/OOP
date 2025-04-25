#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//creating encryptor class
class FileEncryptor
{
    private:
        string filename;
        int encryptionKey;
        
    public:
        FileEncryptor(string fname, int key):filename(fname), encryptionKey(key){}; //init file name and key
        //encryption 
        void encryptAndWrite(string str) 
        {
            ofstream file(filename);
            string msg=str;
            for(char &ch:msg) 
            {
                if(isalpha(ch)) 
                { 
                    //base char for ascii value
                    char start=isupper(ch)? 'A' : 'a';
                    //caeser cihper 
                    ch = (ch - start + encryptionKey) % 26 + start; 
                }
            }
            if(file.is_open())
            {
                file << msg;
                file.close();
                cout << "Data encrypted and written in file. " << endl;
            }
            else
            { 
                cout << "File not open. " << endl;
            }
        }
        
        //decrypting         
        string readAndDecrypt() 
        {
            ifstream file (filename);
            string encrypted_msg;
            if(file.is_open()) 
            {
                getline(file,encrypted_msg);
            }
            file.close();
            string msg=encrypted_msg;
            for(char &ch: msg) 
            {
               if(isalpha(ch)) 
               {
                   char start=isupper(ch)? 'A' : 'a';
                   ch = (ch - start - encryptionKey + 26) % 26 + start; 
               }
            }
            return msg;
        }
        
        void displayFileContents() 
        {
             cout << "Decrypted Message=" << readAndDecrypt() << endl;
        }
};

//main class
int main() 
{
    //creating object
    FileEncryptor f("secret.txt", 3);
    string message;
    cout << "Enter message to encrypt:";
    getline(cin,message);
    f.encryptAndWrite(message);
    cout << "\nReading and decrypting file...." << endl;
    f.displayFileContents();
    return 0;
}
