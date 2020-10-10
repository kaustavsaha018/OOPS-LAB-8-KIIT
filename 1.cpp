/*
create a class Employee which stores employee name,id, and basic salary. Derive two classes from Employee Class:
Regular and part time. The Regular class stores DA,HRA and salary. The Part time class stores the number of hours 
and pay per hour and salary. The salary of the regular employee is basic + 50 % of basic(DA)+ 15 % of basic(HRA) and the salary of 
Part time employee is basic+ wages as per hours. Include appropriate functions to initialize and show the data members 
of the class. And the salary of the employee is to be calculated.
*/

#include<iostream>
#include<string.h>
using namespace std;

class Employee{
	protected:
		string name;
		int id;
		float basic_salary;
	
	public:
		Employee(){
			name="NULL";
			id=0;
			basic_salary=0;
		}
		void getDetails(string name, int id, float basic_salary){
			
			this->name=name;
			this->id=id;
			this->basic_salary=basic_salary;
		}
		float getSal(){
			return basic_salary;
		}
		void showDetails(){
			cout<<"Name: "<<name<<endl;
			cout<<"ID: "<<id<<endl;
		}	
};


class Regular : public Employee{
	protected:
		float DA;
		float HRA;
		float salary;
	
	public:
		void salary_calculate(){
			DA=0.5*basic_salary;
			HRA=0.15*basic_salary;
			salary=basic_salary+DA+HRA;
		    
		}
		void show_salary(){
			cout<<"Salary of the regular Employee = "<<salary<<endl;
		}
		
};

class Part_time : public Employee{
	protected:
		float hours;
		static const float pay_per_hr=15;
		float salary;
		
	public:
		void setHour(int hrs){
			hours=hrs;
		}
		void salary_calculate(){
			salary=basic_salary+(hours*pay_per_hr);
		}
		void show_salary(){
			cout<<"Salary of the part time Employee = "<<salary<<endl;
		}
};

int main(){
	
	Regular E1;
	E1.getDetails("Srijan Verma", 1929057, 1000);
	E1.showDetails();
	E1.salary_calculate();
	E1.show_salary();
	
	cout<<endl<<"----------------------------------------"<<endl<<endl;
	
	Part_time E2;
	E2.getDetails("Kaustav Saha", 1929018, 500);
	E2.setHour(2);
	E2.showDetails();
	E2.salary_calculate();
	E2.show_salary();
	
	return 0;
}
