/*
 * Item.h
 *
 *  Created on: Apr. 5, 2021
 *      Author: yuelinliu
 */

#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

class Item{
private:
	int item_no;
	string item_name;
	string manufacturer;
	float selling_price;
public:

	//constructor for class Item
	Item(int an_item_no, string an_item_name, string a_manufacturer, float a_selling_price){
		item_no = an_item_no;
		item_name = an_item_name;
		manufacturer = a_manufacturer;
		selling_price = a_selling_price;
	};

	//insert item into item list
	void insertIntoInventory(forward_list<Item> &list1, Item &item){
		//if list is empty, insert item at front
		if(list1.empty()){
			list1.push_front(item);
		}
		else{
			//set initial prev to the first item
			auto prev = list1.begin();
			int num = 0;

			//calculate size of list1
			for(auto iterate = list1.begin(); iterate != list1.end(); iterate++){
				num++;
			}

			int i = 0;
			//insert item by item name order
			for (auto iterate = list1.begin(); iterate != list1.end(); iterate++){
				if(iterate->get_item_name().compare(item.item_name) > 0){
					if(i == 0){
						list1.push_front(item);
					}else{
						list1.insert_after(prev, item);
					}
					break;
				}
				prev = iterate;
				i++;
			}
			//if no item's name is larger than current item, add item to the end of the list
			if(i == num){
				list1.insert_after(prev, item);
			}
		}
	};

	//display each item data
	void display(){
		cout << "item name: " << item_name << endl;
		cout << "item number: " << item_no << endl;
		cout << "manufacturer: " << manufacturer << endl;
		cout << "selling price: " << selling_price << "\n\n";
	};

	//get item name
	string get_item_name(){
		return item_name;
	}

	//get item number
	int get_item_no(){
		return item_no;
	}

	//get item's selling price
	float get_selling_price(){
		return selling_price;
	}

	//print item
	void print_item(){
		cout << item_name << ": " << "$" << selling_price << "\n";
	}
};

#endif /* ITEM_H_ */
