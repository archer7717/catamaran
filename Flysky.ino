

int PWM_ROLL = 13; //Define Digital PIN
int PWM_PITCH = 12; //Define Digital PIN
int PWM_THROTTLE = 11; //Define Digital PIN
int PWM_YAW = 10; //Define Digital PIN
int PWM_SWA = 9; //Define Digital PIN
int PWM_VRA = 8; //Define Digital PIN

void setup() {
  pinMode(PWM_ROLL, INPUT);
  pinMode(PWM_PITCH, INPUT);
  pinMode(PWM_THROTTLE, INPUT);
  pinMode(PWM_YAW, INPUT);
  pinMode(PWM_SWA, INPUT);
  pinMode(PWM_VRA, INPUT);
  Serial.begin(115200);
}

void loop() {
  int roll = pulseIn(PWM_ROLL, HIGH); //Read PWM Pulse
  int pitch = pulseIn(PWM_PITCH, HIGH); //Read PWM Pulse
  int throttle = pulseIn(PWM_THROTTLE, HIGH); //Read PWM Pulse
  int yaw = pulseIn(PWM_YAW, HIGH); //Read PWM Pulse
  int swA = pulseIn(PWM_SWA, HIGH); //Read PWM Pulse
  int vrA = pulseIn(PWM_VRA, HIGH); //Read PWM Pulse
  
  Serial.print(" PWM CH1 Roll: ");
  Serial.print(roll-1500);
  Serial.print(" PWM CH2 Pitch: ");
  Serial.print(pitch-1500);
  Serial.print(" PWM CH3 Throttle: ");
  Serial.println(throttle-1014);
  Serial.print(" PWM CH1 Yaw: ");
  Serial.print(yaw-1495);
  Serial.print(" PWM CH2 swA: ");
  Serial.print(swA-995);
  Serial.print(" PWM CH3 vrA: ");
  Serial.println(vrA-995);

}
