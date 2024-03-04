#include<conio.h>
#include<string.h>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<ctime>

using namespace std;

class login
{
public:
    int loginsys();
    string pass = "0000";
};

int login ::loginsys()
{
    while (1)
    {
        string password;
        cout << "\n\n\n\n\t\t\t\t---------->  CAR PARKING MANAGEMENT SYSTEM  <----------" << endl;
        char ch;
        cout << "\n\n\n\t\t\t\t\t\t Car Parking System Login";
        cout << "\n\n\n\n\t\t\t\t\t\t    Enter Password: ";
        ch = _getch();

        while (ch != 13)
        {
            password.push_back(ch);
            cout << '*';
            ch = _getch();
        }

        if (password == pass)
        {
            cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
            system("PAUSE");
            break;
        }

        else
        {
            cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
            system("PAUSE");
            system("CLS");
        }
    }
    return 1;
}



class EarnedMoney{
    private:
        int carType;
        int busType;
        int truckType;
        int bikeType;
        int cycleType;
        int total;
    public: 
    //Creating constructor 
        EarnedMoney(){
            this->carType=0;
            this->busType=0;
            this->truckType=0;
            this->bikeType=0;
            this->cycleType=0;
            this->total=0;
        }
        // Creating function and assigning the values to it 
        void setEarnedMoney(int newcarType,int newbusType,int newtruckType,int newbikeType,int newCycleType,int newtotal){
            this->carType=newcarType;
            this->busType=newbusType;
            this->truckType=newtruckType;
            this->bikeType=newbikeType;
            this->cycleType=newCycleType;
            this->total=newtotal;
        }
        // Printing the values 
        void showEarnedMoney(){
            cout<<"\n--------------------------------------------------------------\n";
            cout<<setw(10)<<"Car|"<<setw(10)<<"Bus|"<<setw(10)<<"Truck|"<<setw(10)<<"Bike|"<<setw(10)<<"Cycle|"<<setw(10)<<"Total|";
            cout<<"\n--------------------------------------------------------------\n";
            cout<<setw(9)<<this->carType<<"|"<<setw(9)<<this->busType<<"|"<<setw(9)<<this->truckType<<"|"<<setw(9)<<this->bikeType<<"|"<<setw(9)<<this->cycleType<<"|"<<setw(9)<<this->total<<"|";
            cout<<"\n--------------------------------------------------------------\n";
        }
        //getting all earned money 
        void getAllEarnedMoney();
        friend void addTwoMoney(EarnedMoney, EarnedMoney&);
        
};
void EarnedMoney:: getAllEarnedMoney(){
	ifstream fin;
	fin.open("EarnedMoneydata.txt",ios_base::in|ios_base::binary);
	
	if(!fin){
		cout<<"\n File not Found";
	}
	else{
		fin.read((char*)this,sizeof(*this));
	    //this->showEarnedMoney();
	}	
}

void addTwoMoney(EarnedMoney oldMoney,EarnedMoney &newMoney){
	newMoney.carType+=oldMoney.carType;	
	newMoney.busType+=oldMoney.busType;	
	newMoney.truckType+=oldMoney.truckType;	
	newMoney.bikeType+=oldMoney.bikeType;	
	newMoney.cycleType+=oldMoney.cycleType;
	newMoney.total+=oldMoney.total;		
}

class VehicleType{
    private:
        char vehicleTypeName[50];
    public:
        VehicleType(){
            strcpy(vehicleTypeName,"Vehicle");
        }
        // this it to enter the type of the vehicle as it may be different 

