#include <iostream>
using namespace std;
class CGoods {
	private:
		long no;
		char *p_name;
		double price;
	public:
		CGoods(long num,char *name,double pri);
		CGoods(const CGoods &c);
		~CGoods();
		void printInfo(); 		
}; 
CGoods::CGoods(long num,char *name,double pri) {
	no = num;
	p_name = name;
	price = pri;
}
CGoods::~CGoods() {
	delete &no;
	delete p_name;
	delete &price;
}
CGoods::CGoods(const CGoods &c) {
	no = no;
	p_name = c.p_name;
	price = price;
}
void CGoods::printInfo() {
	cout << "The no of the goods:" << no << endl;
	cout << "The name of the goods:" << *p_name << endl;
	cout << "The price of the goods:" << price << endl;
}

int main() {
	char goodsName = 'A';
	CGoods cgoods(10, &goodsName, 3.333);
	cgoods.printInfo();
	return 0;		
}





