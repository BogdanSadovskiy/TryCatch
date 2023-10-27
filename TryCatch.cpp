
#include <iostream>
#include <vector>
#include<Windows.h>
using namespace std;
class User {
private:
    string Name;
    string Pass;
public:
    User(string name, string pass) {
        this->Name = name;
        this->Pass = pass;
    }
    bool isUserTrue(string name, string pass) {
        if (this->Name == name && this->Pass == pass) {
            return true;
        }
        return false;
    }
    string getName() {
        return Name;
    }
    string getPass() {
        return Pass;
    }
};

void NameAndPass(string& Pass, string& Name) {
    cout << "Input name : "; cin >> Name;
    cout << "Input pass : "; cin >> Pass;
}

int main()
{
    vector<User> user;
    string name;
    string pass;
    string menu = "";
    while (menu != "e") {
        system("cls");
        cout << "Create user - 1\n";
        cout << "Find user --- 2\n";
        cout << "Print Users - 3\n";
        cout << "e - exit\n";
        cin >> menu;
     
        if ((menu == "2" || menu == "3") && user.size()==0) {
            try {
                throw invalid_argument("NO one user\n");
            }
            catch (const std::exception& ex)
            {
                std::cout << ex.what();
                Sleep(1000);
            }
            continue;
        }

        if (menu == "1") {
            NameAndPass(pass, name);
            user.push_back(User(name, pass));
            cout << "\tCreated\n";
            Sleep(600);
        }
        if (menu == "2") {
            NameAndPass(pass, name);
            bool isUserFound = false;
            for (User tmp : user) {
                if (tmp.isUserTrue(pass, name)) {
                    isUserFound = true;
                }
            }
            try {
                if (isUserFound) {
                    cout << "\tFound\n"; Sleep(600);
                    continue;
                }
                throw exception("Not found\n");
            }
            catch (const std::exception& ex)
            {
                std::cout << ex.what();
                Sleep(1000);
            }
        }
        if (menu == "3") {
            int i = 1;
            for (User tmp : user) {
                cout << "User " << i << endl;
                cout << "Name: " << tmp.getName() << endl;
                cout << "Pass: " << tmp.getPass() << endl << endl;
                i++;
            }
            cout << "\tInput anything to exit"; cin >> menu;
        }
    }

}

