#include <iostream>
#include <string.h>
using namespace std;
// Creating book class
class Book
{
    // declaring data members.
    private:
        char *title;
        char *author;
        int pageCount;
        bool formate;
        float *chapterPages;
        int chapters;
    
    public:
        // Default constructor.
        Book()
        {
            title=new char[1];
            title[0]='\0';
            author=new char[1];
            author[0]='\0';
            pageCount=0;
            formate=false;
            chapterPages=nullptr;
            chapters=0;
        }

        // Parameterized constructor.
        Book(const char* t,const char* a,int count,bool type,int chapter)
        {
            title=new char[strlen(t)+1];
            strcpy(title,t);
            author=new char[strlen(a)+1];
            strcpy(author,a);
            pageCount=count;
            formate=type;
            chapterPages=new float[chapter];
            for(int i=0;i<chapter;i++)
            {
                chapterPages[i]= float (pageCount)/chapter;
            }
            chapters=chapter;
        }

        // Copy constructor.
        Book(const Book& obj)
        {
            // Shallow Constructor.
            // title=obj.title;
            // author=obj.author;
            // pageCount=obj.pageCount;
            // formate=obj.formate;
            // chapterPages=obj.chapterPages;
            // chapters=obj.chapters;

            // Deep constructor.
            title=new char[strlen(obj.title)+1];
            strcpy(title,obj.title);
            author=new char[strlen(obj.author)+1];
            strcpy(author,obj.author);
            pageCount=obj.pageCount;
            formate=obj.formate;
            chapters=obj.chapters;
            chapterPages=new float[chapters];
            for(int i=0;i<chapters;i++)
            {
                chapterPages[i]=obj.chapterPages[i];
            }
        }

        // Utility Method to modify page count.
        void modifyPageCount(int chapter_no,int pages)
        {
            if(chapter_no<chapters && chapter_no>=0)
            {
                chapterPages[chapter_no]=pages;
            }
            else
            {
                cout<<"Chapter not available."<<endl;
            }
        }

        void display()
        {
            cout<<"       Book Information         "<<endl;
            cout<<"--------------------------------"<<endl;
            cout<<"Book Title:"<<title<<endl;
            cout<<"Book Author Name:"<<author<<endl;
            cout<<"Pages Count:"<<pageCount<<endl;
            if(formate)
            {
                cout<<"Formate of Book:Hardcover"<<endl;
            }
            else
            {
                cout<<"Formate of Book:paperback"<<endl;
            }
            if(chapterPages!=nullptr)
            {
                cout<<"Pages per chapter:";
                for(int i=0;i<chapters;i++)
                {
                    cout<<chapterPages[i]<<",";
                }
                cout<<endl;
            }
            else
            {
                cout<<"No pages in book."<<endl;
            }
            cout<<"Numbers of Chapters in book:"<<chapters<<endl;
            cout<<"---------------------------------"<<endl;
        }

        // Destructor.
        ~Book()
        {
            delete[] title;
            delete[] author;
            delete[] chapterPages;

            title=nullptr;
            author=nullptr;
            chapterPages=nullptr;
        }
};

int main()
{
    // calling default constructor.
    Book b1;
    cout<<"\nDefault Constructor:"<<endl<<"\n";
    b1.display();

    // calling parameterized constructor.
    Book b2("Wings of fire","Apj Abdul Kalam",300,true,5);
    cout<<"\nParameterized Constructor:"<<endl<<"\n";
    b2.display();

    // calling copy constructor.
    Book b3(b2);
    cout<<"\nCopy (Deep) Constructor:"<<endl<<"\n";
    b3.display();

    // Modifying pages count.
    b3.modifyPageCount(3,20);
    b3.display();
    
    // Deleting b2 object.
    b2.~Book();
    // object b1 values.
    cout<<"\nObject b1:\n";
    b1.display();
    // object b3 values.
    cout<<"\nObject b3:\n";
    b3.display();
    return 0;
}
