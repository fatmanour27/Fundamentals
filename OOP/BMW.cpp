#include <iostream>
using namespace std;

class BMW
{
private:

	string DriveTrain = "All wheels drive";
	int PassengersCapacity = 5;

	void Engine()
	{
		cout << "Engine: " << EnginePure() << endl;
	}
	void HorsePower()
	{
		cout << "Horse Power: " << HorsePowerPure() << endl;
	}
	void Transmission()
	{
		cout << "Transmission: " << TransmissionPure() << endl;
	}
	void Acceleration()
	{
		cout << "Acceleration: " << AccelerationPure() << endl;
	}
	void FuelTank()
	{
		cout << "Fuel Tank: " << FuelTankPure() << endl;
	}

protected:

	virtual const char* EnginePure() = 0;
	virtual const char* HorsePowerPure() = 0;
	virtual const char* TransmissionPure() = 0;
	virtual const char* AccelerationPure() = 0;
	virtual const char* FuelTankPure() = 0;

public:

	string Driver()
	{
		return DriveTrain;
	}
	void Capacity()
	{
		cout << "Passengers Capacity: " << PassengersCapacity << endl;
	}
	void ListProperties()
	{
		Engine();
		HorsePower();
		Transmission();
		Acceleration();
		FuelTank();
		cout << "Thank you for your visit ^_^ " << endl;
	}
};
class SUV : public BMW{};
class X1 : public SUV
{
protected:

	const char* EnginePure()
	{
		return "2.0-liter BMW TwinPower Turbo inline 4-cylinder";
	}
	const char* HorsePowerPure()
	{
		return "241 bhp";
	}
	const char* TransmissionPure()
	{
		return "7-speed Dual clutch";
	}
	const char* AccelerationPure()
	{
		return "6.2 SEC";
	}
	const char* FuelTankPure()
	{
		return "400 miles";
	}
};
class X3 : public X1
{
protected:
	const char* HorsePowerPure()
	{
		return "248 bhp";
	}
	const char* TransmissionPure()
	{
		return "8-speed sport manual";
	}
	const char* AccelerationPure()
	{
		return "6.0 SEC";
	}
	const char* FuelTankPure()
	{
		return "412 miles";
	}
};
class X4 : public X3
{
protected:
	const char* HorsePowerPure()
	{
		return "248 bhp and 258 ib-ft";
	}
};
class X5 : public SUV
{
protected:
	const char* EnginePure()
	{
		return "3.0-liter BMW TwinPower Turbo inline 6-cylinder";
	}
	const char* HorsePowerPure()
	{
		return "335 bhp and 332 ib-ft";
	}
	const char* TransmissionPure()
	{
		return "8-speed sport manual";
	}
	const char* AccelerationPure()
	{
		return "5.3 SEC";
	}
	const char* FuelTankPure()
	{
		return "669 miles";
	}
};
class X7 : public X5 //X6 the same of X5
{
protected:
	const char* HorsePowerPure()
	{
		return "375 bhp and 398 ib-ft";
	}
	const char* AccelerationPure()
	{
		return "5.8 SEC";
	}
	const char* FuelTankPure()
	{
		return "640 miles";
	}
};
class iX : public SUV
{
protected:
	const char* EnginePure()
	{
		return "Dual electric model";
	}
	const char* HorsePowerPure()
	{
		return "516 hp and 564 in-ft";
	}
	const char* TransmissionPure()
	{
		return "Automatic";
	}
	const char* AccelerationPure()
	{
		return "4.4 SEC";
	}
	const char* FuelTankPure()
	{
		return "305-324 miles";
	}
};
class X3M : public SUV //X4M the same of X3M
{
protected:
	const char* EnginePure()
	{
		return "3.0-liter BMW M TwinPower Turbo inline 6-cylinder";
	}
	const char* HorsePowerPure()
	{
		return "473 bhp";
	}
	const char* TransmissionPure()
	{
		return "8-speed M sport Automatic";
	}
	const char* AccelerationPure()
	{
		return "3.9 SEC";
	}
	const char* FuelTankPure()
	{
		return "292 miles";
	}
};
class X5M : public SUV
{
protected:
	const char* EnginePure()
	{
		return "4.4-liter BMW M TwinPower Turbo V-8";
	}
	const char* HorsePowerPure()
	{
		return "600 bhp";
	}
	const char* TransmissionPure()
	{
		return "8-speed M sport STEPTRONIC";
	}
	const char* AccelerationPure()
	{
		return "3.7 SEC";
	}
	const char* FuelTankPure()
	{
		return "328 miles";
	}
};
class X6M : public X5M
{
protected:
	const char* TransmissionPure()
	{
		return "8-speed M sport Automatic";
	}
};
class Sedan : public BMW{};

