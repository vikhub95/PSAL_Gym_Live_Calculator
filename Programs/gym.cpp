#include <iostream>
#include <string>
using namespace std;

void Event();
double Calculator(string event); //Every event, but Vault
double Vault();
void Instructions();
void Test(double a, double b, double c, double bonus, double req, double SV2);
//Displays values in A, B, C, Bonus, and Start Value Reserves

int main(){
	Instructions();
	Event();
	cout<<endl;
	cout<<"Thank you!"<<endl;
return 0;
}

void Event(){
	string athlete;
	double score;
	string event;
	do{
		cout<<"________________________________________________________________________________"<<endl;
		cout<<"Event: ";
		getline(cin, event);
		if(event == "end"){
			break;
		}
		if(event == "1"){ //Make FX loop
			do{
				cout<<"                                    Floor"<<endl;
				cout<<endl;
				cout<<"Athlete: ";
				getline(cin, athlete);
				if(athlete == "end"){
					break;
				}
				score = Calculator(event);
				cout<<"                                    "<<athlete<<": "<<score<<endl;
				cout<<"________________________________________________________________________________"<<endl;
			}while(getline(cin, athlete) != "end");
		}
		if(event == "2"){ //Make PH loop
			do{
				cout<<"                                  Pommel Horse"<<endl;
				cout<<endl;
				cout<<"Athlete: ";
				getline(cin, athlete);
				if(athlete == "end"){
					break;
				}
				score = Calculator(event);
				cout<<"                                    "<<athlete<<": "<<score<<endl;
				cout<<"________________________________________________________________________________"<<endl;
			}while(getline(cin, athlete) != "end");
		}
		if(event == "3"){ //Make SR loop
			do{
				cout<<"                                  Still Rings"<<endl;
				cout<<endl;
				cout<<"Athlete: ";
				getline(cin, athlete);
				if(athlete == "end"){
					break;
				}
				score = Calculator(event);
				cout<<"                                    "<<athlete<<": "<<score<<endl;
				cout<<"________________________________________________________________________________"<<endl;
			}while(getline(cin, athlete) != "end");
		
		}
		if(event == "4"){ //Vault loop
			do{
				cout<<"                                    Vault"<<endl;
				cout<<endl;
				cout<<"Athlete: ";
				getline(cin, athlete);
				if(athlete == "end"){
					break;
				}
				score = Vault();
				cout<<"                                    "<<athlete<<": "<<score<<endl;
				cout<<"________________________________________________________________________________"<<endl;
			}while(getline(cin, athlete) != "end");
		}
		if(event == "5"){ //Make PB loop
			do{
				cout<<"                                  Parallel Bars"<<endl;
				cout<<endl;
				cout<<"Athlete: ";
				getline(cin, athlete);
				if(athlete == "end"){
					break;
				}
				score = Calculator(event);
				cout<<"                                    "<<athlete<<": "<<score<<endl;
				cout<<"________________________________________________________________________________"<<endl;
			}while(getline(cin, athlete) != "end");
		}
		if(event == "6"){ //Make HB 
			do{
				cout<<"                                    High Bar"<<endl;
				cout<<endl;
				cout<<"Athlete: ";
				getline(cin, athlete);
				if(athlete == "end"){
					break;
				}
				score = Calculator(event);
				cout<<"                                    "<<athlete<<": "<<score<<endl;
				cout<<"________________________________________________________________________________"<<endl;
			}while(getline(cin, athlete) != "end");
		}
	}
	while(event != "end");
}

