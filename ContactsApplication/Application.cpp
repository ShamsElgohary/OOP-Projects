#include <iostream>
#include "Contact.h"




int main() {
	string fname;
	string lname;
	string address{};
	string primaryPhone;
	string secondaryPhone{};
	string company{};
	string email{};
	bool InfoState{false};
	bool EnterNewContact{false};
	int operationState;



	while(1)
	{
		do
		{

		cout<<"Enter Contact Information in this order \nEnter First Name  ";
		cout<<"\nEnter Last Name  ";
		cout<<"\nEnter Primary Phone Number  \n";
		cin>>fname;
		cin>>lname;
		cin>>primaryPhone;

		cout<<"Enter 1 to add more information (Optional) -> Company, Email, Address \n";
		cin>>InfoState;

		if (InfoState == true)
		{
		cout<<"Enter Company Name : ";
		cout<<"\nEnter Email : ";
		cout<<"\nEnter Address : ";
		cin>>company;
		cin>>email;
		cin>>address;
		}

		Contact *c = new Contact(fname,lname,primaryPhone, email, address, company);

		cout<<"Enter 1 to add a new contact and 0 to stop adding contacts... \n";
		cin>>EnterNewContact;


		}while(EnterNewContact);

		cin>>operationState;

		switch (operationState)
		{
		case(1):
				Contact::DisplayAllNumbers();
				break;

		case(2): /* Sorted by last name */
				Contact::DisplayAllNumbers(false);
				break;
		case(3):
				Contact::DisplayAllContactsInfo();
				break;
		case(4):
				Contact::DisplayAllContactsInfo(false);
				break;
		default:break;
		}


	}



	return 0;
}
