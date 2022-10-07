#define IR_BIT_LENGTH 32    // Nombre de bits envoyés par la télécommande IR
#define FirstLastBit 15     // Divisez 32 bits en deux blocs de 15 bits pour les variables entières. Ignorez les deux bits centraux. Ce sont tous les mêmes.
#define BIT_1 1500          // Seuil binaire 1 (microsecondes)
#define BIT_0 450           // Seuil 0 binaire (microsecondes)
#define BIT_START 4000      // Seuil de bit de démarrage (microsecondes)

#define IR_PIN 4            // Broche du capteur IR
#define LED_PIN 13          // La LED s'éteint lorsque le signal est reçu

int debug = 0;              // Assigne comme 1 pour sortir la longueur du flux de données d'impulsions IR brutes en microsecondes
int output_verify = 0;      // flag as 1 to print decoded verification integers. same number for all buttons
int output_key = 0;         // flag as 1 to print decoded key integers
int remote_verify = 16128;  // verifies first bits are 11111100000000 different remotes may have different start codes

int Blue_Bright=0;
int Red_Bright=0;
int Green_Bright=0;

int RedPin = 10;
int GreenPin = 11;
int BluePin = 9;

boolean Blue_flag=false;
boolean Red_flag=false;
boolean Green_flag=false;
boolean Flash_flag=false;

void setColor(int red, int green, int blue)
{
  analogWrite(RedPin, red);
  analogWrite(GreenPin, green);
  analogWrite(BluePin, blue);

}

SoftwareSerial HC05(2, 3);  // RX | TX 

void setup()
{
  pinMode(LED_PIN, OUTPUT); //This shows when ready to recieve
  pinMode(IR_PIN, INPUT);
  digitalWrite(LED_PIN, LOW);

  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  int key = get_ir_key();
  digitalWrite(LED_PIN, LOW);  // turn LED off while processing response
  do_response(key);
  if (Flash_flag)
  {
    for (int i=0;i<255;i++)
    {
      setColor(i, 0, 255-i);
      delay (10);
    }
    for (int i=0;i<255;i++)
    {
      setColor(255-i, i, 0);
      delay (10);
    }
    for (int i=0;i<255;i++)
    {
      setColor(0, 255-i, i);
      delay (10);
    }
  }
  else
  {
    if (Blue_flag)analogWrite(BluePin, Blue_Bright);else analogWrite(BluePin, 0);
    if (Red_flag)analogWrite(RedPin, Red_Bright);else analogWrite(RedPin, 0);
    if (Green_flag)analogWrite(GreenPin, Green_Bright);else analogWrite(GreenPin, 0);
  }
  delay(130);                  // 2 cycle delay to cancel duplicate keypresses
}

/*
  wait for a keypress from the IR remote, and return the
  integer mapping of that key (e.g. power button on remote returns
  the integer 1429)
*/

int get_ir_key()
{
  int pulse[IR_BIT_LENGTH];
  int bits[IR_BIT_LENGTH];

  do {} //Wait for a start bit
  while(pulseIn(IR_PIN, HIGH) < BIT_START);

  read_pulse(pulse);
  pulse_to_bits(pulse, bits);
  RemoteVerify(bits);
  return bits_to_int(bits);
}


/*
  use pulseIn to receive IR pulses from the remote.
  Record the length of these pulses (in ms) in an array
*/

void read_pulse(int pulse[])
{
  for (int i = 0; i < IR_BIT_LENGTH; i++)
  {
    pulse[i] = pulseIn(IR_PIN, HIGH);
  }
}

/*
  IR pulses encode binary "0" as a short pulse, and binary "1"
  as a long pulse.  Given an array containing pulse lengths,
  convert this to an array containing binary values
*/

void pulse_to_bits(int pulse[], int bits[])
{
  if (debug) { Serial.println("-----"); }
  for(int i = 0; i < IR_BIT_LENGTH; i++)
  {
    if (debug) { Serial.println(pulse[i]); }
    if(pulse[i] > BIT_1) //is it a 1?
    {
      bits[i] = 1;
    }
    else if(pulse[i] > BIT_0) //is it a 0?
    {
      bits[i] = 0;
    }
    else //data is invalid...
    {
      Serial.println("Error");
    }
  }
}

