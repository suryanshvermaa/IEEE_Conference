#include <iostream>
#include <vector>
struct user
{
    int id;
    std::string name;
    std::string email;
    std::string passwordHash;
    std::string role;
};

namespace UserRepository{
    int createUser(const user& u);
    std::vector<user> getUsers(int page,int limit);
    user getUser(int id);
    bool updateUser(int id,const user& u);
    bool deleteUser(int id);
}