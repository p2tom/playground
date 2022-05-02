#include <iostream>

using namespace std;



class String {

public:
    String () = default;
    String (const char *name) {
        m_len = strlen(name);
        m_dat = new char[m_len];
        memcpy(m_dat, name, m_len);
        printf("%p : ", (void *)(m_dat));
        cout << "String Constructed" << endl;
    }

    String(const String &other) {
        m_len = other.m_len;
        m_dat = new char[m_len];
        memcpy(m_dat, other.m_dat, m_len);
        printf("%p : ", (void *)(m_dat));
        cout << "String Copy Constructed" << endl;
    }

    String& operator=(const String& other) {

        delete[] m_dat;
        printf("%p : ", (void *)(m_dat));
        cout << "Deleted in Copy Assignment" << endl; 

        m_len = other.m_len;
        m_dat = new char[m_len];
        memcpy(m_dat, other.m_dat, m_len);

        printf("%p : ", (void *)(m_dat));
        cout << "String Copy Assigned" << endl;      

        return *this;
    }

    // String(String &&other) {
    //     m_len = other.m_len;
    //     m_dat = other.m_dat;

    //     other.m_dat = nullptr;
    //     other.m_len = 0;

    //     printf("%p : ", (void *)(m_dat));
    //     cout << "String Move Constructed" << endl;        
    // }

    // String& operator=(String&& other) {

    //     if(this != &other) {
    //         delete[] m_dat;
    //         printf("%p : ", (void *)(m_dat));
    //         cout << "Deleted in Move Assignment" << endl; 

    //         m_len = other.m_len;
    //         m_dat = other.m_dat;

    //         other.m_dat = nullptr;
    //         other.m_len = 0;

    //         printf("%p : ", (void *)(m_dat));
    //         cout << "String Move Assigned" << endl;      

    //     }

    //     return *this;
    // }

    ~String() {
        printf("%p : ", (void *)(m_dat));
        cout << "String Destroyed" << endl;
        m_len = 0;
        delete m_dat;
    }

private:
    char* m_dat = nullptr;
    size_t m_len = 0;

};


class Entity {
public:
    Entity(const String &name) : m_name_(name) {}

    Entity(String &&name) : m_name_(std::move(name)) {}

private:
    String m_name_;

};

int main() {
    Entity my_entity{"Prithvi"};

    // String last_name{"Default"};
    // String my_last_name{"Thomas"};
    // last_name = std::move(my_last_name);
    
    return 0;

}