class SedanTransmission8Speed  //intermediate class
{
protected:
	const char* TransmissionPure()
	{
		return "8-speed STEPTRONIC automatic";
	}
};

class LuxuryTransmissionSingleSpeed //intermediate class
{
protected:
	const char* TransmissionPure()
	{
		return "Single-speed automatic (electric drivetrain)";
	}
};
class Series2 : public Sedan, public SedanTransmission8Speed
{
protected:

	const char* EnginePure()
	{
		return " 2.0L BMW TwinPower Turbo inline 4-cylinder";
	}
	const char* HorsePowerPure()
	{
		return "241 hp";
	}
	const char* TransmissionPure() //we must override Transmission func in Series2 abstract class to can use it
	{
		return SedanTransmission8Speed::TransmissionPure();
	}
	const char* AccelerationPure()
	{
		return "6.3 SEC";
	}
	const char* FuelTankPure()
	{
		return "330 miles";
	}
};
class Series3 : public Series2
{
protected:
	const char* HorsePowerPure()
	{
		return "255 hp";
	}
	const char* AccelerationPure()
	{
		return "5.6 SEC";
	}
	const char* FuelTankPure()
	{
		return "342 miles";
	}
};
class Series5 : public Series3
{
protected:
	const char* AccelerationPure()
	{
		return "5.9 SEC";
	}
	const char* FuelTankPure()
	{
		return "450 miles";
	}
};
class i4Electric : public Sedan, public LuxuryTransmissionSingleSpeed
{
protected:
	const char* EnginePure()
	{
		return "Dual electric motors";
	}
	const char* HorsePowerPure()
	{
		return "335 hp";
	}
	const char* TransmissionPure() //we must override Transmission func in i4Electric abstract class to can use it as it's a pure virtual function
	{
		return LuxuryTransmissionSingleSpeed::TransmissionPure();
	}
	const char* AccelerationPure()
	{
		return "5.7 SEC";
	}
	const char* FuelTankPure()
	{
		return "battery range up to 301 miles";
	}
};
class i7Luxury : public i4Electric
{
protected:
	const char* AccelerationPure()
	{
		return "4.5 SEC";
	}
	const char* FuelTankPure()
	{
		return "battery range up to 310 miles";
	}
};
class Series2M : public Series2
{
protected:
	const char* EnginePure()
	{
		return "Performance-tuned 2.0L turbocharged engine";
	}
	const char* HorsePowerPure()
	{
		return "301 hp";
	}
	const char* AccelerationPure()
	{
		return "4.7 SEC";
	}
};
class Series3M : public Sedan, public SedanTransmission8Speed
{
protected:
	const char* EnginePure()
	{
		return "Plug-in hybrid (2.0L inline 4-cylinder + electric motor)";
	}
	const char* HorsePowerPure()
	{
		return "228 hp";
	}
	const char* TransmissionPure()
	{
		return SedanTransmission8Speed::TransmissionPure();
	}
	const char* AccelerationPure()
	{
		return "5.7 SEC";
	}
	const char* FuelTankPure()
	{
		return "battery range up to 301 miles";
	}
};
class Series5M : public Sedan, public SedanTransmission8Speed
{
protected:
	const char* EnginePure()
	{
		return "3.0L BMW TwinPower Turbo inline 6-cylinder with mild-hybrid technology";
	}
	const char* HorsePowerPure()
	{
		return "375 hp";
	}
	const char* TransmissionPure()
	{
		return SedanTransmission8Speed::TransmissionPure();
	}
	const char* AccelerationPure()
	{
		return "4.9 SEC";
	}
	const char* FuelTankPure()
	{
		return "450 miles";
	}
};
class i4ElectricM : public i4Electric
{
protected:
	const char* HorsePowerPure()
	{
		return "536 hp";
	}
	const char* AccelerationPure()
	{
		return "3.7 SEC";
	}
};
class Coupe : public BMW{};  //notice in this class we will not use intermediate classes
class Series2Coupe : public Coupe
{
protected:
	const char* EnginePure()
	{
		return "2.0L BMW TwinPower Turbo inline 4-cylinder";
	}
	const char* HorsePowerPure()
	{
		return "255 hp";
	}
	const char* TransmissionPure()
	{
		return "8-speed STEPTRONIC automatic";
	}
	const char* AccelerationPure()
	{
		return "5.5 SEC";
	}
	const char* FuelTankPure()
	{
		return "342.5 miles";
	}
};
class Series4Coupe : public Series2Coupe
{
protected:
	const char* AccelerationPure()
	{
		return "5.3 SEC";
	}
	const char* FuelTankPure()
	{
		return "390 miles";
	}
};
class M2Coupe : public Coupe
{
protected:
	const char* EnginePure()
	{
		return "3.0L BMW M TwinPower Turbo inline 6-cylinder";
	}
	const char* HorsePowerPure()
	{
		return "453 hp";
	}
	const char* TransmissionPure()
	{
		return "6-speed manual or 8-speed M STEPTRONIC automatic";
	}
	const char* AccelerationPure()
	{
		return "4.5 SEC";
	}
	const char* FuelTankPure()
	{
		return "342.5 miles";
	}
};
class M4Coupe : public M2Coupe
{
protected:
	const char* HorsePowerPure()
	{
		return "503 hp";
	}
	const char* TransmissionPure()
	{
		return "8-speed M STEPTRONIC automatic";
	}
	const char* AccelerationPure()
	{
		return "3.8 SEC";
	}
	const char* FuelTankPure()
	{
		return "390 miles";
	}
};
class Series8Luxury : public Coupe
{
protected:
	const char* EnginePure()
	{
		return "3.0L BMW TwinPower Turbo inline 6-cylinder";
	}
	const char* HorsePowerPure()
	{
		return "355 hp";
	}
	const char* TransmissionPure()
	{
		return "8-speed STEPTRONIC automatic";
	}
	const char* AccelerationPure()
	{
		return "4.7 SEC";
	}
	const char* FuelTankPure()
	{
		return "450 miles";
	}
};
class Series8LuxuryHybrid : public Series8Luxury
{
protected:
	const char* EnginePure()
	{
		return "4.4L BMW M TwinPower Turbo V8";
	}
	const char* HorsePowerPure()
	{
		return "523 hp";
	}
	const char* AccelerationPure()
	{
		return "3.7 SEC";
	}
};
class Touring : public BMW{};
class M5 : public Touring
{
protected:
	const char* EnginePure()
	{
		return "4.4L V8 TwinPower Turbo, 8-cylinder petrol engine with M TwinScroll turbochargers";
	}
	const char* HorsePowerPure()
	{
		return " 617 hp and 553 ib-ft";
	}
	const char* TransmissionPure()
	{
		return "8-speed M STEPTRONIC";
	}
	const char* AccelerationPure()
	{
		return "3.5-3.7 SEC";
	}
	const char* FuelTankPure()
	{
		return "68 liters";
	}
};

