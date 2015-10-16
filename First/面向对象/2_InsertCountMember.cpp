#include <iostream>
using namespace std;
class CGoods {
	private:
		long no;
		char *p_name;
		double price;
		int count;
	public:
		CGoods(long num,char *name,double pri,int cou);
		CGoods(const CGoods &c);
		~CGoods();	
		void printInfo();
		int getCount();
		friend char * getName(CGoods &cgoods);
}; 
CGoods::CGoods(long num,char *name,double pri,int cou) {
	no = num;
	p_name = name;
	price = pri;
	count = cou;
}
CGoods::~CGoods() {
	delete &no;
	delete p_name;
	delete &price;
	delete &count;
}
CGoods::CGoods(const CGoods &c) {
	no = no;
	p_name = c.p_name;
	price = price;
	count = count;
}
void CGoods::printInfo() {
	cout << "The no of the goods:" << no << endl;
	cout << "The name of the goods:" << *p_name << endl;
	cout << "The price of the goods:" << price << endl;
	cout << "The count of the goods:" << count << endl;
}
int CGoods::getCount() {
	return count;
}
char * getName(CGoods &cgoods) {
	return cgoods.p_name;
}

int main() {
	char cgoodsName = 'B';
	CGoods cgoods(11,&cgoodsName,5.555,23);
	char getedName;
	getedName = *getName(cgoods);
	cout << "Get Name By Friend Function:" << getedName << endl;
	return 0;
}




