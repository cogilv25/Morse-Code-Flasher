class MorseCodeCharacter
{
  public:
  int sequence[5];
  
  MorseCodeCharacter(int a, int b, int c, int d, int e)
  {
    sequence[0] = a;
    sequence[1] = b;
    sequence[2] = c;
    sequence[3] = d;
    sequence[4] = e;
  }
  void writeLetter(int pinID,int speed)
  {
    for(int i=0;i<5;i++)
    {
      if(sequence[i] == 1)
      {
        digitalWrite(pinID,HIGH);
        delay(100*speed);
        digitalWrite(pinID,LOW);
        delay(100*speed);
      }
      else if(sequence[i] == 2)
      {
        digitalWrite(pinID,HIGH);
        delay(300*speed);
        digitalWrite(pinID,LOW);
        delay(100*speed);
      }
    }
  }
};

class MorseCodeWriter
{
 private:
 int outputPin;
 int outputSpeed;
 public:
 MorseCodeCharacter * letters[26];
 MorseCodeCharacter * numbers[10];
 //Constructor - called when an Object is created
 MorseCodeWriter(int pinID, int speed)
 {
  outputPin = pinID;
  outputSpeed = speed;
  
  //initialise letters
  letters[0] = new MorseCodeCharacter(1,2,0,0,0); //A
  letters[1] = new MorseCodeCharacter(2,1,1,1,0); //B
  letters[2] = new MorseCodeCharacter(2,1,2,1,0); //C
  letters[3] = new MorseCodeCharacter(2,1,1,0,0); //D
  letters[4] = new MorseCodeCharacter(1,0,0,0,0); //E
  letters[5] = new MorseCodeCharacter(1,1,2,1,0); //F
  letters[6] = new MorseCodeCharacter(2,2,1,0,0); //G
  letters[7] = new MorseCodeCharacter(1,1,1,1,0); //H
  letters[8] = new MorseCodeCharacter(1,1,0,0,0); //I
  letters[9] = new MorseCodeCharacter(1,2,2,2,0); //J
  letters[10] = new MorseCodeCharacter(2,1,2,0,0); //K
  letters[11] = new MorseCodeCharacter(1,2,1,1,0); //L
  letters[12] = new MorseCodeCharacter(2,2,0,0,0); //M
  letters[13] = new MorseCodeCharacter(2,1,0,0,0); //N
  letters[14] = new MorseCodeCharacter(2,2,2,0,0); //O
  letters[15] = new MorseCodeCharacter(1,2,2,1,0); //P
  letters[16] = new MorseCodeCharacter(2,2,1,2,0); //Q
  letters[17] = new MorseCodeCharacter(1,2,1,0,0); //R
  letters[18] = new MorseCodeCharacter(1,1,1,0,0); //S
  letters[19] = new MorseCodeCharacter(2,0,0,0,0); //T
  letters[20] = new MorseCodeCharacter(1,1,2,0,0); //U
  letters[21] = new MorseCodeCharacter(1,1,1,2,0); //V
  letters[22] = new MorseCodeCharacter(1,2,2,0,0); //W
  letters[23] = new MorseCodeCharacter(2,1,1,2,0); //X
  letters[24] = new MorseCodeCharacter(2,1,2,2,0); //Y
  letters[25] = new MorseCodeCharacter(2,2,1,1,0); //Z
  
  //initialise numbers
  numbers[0] = new MorseCodeCharacter(2,2,2,2,2); //0
  numbers[1] = new MorseCodeCharacter(1,2,2,2,2); //1
  numbers[2] = new MorseCodeCharacter(1,1,2,2,2); //2
  numbers[3] = new MorseCodeCharacter(1,1,1,2,2); //3
  numbers[4] = new MorseCodeCharacter(1,1,1,1,2); //4
  numbers[5] = new MorseCodeCharacter(1,1,1,1,1); //5
  numbers[6] = new MorseCodeCharacter(2,1,1,1,1); //6
  numbers[7] = new MorseCodeCharacter(2,2,1,1,1); //7
  numbers[8] = new MorseCodeCharacter(2,2,2,1,1); //8
  numbers[9] = new MorseCodeCharacter(2,2,2,2,1); //9
 }

  //Deconstructor - called when an object is destroyed
 ~MorseCodeWriter()
 {
  //Anything created using "new" needs to be destroyed using "delete"
  //this isn't really needed for this program but it's good practice
  for(int i=0;i<26;i++)
  {
    delete letters[i];
    //You don't need curly braces ({}) when an if or for only runs one line
    if(i<10)
      delete numbers[i];
  }
 }

 
 void writeSentenceInMorse(const char * string)
 {
  //write supplied sentence in MorseCode on supplied pinID

  //This is a pointer to the current character
  const char * c = string;

  //Strings are null-terminated this means the last character is ASCII(0)
  //so this loop will run until it finds a 0
  while(*c != 0)
  {
    if(*c >47)
    {
      if(*c>64)
      {
        if(*c>96 && *c<123){
          //Lowercase Letter
          letters[*c-97]->writeLetter(outputPin,outputSpeed);
          delay(outputSpeed*200);
        }
        else if(*c<91)
        {
          //Uppercase Letter
          letters[*c-65]->writeLetter(outputPin,outputSpeed);
          delay(outputSpeed*200);
        }
      }
      else if(*c <58)
      {
        //Number
        numbers[*c-48]->writeLetter(outputPin,outputSpeed);
          delay(outputSpeed*200);
      }
    }
    else if(*c == 32)
      delay(outputSpeed*700);

    //Increment the pointer by 1 (this means that c is now pointing at the next letter)
    c++;
  }
 }
};

