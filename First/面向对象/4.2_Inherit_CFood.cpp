#include <iostream>
using namespace std;
class CGoods {
	protected:
		long no;
		char *p_name;
		double price;
	public:
		CGoods(long num,char *name,double pri);
		CGoods(const CGoods &c);
		~CGoods();
				
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

class CFood:public CGoods {
	private:
		char *p_brand;
	public:
		void usedFor();
		CFood(long num,char *name,double pri,char *brand):CGoods(num,name,pri) {
			p_brand = brand;
		}
		~CFood();
};
void CFood::usedFor() {
	cout << "The cfood " << *p_name << "," << "brand is " << *p_brand << ","  
		<< "will to be relaxing and to aid sleep!" << endl;	
	
} 
CFood::~CFood() {
	delete p_brand;
}
int main() {
	char name = 'N';
	char brand = 'B';
	CFood cfood(23,&name,5.55,&brand);
	cfood.usedFor();
}
