#include<iostream>
#include<fstream>
#include<sstream> // istringstream
#include<string>
#include<ctime>
#include<vector>

using namespace std;

static vector<string> list = {"simple", "medium", "difficult"};

int main(){

	string line;
	ifstream fin("record.txt");
	ofstream fout("tmp.txt");
	int counter;
	
	if(fin.is_open()){
		while(getline(fin,line)){
			if(line == list[0]){
				fout<<line<<endl;;
				getline(fin,line);
				istringstream isstr(line);
				cout<<isstr.str()<<endl;
				isstr>>counter;
				time_t t = time(nullptr);
				fout<<5<<" "<<asctime(localtime(&t));		
			}else{
				fout<<line<<endl;
			}
		}
	}

	//	fout<<endl;
	
	fin.close();
	fout.close();

	remove("record.txt");
	rename("tmp.txt","record.txt");

    return 0;
}
