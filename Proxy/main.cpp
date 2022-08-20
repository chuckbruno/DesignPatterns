
#include "proxy.h"
#include <iostream>

int main()
{
	ItemRequest our_store_front;
	our_store_front.AddInventory(ItemForSale{ 123, 10, 1 });
	our_store_front.AddInventory(ItemForSale{ 456, 10, 1 });
	our_store_front.AddInventory(ItemForSale{ 789, 10, 1 });
	our_store_front.AddInventory(ItemForSale{ 233, 51, 1 });
	our_store_front.AddInventory(ItemForSale{ 434, 10, 1 });
	our_store_front.AddInventory(ItemForSale{ 656, 10, 1 });

	// proxy it
	CheckBeforeItemRequest proxy_store(&our_store_front);
	proxy_store.AddInventory(ItemForSale{ 277, 2, 2 });

	// client
	PaymentType out_payment = PaymentType::CREDIT;

	auto return_code = proxy_store.RequestItem(234, out_payment);
	std::cout << "return code for purchase 234: " << return_code << std::endl;

	auto return_code2 = proxy_store.RequestItem(233, out_payment);
	std::cout << "return code for purchase 233: " << return_code2 << std::endl;

	getchar();
}