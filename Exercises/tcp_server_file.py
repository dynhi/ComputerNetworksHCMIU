from socket import *

serverSocket = socket(AF_INET, SOCK_STREAM)
host = "10.205.9.45"
port = 1234
bandwidth = 20*(10**6) #~20MB
fileName = "message(recv).txt"
receiveFile = open(fileName, 'wb+')

serverSocket.bind((host, port))
serverSocket.listen(5)
print('Ready to receive')

connectionSocket, address = serverSocket.accept()
receiveBytes = connectionSocket.recv(bandwidth)
while (receiveBytes):
    print("Receiving...")
    receiveFile.write(receiveBytes)
    receiveBytes = connectionSocket.recv(bandwidth)
receiveFile.close()
print("Done Receiving")
connectionSocket.send('Thank you for the file'.encode())
connectionSocket.close()