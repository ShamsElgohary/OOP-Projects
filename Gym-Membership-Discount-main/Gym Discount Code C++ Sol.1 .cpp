/*
   Name: Shams Aldin Abdelrahman Ali Ali
  
*/
#include <iostream>
#include <string>
using namespace std;

class Customer {
private:	string  membership;
			int membershipID;

public:
	Customer() {  /*Defualt*/ };

	Customer(int membershipID) {
		if (membershipID == 0)
		{
			membership = "not a member";
			this->membershipID = membershipID;
		}
		else if (membershipID == 1)
		{
			membership = "silver";
			this->membershipID = membershipID;
		}
		else if (membershipID == 2)
		{
			membership = "gold";
			this->membershipID = membershipID;
		}
		else if (membershipID == 3)
		{
			membership = "platinum";
			this->membershipID = membershipID;
		}

	}


	void set_membershipID(int m) { membershipID = m; }

	int get_membershipID() { return membershipID; }

	void set_membership(string m) { membership = m; }

	string get_membership() { return membership; }

};

class Discount {
private: double DiscountOnProduct, DiscountOnService;
public:

	double ServiceDiscount(Customer c)
	{
		int mem = c.get_membershipID();

		if (mem == 0)
			DiscountOnService = 1;				// Not a member
		else if (mem == 1)
			DiscountOnService = 0.85;			//silver 
		else if (mem == 2)
			DiscountOnService = 0.8;			 // gold
		else if (mem == 3)
			DiscountOnService = 0.75;			//platinium
		return DiscountOnService;
	}

	double ProductDiscount(Customer c)  //If member then discount 0.9 else no discount
	{
		int mem = c.get_membershipID();

		if (mem == 0) DiscountOnProduct = 1;

		else DiscountOnProduct = 0.9;

		return DiscountOnProduct;

	}
};

class Visit {
private:
	double Product_Cost = 0, Service_Cost = 0, bill = 0;
	Discount discount;
public:


	void set_product(double p) { Product_Cost = p; }

	double get_product() { return Product_Cost; }

	void set_service(double s) { Service_Cost = s; }

	double get_service() { return Service_Cost; }  // all of the previous is before the discount




	void TotalPrice(Customer c)
	{
		bill = Service_Cost * (discount.ServiceDiscount(c)) + Product_Cost * (discount.ProductDiscount(c));

		cout << "The bill before the discount is ...... = " << Product_Cost + Service_Cost << endl
			<< "The bill after the discount is  ...... = " << bill << endl
			<< "The member type is  ...... = " << c.get_membership() << endl;
	}
};



int main() {

	cout << "Please enter the member ship number:\n";
	cout << "Enter 0 for No Membership\n";
	cout << "Enter 1 for Silver Membership\n";
	cout << "Enter 2 for Gold Membership\n";
	cout << "Enter 3 for Platinum Membership\n";
	cout << "------------------------------------------------------\n";
	int ID;
	cin >> ID;

	Customer customer(ID);

	// We can add variables in set service and product rather than constant numbers for example set_product(ProductCost);
	Visit v1;
	v1.set_service(100);
	v1.set_product(100);
	v1.TotalPrice(customer);

	return 0;
}
