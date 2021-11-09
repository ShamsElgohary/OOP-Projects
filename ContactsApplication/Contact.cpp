#include "Contact.h"

/* Custom Function Object Used as a comparator in the multiset*/
struct ContactFirstNameOrdered
{
	bool operator() (const Contact &c1 , const Contact &c2)
	{
		return (c1.GetFirstName() < c2.GetFirstName() );
	}
};

struct ContactLastNameOrdered
{
	bool operator() (const Contact &c1 , const Contact &c2)
	{
		return (c1.GetLastName() < c2.GetLastName() );
	}
};


static multiset<Contact, ContactFirstNameOrdered> ContactsByFirstName;
static multiset<Contact, ContactLastNameOrdered> ContactsByLastName;


Contact::Contact()
{}

Contact::Contact(string firstName, string lastName, string primaryNumber) : Contact(firstName, lastName, primaryNumber, "", "" , "")
{}

Contact::Contact(string firstName, string lastName, string primaryNumber, string email, string address, string company ): \
		FirstName(firstName),LastName(lastName),PrimaryPhone(primaryNumber), Email(email),Address(address),Company(company)
{
	ContactsByFirstName.insert(*this);
	ContactsByLastName.insert(*this);
}

Contact::~Contact() {}

void Contact::DisplayAllContactsInfo( bool FirstNameFlag )
{
	if (FirstNameFlag == true)
	{
		for (const auto &contacts : ContactsByFirstName)
				PrintInfo(contacts);
	}

	else if(FirstNameFlag == false)
	{
		for (const auto &contacts : ContactsByLastName)
			PrintInfo(contacts);
	}


}


void Contact::DisplayAllNumbers(bool FirstNameFlag )
{
	if (FirstNameFlag == true)
	for (const auto &contacts : ContactsByFirstName)
	{
		cout<< "First Name : "<<contacts.FirstName<<"\t \t - "<<"Last Name : "<<contacts.LastName
		    <<"\t \t - Primary Phone Number : "<< contacts.PrimaryPhone<<"\n";
	}

	else
		for (const auto &contacts : ContactsByLastName)
		{
			cout<< "First Name : "<<contacts.FirstName<<"\t \t - "<<"Last Name : "<<contacts.LastName
			    <<"\t \t - Primary Phone Number : "<< contacts.PrimaryPhone<<"\n";
		}

}

void Contact::DisplayContactByName(string name, bool FirstNameFlag)
{
	if(FirstNameFlag == true)
	{
		for (const auto &contacts : ContactsByFirstName)
			if ( contacts.FirstName == name )
				PrintInfo(contacts);
	}
	else
	{
		for (const auto &contacts : ContactsByFirstName)
			if ( contacts.LastName == name )
				PrintInfo(contacts);
	}
}

void Contact::DisplayCompanyContacts(string company)
{
	for (const auto &contacts : ContactsByFirstName)
	{
		if ( contacts.Company == company )
		{
			PrintInfo(contacts);
		}
	}
}

void Contact::SaveContact() const
{
	/* Sets are immutable so we have to erase the previous version of this contact if there was any and save the edited contact */
	if ( ContactsByFirstName.find(*this) != ContactsByFirstName.end())
	{
		ContactsByFirstName.erase(*this);
		ContactsByLastName.erase(*this);
	}

	ContactsByFirstName.insert(*this);
	ContactsByLastName.insert(*this);
}

void Contact::EraseContact() const
{
	if ( ContactsByFirstName.find(*this) != ContactsByFirstName.end())
	{
		ContactsByFirstName.erase(*this);
		ContactsByLastName.erase(*this);
	}
}

string Contact::GetFirstName() const
{
	return FirstName;
}

string Contact::GetLastName() const
{
	return LastName;
}

string Contact::GetEmail() const
{
	return Email;
}

string Contact::GetAddress() const
{
	return Address;
}

string Contact::GetPrimaryPhone() const
{
	return PrimaryPhone;
}

string Contact::GetSecondaryPhone() const
{
	return SecondaryPhone;
}

void Contact::SetFirstName(string firstName)
{
	FirstName = firstName;
}

void Contact::SetLastName(string lastName)
{
	LastName = lastName;
}

void Contact::SetEmail(string email)
{
	Email=email;
}

void Contact::SetAddress(string address)
{
	Address=address;
}

void Contact::SetPrimaryPhone(string primePhone)
{
	PrimaryPhone = primePhone;
}

void Contact::SetSecondaryPhone(string secondPhone)
{
	SecondaryPhone = secondPhone;
}


void Contact::PrintInfo(const Contact &C)
{
	cout<< "\nFirst Name : "<<C.FirstName<<"\t\t - Last Name : "<<C.LastName << "\t \t - Email : "<< C.Email
			<< "\t \t - Address : "<< C.Address << "\nPrimary Phone Number : "<< C.PrimaryPhone
			<< "\t \t - Secondary Phone Number : "<<C.SecondaryPhone <<"\n \n";
}





/* We need more than one type of operator overloading
bool operator< (const Contact &c1 , const Contact &c2)
{
	return (c1.GetFirstName() < c2.GetFirstName() );
}

Below would be needed if we were to use an unordered set

struct ContactHashFunction
{
	 size_t operator()(const Contact &c) const
	 {
			auto H1 = hash<string>{}( c.GetFirstName() );
			auto H2 = hash<string>{}( c.GetLastName()  );
			auto H3 = hash<string>{}( c.GetPrimaryPhone() );
			return H1^ H2 ^ H3;
	 }
};

bool Contact::operator==(const Contact &OtherContact) const
{
	return (FirstName == OtherContact.FirstName) && (LastName == OtherContact.LastName) && ( PrimaryPhone == OtherContact.PrimaryPhone);
}

static unordered_set<Contact, ContactHashFunction> Contacts_Cotainer;

*/
