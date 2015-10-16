#include <iostream>
using namespace std;
#define ISYEAP(year) (((year%100!=0)&&(year%4==0)) || (year%400==0))?1:0
	//定义判断闰年的宏 
int dayOfMonth[13][2] = {{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},
							{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
							//存储每月的天数，因为闰年的原因，只有2月不同 
struct Date { //定义Date结构体 
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
	"星期天",
	"星期一",
	"星期二",
	"星期三",
	"星期四",
	"星期五",
	"星期六" 
};	
int buf[5001][13][32]; //存放以下标为年月日离初始天数的距离； 

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
	} //初始化buf数组；
	 
	for(int i=0;i<7;i++) { //输出需要显示的星期列表； 
		cout << weekName[i] << "\t";
	}
	cout << endl;


	int numOfDays = buf[inputYear][inputMonth][inputDay];
	int firstDay = (numOfDays+1)%7;
	int array[6][7] = {0};
	array[0][firstDay] = 1;
	for(int k=0;k<firstDay;k++) 
		cout << "\t";			//输出每月第一天前面的空白部分，每个空处用一个制表符的空白长度代替； 
	for(int j=firstDay;j<7;j++) {
		cout << array[0][j] << "\t";
		array[0][j+1] = array[0][j]+1;
	}  //输出第一行需要显示的日期； 
	
	cout << "\n"; //第一行已经输出完毕，换行准备进行输入中间的整行； 
	int countOfDays = dayOfMonth[inputMonth][ISYEAP(inputYear)]; 
	array[1][0] = array[0][6]+1;
	int remainDays = (countOfDays-(7-firstDay));
	for(int i=1;i<(remainDays/7+1);i++) {  //(remainDays/7+1) 计算出中间需要输出的整行的最大行数； 
		for(int j=0;j<7;j++) {
			cout << array[i][j] << "\t";
			array[i][j+1] = array[i][j]+1;		
		}     //输出中间整行行数完毕，下面将输出最后一非整行； 
		cout << "\n";
	}
	int lastRaw = remainDays/7+1; //计算最后一行的行数； 
	array[lastRaw][0]= array[remainDays/7][6]+1;//给最后一行的第一个数赋值； 
	for(int j=0;j<remainDays%7;j++) {	//通过求余运算算出最后一行需要输出所少个数；	
		cout << array[lastRaw][j] << "\t";	
		array[lastRaw][j+1] = array[lastRaw][j]+1;
	} //最后一行输出完毕； 
} 

int main() {
	getCalendar(2015,10,8);
	return 0;
}


