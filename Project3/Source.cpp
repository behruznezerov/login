#include <iostream>
using namespace std;

class Database;

class User {

	string username;
	string password;

public:

	friend class Database;


	User() {

		username = "default";
		password = "default";

	}

	User(string user, string pass) {

		username = user;
		password = pass;

	}

	User(const User& oth) {
		username = oth.username;
		password = oth.password;
	}

	User& operator=(User& other) {

		username = other.username;
		password = other.password;
		return *this;

	}

#pragma endregion

	friend istream& operator>>(istream& in, User& oth) {

		cout << "Username : " << endl;
		in >> oth.username;
		cout << "Password : " << endl;
		in >> oth.password;
		cout << "Ugurlu Kayit\n";
		return in;
	}

};

class Database {
	int size = 0;
	User* users = nullptr;

public:

	bool SignIn(User& user) {
		for (int i = 0; i < size; i++)
		{
			if (user.username == users->username) {
				if (user.password == users->password)
				{
					cout << "Daxil Olundu\n";
					return true;
				}
				else
				{
					cout << "Kod Sehvdir\n";
					return false;
				}
			}
			else
			{
				cout << "Username sehvdir\n";
				return false;
			}
		}
	}

	bool SignUp(User& user) {
		if (size != 0) {
			for (int i = 0; i < size; i++)
			{
				if (user.username == users->username)
				{
					cout << "Username isledilir";
					return false;
				}
				else
				{
					User* temp = new User[size + 1];
					for (int i = 0; i < size; i++)
					{
						temp[i] = users[i];
					}
					temp[size] = user;
					delete[] users;
					users = temp;
					temp = nullptr;
					size++;
				}
			}
		}
		else {
			User* temp = new User[size + 1];
			for (int i = 0; i < size; i++)
			{
				temp[i] = users[i];
			}
			temp[size] = user;
			delete[] users;
			users = temp;
			temp = nullptr;
			size++;
		}
	}
};

int main() {

	Database bab;
	User babu("babunano252", "babunano");
	User Behruz;
	cin >> Behruz;
	cout << "\n\n";
	bab.SignUp(Behruz);
	bab.SignIn(Behruz);

}