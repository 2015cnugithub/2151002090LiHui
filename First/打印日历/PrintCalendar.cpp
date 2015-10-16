#include <iostream>
using namespace std;
#define ISYEAP(year) (((year%100!=0)&&(year%4==0)) || (year%400==0))?1:0
	//�����ж�����ĺ� 
int dayOfMonth[13][2] = {{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},
							{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
							//�洢ÿ�µ���������Ϊ�����ԭ��ֻ��2�²�ͬ 
struct Date { //����Date�ṹ�� 
	int Day;
	int Month;
	int Year;
	void nextDay() {  
		Day ++;
		if(Day > dayOfMonth[Month][ISYEAP(Year)]) {
			Day = 1;
			Month ++;
			if(Month > 12) {
				Month = 1;
				Year ++;
			}
		}
	}
};
char weekName[7][30] = {
	"������",
	"����һ",
	"���ڶ�",
	"������",
	"������",
	"������",
	"������" 
};	
int buf[5001][13][32]; //������±�Ϊ���������ʼ�����ľ��룻 

void getCalendar(int inputYear,int inputMonth,int inputDay) {
	Date date;
	int count = -2;
	date.Day = 1;
	date.Month = 1;
	date.Year = 0;
	while(date.Year < 5001) {
		buf[date.Year][date.Month][date.Day] = count;
		date.nextDay();
		count ++;
	} //��ʼ��buf���飻
	 
	for(int i=0;i<7;i++) { //�����Ҫ��ʾ�������б� 
		cout << weekName[i] << "\t";
	}
	cout << endl;


	int numOfDays = buf[inputYear][inputMonth][inputDay];
	int firstDay = (numOfDays+1)%7;
	int array[6][7] = {0};
	array[0][firstDay] = 1;
	for(int k=0;k<firstDay;k++) 
		cout << "\t";			//���ÿ�µ�һ��ǰ��Ŀհײ��֣�ÿ���մ���һ���Ʊ���Ŀհ׳��ȴ��棻 
	for(int j=firstDay;j<7;j++) {
		cout << array[0][j] << "\t";
		array[0][j+1] = array[0][j]+1;
	}  //�����һ����Ҫ��ʾ�����ڣ� 
	
	cout << "\n"; //��һ���Ѿ������ϣ�����׼�����������м�����У� 
	int countOfDays = dayOfMonth[inputMonth][ISYEAP(inputYear)]; 
	array[1][0] = array[0][6]+1;
	int remainDays = (countOfDays-(7-firstDay));
	for(int i=1;i<(remainDays/7+1);i++) {  //(remainDays/7+1) ������м���Ҫ��������е���������� 
		for(int j=0;j<7;j++) {
			cout << array[i][j] << "\t";
			array[i][j+1] = array[i][j]+1;		
		}     //����м�����������ϣ����潫������һ�����У� 
		cout << "\n";
	}
	int lastRaw = remainDays/7+1; //�������һ�е������� 
	array[lastRaw][0]= array[remainDays/7][6]+1;//�����һ�еĵ�һ������ֵ�� 
	for(int j=0;j<remainDays%7;j++) {	//ͨ����������������һ����Ҫ������ٸ�����	
		cout << array[lastRaw][j] << "\t";	
		array[lastRaw][j+1] = array[lastRaw][j]+1;
	} //���һ�������ϣ� 
} 

int main() {
	getCalendar(2015,10,8);
	return 0;
}


