#include <iostream>
#include <string>
using namespace std;

void Event();
double Calculator(string event); //Every event, but Vault
double Vault();
void Instructions();
void Test(double a, double b, double c, double bonus, double req, double Full_SV);
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
	string event;
	double score;
	
	do{
		bool exit_event = false;			// needs to be in the loop to reset after every event switch
		cout<<"________________________________________________________________________________"<<endl;
		cout<<"Event: ";
		getline(cin, event);
		
		// Floor
		if(event == "1"){
			do{
				cout<<"                                    Floor"<<endl;
				cout<<endl;
				cout<<"Athlete: ";
				getline(cin, athlete);
				if(athlete == "0"){
					exit_event = true;
				}
				else{
					score = Calculator(event);
					cout<<"                                    "<<athlete<<": "<<score<<endl;
					cout<<"________________________________________________________________________________"<<endl;
				}
			}while(exit_event == false);
		}
		
		// Pommel Horse
		else if(event == "2"){
			while(exit_event == false){
				cout<<"                                  Pommel Horse"<<endl;
				cout<<endl;
				cout<<"Athlete: ";
				getline(cin, athlete);
				if(athlete == "0"){
					exit_event = true;
				}
				else{
					score = Calculator(event);
					cout<<"                                    "<<athlete<<": "<<score<<endl;
					cout<<"________________________________________________________________________________"<<endl;
				}
			}
		}
		
		// Still Rings
		else if(event == "3"){
			while(exit_event == false){
				cout<<"                                  Still Rings"<<endl;
				cout<<endl;
				cout<<"Athlete: ";
				getline(cin, athlete);
				if(athlete == "0"){
					exit_event = true;
				}
				else{
					score = Calculator(event);
					cout<<"                                    "<<athlete<<": "<<score<<endl;
					cout<<"________________________________________________________________________________"<<endl;
				}
			}
		}
		
		// Vault
		else if(event == "4"){
			while(exit_event == false){
				cout<<"                                    Vault"<<endl;
				cout<<endl;
				cout<<"Athlete: ";
				getline(cin, athlete);
				if(athlete == "0"){
					exit_event = true;
				}
				else{
					score = Vault();
					cout<<"                                    "<<athlete<<": "<<score<<endl;
					cout<<"________________________________________________________________________________"<<endl;
				}
			}
		}
		
		// Parallel Bars
		else if(event == "5"){
			while(exit_event == false){
				cout<<"                                  Parallel Bars"<<endl;
				cout<<endl;
				cout<<"Athlete: ";
				getline(cin, athlete);
				if(athlete == "0"){
					exit_event = true;
				}
				else{
					score = Calculator(event);
					cout<<"                                    "<<athlete<<": "<<score<<endl;
					cout<<"________________________________________________________________________________"<<endl;
				}
			}
		}
		
		// High Bar
		else if(event == "6"){ 
			while(exit_event == false){
				cout<<"                                    High Bar"<<endl;
				cout<<endl;
				cout<<"Athlete: ";
				getline(cin, athlete);
				if(athlete == "0"){
					exit_event = true;
				}
				else{
					score = Calculator(event);
					cout<<"                                    "<<athlete<<": "<<score<<endl;
					cout<<"________________________________________________________________________________"<<endl;
				}
			}
		}
				
		// Error handling; Input out of scope.
		else{
			cout<<"Unrecognized Input. "<<endl;
		}
	}
	while(event != "end");
}

