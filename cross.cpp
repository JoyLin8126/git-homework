class health
{
public:
///attributes///
int heartbeat;
int weight;
int height;
int breathingrate;
int age;

///constructors///
patient()
{
for(int height=150; height<=200; height++)
{
  cout<<height<< ” “;
}
cout<< “\n”;
}

///functions///
int BMI(int weight, int height){
cout<<”Enter your height(m)”;
cin>>height;
cout<<”Enter your weight(kg)”;
cin weight;
cout<<”Enter your age: “;
cin>>age;
cout<<”Your BMI is : “<<(weight/height/height);
cout<<”Average range of BMI in “<<age<<”is”<<BMI;
}

int running(int heartbeat)
{ 
if (heartbeat>100)
{
cout<<”Warning”;
}
else if(heartbeat<60) 
{
cout<<”Warning”;
}
else
{
cout<<”Good”;
}