double Calculator(string event){

	//Declarations
	char ans; //Variable for yes or no dismount question
	char ans2; //Second variable for yes or no dismount question
	double presentationValue=5.4;
	double SV; //Actual Start value (9.4 maximum)
	double SV2; //Start Value after skill bonus and connection bonus is added
	double FinalScore; //Final Score
	double req=0; //Requirement reserve
	double a=0; //A Skill reserve
	double b=0; //B Skill reserve
	double c=0; //C Skill reserve
	double bonus=0; //Bonus reserve
	double small=0; //Small deduction reserve
	double medium=0; //Medium deduction reserve
	double large=0; //Large deduction reserve
	double fall=0; //Fall deduction reserve
	double Deductions=0; //Total deductions
	double missingParts=0; //Deductions for missing parts
	double numberFalls; //Number of falls
	double numberReq; //Number of requirements
	int parts=0; //Number of parts
	char n; //User skill value, requirements, bonus, deductions input
	cout<<"Input here: "; //Live user input
	
	//Calculations
	do{
		cin>>n;
		if((n=='a')){ //Adds .1 for each A skill (DONE)
			if(a<0.4){ //Limits to 4 A skills
				a+=0.1;
			}
		}
		if((n=='b')){ //Adds .3 for each B skill (DONE)
			if(b<1.8){ //Limits to 4 B skills AND 2 partially replaced C skills
				b+=0.3;
			}
		}
		if((n=='d')){ //Adds .6 into C box and .2 into bonus box
			bonus+=0.2;
			c+=0.6; //Treats D as a C skill
			if((c>1.2)){ //Bonus for each extra C skill
				bonus+=0.1;
			}
			if((b<1.2)&&(c>1.2)){ //Allows for C skills to replace B skills if there are over 2 C skills and less 4 B skills.
				b+=0.3;
			}
		}
		if((n=='c')){ //Adds .6 for each C skill
			c+=0.6; //Limits to 2 C skills
			if((c>1.2)){ //Bonus for each extra C skill
				bonus+=0.1;
			}
			if((b<1.2)&&(c>1.2)){ //Allows for C skills to replace B skills if there are over 2 C skills and less 4 B skills.
				b+=0.3;
			}
		}
		if((n=='r')){ //Adds .4 for each requirements (DONE)
			if(req<1.2){ //Limits to 3 requirements
				req+=0.4;
			}
		}
		if((n=='+')){ //User Bonus input (DONE)
			bonus+=0.1; //Fixed in Corrections post loop
		}
		if((n=='1')){ //Small deduction (DONE)
			small+=0.1;
		}
		if((n=='2')){ //Medium deduction (DONE)
			medium+=0.2;
		}
		if((n=='4')){ //Large deduction (DONE)
			large+=0.4;
		}
		if((n=='5')){ //Fall (DONE)
			fall+=0.5;
		}
		if((n=='a') || (n=='b') || (n=='c') || (n=='d')){ //Number of Parts (DONE)
			parts+=1;
		}
	}
	while(n != 'e'); //ends loop
	
	//Corrections
	if((bonus>=.6)){ //Maximizes bonus value (DONE)
		bonus=.6;
	}
	if((c>=1.2)){ //Maximizes C reserve value (DONE)
		//Note: C can be over 1.2 because of the way Bonus works
		if((b>1.2)){
			b=1.2;
		}
		c=1.2;
	}
	
	SV=(presentationValue + a + b + c + req); //Start Value without Bonus
	SV2 = SV + bonus; //Start Value with Bonus
	
	//Test Function
	//Test(a, b, c, bonus, req, SV2);
	
	//Rules
	if((SV2>=9.8)){ //9.8+ Routines need a C level dismount
		cout<<"C value dismount (y/n): ";
		cin>>ans;
		if((ans=='y')){ //If yes, safe
			Deductions+=0;
		}
		if((ans=='n')){ //If no, asks whether it was a B level dismount or not
			cout<<"B value dismount (y/n): ";
			cin>>ans2;
				if((ans2=='y')){ //If yes, only 0.2 off
					Deductions+=0.2;
				}
				if((ans2=='n')){ //If no, 0.4 off
					Deductions+=0.4;
				}
		}
	}
	else if((SV2>=9.4)){ //9.4+ SV routines need a B level dismount
		cout<<"B value dismount (y/n): ";
		cin>>ans;
		if((ans=='y')){ //If yes, safe 
			Deductions+=0;
		}
		else if((ans=='n')){ //If no, 0.2 deduction
			Deductions+=0.2;
		}
	}
	
	//Event-specific conditions based on user event input
	if(event == "2"){ //Pommel Horse
		char circles; //Circles
		char ends; //Touched both ends
		cout<<"Circles (y/n): ";
		cin>>circles;
		if((circles=='n')){
			Deductions+=0.2;
		}
		cout<<"Touched both ends (y/n): ";
		cin>>ends;
		if((ends=='n')){
			Deductions+=0.2;
		}
	}
	if(event == "6"){ //High Bar
		char backgiants; //Back Giants
		char forwardgiants; //Forward Giants
		cout<<"Back Giants (y/n): ";
		cin>>backgiants;
		if((backgiants=='n')){
			Deductions+=0.2;
		}
		cout<<"Forward Giants (y/n): ";
		cin>>forwardgiants;
		if((forwardgiants=='n')){
			Deductions+=0.2;
		}
	}
	
	//Other Data
	numberFalls = (fall*10.0)/5; //Total falls
	if((parts>=10)){ //Over 10 parts, no deductions
		missingParts+=0;
		parts=10;
	}
	else if((parts<=7)){ //0-7 parts, 0.5 each
		missingParts+=(8-parts)*(0.5);
	}
	Deductions+=(small + medium + large + fall + missingParts); //Total deductions
	numberReq = (req*10.0)/4; //Number of requirements
	FinalScore = SV2 - Deductions; //Generates Final Score
	
	//Final Report
	cout<<"Requirements: "<< numberReq <<endl;
	cout<<"Start Value: "<< SV <<endl;
	cout<<"Bonus: "<< bonus <<"/0.6"<<endl;
	cout<<"Full Start Value: "<< SV2 <<endl;
	cout<<"Missing Parts: "<< 10-parts <<endl;
	cout<<"Deductions: "<< Deductions <<endl;
	cout<<"Number of falls: "<< numberFalls <<endl;
	cout<<"Final Score: "<< FinalScore <<endl;
return FinalScore;
}

