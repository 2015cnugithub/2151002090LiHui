#include <iostream>
using namespace std;
class CGoods {
	protected:
		long no;
		char *p_name;
		double price;
	public:
		CGoods() {};
		CGoods(long num,char *name,double pri);
		CGoods(const CGoods &c);
		~CGoods();
		//void usedInfo() {};
		virtual void usedFor() {
		}		
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
//void CGoods::usedFor() {
//	char *goodsName = cgoods.p_name;
//	
//	cout << "The cfood " << *goodsName << " ";
	//cgoods.usedInfo();
//}

class CClothes:public CGoods {
	private:
		char *p_brand;
	public:
//		void usedInfo() {
//			cout << " is be used for an astronaut!" << endl;
//		}
		CClothes(long num,char *name,double pri,char *brand):CGoods(num,name,pri){
			p_brand = brand;
		}	
		~CClothes() {
			delete p_brand;
		}
		virtual void usedFor() {
			
			cout << "The cclothes is be used for an astronaut!" << endl;
		}
};

class CFood:public CGoods {
	private:
		char *p_brand;
	public:
//		void usedInfo() {
//			cout << " will to be relaxing and to aid sleep!" << endl;
//		}
		CFood(long num,char *name,double pri,char *brand):CGoods(num,name,pri) {
			p_brand = brand;
		}
		~CFood() {
			delete p_brand;
		}
		virtual void usedFor() {
			cout <<  "The food will to be relaxing and to aid sleep!" << endl;
		}	
};

int main() {
	
	char clothesName = 'A';
	char clothesBrand = 'a';
	char foodName = 'B';
	char foodBrand = 'b';
	CGoods *cgoods;
	CClothes cclothes(1,&clothesName,1.11,&clothesBrand);
	CFood cfood(2,&foodName,2.22,&foodBrand);
	
	cgoods = &cclothes;		
	cgoods->usedFor();
	cgoods = &cfood;
	cgoods->usedFor();
	return 0;
}
