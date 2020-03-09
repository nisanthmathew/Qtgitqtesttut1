#ifndef MYSTRING_H
#define MYSTRING_H

#include <QObject>
#include <iostream>
class MyString : public QObject
{
    Q_OBJECT
private:
    char* mystr; //c style string which holds mystring
public:
    explicit MyString(QObject *parent = nullptr); // no arg constructor
    MyString(const char* normalstr); // overloaded constructor
    MyString(MyString &copystring); // copy constructor
    ~MyString();

    void display(std::ostream& outstream) const; // display string
    int getlength() const; // display string length
    const char* getmystring() const; // get string
    MyString &operator=(const MyString &rhs); // assignment operator overloading
signals:

};

#endif // MYSTRING_H
