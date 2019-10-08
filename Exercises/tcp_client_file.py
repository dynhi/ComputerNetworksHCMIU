from socket import *

clientSocket = socket(AF_INET, SOCK_STREAM)
host = '10.205.11.21'
port = 1234
fileName = "image1.jpg"
bandwidth = 20*(10**6) #~20MB

clientSocket.connect((host, port))
fileSend = open(fileName, 'rb')
sendBytes = fileSend.read(bandwidth)
while (sendBytes):
    print('Sending...')
    clientSocket.send(sendBytes)
    sendBytes = fileSend.read(bandwidth)

fileSend.close()
print("Done Sending")
clientSocket.shutdown(SHUT_WR)
print(clientSocket.recv(bandwidth).decode())
clientSocket.close()