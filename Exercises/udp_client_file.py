from socket import *

clientSocket = socket(AF_INET, SOCK_DGRAM)
host = '10.205.11.21'
port = 1234
fileName = "image1.jpg"
bandwidth = 20000
server_address = (host, port)
print("Ready to send file")

clientSocket.sendto("File incomming".encode(), server_address)
fileSend = open(fileName, 'rb')

sendBytes = fileSend.read(bandwidth)
while (sendBytes):
    print('Sending...')
    clientSocket.sendto(sendBytes, server_address)
    sendBytes = fileSend.read(bandwidth)

fileSend.close()
print("Done Sending")
clientSocket.shutdown(SHUT_WR)
print(clientSocket.recv(bandwidth).decode())
clientSocket.close()