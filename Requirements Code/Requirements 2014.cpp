#include <iostream>
using namespace std;

int main(){
	char e; //Event
	cout<<"  "<<endl;
	cout<<"  "<<endl;
	cout<<"Welcome to the requirement reminder program!"<<endl;
	cout<<"FX=1 PH=2 SR=3 V=4 PB=5 HB=6 END='e'"<<endl;
	cout<<"  "<<endl;
	cout<<"Input an event: ";
	cin>>e;
	do{
	if((e=='1')){
		cout<<"Floor Exercise"<<endl;
		cout<<"(1)One tumbling series, either forward or backward of at leastnB Value."<<endl;
		cout<<"(2)One tumbling series in the opposite direction of at least C Value."<<endl;
		cout<<"(3)A strength skills of at least B Value."<<endl;
		cout<<"  "<<endl;
		cout<<"Input an event: ";
		cin>>e;
		}
	if((e=='2')){
		cout<<"Pommel Horse"<<endl;
		cout<<"(1)Any two scissors."<<endl;
		cout<<"(2)Double leg skill of at least B Value other than the mount or dismount."<<endl;
		cout<<"(3)Additional double leg skill of at least B Value (may include the dismount.)"<<endl;
		cout<<"  "<<endl;
		cout<<"Input an event: ";
		cin>>e;
		}
	if((e=='4')){
		cout<<"Vault"<<endl;
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
		cout<<"Input an event: ";
		cin>>e;
		}
	if((e=='3')){
		cout<<"Still Rings"<<endl;
		cout<<"(1)One static strength skill of at least B value."<<endl;
		cout<<"(2)One handstand executed with swing."<<endl;
		cout<<"(3)One handstand executed with strength."<<endl;
		cout<<"  "<<endl;
		cout<<"Input an event: ";
		cin>>e;
		}
	if((e=='5')){
		cout<<"Parallel Bars"<<endl;
		cout<<"(1)Any release move of at least B value."<<endl;
		cout<<"(2)One skill done in or through a handstand."<<endl;
		cout<<"(3)One skill on two rails in or through a hang."<<endl;
		cout<<"  "<<endl;
		cout<<"Input an event: ";
		cin>>e;
		}
	if((e=='6')){
		cout<<"High Bar"<<endl;
		cout<<"(1)One in-bar skill of at least B value."<<endl;
		cout<<"(2)Any B skill done with a dorsal/cubical grip through the lover vertical."<<endl;
		cout<<"(3)Any B value release skill."<<endl;
		cout<<"  "<<endl;
		cout<<"Input an event: ";
		cin>>e;
		}
	}
	while(e != 'e');
	cout<<"Thank you!"<<endl;
return 0;
}