void NumOfPassengers(BMW* ptr)
{
	ptr->Capacity();
}
void List(BMW* ptr)
{
	ptr->ListProperties();
}

int main()
{
	int choice = -1;
	cout << "Choose From BMW models" << endl
		<< "Enter 1 to get features of  X1 xDrive28i SUV model " << endl
		<< "Enter 2 to get features of X3 30 xDrive SUV model " << endl
		<< "Enter 3 to get features of X4 xDrive30i SUV model " << endl
		<< "Enter 4 to get features of X5 xDrive40i SUV model " << endl
		<< "Enter 5 to get features of X7 xDrive40i SUV model " << endl
		<< "Enter 6 to get features of iX xDrive50 SUV model " << endl
		<< "Enter 7 to get features of X3 M50 xDrive SUV model " << endl
		<< "Enter 8 to get features of X5 M60i SUV model" << endl
		<< "Enter 9 to get features of X6 M Competition SUV model " << endl
		<< "Enter 10 to get features of 2 Series-228i Gran group Sedan model " << endl
		<< "Enter 11 to get features of 3 Series-330i (G20) Sedan model " << endl
		<< "Enter 12 to get features of 5 Series-530i Sedan model " << endl
		<< "Enter 13 to get features of i4 Electric-eDrive40 Sedan model " << endl
		<< "Enter 14 to get features of i7 Luxury Electric Sedan model " << endl
		<< "Enter 15 to get features of 2 Series-M235 Gran group Sedan model(M) " << endl
		<< "Enter 16 to get features of 3 Series-330e (G20) Sedan model(M) " << endl
		<< "Enter 17 to get features of 5 Series-540i (G30) Sedan model(M) " << endl
		<< "Enter 18 to get features of i4 Electric-M50 Sedan model(M)" << endl
		<< "Enter 19 to get 2 series Coupe model" << endl
		<< "Enter 20 to get 4 series Coupe model" << endl
		<< "Enter 21 to get M2 Coupe model" << endl
		<< "Enter 22 to get M4 Coupe model" << endl
		<< "Enter 23 to get 840i Luxury Coupe model" << endl
		<< "Enter 24 to get M850i xDrive Luxury Hybrid Coupe model" << endl
		<< "Enter 25 to get features of M5 Touring model " << endl
		<< "Enter 0 to exit: " << endl
		<< "Your Choice: ";
	cin >> choice;
	cout << endl;

	BMW* ptr = nullptr;

	if (choice == 0)
	{
		cout << "Exiting!" << endl;
	}
	else if (choice >= 1 && choice <= 25)
	{
		switch (choice)
		{
		case 1:
			ptr = new X1;
			break;
		case 2:
			ptr = new X3;
			break;
		case 3:
			ptr = new X4;
			break;
		case 4:
			ptr = new X5;
			break;
		case 5:
			ptr = new X7;
			break;
		case 6:
			ptr = new iX;
			break;
		case 7:
			ptr = new X3M;
			break;
		case 8:
			ptr = new X5M;
			break;
		case 9:
			ptr = new X6M;
			break;
		case 10:
			ptr = new Series2;
			break;
		case 11:
			ptr = new Series3;
			break;
		case 12:
			ptr = new Series5;
			break;
		case 13:
			ptr = new i4Electric;
			break;
		case 14:
			ptr = new i7Luxury;
			break;
		case 15:
			ptr = new Series2M;
			break;
		case 16:
			ptr = new Series3M;
			break;
		case 17:
			ptr = new Series5M;
			break;
		case 18:
			ptr = new i4ElectricM;
			break;
		case 19:
			ptr = new Series2Coupe;
			break;
		case 20:
			ptr = new Series4Coupe;
			break;
		case 21:
			ptr = new M2Coupe;
			break;
		case 22:
			ptr = new M4Coupe;
			break;
		case 23:
			ptr = new Series8Luxury;
			break;
		case 24:
			ptr = new Series8LuxuryHybrid;
			break;
		case 25:
			ptr = new M5;
			break;
		}
		cout << "Drive Train: " << ptr->Driver() << endl;
		NumOfPassengers(ptr);
		List(ptr);

		delete ptr;
	}
	else
	{
		cout << "Sorry Invalid Choice Try Again *_^" << endl;
	}

	return 0;
}
//Notice: we can Dispensable intermediate classes because we repeat Transmission Function by intermediate classes at derived class to be overriden as a pure virtual function to can points those classes by pointer(ptr)
//        But the main aim from using intermediate classes is prevent repetition Transmission function in derived classes but that not achieved
//        So we can use only base Sedan abstract class in inheritance and this will cause the repetition of Transmission function  at the derived classes in the same number of times repeatetion when using intermediate classes
//        I used intermediate classes to only practice using them as they very importance in preventing the repetition of The same function used in different ways in another case(that don't use pure virtaul function)