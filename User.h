#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
using namespace std;
class User {

private:
    char userName[ 15 ];             //username  max character 15
    char firstName[ 10 ];               //firstanme max character 10
    string password;

public:
    User(){};                                   //mutators and accessors

    void setPassword();
    string getPassword() const;

    void setUserName();
    string getUserName() const;

    void setFirstName();
    string getFirstName() const;

    void saveUsersToFile(const User &);
    bool checkPassword(const User &);

};



#endif // USER_H_INCLUDED
