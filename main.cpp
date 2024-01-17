/*
 * main.cpp
 *
 *  Created on: Apr. 5, 2021
 *      Author: yuelinliu
 */

#include "Item.h"
#include "Customer.h"
#include "Bill.h"
#include <map>
#include <vector>

//remove item from itemList by item number
void removeItem(int itemNo, forward_list<Item> &list1){
	auto prev = list1.begin();
	for (auto iterate = list1.begin(); iterate != list1.end(); iterate++){
		if(iterate->get_item_no() == itemNo){
			list1.erase_after(prev);
		}
		prev = iterate;
	}
};

//print all items in the item list
void display_items(forward_list<Item> list1){
	for (auto iterate = list1.begin(); iterate != list1.end(); iterate++){
			iterate ->display();
	}
};

//calculate total sale of a company
float calculate_total_sale(vector<Bill> bill1, string date){
	float total = 0;
	for(auto iterate = bill1.begin(); iterate != bill1.end(); iterate++){
		if(iterate->get_date().compare(date) == 0){
			total += iterate->get_balance();
		}
	}
	return total;
};

//show all bills by customer id
void show_bill_by_customer(int id,vector<Bill> bill1){
	for(auto iterate = bill1.begin(); iterate != bill1.end(); iterate++){
		if(iterate->get_customer_id() == id){
			iterate->print_bill();
			cout << "\n\n";
		}
	}
};

//print all customer id of preference members
void print_preference_customers(map<int,float> p1){
	cout << "customer id\n";
	for (auto iterate = p1.begin(); iterate != p1.end(); iterate++){
		cout << (*iterate).first << "\n";
	}
};

int main(){

	//initialize item list
	forward_list<Item> itemList;
	Item item1(1001, "tablet", "Samsung", 779);
	item1.insertIntoInventory(itemList, item1);
	Item item2(1002, "iphone 12", "Apple", 1199);
	item2.insertIntoInventory(itemList, item2);
	Item item3(1003, "apple", "Arctic", 2.56);
	item3.insertIntoInventory(itemList, item3);
	Item item4(1004, "mac lipstick", "Estée Lauder", 24);
	item4.insertIntoInventory(itemList, item4);
	Item item5(1005, "zucchini", "Cott Corporation", 3.23);
	item5.insertIntoInventory(itemList, item5);
	Item item6(1006, "banana", "Dole Food Company", 1.93);
	item6.insertIntoInventory(itemList, item6);
	Item item7(1007, "lamp", "GE Lighting", 33.97);
	item7.insertIntoInventory(itemList, item7);
	Item item8(1008, "sportswear", "Nike", 130);
	item8.insertIntoInventory(itemList, item8);
	Item item9(1009, "handbag", "Gucci", 2460);
	item9.insertIntoInventory(itemList, item9);
	Item item10(1010, "pants", "Metersbonwe", 48);
	item10.insertIntoInventory(itemList, item10);
	Item item11(1011, "dress", "GAP", 54.95);
	item11.insertIntoInventory(itemList, item11);

	//display item list
	display_items(itemList);


	//delete certain items from the inventory
	removeItem(1001, itemList);
	removeItem(1003, itemList);
	removeItem(1009, itemList);

	//display item list after deleting certain items
	cout << "------------------- inventory after delete items -------------------\n\n";
	display_items(itemList);


	//initialize customers
	Customer c1(2001, "Alen", "613-555-0179");
	Customer c2(2002, "Mary", "403-762-6435");
	Customer c3(2003, "David", "505-893-0164");
	Customer c4(2004, "Nick", "980-329-4345");
	Customer c5(2005, "Kevin", "233-893-4365");
	Customer c6(2006, "John", "654-345-0695");

	//initialize preference
	map<int,float> preference;
	preference[2005] = 0.2;
	preference[2006] = 0.5;

	//list for first customer
	list<Item> list1;
	list1.push_back(item2);
	list1.push_back(item4);

	//list for second customer
	list<Item> list2;
	list2.push_back(item5);
	list2.push_back(item6);
	list2.push_back(item8);

	list<Item> list21;
	list21.push_back(item6);
	list21.push_back(item10);

	//list for third customer
	list<Item> list3;
	list3.push_back(item10);
	list3.push_back(item11);

	//list for forth customer
	list<Item> list4;
	list4.push_back(item2);

	//initialize bills
	Bill b1(3001, "Nov.30, 2020", 0, &c1, list1);
	Bill b2(3002, "Nov.30, 2020", 0, &c2, list2);
	Bill b3(3003, "Mar.3, 2020", 0, &c3, list3);
	Bill b4(3004, "Nov.30, 2020", 0, &c4, list4);
	Bill b5(3005, "Dec.2, 2020", 0, &c2, list21);


	//store customer bills
	vector<Bill> bill;
	bill.push_back(b1);
	bill.push_back(b2);
	bill.push_back(b3);
	bill.push_back(b4);
	bill.push_back(b5);

	//calculate and print total sales on Nov.30, 2020
	float total_sale = calculate_total_sale(bill, "Nov.30, 2020");
	cout << "------------------- Total sales on Nov.30, 2020 -------------------\n\n";
	cout << total_sale << "\n\n";

	//print all bills of customer 2002
	cout << "------------------- All bills of customer 2002 -------------------\n\n";
	show_bill_by_customer(2002, bill);

	//print customer_id for all customers who have a discount preference
	cout << "------------------- customers who have discount preference -------------------\n\n";
	print_preference_customers(preference);

	return 0;

}



