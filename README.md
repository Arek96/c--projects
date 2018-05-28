# c++_projects    

This repozitory conatins 11 projects made especially for **Object Programming** classes at Politechnika Śląska.  
Every project has full description of the task in pdf format in the destination folder (right beside the source code). Each application (from the first one to the fifth one) has a unit test. The testers for aplications are made by mgr Paweł Iwaneczko. Only one tester is my authorship and it is also one of the projects.  

##Description of each project

###Quadratic functions zeros  

Simple object aplication for finding the quadratic function zeros, and solving basic math equations like adding, substracting, multiplicating and dividing  

###Linked list    

Project with linked list class. You may find these methods in it:  

-  pushing back a point into the list
-  poping back a point
-  inserting a point in a specified place in the list
-  finding a specified point
-  getting a specified point
-  getting the size of of the list  

It is also compared, with a vector class from standard collection, by measuring the time of executing a task for each class individually.    

###Reader  

It contains two classes. The logger class adds a point, or a cloud of points, depending on the chosen method, to a file. It can save a binary or a csv file. The reader class reads points from a binary or csv file. It reads one point or many depending on the method.  

###ATM  

ATM machines software. Contains 4 classes, for every type of ATM. 

-  ATM class: is a basic class where are methods to unlock, withdraw and get the service info
-  Regular ATM class: inherits from ATM class. Additionaly has a method to check balance of account.
-  Cash In ATM class: inherits from Regular ATM. Has a method to deposit an amunt of cash.
-  Super ATM class: inherits from Cash In ATM. Has a method of rfid withdraw constrained to 50.  

###Threads  

Project for excercising threads creating and comunication between them.
It has a class Producent.In constructor a new therad is created and analogicaly, in the destructor the thread is terminated. The GetDataCopy method assigns created data addres to a pointer. 
Having created new object and called the GetDataCopy method, the main function(beeing a separate thread) gets data from the thread made in Producent class, counting the average of all numbers.  

###Tester  

Unit test of Quadratic functions zeros program.  

###Server  

Program for setting up a server using sockets. The server is initiailized in constructor of the Server class. The destructor closes the Client socket.
Server povides 3 methods:

-  Accept for listenning and accepting client socket
-  Echo for receiving frames. If the received frame is a text it is displayed in the console, else it could be only a file wich will be saved binary. After this the method displays information about received and send bytes.
-  Shutdown: shuts down the client socket.  

###Client  

Connects to the Server(the project described right above) and exchanges data with it. Client initializes Winsock, creates a socket and connects to a server in constructor. In the destructor the connection socket it closed.  
Methods of Client class:

-  Send: creates a frame and sends it to the server. Could send only text via this method.
-  Receive: displays data about bytes reached server and closed connection
-  SendFile: Creates frame with file and sends it to tyhe server.  

###Filters  

This program uses the OpenCV library to manipulate read images.
First it applies Sobel edge detection filter to image and saves it in the indictaed directory. Next it reverses the colors of the image and saves it. At the end it blurs the image, saves it and opens a window with image.  

###SQL  

Connects to a database and executes SQL commands.  

###OpenGL  

Uses the OpenGL library to display plygons in a window.

