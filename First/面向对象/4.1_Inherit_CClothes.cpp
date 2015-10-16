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



class CClothes:public CGoods {
	private:
		char *p_brand;
	public:
		void usedFor();
		CClothes(long num,char *name,double pri,char *brand):CGoods(num,name,pri){
			p_brand = brand;
		}	
		~CClothes();
};

void CClothes::usedFor() {
	cout << "The cclothes " << *p_name << "," << "brand is " << *p_brand << ","  
		<< "is be used for an astronaut!" << endl;	
}
CClothes::~CClothes() {
	delete p_brand;
}
int main() {
	char name = 'N';
	char brand = 'B';
	CClothes cclothes(55,&name,6.66,&brand);
	cclothes.usedFor();
	return 0;
}



