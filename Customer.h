/*
 * Customer.h
 *
 *  Created on: Apr. 5, 2021
 *      Author: yuelinliu
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <iostream>
#include <string>
using namespace std;

class Customer{
private:
	int customer_id;
	string customer_name;
	string customer_phone;
public:
	//constructor for class Customer
	Customer(int a_id, string a_name, string a_phone){
		customer_id = a_id;
		customer_name = a_name;
		customer_phone = a_phone;
	};

	//get customer id
	int getCustomerID(){
		return customer_id;
	};

};

#endif /* CUSTOMER_H_ */
