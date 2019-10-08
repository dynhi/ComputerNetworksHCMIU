from socket import *

serverSocket = socket(AF_INET, SOCK_DGRAM)
host = '10.205.9.45'
port = 1234
bandwidth = 20000
fileName = "message(recv).txt"
receiveFile = open(fileName, 'wb+')

serverSocket.bind((host, port))
# serverSocket.listen(5)
print('Ready to receive')
connectionSocket, clientAddress = serverSocket.recvfrom(1024)
print(connectionSocket.decode())

receiveBytes, clientAddress = serverSocket.recvfrom(bandwidth)
while (receiveBytes):
    print("Receiving...")
    receiveFile.write(receiveBytes)
    receiveBytes, clientAddress = serverSocket.recvfrom(bandwidth)

receiveFile.close()
print("Done Receiving")
serverSocket.sendto("Thanks for the file".encode(), clientAddress)
connectionSocket.close()