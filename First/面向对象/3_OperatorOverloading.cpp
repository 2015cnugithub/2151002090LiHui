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
		bool operator < (const CGoods &c1);
		bool operator >= (const CGoods &c2);
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
bool CGoods::operator < (const CGoods &c) {
	return (price < c.price);
}
bool CGoods::operator >= (const CGoods &c) {
	return (price >= c.price); 
}

int main() {
	char name1 = 'D';
	char name2 = 'E';
	CGoods c1(11,&name1,1.22,100);
	CGoods c2(12,&name2,3.33,200);
	if(c1 < c2) {
		cout << "c1 is less than c2" <<endl;
	}
		else 
			cout  << "c1 is not less than c2" <<endl;
	if(!(c1 >= c2)) {
		cout << "c1 not >= c2" << endl;
	}
		else 
			cout << "c1 >= c2" << endl;	
	
	return 0;	
}