double Calculator(string event){

	//Declarations
	char ans; 							//Variable for yes or no dismount question
	char ans2; 							//Second variable for yes or no dismount question
	double pres_value = 5.4;
	double SV; 							//Actual Start value (9.4 maximum)
	double Full_SV; 						//Start Value after skill bonus and connection bonus is added
	double FinalScore; 					//Final Score
	double req = 0; 						//Requirement reserve
	double a = 0; 						//A Skill reserve
	double b = 0; 						//B Skill reserve
	double c = 0; 						//C Skill reserve
	double bonus = 0; 					//Bonus reserve
	double small_deduction = 0; 					//Small deduction reserve
	double medium_deduction = 0; 					//Medium deduction reserve
	double large_deduction = 0; 					//Large deduction reserve
	int falls = 0; 						//falls deduction reserve
	double total_deductions = 0;
	double missing_parts = 0; 			//total_deductions for missing parts
	int parts = 0; 						//Number of parts
	char n; 							//User skill value, requirements, bonus, total_deductions input
	cout<<"Input here: "; 				//Live user input
	
	//Calculations
	do{
		cin>>n;
		cin.ignore();					// Need this to work in conjunction with getline(cin, athlete)
										// Explanation: https://bit.ly/2IFIZZo
		
		// A Skills
		if( (n == 'a') && (a < 0.4) ){
			a+=0.1;
			parts++;
		}
		
		// B Skills
		if( (n == 'b') && (b < 1.8) ){
			b+=0.3;
			parts++;
		}
		
		// D Skills
		if(n == 'd'){
			bonus+=0.2;
			c+=0.6; 				//Treats D as a C skill
			parts++;
			if(c > 1.2){ 			//Bonus for each extra C skill
				bonus+=0.1;
			}
			if( (b < 1.2) && (c > 1.2) ){ 	//Allows for C skills to replace B skills if there are over 2 C skills and less than 4 B skills.
				b+=0.3;
			}
		}
		
		// C Skills
		if(n == 'c'){ 					//Adds .6 for each C skill
			parts++;
			c+=0.6; 					//Limits to 2 C skills
			if(c > 1.2){ 				//Bonus for each extra C skill
				bonus+=0.1;
			}
			if( (b < 1.2) && (c > 1.2) ){ 		//Allows for C skills to replace B skills if there are over 2 C skills and less 4 B skills.
				b+=0.3;
			}
		}
		
		if( (n == 'r') && (req < 3) ){
			req++;
		}
		if(n == '+'){
			bonus+=0.1;
		}
		if(n == '1'){ 
			small_deduction++;
		}
		if(n == '2'){ 
			medium_deduction++;
		}
		if(n == '4'){
			large_deduction++;
		}
		if(n == '5'){
			falls++;
		}
		if(n == 'e'){
			break;
		}

	}
	while(n != 'e');
	
	//Corrections
	if(bonus > 0.6){ 
		bonus = 0.6;
	}
	if(c >= 1.2){ //Maximizes C reserve value
		//Note: C can be over 1.2 because of the way Bonus works
		if(b > 1.2){
			b = 1.2;
		}
		c = 1.2;
	}
	
	
	SV = ( pres_value + a + b + c + (req*0.4) ); 		//Start Value without Bonus
	Full_SV = SV + bonus; 									//Start Value with Bonus
	
	//Test Function
	//Test(a, b, c, bonus, req, Full_SV);
	
	//*********** Deductions **************
	
	// Dismount Deductions
	if(Full_SV >= 9.8){ 							// SV 9.8+ needs at least C level dismount
		cout<<"C value dismount (y/n): ";
		cin>>ans;
		if(ans == 'y'){
			total_deductions += 0;
		}
		else if(ans == 'n'){ 					//If no, asks whether it was a B level dismount or not
			cout<<"B value dismount (y/n): ";
			cin>>ans2;
				if(ans2 == 'y'){ 				//If yes, only 0.2 off
					total_deductions += 0.2;
				}
				else if(ans2 == 'n'){ 			//If no, 0.4 off
					total_deductions += 0.4;
				}
		}
	}
	else if(Full_SV >= 9.4){ 						// SV 9.4+ needs at least B level dismount
		cout<<"B value dismount (y/n): ";
		cin>>ans;
		if(ans == 'y'){
			total_deductions += 0;
		}
		else if(ans == 'n'){ 
			total_deductions += 0.2;
		}
	}
	else{										// SV <9.4 does not require at least a B value dismount
		total_deductions += 0;
	}
	
	// Event-specific Deductions
	if(event == "2"){ //Pommel Horse
		char circles; //Circles
		char ends; //Touched both ends
		cout<<"Circles (y/n): ";
		cin>>circles;
		if(circles == 'n'){
			total_deductions += 0.2;
		}
		cout<<"Touched both ends (y/n): ";
		cin>>ends;
		if(ends == 'n'){
			total_deductions += 0.2;
		}
	}
	if(event == "6"){ //High Bar
		char backgiants; //Back Giants
		char forwardgiants; //Forward Giants
		cout<<"Back Giants (y/n): ";
		cin>>backgiants;
		if(backgiants == 'n'){
			total_deductions += 0.2;
		}
		cout<<"Forward Giants (y/n): ";
		cin>>forwardgiants;
		if(forwardgiants == 'n'){
			total_deductions += 0.2;
		}
	}
	
	// Short Routine Deductions
	if(parts >= 8){ //Over 8 parts, no deductions
		missing_parts = 0;
	}
	else{
		missing_parts += (8-parts);
	}
	
	// Final Deduction calculation
	total_deductions += ( (small_deduction*0.1) + (medium_deduction*0.2) + (large_deduction*0.4) + (falls*0.5) + (missing_parts*0.5) );

	// Final Score
	FinalScore = Full_SV - total_deductions; 
	
	//Final Report
	cout<<"Requirements: "<< req <<endl;
	cout<<"Start Value: "<< SV <<endl;
	cout<<"Bonus: "<< bonus <<"/0.6"<<endl;
	cout<<"Full Start Value: "<< Full_SV <<endl;
	cout<<"Missing Parts: "<< missing_parts <<endl;
	cout<<"Deductions: "<< total_deductions <<endl;
	cout<<"Falls: "<< falls <<endl;
	cout<<"Final Score: "<< FinalScore <<endl;
	
return FinalScore;
}

