/*
   Name: Shams Aldin Abdelrahman Ali Ali

*/

#include <iostream>
#include <string>
using namespace std;

class  Discount {
private:
	double discountPrecentOnProduct;
	double discountPrecentOnService;

public:
	Discount() {
		discountPrecentOnProduct = 0;
		discountPrecentOnService = 0;
	}
	Discount(double disountOnProduct, double discountOnService) {
		discountPrecentOnProduct = disountOnProduct;
		discountPrecentOnService = discountOnService;
	}
	double getDiscountPrecentOnService()
	{
		return discountPrecentOnService; // there is no need to check if there is no discount (not a member) as it's already been calculated in the visit class
	}
	double setDiscountPrecentOnService(double d)
	{
		discountPrecentOnService = d;
	}
	double getDiscountPrecentOnProduct()
	{
		return discountPrecentOnProduct; // there is no need to check if there is no discount (not a member) as it's already been calculated in the visit class
	}
	double setDiscountPrecentOnProduct(double d)
	{
		discountPrecentOnProduct = d;
	}
};
class Customer {
private:
	string membership;
	Discount* discount;
public:

	Customer() {
		discount = new Discount(0, 0);

	};	//defualt constructor so we can call other classes without using a constructor (prevent error) 
	Customer(int membershipID) {
		if (membershipID == 0)
		{
			membership = "normal";

			discount = new Discount(1, 1);

		}
		else if (membershipID == 1)
		{
			membership = "silver";

			discount = new Discount(0.85, 0.9);
		}
		else if (membershipID == 2)
		{

			membership = "gold";
			discount = new Discount(0.8, 0.9);
		}
		else if (membershipID == 3)
		{
			membership = "platinum";

			discount = new Discount(0.75, 0.9);
		}

	}
	void set_membership(string m) { membership = m; }
	string get_membership() { return membership; }
	Discount* get_discount() { return discount; }
};


class  Visit {
private:
	double Product_Cost = 0, Service_Cost = 0, bill = 0;
	Customer customer;
public:

	Visit(Customer c)
	{
		customer = c;
	}
	void set_product(double p) { Product_Cost = p; }

	double get_product() { return Product_Cost; }

	void set_service(double s) { Service_Cost = s; }

	double get_service() { return Service_Cost; }  // all of the previous is before the discount

	void getTotalPrice()
	{

		bill = Service_Cost * (customer.get_discount()->getDiscountPrecentOnService());
		bill += Product_Cost * customer.get_discount()->getDiscountPrecentOnProduct();  // any member has a 10% discount on any product (0.9*product)

		cout << "The price before the discount is : " << Service_Cost + Product_Cost << endl << "L.E and after the discount is :" << bill << "L.E" << endl;
	}
};



int main() {
	while (true)
	{
		cout << "Please enter the member ship number:\n";
		cout << "Enter 0 for Normal Membership\n";
		cout << "Enter 1 for Silver Membership\n";
		cout << "Enter 2 for Gold Membership\n";
		cout << "Enter 3 for Platinum Membership\n";
		int tempID;
		cin >> tempID;
		Customer c1(tempID);
		Visit v1(c1);
		v1.set_service(300);
		v1.set_product(500);
		v1.getTotalPrice();
	}


	return 0;
}