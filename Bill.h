/*
 * Bill.h
 *
 *  Created on: Apr. 5, 2021
 *      Author: yuelinliu
 */

#ifndef BILL_H_
#define BILL_H_
#include <iostream>
#include <string>
#include "Item.h"
#include "Customer.h"
#include <list>
using namespace std;

class Bill{
private:
	int bill_no;
	string billing_date;
	float balance;
	Customer *customer;
	list<Item> items;
public:
	//constructor for class Bill
	Bill(int a_bill_no, string a_billing_date, float a_balance, Customer *a_customer, list<Item> list2){
		bill_no = a_bill_no;
		billing_date = a_billing_date;
		balance = calculate_balance(list2);
		customer = a_customer;
		items = list2;
	};

	//calculate balance of given list
	float calculate_balance(list<Item> list2){
		float aBalance = 0;
		for (auto iterate = list2.begin(); iterate != list2.end(); iterate++){
			aBalance += iterate -> get_selling_price();
		}
		//add tax to total balance
		aBalance *= 1.13;
		return aBalance;
	};

	//print bill
	void print_bill(){
		cout << "Bill on " << billing_date << "\n";
		for (auto iterate = items.begin(); iterate != items.end(); iterate++){
			iterate->print_item();
		}
		cout << "Total: " << "$" << balance;
	}

	//get balance
	float get_balance(){
		return balance;
	};

	//get date
	string get_date(){
		return billing_date;
	};

	//get customer id
	int get_customer_id(){
		return customer->getCustomerID();
	};
};

#endif /* BILL_H_ */
