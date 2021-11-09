#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
#include <memory>
#include <set>
#include <unordered_set>


using namespace std;


class Contact {

private:
	string FirstName;
	string LastName;
	string PrimaryPhone;
	string Email;
	string Address;
	string Company;
	string SecondaryPhone{0};
//	unique_ptr<Contact> Ptr2Family{nullptr};
//	unique_ptr<Contact> Ptr2Friends{nullptr};
//	unique_ptr<Contact> Ptr2Acquintances{nullptr};



public:

	Contact();

	Contact(string firstName, string lastName, string primaryNumber);

	Contact(string firstName, string lastName, string primaryNumber, string email, string address, string company);

	static void DisplayAllContactsInfo(bool FirstNameFlag = true);

	static void DisplayAllNumbers(bool FirstNameFlag = true );

	static void DisplayCompanyContacts(string company);

	static void DisplayContactByName(string name, bool FirstNameFlag = true); 	// If we want to search by the last name then Flag = false

	void SaveContact() const;

	void EraseContact() const;

	string GetFirstName() const;

	string GetLastName() const;

	string GetEmail() const;

	string GetAddress() const;

	string GetPrimaryPhone() const;

	string GetSecondaryPhone() const;

	void SetFirstName(string firstName);

	void SetLastName(string lastName);

	void SetEmail(string email);

	void SetAddress(string address);

	void SetPrimaryPhone(string primePhone);

	void SetSecondaryPhone(string secondPhone);

	static void PrintInfo(const Contact &C);

	~Contact();

};





#endif /* CONTACT_H_ */
