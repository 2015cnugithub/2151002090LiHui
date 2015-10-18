#include <iostream>
#include <cstring>
using namespace std;
class Worker {
	protected:
		string name;
		int age;
		string sex;
		string type;
		int salary_level;
		int pay_per_hour;
	public:
		virtual void Compute_pay(double hours) = 0;
		friend ostream& operator << (ostream& out,Worker& worker);
		Worker() {};
		virtual void setName(string wname) {
//			name = wname;
		}
		virtual string getName() {
//			return this->name;
		} 
		
		virtual void setAge(int wage) {
//			age = wage;
		} 
		virtual int getAge() {
//			return this->age;
		}
		
		virtual void setSex(string wsex) {
//			sex = wsex;
		}
		virtual string getSex() {
//			return this->sex;
		} 
		
		virtual void setType(string wtype) {
//			type = wtype;
		}
		virtual string getType() {
//			return this->type;
		} 
		
		virtual void setSalaryLevel(int w_salary_level) {
//			salary_level = w_salary_level;
		}
		virtual int getSalaryLevel() {
//			return this->salary_level;
		}
		
		virtual void setPayPerHour(int w_pay_per_hour) {
//			pay_per_hour = w_pay_per_hour;
		}
		virtual int getPayPerHour() {
//			return this->pay_per_hour;
		}
};
ostream& operator << (ostream& out,Worker& worker) {
	out << "�û�����" << worker.getName() << "\n" 
		<< "�û����䣺" <<worker.getAge() << "\n"
		<< "�Ա�" << worker.getSex() << "\n"
		<< "���ͣ�" << worker.getType() << "\n"
		<< "н��ȼ���" << worker.getSalaryLevel() << "\n"
		<< "Сʱ���ʶ" << worker.getPayPerHour() << "\n"; 
		return out;
}

class HourlyWorker:public Worker {
	private:
		double weekpay;
		
	public:
		HourlyWorker() {};
		virtual void Compute_pay(double hours) {
			if(this->salary_level==1)
				this->pay_per_hour = 10;
				else if(this->salary_level==2)
					this->pay_per_hour = 20;
					else if(this->salary_level==3)
						this->pay_per_hour = 30;
			if(hours <= 40)
				this->weekpay = (this->pay_per_hour)* hours;
				else if(hours > 40)
					this->weekpay = (this->pay_per_hour)*40 + 1.5*(this->pay_per_hour)*(hours-40);
					//else return false;
		}
		virtual void setName(string wname) {
			name = wname;
		}
		virtual string getName() {
			return this->name;
		} 
		
		virtual void setAge(int wage) {
			age = wage;
		} 
		virtual int getAge() {
			return this->age;
		}
		
		virtual void setSex(string wsex) {
			sex = wsex;
		}
		virtual string getSex() {
			return this->sex;
		} 
		
		virtual void setType(string wtype) {
			type = wtype;
		}
		virtual string getType() {
			return this->type;
		} 
		
		virtual void setSalaryLevel(int w_salary_level) {
			salary_level = w_salary_level;
		}
		virtual int getSalaryLevel() {
			return this->salary_level;
		}
		
		virtual void setPayPerHour(int w_pay_per_hour) {
			pay_per_hour = w_pay_per_hour;
		}
		virtual int getPayPerHour() {
			return this->pay_per_hour;
		}
};
class SalariedWorker:public Worker {
	private:
		double weekpay;
	public:
		SalariedWorker() {};
		virtual void Compute_pay(double hours) {
			if(this->salary_level==1)
				this->pay_per_hour=30;
				else if(this->salary_level==2)
					this->pay_per_hour=50;
			if(hours >= 35)
				this->weekpay = (this->pay_per_hour)*40;
				else if(hours < 35)
					this->weekpay = (this->pay_per_hour)*hours + 0.5*(this->pay_per_hour)*(35-hours);
		}
		virtual void setName(string wname) {
			name = wname;
		}
		virtual string getName() {
			return this->name;
		} 
		
		virtual void setAge(int wage) {
			age = wage;
		} 
		virtual int getAge() {
			return this->age;
		}
		
		virtual void setSex(string wsex) {
			sex = wsex;
		}
		virtual string getSex() {
			return this->sex;
		} 
		
		virtual void setType(string wtype) {
			type = wtype;
		}
		virtual string getType() {
			return this->type;
		} 
		
		virtual void setSalaryLevel(int w_salary_level) {
			salary_level = w_salary_level;
		}
		virtual int getSalaryLevel() {
			return this->salary_level;
		}
		
		virtual void setPayPerHour(int w_pay_per_hour) {
			pay_per_hour = w_pay_per_hour;
		}
		virtual int getPayPerHour() {
			return this->pay_per_hour;
		}
};
int main() {
	Worker *worker[5];
	string nameTemp[5];
	int ageTemp[5];
	string sexTemp[5];
	string typeTemp[5];
	int salaryLevelTemp[5];
	int payPerHour[5];
	for(int i=0;i<5;i++) {
		cin >> nameTemp[i] >> ageTemp[i] >> sexTemp[i] >> typeTemp[i] >> salaryLevelTemp[i] ;
		cout << "\n";
	}	
	HourlyWorker *hworker0;
	hworker0->setName(nameTemp[0]);
	hworker0->setAge(ageTemp[0]);
	hworker0->setSex(sexTemp[0]);
	hworker0->setType(typeTemp[0]);
	hworker0->setSalaryLevel(salaryLevelTemp[0]);
	worker[0] = hworker0;
	
	HourlyWorker *hworker1;
	hworker1->setName(nameTemp[1]);
	hworker1->setAge(ageTemp[1]);
	hworker1->setSex(sexTemp[1]);
	hworker1->setType(typeTemp[1]);
	hworker1->setSalaryLevel(salaryLevelTemp[1]);
	worker[1] = hworker1;
	
	HourlyWorker *hworker2;
	hworker2->setName(nameTemp[2]);
	hworker2->setAge(ageTemp[2]);
	hworker2->setSex(sexTemp[2]);
	hworker2->setType(typeTemp[2]);
	hworker2->setSalaryLevel(salaryLevelTemp[2]);
	worker[2] = hworker2;
	
	SalariedWorker *sworker0;
	sworker0->setName(nameTemp[3]);
	sworker0->setAge(ageTemp[3]);
	sworker0->setSex(sexTemp[3]);
	sworker0->setType(typeTemp[3]);
	sworker0->setSalaryLevel(salaryLevelTemp[3]);
	worker[3] = sworker0;
	
	SalariedWorker *sworker1;
	sworker1->setName(nameTemp[4]);
	sworker1->setAge(ageTemp[4]);
	sworker1->setSex(sexTemp[4]);
	sworker1->setType(typeTemp[4]);
	sworker1->setSalaryLevel(salaryLevelTemp[4]);
	worker[4] = sworker1;
	
	int hoursTemp[5];
	for(int j=0;j<5;j++) {
		cin >> hoursTemp[j]; 
		worker[j]->Compute_pay(hoursTemp[j]);
	}
	for(int k=0;k<5;k++) {
		cout << worker[k];
	}
	return 0;
}