double Vault(){
	char d; //Deduction Input
	double total_deductions=0; //Sum of total_deductions
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
	
	cout<<"Input total_deductions: ";
	do{
		cin>>d;
		if((d=='+')){ //User Bonus input
			bonus+=0.1;
		}
		if((d=='1')){
			total_deductions+=0.1;
		}
		if((d=='2')){
			total_deductions+=0.2;
		}
		if((d=='4')){
			total_deductions+=0.4;
		}
		if((d=='5')){
			total_deductions+=0.5;
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
	FinalScore = SV + bonus - total_deductions;
return FinalScore;
}

void Instructions(){
	cout<<"________________________________________________________________________________"<<endl;
	cout<<endl;
	cout<<"Welcome to the first PSAL Gymnastics live calculator for Judges!"<<endl;
	cout<<""<<endl;
	
	cout<<"1) Select an event with it's corresponding number (see section below)."<<endl;
	cout<<"2) Type athlete's name and hit enter."<<endl;
	cout<<"3) Input letter values of skills, requirements, deductions, and bonus."<<endl;
	cout<<"4) Enter 'e' followed by the enter key to proceed."<<endl;
	cout<<"5) Enter '0' when asked for the athlete's name to change apparatus"<<endl;
	cout<<"6) Enter 'end' when asked for the apparatus to close the program."<<endl;
	cout<<endl;
	cout<<"                              Event Selection"<<endl;
	cout<<endl;
	cout<<"*** Floor Exercise (FX): 1"<<endl;
	cout<<"*** Pommel Horse   (PH): 2"<<endl;
	cout<<"*** Still Rings    (SR): 3"<<endl;
	cout<<"*** Vault           (V): 4"<<endl;
	cout<<"*** Parallel Bars  (PB): 5"<<endl;
	cout<<"*** High Bar       (HB): 6"<<endl;
	cout<<endl;
	cout<<"*** Exit Program       : end"<<endl;
	
	cout<<"The following are the allowed characters when live judging"<<endl;
	cout<<"All other characters will be ignored."<<endl;
	cout<<"*** A Skill            : a"<<endl;
	cout<<"*** B Skill            : b"<<endl;
	cout<<"*** C Skill            : c"<<endl;
	cout<<"*** D Skill            : d"<<endl;
	cout<<"*** Requirement        : r"<<endl;
	cout<<"*** Bonus              : +"<<endl;
	
	cout<<"*** Small Decuction (-0.1)   : 1"<<endl;
	cout<<"*** Medium Decuction (-0.2)  : 2"<<endl;
	cout<<"*** Large Decuction (-0.4)   : 4"<<endl;
	cout<<"*** Falls (-0.5)             : 5"<<endl;

}

void Test(double a, double b, double c, double bonus, double req, double Full_SV){
	cout<<endl;
	cout<<"A reserve value: "<< a <<endl;
	cout<<"B reserve value: "<< b <<endl;
	cout<<"C reserve value: "<< c <<endl;
	cout<<"Requirements reserve value: "<< req <<endl;
	cout<<"Bonus Reserve value: "<< bonus <<endl;
	cout<<"Start Value: "<< Full_SV <<endl;
	cout<<endl;
}

