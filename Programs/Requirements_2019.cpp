#include <iostream>
using namespace std;

int main(){
	char event; 
	cout<<endl;
	cout<<endl;
	cout<<"PSAL Event Requirements (2019)"<<endl;
	cout<<"FX=1 PH=2 SR=3 V=4 PB=5 HB=6 Exit=e"<<endl;

	do{
		cout<<endl;
		cout<<"Input an event: ";
		cin>>event;
		
		if((event == '1')){
			cout<<"Floor Exercise"<<endl;
			cout<<"(1)One tumbling skill, either forward or backward of at least C Value."<<endl;
			cout<<"(2)Either one tumbling series moving in the opposite direction with B value"<<endl;
			cout<<"   OR a single tumbling skill moving in the opposite direction with C value."<<endl;
			cout<<"(3)One strength skill of at least B Value."<<endl;
		}
		else if((event == '2')){
			cout<<"Pommel Horse"<<endl;
			cout<<"(1)Any two scissors."<<endl;
			cout<<"(2)Double leg circle skill of at least B Value, excluding mount (must start from circle or rear support)."<<endl;
			cout<<"(3)Additional double leg skill of at least B Value (may include the dismount.)"<<endl;
		}
		else if((event == '3')){
			cout<<"Still Rings"<<endl;
			cout<<"(1)One static strength skill of at least B value."<<endl;
			cout<<"(2)A (nominally) straight body B value inlocate or dislocate (shoulders rise halfway to the bottom of rings)."<<endl;
			cout<<"(3)One handstand executed with strength any value (hold 2 seconds)."<<endl;
		}
		else if((event == '4')){
			cout<<"Vault"<<endl;
			
			// 7.0
			cout<<"7.0:"<<endl;
			cout<<"-Squat extension"<<endl;
			cout<<endl;
			
			// 7.6
			cout<<"7.6:"<<endl;
			cout<<"-Straddle with 1/2 twist"<<endl;
			cout<<endl;
			
			// 8.0
			cout<<"8.0:"<<endl;
			cout<<"-Round-off"<<endl;
			cout<<"-Stoop"<<endl;
			cout<<endl;
			
			// 8.4
			cout<<"8.4:"<<endl;
			cout<<"-Handspring with or without 1/2 twist"<<endl;
			cout<<"-Handspring sideways with 3/4 twist"<<endl;
			cout<<"-Half on - Handspring off with/without 1/2 twist"<<endl;
			cout<<"-Stoop with 1/2 twist"<<endl;
			cout<<"-Hecht with or without 1/2 twist"<<endl;
			cout<<endl;
			
			// 8.6
			cout<<"8.6:"<<endl;
			cout<<"-Full on - Handspring off"<<endl;
			cout<<"-Full on - half off"<<endl;
			cout<<"-Half on - full off"<<endl;
			cout<<"-Stoop with 1/1 twist"<<endl;
			cout<<endl;
			
			// 9.0
			cout<<"9.0:"<<endl;
			cout<<"-Handspring with 1/1 twist"<<endl;
			cout<<"-Handspring sideways with 1 1/4 twist"<<endl;
			cout<<"-Full on - Full off"<<endl;
			cout<<endl;
			
			// 9.2
			cout<<"9.2:"<<endl;
			cout<<"-Hecht with 1/1 twist"<<endl;
			cout<<"-Tsukahara (tuck)"<<endl;
			cout<<endl;
			
			// 9.4
			cout<<"9.4:"<<endl;
			cout<<"-Handspring with 1 1/2 twist"<<endl;
			cout<<"-Tsukahara (pike)"<<endl;
			cout<<"-Tsukahara (tuck) with 1/2 twist"<<endl;
			cout<<"-Handspring, tuck front salto with/without 1/2 twist"<<endl;
			cout<<"-Handspring sideways with 1/4 twist, tuck front salto"<<endl;
			cout<<endl;
			
			//9.6
			cout<<"9.6:"<<endl;
			cout<<"-Handspring sideways with 1/4 twist, pike front salto"<<endl;
			cout<<"-Handspring, pike front salto with/without 1/2 twist"<<endl;
			cout<<"-Handspring with double twist"<<endl;
			cout<<"-Tsukahara (layout) with/without 1/2 twist"<<endl;
			cout<<"-Cuervo (pike)"<<endl;
			cout<<"-Kasamatsu (tuck)/Tsukahara tuck with 1/1 twist"<<endl;
			cout<<endl;
			
			// 9.8
			cout<<"9.8:"<<endl;
			cout<<"-Handspring sideways with 1/4 twist, layout front salto"<<endl;
			cout<<"-Handspring with 2 1/2 twists"<<endl;
			cout<<"-Handspring layout front salt with/without 1/2 twist"<<endl;
			cout<<"-Cuervo (layout)"<<endl;
			cout<<"-Tsukahara pike with 1/1 twist"<<endl;
			cout<<"-Kasamatsu or Tsukahara (tuck, pike, layout) 1 1/2 twist or more"<<endl;
		}
		else if((event == '5')){
			cout<<"Parallel Bars"<<endl;
			cout<<"(1)One skill, at least “B” value in which both hands are free of the bars, then re-grasp with one or both hands."<<endl;
			cout<<"(2)One skill done in or through a handstand."<<endl;
			cout<<"(3)One skill on two rails in or through a hang."<<endl;
		}
		else if((event == '6')){
			cout<<"High Bar"<<endl;
			cout<<"(1)One in-bar skill of at least B value."<<endl;
			cout<<"(2)A long hang ½ turn, fwd or bwd, either from and to giants or between a giant and at least a “B” value skill."<<endl;
			cout<<"(3)A B skill in which both hands are free of the bar, lift, then re-grasp with one or both hands."<<endl;
		}
		else{
			cout<<"Input out of scope."<<endl;
		}
	}
	while(event != 'e');

	return 0;
}