/*
  check returns proper first 14 check bits
*/

void RemoteVerify(int bits[])
{
  int result = 0;
  int seed = 1;

  //Convert bits to integer
  for(int i = 0 ; i < (FirstLastBit) ; i++)
  {
    if(bits[i] == 1)
    {
    result += seed;
    }

    seed *= 2;
  }
        if (output_verify)
      {
        Serial.print("Remote ");
        Serial.print(result);
        Serial.println(" verification code");
      }
 if (remote_verify != result) {delay (60); get_ir_key();} //verify first group of bits. delay for data stream to end, then try again.
}


/*
  convert an array of binary values to a single base-10 integer
*/

int bits_to_int(int bits[])
{
  int result = 0;
  int seed = 1;

  //Convert bits to integer
  for(int i = (IR_BIT_LENGTH-FirstLastBit) ; i < IR_BIT_LENGTH ; i++)
  {
    if(bits[i] == 1)
    {
    result += seed;
    }
    seed *= 2;
  }
  return result;
}


/*
  respond to specific remote-control keys with different behaviors
*/

void do_response(int key)
{

  if (output_key)
   {
      Serial.print("Key ");
      Serial.println(key);
   }

  switch (key)
  {
    case 32640:  // turns on UUT power
      if (Blue_flag|Red_flag|Green_flag){Blue_flag=false;Red_flag=false;Green_flag=false;Flash_flag=false;}
      else {Blue_flag=true;Red_flag=true;Green_flag==true;}
      Serial.println("POWER");
      break;

    case 32385:  // FUNC/STOP turns off UUT power
      Serial.println("FUNC/STOP");
      break;

    case 32130:  // |<< ReTest failed Test
      Serial.println("|<<");
      break;

    case 32002:  // >|| Test
      Serial.println(">||");
      break;

    case 31875:  // >>| perform selected test number
      Serial.println(">>|");
      break;

    case 32512:  // VOL+ turns on individual test beeper
      Serial.println("VOL+");
      break;

    case 31492:  // VOL- turns off individual test beeper
      Serial.println("VOL-");
      break;

    case 31620:  // v scroll down tests
    if (Blue_flag==true&&Blue_Bright>10)Blue_Bright-=10;
    if (Red_flag==true&&Red_Bright>10)Red_Bright-=10;
    if (Green_flag==true&&Green_Bright>10)Green_Bright-=10;
      Serial.println("v");
      break;

    case 31365:  // ^ scroll up tests
    if (Blue_flag==true&&Blue_Bright<245)Blue_Bright+=10;
    if (Red_flag==true&&Red_Bright<245)Red_Bright+=10;
    if (Green_flag==true&&Green_Bright<245)Green_Bright+=10;
      Serial.println("^");

      break;

    case 30982:  // EQ negative tests internal setup
      Serial.println("EQ");
      break;

    case 30855:  // ST/REPT Positive tests Select Test and Repeat Test
    Serial.println("ST/REPT");
      break;

    case 31110:  // 0
      Serial.println("0");
      break;

    case 30600:  // 1
    Red_flag=true;
    Green_flag=false;
    Blue_flag=false;
    Flash_flag=false;
    Red_Bright=120;
      Serial.println("1");
      break;

    case 30472:  // 2
    Green_flag=true;
    Red_flag=false;
    Blue_flag=false;
    Flash_flag=false;
    Green_Bright=120;
      Serial.println("2");
      break;

    case 30345:  // 3
    Blue_flag=true;
    Green_flag=false;
    Red_flag=false;
    Flash_flag=false;
    Blue_Bright=120;
      Serial.println("3");
      break;

    case 30090:  // 4
    Flash_flag=true;
      Serial.println("4");
      break;

    case 29962:  // 5
      Serial.println("5");
      break;

    case 29835:  // 6
      Serial.println("6");
      break;

    case 29580:  // 7
      Serial.println("7");
      break;

    case 29452:  // 8
      Serial.println("8");
      break;

    case 29325:  // 9
      Serial.println("9");
      break;

    default:
      {
        Serial.print("Key ");
        Serial.print(key);
        Serial.println(" not programmed");
      }
    break;
  }
}