        void setVehicleType(EarnedMoney &earnedMoney){
            // creating infinite while loop so that even if choice is invalid we can enter the choice again.
            while(1){
                cout<<"\nSelect Vehicle Type: ";
                cout<<"\n1. Car 2. Bus  3. Truck  4. Bike  5. Cycle \n ";
                cout<<"\nEnter Your Choice :  ";
                int vehicleType;
                cin>>vehicleType;
                if(vehicleType==1){
                    strcpy(vehicleTypeName,"car");
                    earnedMoney.setEarnedMoney(100,0,0,0,0,100);
                    break;
                }
                else if(vehicleType==2){
                    strcpy(vehicleTypeName,"Bus");
                    earnedMoney.setEarnedMoney(0,200,0,0,0,200);
                    break;
                }
                else if(vehicleType==3){
                    strcpy(vehicleTypeName,"Truck");
                    earnedMoney.setEarnedMoney(0,0,400,0,0,400);
                    break;
                }
                else if(vehicleType==4){
                    strcpy(vehicleTypeName,"Bike");
                    earnedMoney.setEarnedMoney(0,0,0,50,0,50);
                    break;
                }
                else if(vehicleType==5){
                    strcpy(vehicleTypeName,"Cycle");
                    earnedMoney.setEarnedMoney(0,0,0,0,20,20);
                    break;
                }
                else{
                    cout<<"\nInvalid Choice: ";
                }
            }
        }

        //function to print the type of vehicle
        void showVehicleType(){cout<<vehicleTypeName<<"  ";}
};

//class Vehicle:public VehicleType  this inherits the properties from vehicletype class
//vehicleTypeName[50] has came in class Vehicle 
//concept used is inheritance ...

class Vehicle:public VehicleType{
    private:
    int vehicleNo;
    char shortDescription[60];
    char description[100];
    char createdBy[50];
    char lastUpdatedBy[50];
    char createdDateTime[50];
    char lastUpdatedDateTime[50];
    // creating object so that values are assigned to particular type of vehicle
    EarnedMoney earnedMoney;

    public:
    //creating constructor
    //this child class constructor" vehicle()"(line109) will call parent class constructor "VehicleType" (line50)
    Vehicle(){
        //this is object pointer (has address)

        this->vehicleNo=0;
        //strcpy is a string copy function 
        strcpy(this->shortDescription,"default");
        strcpy(this->description,"default");
        strcpy(this->createdBy,"Pranav");
        strcpy(this->lastUpdatedBy,"Pranav");
        //creating object for time function here it is tt
        time_t tt;
        //calling time fun
        time(&tt);
        strcpy(this->createdDateTime,asctime(localtime(&tt)));
        //asctime is function used to get time in string format
        strcpy(this->lastUpdatedDateTime,asctime(localtime(&tt)));

    }
    void setVehicle(){
            cout<<"\nEnter The Vehicle Number: ";
            cin>>vehicleNo;
            cin.ignore();
            cout<<"\nEnter Driver Name :  ";
            cin.getline(shortDescription,50);
            cout<<"\nEnter The Vehicle Description: ";
            cin.getline(description,100);
            strcpy(createdBy,"Pranav");
            strcpy(lastUpdatedBy,"Pranav");
            //calling the print vehicle type function
            setVehicleType(earnedMoney);
            // for date and time
            time_t tt;  
            time (&tt); 
            strcpy(createdDateTime,asctime(localtime(&tt)));
            strcpy(lastUpdatedDateTime,asctime(localtime(&tt)));
    }
     void showVehicle(){
            cout<<vehicleNo<<"  "<<shortDescription<<"  ";
            cout<<description<<"  ";
            showVehicleType();
            cout<<createdBy<<"  "<<lastUpdatedBy<<"  ";
            cout<<createdDateTime<<lastUpdatedDateTime<<endl;
            earnedMoney.showEarnedMoney();  

            //calling the show total earned money using the object used previously as we need object to call it  
        }
        //function for --------- FILE HANDLING --------
        void addvehicle();
        void getAllVehicleList();
        void searchVehicle(int vno);
        void deleteVehicle(int vno);
        void updateVehicle(int vno);
};


//-----------------------------------------FILE HANDLING ----------------------------------------------------
// defining member function that means we have to create/declare the function inside the class and define it outside the class 
// defining the member function using membership label 


