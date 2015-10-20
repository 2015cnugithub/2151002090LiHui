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
		virtual void setName(string wname) {}
		virtual string getName() {} 
		
		virtual void setAge(int wage) {} 
		virtual int getAge() {}
		
		virtual void setSex(string wsex) {}
		virtual string getSex() {} 
		
		virtual void setType(string wtype) {}
		virtual string getType() {} 
		
		virtual void setSalaryLevel(int w_salary_level) {}
		virtual int getSalaryLevel() {}
		
		virtual void setPayPerHour(int w_pay_per_hour) {}
		virtual int getPayPerHour() {}
};
ostream& operator << (ostream& out,Worker& worker) {
	out << "用户名：" << worker.getName() << "\n" 
		<< "用户年龄：" <<worker.getAge() << "\n"
		<< "性别：" << worker.getSex() << "\n"
		<< "类型：" << worker.getType() << "\n"
		<< "薪金等级：" << worker.getSalaryLevel() << "\n"
		<< "小时工资额：" << worker.getPayPerHour() << "\n"; 
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
	worker[0] = hworker0;
	
	HourlyWorker *hworker1;
	worker[1] = hworker1;
	
	HourlyWorker *hworker2;
	worker[2] = hworker2;
	
	SalariedWorker *sworker0;
	worker[3] = sworker0;
	
	SalariedWorker *sworker1;
	worker[4] = sworker1;
	
	for(int i=0;i<4;i++) {
		worker[i]->setName(nameTemp[i]);
	}
	for(int i=0;i<4;i++) {
		worker[i]->setAge(ageTemp[i]);
	}
	for(int i=0;i<4;i++) {
		worker[i]->setSex(sexTemp[i]);
	}
	for(int i=0;i<4;i++) {
		worker[i]->setType(typeTemp[i]);
	}
	for(int i=0;i<4;i++) {
		worker[i]->setSalaryLevel(salaryLevelTemp[i]);
	}
	
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

