#include <vector>
#include <iostream>

enum PaymentType {CREDIT, BANK, WIRE, CRYPTO};

bool Charge(const PaymentType payment_, int amount_to_charge)
{
	return true;
}

struct ItemForSale
{
	int sku;
	int cost_pre;
	int num_in_stock;
};

typedef std::vector<ItemForSale> Inventory;

class Request
{
public:
	virtual ~Request() = default;
	virtual void AddInventory(ItemForSale ifs) = 0;
	virtual int RequestItem(const int item_sku, const PaymentType payment_) = 0;
protected:
	Inventory current_inventory;
};

class ItemRequest : Request
{
public:
	virtual ~ItemRequest(){}
	virtual void AddInventory(ItemForSale ifs) override
	{
		for (auto& item : current_inventory)
		{
			if (item.sku == ifs.sku)
			{
				item.num_in_stock += ifs.num_in_stock;
				return;
			}
		}

		current_inventory.push_back(ifs);
	}

	virtual int RequestItem(const int item_sku, const PaymentType payment_) override
	{
		for (auto& item : current_inventory)
		{
			if (item.sku == item_sku && item.num_in_stock > 0)
			{
				if (Charge(payment_, item.cost_pre))
				{
					item.num_in_stock--;
					return item.cost_pre;
				}
				return -1;
			}
		}
		return 0;
	}
};

class CheckBeforeItemRequest :Request
{
private:
	ItemRequest* item_request;
	void LogInventoryAdd(ItemForSale ifs)
	{
		std::cout << "attempted to add sku: " << ifs.sku << std::endl;
	}

	bool PaymentCheck(const PaymentType payment_)
	{
		std::cout << "the card is actived" << std::endl;
		std::cout << "the car is legal" << std::endl;
		return true;
	}

public:
	CheckBeforeItemRequest(ItemRequest* item_req):item_request(new ItemRequest(*item_req)){}
	~CheckBeforeItemRequest() { delete item_request; }
	virtual void AddInventory(ItemForSale ifs) override
	{
		LogInventoryAdd(ifs);
		item_request->AddInventory(ifs);
	}

	virtual int RequestItem(const int item_sku, const PaymentType payment_) override
	{
		if (!PaymentCheck(payment_))
		{
			return -1;
		}
		return item_request->RequestItem(item_sku, payment_);
	}
};