void Vehicle:: addvehicle(){
    ofstream fout;
    fout.open("Vehicledata.txt",ios_base::app|ios_base::binary ); /*open file in append mode .. file gets updated if opened .... in write mode previous data gets deleted*/
    getch();
    fout.write((char*)this , sizeof(*this)); // (adress of object v , size of object v  (* is used for derefrencing )  ) 
    // take the address as char value..
    //  this pointer contains the address of the caller object  in our case caller object is v so we can call it using this pointer
    fout.close();
    EarnedMoney em;
	em.getAllEarnedMoney();
	addTwoMoney(em,this->earnedMoney);
    fout.open("EarnedMoneydata.txt",ios_base::out|ios_base::binary );
    fout.write((char*)(&this->earnedMoney),sizeof(this->earnedMoney));
    fout.close();
    cout<<"\nRecord added Successfully\n";
}

//printing all the vehicles entered
//all things same as above but difference is that it only reads the data
void Vehicle:: getAllVehicleList(){
    ifstream fin;
    // nor means number of record
    int nor = 0;

    fin.open("Vehicledata.txt",ios_base::in|ios_base::binary );
    if(!fin){
        cout<<"\n File not Found";
    }
    else{
        fin.read((char*)this , sizeof(*this));
        //eof end of file --- read the file till the end of file
        while(!fin.eof()){
            this->showVehicle();
            nor++;
            fin.read((char*)this , sizeof(*this));
        }
        fin.close();
        if(nor==0){
            cout<<"\n File has no Records ";
        }
    }
}

// vno vehicle number to search the particular vehicle 
void Vehicle:: searchVehicle(int vno){
     ifstream fin;
    // nor means number of record
    int nor = 0;

    fin.open("Vehicledata.txt",ios_base::in|ios_base::binary );
    if(!fin){
        cout<<"\n File not Found";
    }
    else{
        fin.read((char*)this , sizeof(*this));
        //eof end of file --- read the file till the end of file
        while(!fin.eof()){
            if(this->vehicleNo==vno){
                this->showVehicle();
                nor=1;
                break;
            }
            fin.read((char*)this , sizeof(*this));
        }
        fin.close();
        if(nor==0){
            cout<<"\n Record not Found ";
        }
    }
}

void Vehicle:: deleteVehicle(int vno){
// logic to delete is -----
//to delete the vehicle we will create the temp txt file that will only read the data ... 
//we will copy the data from the original txtfile to temp txtfile but it will not contain the number we want to delete  
// then we will rename the temp txtfile with original txt file name 

    ifstream fin;
    ofstream fout;
    int flag= 0;

    fin.open("Vehicledata.txt",ios_base::in|ios_base::binary );
    if(!fin){
        cout<<"\n File not Found";
    }
    else{
        fin.read((char*)this , sizeof(*this));
        //eof end of file --- read the file till the end of file
        fout.open("tempVehicledata.txt",ios_base::out|ios_base::binary);
        while(!fin.eof()){
            if(this->vehicleNo==vno){
                flag = 1;
            }
            else{
                fout.write((char*)this , sizeof(*this));
            }
            fin.read((char*)this , sizeof(*this));
        }
        fin.close();
        fout.close();

        //if the number to delete (record) is not found then we will remove the temp txtfile itself ...
        if(flag==0){
            cout<<"\n Record not Found: Hence cannot Delete ";
            remove("tempVehicledata.txt");
        }
        else{
     //if the number we want to delete(record) is found then we will delete the original txt file 
     //and we will rename the temp txt file name same to the original txtfile name    
            cout<<"/n Record Deleted ";
            remove("Vehicledata.txt");
            rename("tempVehicledata.txt","Vehicledata.txt");
        }
    }
}