double Vault(){
	char d; //Deduction Input
	double Deductions=0; //Sum of deductions
	double SV; //Start Value
	double bonus=0; //Bonus
	string athlete; //Gymnast name
	double FinalScore; //Final Score
	cout<<"For a list of Vaults with values, enter '1' (one) when asked for Start Value."<<endl;
	cout<<"  "<<endl;
	cout<<"Reminder: ___      1M     1.5M   2M     2.5M   3M"<<endl;
	cout<<"       __|___|______|______|______|______|______|______"<<endl;
	cout<<"               -0.8   -0.3   -0.1          +0.1   +0.2"<<endl;
	cout<<"  "<<endl;
	cout<<"  "<<endl;
	
	cout<<"Input deductions: ";
	do{
		cin>>d;
		if((d=='+')){ //User Bonus input
			bonus+=0.1;
		}
		if((d=='1')){
			Deductions+=0.1;
		}
		if((d=='2')){
			Deductions+=0.2;
		}
		if((d=='4')){
			Deductions+=0.4;
		}
		if((d=='5')){
			Deductions+=0.5;
		}
	}
	while(d != 'e'); //ends loop
	cout<<"Bonus: "<<bonus<<endl;
	cout<<"Enter Start Value: ";
	cin>>SV;
	if((SV==1)){ 
		cout<<"7.0:"<<endl;
		cout<<"-Straddle"<<endl;
		cout<<"-Squat extension"<<endl;
		cout<<"  "<<endl;
		cout<<"7.6:"<<endl;
		cout<<"-Straddle with 1/2 twist"<<endl;
		cout<<"  "<<endl;
		cout<<"8.0:"<<endl;
		cout<<"-Round-off"<<endl;
		cout<<"-Stoop"<<endl;
		cout<<"  "<<endl;
		cout<<"8.4:"<<endl;
		cout<<"-Handspring with or without 1/2 twist"<<endl;
		cout<<"-Handspring sideways with 3/4 twist"<<endl;
		cout<<"-Half on - Handspring off with/without 1/2 twist"<<endl;
		cout<<"-Stoop with 1/2 twist"<<endl;
		cout<<"-Hecht with or without 1/2 twist"<<endl;
		cout<<"  "<<endl;
		cout<<"8.6:"<<endl;
		cout<<"-Full on - Handspring off"<<endl;
		cout<<"-Full on - half off"<<endl;
		cout<<"-Half on - full off"<<endl;
		cout<<"-Stoop with 1/1 twist"<<endl;
		cout<<"  "<<endl;
		cout<<"9.0:"<<endl;
		cout<<"-Handspring with 1/1 twist"<<endl;
		cout<<"-Handspring sideways with 1 1/4 twist"<<endl;
		cout<<"-Full on - Full off"<<endl;
		cout<<"  "<<endl;
		cout<<"9.2:"<<endl;
		cout<<"-Hecht with 1/1 twist"<<endl;
		cout<<"-Tsukahara (tuck)"<<endl;
		cout<<" "<<endl;
		cout<<"9.4:"<<endl;
		cout<<"-Handspring with 1 1/2 twist"<<endl;
		cout<<"-Tsukahara (pike)"<<endl;
		cout<<"-Tsukahara (tuck) with 1/2 twist"<<endl;
		cout<<"-Handspring, tuck front salto with/without 1/2 twist"<<endl;
		cout<<"-Handspring sideways with 1/4 twist, tuck front salto"<<endl;
		cout<<"  "<<endl;
		cout<<"9.6:"<<endl;
		cout<<"-Handspring sideways with 1/4 twist, pike front salto"<<endl;
		cout<<"-Handspring, pike front salto with/without 1/2 twist"<<endl;
		cout<<"-Handspring with double twist"<<endl;
		cout<<"-Tsukahara (layout) with/without 1/2 twist"<<endl;
		cout<<"-Cuervo (pike)"<<endl;
		cout<<"-Kasamatsu (tuck)/Tsukahara tuck with 1/1 twist"<<endl;
		cout<<"  "<<endl;
		cout<<"9.8:"<<endl;
		cout<<"-Handspring sideways with 1/4 twist, layout front salto"<<endl;
		cout<<"-Handspring with 2 1/2 twists"<<endl;
		cout<<"-Handspring layout front salt with/without 1/2 twist"<<endl;
		cout<<"-Cuervo (layout)"<<endl;
		cout<<"-Tsukahara pike with 1/1 twist"<<endl;
		cout<<"-Kasamatsu or Tsukahara (tuck, pike, layout) 1 1/2 twist or more"<<endl;
		cout<<" "<<endl;
		cout<<"Enter Start Value: ";
		cin>>SV;
	}
	FinalScore = SV + bonus - Deductions;
return FinalScore;
}

