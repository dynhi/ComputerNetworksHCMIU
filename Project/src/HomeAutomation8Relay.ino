#include <SPI.h>
#include <Ethernet.h>  //Ethernet libraries

// MAC address and IP address 
// IP address in local network
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

// routers IP address
byte gateway[] = {192, 168, 1, 1};
// subnet address
byte subnet[] = {255, 255, 255, 0};
IPAddress ip(192, 168, 1, 120);

// Initialize the Ethernet server library with the IP address and port you want to use (80 for HTTP)
EthernetServer server(80);

#define RELAY_CHANNEL1 2
#define RELAY_CHANNEL2 3
#define RELAY_CHANNEL3 4
#define RELAY_CHANNEL4 5
#define RELAY_CHANNEL5 5
#define RELAY_CHANNEL6 6
#define RELAY_CHANNEL7 7
#define RELAY_CHANNEL8 8

String readString;

void setup() {
  // put your setup code here, to run once:
    pinMode(RELAY_CHANNEL1, OUTPUT);
  digitalWrite(RELAY_CHANNEL1, HIGH); // switch on light 1

    pinMode(RELAY_CHANNEL2, OUTPUT);
  digitalWrite(RELAY_CHANNEL2, HIGH); // switch on light 2
  
    pinMode(RELAY_CHANNEL3, OUTPUT);
  digitalWrite(RELAY_CHANNEL3, HIGH); // switch on light 3

    pinMode(RELAY_CHANNEL4, OUTPUT);
  digitalWrite(RELAY_CHANNEL4, HIGH); // switch on light 4

    pinMode(RELAY_CHANNEL5, OUTPUT);
  digitalWrite(RELAY_CHANNEL5, HIGH); // switch on light 5

    pinMode(RELAY_CHANNEL6, OUTPUT);
  digitalWrite(RELAY_CHANNEL6, HIGH); // switch on light 6

    pinMode(RELAY_CHANNEL7, OUTPUT);
  digitalWrite(RELAY_CHANNEL7, HIGH); // switch on light 7

    pinMode(RELAY_CHANNEL8, OUTPUT);
  digitalWrite(RELAY_CHANNEL8, HIGH); // switch on light 8

  // Open serial communications and wait for port to open
  Serial.begin(9600);
    while(!Serial){
      ;//wait for serial port to connect
    }

    // Start the Ethernet connection and the server
    Ethernet.begin(mac, ip);

    server.begin();
    Serial.print("Server is at ");
    Serial.println(Ethernet.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

  // Listen for incoming clients
  EthernetClient client = server.available();

  if(client){
    Serial.println("New client");
    //http request ends with a blank line
    boolean currentBlankLine = true;
    while(client.connected()){
      if(client.available()){
        char c = client.read();

        if(readString.length() < 100){
          //store characters to string
          readString += c;  //Serial.print(c);
        }

        Serial.write(c);
        //in case having to end the line (received a new line) and the line is blank, the http request has ended, so reply can be sent
        if(c == '\n' && currentBlankLine){
          // send a standard http respinse header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");

          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          
          client.println("<HEAD>");
          client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
          client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
          client.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"http://vandenbrande3ddesign.com/homeautomation.css\" />");
          client.println("<meta http-equiv=\"refresh\" content=\"5;url=http://192.168.1.120/\"/>" );
          client.println("</HEAD>");
          
          client.println("<body bgcolor=\"#333333\">");
          
          client.println("<h4><center><img border=\"2\" src=\"https://hcmiu.edu.vn/wp-content/uploads/2017/08/logo-vector-IU-01-255x255.png\" /></center></h4>");
          
          client.print("<center> <p> <h1></h1></p> ");
          
          /* Relay Control Code  */                
        
          client.println("<a href=\"/?relay1off\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\"; color:red ;>Lamp 1 OFF </font> </button> </a> ");
          client.println("<a href=\"/?relay1on\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 1 ON </font> </button> </a> <br />"); 
          client.println("<br />");
          

          client.println("<a href=\"/?relay2off\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 2 OFF </font> </button> </a> ");
          client.println("<a href=\"/?relay2on\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 2 ON </font> </button> </a> <br />"); 
          client.println("<br />");
          
          
          client.println("<a href=\"/?relay3off\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 3 OFF </font> </button> </a> ");
          client.println("<a href=\"/?relay3on\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 3 ON </font> </button> </a> <br />"); 
          client.println("<br />");
          

          client.println("<a href=\"/?relay4off\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 4 OFF </font> </button> </a> ");
          client.println("<a href=\"/?relay4on\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 4 ON </font> </button> </a> <br />"); 
          client.println("<br />");
         
          
          client.println("<a href=\"/?relay5off\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 5 OFF </font> </button> </a> ");
          client.println("<a href=\"/?relay5on\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 5 ON </font> </button> </a> <br />"); 
          client.println("<br />");        


          client.println("<a href=\"/?relay6off\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 6 OFF </font> </button> </a> ");
          client.println("<a href=\"/?relay6on\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 6 ON </font> </button> </a> <br />"); 
          client.println("<br />");
         
          
          client.println("<a href=\"/?relay7off\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 7 OFF </font> </button> </a> ");
          client.println("<a href=\"/?relay7on\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 7 ON </font> </button> </a> <br />");  
          client.println("<br />");
          

          client.println("<a href=\"/?relay8off\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 8 OFF </font> </button> </a> ");
          client.println("<a href=\"/?relay8on\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Lamp 8 ON </font> </button> </a> <br />"); 
          client.println("<br />");
         
          
          // control arduino pin via ethernet Start //

        if(readString.indexOf("?relay1off") >0){
          //checks for on
            digitalWrite(RELAY_CHANNEL1, HIGH);    // set pin 4 high
            //Serial.println("Led On");
      
            client.println("<link rel='apple-touch-icon' href='http://www.clker.com/cliparts/b/M/J/u/l/a/on-button-md.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
        }
        else{
          if(readString.indexOf("?relay1on") >0){
            //checks for off
            digitalWrite(RELAY_CHANNEL1, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://www.downloadclipart.net/medium/24595-off-button-clip-art.png' />");

            //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
          
          
        if(readString.indexOf("?relay2off") >0){
            //checks for on
            digitalWrite(RELAY_CHANNEL2, HIGH);    // set pin 4 high
            //Serial.println("Led On");
      
            client.println("<link rel='apple-touch-icon' href='http://www.clker.com/cliparts/b/M/J/u/l/a/on-button-md.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
        }
        else{
          if(readString.indexOf("?relay2on") >0){
            //checks for off
            digitalWrite(RELAY_CHANNEL2, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://www.downloadclipart.net/medium/24595-off-button-clip-art.png' />");

            //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
          
          
        if(readString.indexOf("?relay3off") >0){
            //checks for on
            digitalWrite(RELAY_CHANNEL3, HIGH);    // set pin 4 high
            //Serial.println("Led On");
      
            client.println("<link rel='apple-touch-icon' href='http://www.clker.com/cliparts/b/M/J/u/l/a/on-button-md.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
        }
        else{
          if(readString.indexOf("?relay3on") >0){
            //checks for off
            digitalWrite(RELAY_CHANNEL3, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://www.downloadclipart.net/medium/24595-off-button-clip-art.png' />");

            //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
        
        if(readString.indexOf("?relay4off") >0){
            //checks for on
            digitalWrite(RELAY_CHANNEL4, HIGH);    // set pin 4 high
            //Serial.println("Led On");
      
            client.println("<link rel='apple-touch-icon' href='http://www.clker.com/cliparts/b/M/J/u/l/a/on-button-md.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
        }
        else{
          if(readString.indexOf("?relay4on") >0){
            //checks for off
            digitalWrite(RELAY_CHANNEL4, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://www.downloadclipart.net/medium/24595-off-button-clip-art.png' />");

            //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
        
        if(readString.indexOf("?relay5off") >0){
            //checks for on
            digitalWrite(RELAY_CHANNEL5, HIGH);    // set pin 4 high
            //Serial.println("Led On");
      
            client.println("<link rel='apple-touch-icon' href='http://www.clker.com/cliparts/b/M/J/u/l/a/on-button-md.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
        }
        else{
          if(readString.indexOf("?relay5on") >0){
            //checks for off
            digitalWrite(RELAY_CHANNEL5, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://www.downloadclipart.net/medium/24595-off-button-clip-art.png' />");

            //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
          
          
        if(readString.indexOf("?relay6off") >0){
            //checks for on
            digitalWrite(RELAY_CHANNEL6, HIGH);    // set pin 4 high
            //Serial.println("Led On");
      
            client.println("<link rel='apple-touch-icon' href='http://www.clker.com/cliparts/b/M/J/u/l/a/on-button-md.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
        }
        else{
          if(readString.indexOf("?relay6on") >0){
            //checks for off
            digitalWrite(RELAY_CHANNEL6, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://www.downloadclipart.net/medium/24595-off-button-clip-art.png' />");

            //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
          
          
        if(readString.indexOf("?relay7off") >0){
            //checks for on
            digitalWrite(RELAY_CHANNEL7, HIGH);    // set pin 4 high
            //Serial.println("Led On");
      
            client.println("<link rel='apple-touch-icon' href='http://www.clker.com/cliparts/b/M/J/u/l/a/on-button-md.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
         }
        else{
          if(readString.indexOf("?relay7on") >0){
            //checks for off
            digitalWrite(RELAY_CHANNEL7, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://www.downloadclipart.net/medium/24595-off-button-clip-art.png' />");

            //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
        
        if(readString.indexOf("?relay8off") >0){
            //checks for on
            digitalWrite(RELAY_CHANNEL8, HIGH);    // set pin 4 high
            //Serial.println("Led On");
      
            client.println("<link rel='apple-touch-icon' href='http://www.clker.com/cliparts/b/M/J/u/l/a/on-button-md.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
        }
        else{
          if(readString.indexOf("?relay8on") >0){
            //checks for off
            digitalWrite(RELAY_CHANNEL8, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://www.downloadclipart.net/medium/24595-off-button-clip-art.png' />");

            //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
                  
          readString="";
          client.println("</body>");         
          client.println("</html>");
         
          break;
        }// if ( c == '\n' && currentBlankLine)
        
        
        if (c == '\n') {
          // you're starting a new line
          currentBlankLine = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentBlankLine = false;
        }      
      }
    }
    
    // give the web browser time to receive the data   
    delay(1);
    
    // close the connection:
    client.stop();
    Serial.println("Client disonnected");
    
  }//if(Client)

} //loop