// function to update the vehicle details  
void Vehicle:: updateVehicle(int vno){
     // ifstream is for read -----  ofstream is for write ------  f stram is to read & write both  
     fstream foutIn;
    // nor means number of record
    int flag = 0;

    foutIn.open("Vehicledata.txt",ios_base::in|ios_base::out|ios_base::ate|ios_base::binary );
    //get pointer is pointing to last location in file when opened in update mode 
    // to change its location we use seekg function which will point to the first location in file  
    foutIn.seekg(0);
    if(!foutIn){
        cout<<"\n File not Found";
    }
    else{
        foutIn.read((char*)this , sizeof(*this));
        //eof end of file --- read the file till the end of file
        while(!foutIn.eof()){
            if(this->vehicleNo==vno){
                cout<<"\nUpdating the Data";
                cout<<"\nEnter The Vehicle Number: ";
                cin>>vehicleNo;
                cin.ignore();
                cout<<"\nEnter Driver Name : ";
                cin.getline(shortDescription,50);
                cout<<"\nEnter The Vehicle Description: ";
                cin.getline(description,100);
                strcpy(createdBy,"Pranav");
                
                strcpy(lastUpdatedBy,"Pranav");
                //calling the print vehicle type function
                // for date and time
                time_t tt;  
                time (&tt); 
                strcpy(lastUpdatedDateTime,asctime(localtime(&tt)));
                //seekp is for put pointer
                //tell p tells the current position of put pointer
                //we have to take p pointer 1 postion /1 record back because while reading it is on next record and if we write it there it will overwrite the record 
                // so we take it to the position we want to update that is current posi - size of this 
                foutIn.seekp(foutIn.tellp()-sizeof(*this));
                foutIn.write((char*)this , sizeof(*this));
                cout<<"\n Record Updated Successfully\n";
                
                flag=1;
                break;
            }
            foutIn.read((char*)this , sizeof(*this));
        }
        foutIn.close();
        if(flag==0){
            cout<<"\n Record not Found ";
        }
    }
}
int menu(){
    int ch;
    printf("\n---------------------------------------------------\n");
    printf("\n1. Add Vehicle");
    printf("\n2. Search Vehicle");
    printf("\n3. Delete Vehicle");
    printf("\n4. Update Vehicle");
    printf("\n5. List All Vehicle");
    printf("\n6. Check Earned Money");
    printf("\n7. Exit\n");
    printf("\n---------------------------------------------------\n");
    printf("\nEnter Your Choice: ");
    scanf("%d",&ch);
    return(ch);
}
int main(){
    system("cls");
    login loginobj;
    loginobj.loginsys();
    Vehicle vehicle;
    EarnedMoney earnedMoney;
    int breakInfiniteLoop=0 , vno;
    while(1){
    	system("cls");
    	cout << "\n\n\n\n\t\t\t\t---------->  CAR PARKING MANAGEMENT SYSTEM  <----------" << endl;
    	switch(menu()){
    		case 1:
    			vehicle.setVehicle();
    			vehicle.addvehicle();
    			getch();
    			break;	
    		case 2:
    			cout<<"\n Enter the Vehicle Vehicle Number you want to Search : ";
    			cin>>vno;
    			vehicle.searchVehicle(vno);
    			getch();
    			break;
			case 3:cout<<"\n Enter the Vehicle Vehicle Number you want to Delete : ";
    			cin>>vno;
    			vehicle.deleteVehicle(vno);
    			getch();
    			break;
			case 4:cout<<"\n Enter the Vehicle Vehicle Number you want to Update : ";
    			cin>>vno;
    			vehicle.updateVehicle(vno);
    			getch();
    			break;
			case 5:
				cout<<"\nList of Vehicles : \n ";
				vehicle.getAllVehicleList();
				getch();
    			break;
			case 6:
				cout<<"\nOverall Earned Money: \n ";
				earnedMoney.getAllEarnedMoney();
				earnedMoney.showEarnedMoney();
				getch();
    			break;
			case 7:
				breakInfiniteLoop=1;
				break;
			default:
				cout<<"\n Invalid Choice !! ";
				getch();
		}//end of switch 
		if(breakInfiniteLoop==1){
			break;
		}//end of infinite loop
	}
    return(0);
}