void Instructions(){
	cout<<"________________________________________________________________________________"<<endl;
	cout<<endl;
	cout<<"Welcome to the first ever PSAL live judging calculator!"<<endl;
	cout<<"1) Enter the corresponding number of the apparatus (see Note)."<<endl;
	cout<<"2) Enter the name of the athlete."<<endl;
	cout<<"3) Enter letter values of skills, deductions, and bonus without any spaces."<<endl;
	cout<<"4) Enter 'e' followed by the enter key to proceed."<<endl;
	cout<<"5) Enter 'end' when asked for the athlete's name to change apparatus"<<endl;
	cout<<"6) Enter 'end' when asked for the apparatus to close the program."<<endl;
	cout<<endl;
	cout<<"                                       Input Notes:"<<endl;
	cout<<endl;
	cout<<"*** 1=FX, 2=PH, 3=SR, 4=V, 5=SR, 6=HB, 'end'=close program ***"<<endl;
	cout<<"*** a=A Skill, b=B Skill, c=C Skill, d=D Skill, r=Requirement, e=End ***"<<endl;
	cout<<"*** Deductions: 1=small, 2=medium, 4=large, 5=fall and Bonus='+' ***"<<endl;
}

void Test(double a, double b, double c, double bonus, double req, double SV2){
	cout<<endl;
	cout<<"A reserve value: "<< a <<endl;
	cout<<"B reserve value: "<< b <<endl;
	cout<<"C reserve value: "<< c <<endl;
	cout<<"Requirements reserve value: "<< req <<endl;
	cout<<"Bonus Reserve value: "<< bonus <<endl;
	cout<<"Start Value: "<< SV2 <<endl;
	cout<<endl;
}

